cmake_minimum_required(VERSION 3.1)
message("cur dir = ${CMAKE_CURRENT_LIST_DIR}")

include_directories(${CMAKE_CURRENT_LIST_DIR})
aux_source_directory(${CMAKE_CURRENT_LIST_DIR} PROJ_SRC_LIST)