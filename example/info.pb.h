// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: info.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_info_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_info_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_info_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_info_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_info_2eproto;
namespace dwt {
class InfoRequest;
struct InfoRequestDefaultTypeInternal;
extern InfoRequestDefaultTypeInternal _InfoRequest_default_instance_;
class InfoResponse;
struct InfoResponseDefaultTypeInternal;
extern InfoResponseDefaultTypeInternal _InfoResponse_default_instance_;
}  // namespace dwt
PROTOBUF_NAMESPACE_OPEN
template<> ::dwt::InfoRequest* Arena::CreateMaybeMessage<::dwt::InfoRequest>(Arena*);
template<> ::dwt::InfoResponse* Arena::CreateMaybeMessage<::dwt::InfoResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace dwt {

// ===================================================================

class InfoRequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:dwt.InfoRequest) */ {
 public:
  inline InfoRequest() : InfoRequest(nullptr) {}
  ~InfoRequest() override;
  explicit PROTOBUF_CONSTEXPR InfoRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  InfoRequest(const InfoRequest& from);
  InfoRequest(InfoRequest&& from) noexcept
    : InfoRequest() {
    *this = ::std::move(from);
  }

  inline InfoRequest& operator=(const InfoRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline InfoRequest& operator=(InfoRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const InfoRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const InfoRequest* internal_default_instance() {
    return reinterpret_cast<const InfoRequest*>(
               &_InfoRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(InfoRequest& a, InfoRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(InfoRequest* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(InfoRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  InfoRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<InfoRequest>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const InfoRequest& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const InfoRequest& from) {
    InfoRequest::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(InfoRequest* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "dwt.InfoRequest";
  }
  protected:
  explicit InfoRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUidFieldNumber = 1,
    kTypeFieldNumber = 2,
  };
  // int32 uid = 1;
  void clear_uid();
  int32_t uid() const;
  void set_uid(int32_t value);
  private:
  int32_t _internal_uid() const;
  void _internal_set_uid(int32_t value);
  public:

  // int32 type = 2;
  void clear_type();
  int32_t type() const;
  void set_type(int32_t value);
  private:
  int32_t _internal_type() const;
  void _internal_set_type(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:dwt.InfoRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    int32_t uid_;
    int32_t type_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_info_2eproto;
};
// -------------------------------------------------------------------

class InfoResponse final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:dwt.InfoResponse) */ {
 public:
  inline InfoResponse() : InfoResponse(nullptr) {}
  ~InfoResponse() override;
  explicit PROTOBUF_CONSTEXPR InfoResponse(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  InfoResponse(const InfoResponse& from);
  InfoResponse(InfoResponse&& from) noexcept
    : InfoResponse() {
    *this = ::std::move(from);
  }

  inline InfoResponse& operator=(const InfoResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline InfoResponse& operator=(InfoResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const InfoResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const InfoResponse* internal_default_instance() {
    return reinterpret_cast<const InfoResponse*>(
               &_InfoResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(InfoResponse& a, InfoResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(InfoResponse* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(InfoResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  InfoResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<InfoResponse>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const InfoResponse& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const InfoResponse& from) {
    InfoResponse::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(InfoResponse* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "dwt.InfoResponse";
  }
  protected:
  explicit InfoResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kInfoFieldNumber = 3,
    kSuccessFieldNumber = 1,
    kSizeFieldNumber = 2,
  };
  // repeated bytes info = 3;
  int info_size() const;
  private:
  int _internal_info_size() const;
  public:
  void clear_info();
  const std::string& info(int index) const;
  std::string* mutable_info(int index);
  void set_info(int index, const std::string& value);
  void set_info(int index, std::string&& value);
  void set_info(int index, const char* value);
  void set_info(int index, const void* value, size_t size);
  std::string* add_info();
  void add_info(const std::string& value);
  void add_info(std::string&& value);
  void add_info(const char* value);
  void add_info(const void* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& info() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_info();
  private:
  const std::string& _internal_info(int index) const;
  std::string* _internal_add_info();
  public:

  // bool success = 1;
  void clear_success();
  bool success() const;
  void set_success(bool value);
  private:
  bool _internal_success() const;
  void _internal_set_success(bool value);
  public:

  // int32 size = 2;
  void clear_size();
  int32_t size() const;
  void set_size(int32_t value);
  private:
  int32_t _internal_size() const;
  void _internal_set_size(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:dwt.InfoResponse)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> info_;
    bool success_;
    int32_t size_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_info_2eproto;
};
// ===================================================================

class InfoServiceRpc_Stub;

class InfoServiceRpc : public ::PROTOBUF_NAMESPACE_ID::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline InfoServiceRpc() {};
 public:
  virtual ~InfoServiceRpc();

  typedef InfoServiceRpc_Stub Stub;

  static const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* descriptor();

  virtual void GetInfo(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                       const ::dwt::InfoRequest* request,
                       ::dwt::InfoResponse* response,
                       ::google::protobuf::Closure* done);

  // implements Service ----------------------------------------------

  const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                  ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                  const ::PROTOBUF_NAMESPACE_ID::Message* request,
                  ::PROTOBUF_NAMESPACE_ID::Message* response,
                  ::google::protobuf::Closure* done);
  const ::PROTOBUF_NAMESPACE_ID::Message& GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const;
  const ::PROTOBUF_NAMESPACE_ID::Message& GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(InfoServiceRpc);
};

class InfoServiceRpc_Stub : public InfoServiceRpc {
 public:
  InfoServiceRpc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel);
  InfoServiceRpc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
                   ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership);
  ~InfoServiceRpc_Stub();

  inline ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel() { return channel_; }

  // implements InfoServiceRpc ------------------------------------------

  void GetInfo(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                       const ::dwt::InfoRequest* request,
                       ::dwt::InfoResponse* response,
                       ::google::protobuf::Closure* done);
 private:
  ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(InfoServiceRpc_Stub);
};


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// InfoRequest

// int32 uid = 1;
inline void InfoRequest::clear_uid() {
  _impl_.uid_ = 0;
}
inline int32_t InfoRequest::_internal_uid() const {
  return _impl_.uid_;
}
inline int32_t InfoRequest::uid() const {
  // @@protoc_insertion_point(field_get:dwt.InfoRequest.uid)
  return _internal_uid();
}
inline void InfoRequest::_internal_set_uid(int32_t value) {
  
  _impl_.uid_ = value;
}
inline void InfoRequest::set_uid(int32_t value) {
  _internal_set_uid(value);
  // @@protoc_insertion_point(field_set:dwt.InfoRequest.uid)
}

// int32 type = 2;
inline void InfoRequest::clear_type() {
  _impl_.type_ = 0;
}
inline int32_t InfoRequest::_internal_type() const {
  return _impl_.type_;
}
inline int32_t InfoRequest::type() const {
  // @@protoc_insertion_point(field_get:dwt.InfoRequest.type)
  return _internal_type();
}
inline void InfoRequest::_internal_set_type(int32_t value) {
  
  _impl_.type_ = value;
}
inline void InfoRequest::set_type(int32_t value) {
  _internal_set_type(value);
  // @@protoc_insertion_point(field_set:dwt.InfoRequest.type)
}

// -------------------------------------------------------------------

// InfoResponse

// bool success = 1;
inline void InfoResponse::clear_success() {
  _impl_.success_ = false;
}
inline bool InfoResponse::_internal_success() const {
  return _impl_.success_;
}
inline bool InfoResponse::success() const {
  // @@protoc_insertion_point(field_get:dwt.InfoResponse.success)
  return _internal_success();
}
inline void InfoResponse::_internal_set_success(bool value) {
  
  _impl_.success_ = value;
}
inline void InfoResponse::set_success(bool value) {
  _internal_set_success(value);
  // @@protoc_insertion_point(field_set:dwt.InfoResponse.success)
}

// int32 size = 2;
inline void InfoResponse::clear_size() {
  _impl_.size_ = 0;
}
inline int32_t InfoResponse::_internal_size() const {
  return _impl_.size_;
}
inline int32_t InfoResponse::size() const {
  // @@protoc_insertion_point(field_get:dwt.InfoResponse.size)
  return _internal_size();
}
inline void InfoResponse::_internal_set_size(int32_t value) {
  
  _impl_.size_ = value;
}
inline void InfoResponse::set_size(int32_t value) {
  _internal_set_size(value);
  // @@protoc_insertion_point(field_set:dwt.InfoResponse.size)
}

// repeated bytes info = 3;
inline int InfoResponse::_internal_info_size() const {
  return _impl_.info_.size();
}
inline int InfoResponse::info_size() const {
  return _internal_info_size();
}
inline void InfoResponse::clear_info() {
  _impl_.info_.Clear();
}
inline std::string* InfoResponse::add_info() {
  std::string* _s = _internal_add_info();
  // @@protoc_insertion_point(field_add_mutable:dwt.InfoResponse.info)
  return _s;
}
inline const std::string& InfoResponse::_internal_info(int index) const {
  return _impl_.info_.Get(index);
}
inline const std::string& InfoResponse::info(int index) const {
  // @@protoc_insertion_point(field_get:dwt.InfoResponse.info)
  return _internal_info(index);
}
inline std::string* InfoResponse::mutable_info(int index) {
  // @@protoc_insertion_point(field_mutable:dwt.InfoResponse.info)
  return _impl_.info_.Mutable(index);
}
inline void InfoResponse::set_info(int index, const std::string& value) {
  _impl_.info_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set:dwt.InfoResponse.info)
}
inline void InfoResponse::set_info(int index, std::string&& value) {
  _impl_.info_.Mutable(index)->assign(std::move(value));
  // @@protoc_insertion_point(field_set:dwt.InfoResponse.info)
}
inline void InfoResponse::set_info(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _impl_.info_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:dwt.InfoResponse.info)
}
inline void InfoResponse::set_info(int index, const void* value, size_t size) {
  _impl_.info_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:dwt.InfoResponse.info)
}
inline std::string* InfoResponse::_internal_add_info() {
  return _impl_.info_.Add();
}
inline void InfoResponse::add_info(const std::string& value) {
  _impl_.info_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:dwt.InfoResponse.info)
}
inline void InfoResponse::add_info(std::string&& value) {
  _impl_.info_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:dwt.InfoResponse.info)
}
inline void InfoResponse::add_info(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _impl_.info_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:dwt.InfoResponse.info)
}
inline void InfoResponse::add_info(const void* value, size_t size) {
  _impl_.info_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:dwt.InfoResponse.info)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
InfoResponse::info() const {
  // @@protoc_insertion_point(field_list:dwt.InfoResponse.info)
  return _impl_.info_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
InfoResponse::mutable_info() {
  // @@protoc_insertion_point(field_mutable_list:dwt.InfoResponse.info)
  return &_impl_.info_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace dwt

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_info_2eproto
