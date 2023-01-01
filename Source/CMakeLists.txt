cmake_minimum_required(VERSION 3.1)

#打印当前路径
message("cur dir = ${CMAKE_CURRENT_LIST_DIR}")

#增加头文件搜索路径
include_directories(${CMAKE_CURRENT_LIST_DIR}
                    ${CMAKE_CURRENT_LIST_DIR}/Private
                    ${CMAKE_CURRENT_LIST_DIR}/Public)

#增加源文件
aux_source_directory(${CMAKE_CURRENT_LIST_DIR} PROJ_SRC_LIST)

include_directories(${CMAKE_CURRENT_LIST_DIR/Private/CMakeLists.txt})

message("PROJ_SRC_LIST: ${PROJ_SRC_LIST}")

project(test)
add_executable(test Private/Activities/Maintain.cpp
                    Private/Activities/Activity.cpp
                    Private/Activities/Complaint.cpp
                    Private/Activities/Evaluate.cpp
                    Private/Systems/DispatchSystem.cpp
                    test/test.cpp
                    )
