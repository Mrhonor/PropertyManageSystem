cmake_minimum_required(VERSION 3.1)

#打印当前路径
message("cur dir = ${CMAKE_CURRENT_LIST_DIR}")

#增加头文件搜索路径
include_directories(${CMAKE_CURRENT_LIST_DIR})

#增加源文件
aux_source_directory(${CMAKE_CURRENT_LIST_DIR} PROJ_SRC_LIST)

include(${CMAKE_CURRENT_LIST_DIR/Private/CMakeLists.txt})

project(test)
add_executable(test ${PROJ_SRC_LIST})
