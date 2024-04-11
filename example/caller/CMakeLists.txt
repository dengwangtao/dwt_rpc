
aux_source_directory(. SRC_LIST)

add_executable(consumer ${SRC_LIST} ../user.pb.cc ../info.pb.cc)

target_link_libraries(consumer dwtrpc protobuf)