# dwt_rpc
RPC框架

基于muduo和protobuf的RPC（远程过程调用）框架，提供服务注册和服务调用，使用zookeeper作为服务注册中心

基本过程：

![rpc](https://github.com/dengwangtao/dwt_rpc/blob/main/rpc.png?raw=true)

## 开发环境

Windows Docker Desktop:  

- Ubuntu:22.04 (docker容器)
  - g++ 11.4.0
  - cmake 3.29.0
  - muduo
  - protobuf
- zookeeper环境 (docker容器)



## 容器

```shell
# 创建docker桥接网络
docker network create --driver bridge local-network

# 创建开发容器
docker run -it -d --name dev_01 --privileged=true --network=local-network --network-alias=dev_01 -v C:/docker_v/dev_01:/dwt ubuntu_dev

# 创建zookeeper容器
# 在本地创建三个目录 data datalog conf
# 创建一个临时容器, 使用docker cp test_zk:conf . 将配置文件拷贝出来, 放置到刚创建的conf中
# C:\docker_v\local-zookeeper\conf
# C:\docker_v\local-zookeeper\datalog
# C:\docker_v\local-zookeeper\data
docker run -d -e TZ="Asia/Shanghai" -p 21810:2181 -v C:\docker_v\local-zookeeper\data:/data -v C:\docker_v\local-zookeeper\datalog:/datalog -v C:\docker_v\local-zookeeper\conf:/conf --name local-zookeeper --network=local-network --network-alias=local-zookeeper zookeeper:3.4.10


# 注：通过开发服务器可以根据“local-zookeeper”找到zk服务器， 通过docker DNS解析
```



## 目录树

```
.
|-- CMakeLists.txt
|-- README.md
|-- bin							编译生成的example可执行文件 和 运行所需配置文件
|   |-- consumer
|   |-- dwtconfig.json
|   |-- log						日志文件
|   `-- provider
|-- build
|-- example						框架使用example
|   |-- CMakeLists.txt
|   |-- callee
|   |   |-- CMakeLists.txt
|   |   `-- userservice.cpp
|   |-- caller
|   |   |-- CMakeLists.txt
|   |   `-- calluserservice.cpp
|   |-- info.pb.cc
|   |-- info.pb.h
|   |-- info.proto
|   |-- user.pb.cc
|   |-- user.pb.h
|   `-- user.proto
|-- lib							框架编译目标， 静态库
|   `-- libdwtrpc.a
|-- src							框架源码
|   |-- CMakeLists.txt
|   |-- dwt_buffer.cpp
|   |-- dwt_logger.cpp
|   |-- dwt_rpc_application.cpp
|   |-- dwt_rpc_channel.cpp
|   |-- dwt_rpc_config.cpp
|   |-- dwt_rpc_controller.cpp
|   |-- dwt_rpc_provider.cpp
|   |-- include							头文件
|   |   |-- dwt_block_queue.hpp			阻塞队列（日志）
|   |   |-- dwt_buffer.h				缓冲区（日志）
|   |   |-- dwt_logger.h				异步日志
|   |   |-- dwt_rpc_application.h		框架初始化模块
|   |   |-- dwt_rpc_channel.h			服务调用模块
|   |   |-- dwt_rpc_config.h			框架配置模块
|   |   |-- dwt_rpc_controller.h		controller模块
|   |   |-- dwt_rpc_provider.h			服务注册模块
|   |   |-- rpcheader.pb.h				框架通信协议（protobuf）
|   |   `-- zookeeper_util.h
|   |-- rpcheader.pb.cc
|   |-- rpcheader.proto
|   |-- thirdparty
|   |   |-- cmdline.hpp					第三方命令行解析， 用于指定日志等级、配置文件位置
|   |   `-- json.hpp					解析配置文件
|   `-- zookeeper_util.cpp				连接zk服务器
`-- test
```



## 开发工具

- Visual Studio Code




### 第三方库
- jsonhpp：[nlohmann/json: JSON for Modern C++ (github.com)](https://github.com/nlohmann/json) (配置文件)
- cmdline：[tanakh/cmdline: A Command Line Parser (github.com)](https://github.com/tanakh/cmdline) (解析命令行参数)
- muduo：[chenshuo/muduo: Event-driven network library for multi-threaded Linux server in C++11 (github.com)](https://github.com/chenshuo/muduo) (网络通信)
- zookeeper：[zookeeper Tags | Docker Hub](https://hub.docker.com/_/zookeeper/tags) (zk客户端C接口)



## Example 调用过程

![example](https://github.com/dengwangtao/dwt_rpc/blob/main/example/example.png?raw=true)
