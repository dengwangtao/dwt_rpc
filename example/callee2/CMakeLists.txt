

aux_source_directory(. SRC_LIST)

add_executable(provider2 ${SRC_LIST} ../info.pb.cc)

# 链接库
target_link_libraries(provider2 dwtrpc protobuf)