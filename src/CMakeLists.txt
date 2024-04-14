

aux_source_directory(. SRC_LIST)

add_library(dwtrpc ${SRC_LIST})

target_link_libraries(dwtrpc muduo_net muduo_base zookeeper_mt pthread)