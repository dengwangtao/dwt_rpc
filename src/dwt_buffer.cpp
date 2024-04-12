 #include "dwt_buffer.h"

DwtBuffer::DwtBuffer(int initBuffSize) : buffer_(initBuffSize), readPos_(0), writePos_(0) {}

// 可以读的数据的大小  写位置 - 读位置，中间的数据就是可以读的大小
size_t DwtBuffer::ReadableBytes() const {  
    return writePos_ - readPos_;
}

// 可以写的数据大小，缓冲区的总大小 - 写位置
size_t DwtBuffer::WritableBytes() const {
    return buffer_.size() - writePos_;
}

// 前面可以用的空间，当前读取到哪个位置，就是前面可以用的空间大小
size_t DwtBuffer::PrependableBytes() const {
    return readPos_;
}

const char* DwtBuffer::Peek() const {
    return BeginPtr_() + readPos_;
}

void DwtBuffer::Retrieve(size_t len) {
    assert(len <= ReadableBytes());
    readPos_ += len;
}

//buff.RetrieveUntil(lineEnd + 2);
void DwtBuffer::RetrieveUntil(const char* end) {
    assert(Peek() <= end );
    Retrieve(end - Peek());
}

void DwtBuffer::RetrieveAll() {
    bzero(&buffer_[0], buffer_.size());
    readPos_ = 0;
    writePos_ = 0;
}

std::string DwtBuffer::RetrieveAllToStr() {
    std::string str(Peek(), ReadableBytes());
    RetrieveAll();
    return str;
}

const char* DwtBuffer::BeginWriteConst() const {
    return BeginPtr_() + writePos_;
}

char* DwtBuffer::BeginWrite() {
    return BeginPtr_() + writePos_;
}

void DwtBuffer::HasWritten(size_t len) {
    writePos_ += len;
} 

void DwtBuffer::Append(const std::string& str) {
    Append(str.data(), str.length());
}

void DwtBuffer::Append(const void* data, size_t len) {
    assert(data);
    Append(static_cast<const char*>(data), len);
}

//  Append(buff, len - writable);   buff临时数组，len-writable是临时数组中的数据个数
void DwtBuffer::Append(const char* str, size_t len) {
    assert(str);
    EnsureWriteable(len);
    std::copy(str, str + len, BeginWrite());
    HasWritten(len);
}

void DwtBuffer::Append(const DwtBuffer& buff) {
    Append(buff.Peek(), buff.ReadableBytes());
}

void DwtBuffer::EnsureWriteable(size_t len) {
    if(WritableBytes() < len) {
        MakeSpace_(len);
    }
    assert(WritableBytes() >= len);
}

ssize_t DwtBuffer::ReadFd(int fd, int* saveErrno) {
    // 64KB
    char buff[65535];   // 临时的数组，保证能够把所有的数据都读出来
    
    struct iovec iov[2];
    const size_t writable = WritableBytes();
    
    /* 分散读，保证数据全部读完 */
    // iov[0] Buffer内置的数组_buffer，默认大小是1024
    // iov[1] buff临时数组，大小为65535
    iov[0].iov_base = BeginPtr_() + writePos_;
    iov[0].iov_len = writable;
    iov[1].iov_base = buff;
    iov[1].iov_len = sizeof(buff);

    const ssize_t len = readv(fd, iov, 2);  // 真正的读操作
    if(len < 0) {
        *saveErrno = errno;
    }
    else if(static_cast<size_t>(len) <= writable) {
        writePos_ += len;
    }
    else {
        writePos_ = buffer_.size();
        Append(buff, len - writable);
    }
    return len;
}

ssize_t DwtBuffer::WriteFd(int fd, int* saveErrno) {
    size_t readSize = ReadableBytes();
    ssize_t len = write(fd, Peek(), readSize);
    if(len < 0) {
        *saveErrno = errno;
        return len;
    } 
    readPos_ += len;
    return len;
}

char* DwtBuffer::BeginPtr_() {
    return &*buffer_.begin();  // 等价于&buffer[0]
}

const char* DwtBuffer::BeginPtr_() const {
    return &*buffer_.begin();
}

void DwtBuffer::MakeSpace_(size_t len) {
    if(WritableBytes() + PrependableBytes() < len) {
        buffer_.resize(writePos_ + len + 1);
    } 
    else {
        size_t readable = ReadableBytes();
        std::copy(BeginPtr_() + readPos_, BeginPtr_() + writePos_, BeginPtr_());
        readPos_ = 0;
        writePos_ = readPos_ + readable;
        assert(readable == ReadableBytes());
    }
}