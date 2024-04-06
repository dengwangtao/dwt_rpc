

aux_source_directory(. SRC_LIST)

add_executable(provider ${SRC_LIST} ../user.pb.cc)

# 链接动态库
target_link_libraries(provider dwtrpc protobuf)