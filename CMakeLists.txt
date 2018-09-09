cmake_minimum_required(VERSION 3.8)

project(Test CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MYSOURCES "src/dog")

add_subdirectory(${MYSOURCES})

add_executable(main src/main)

target_link_libraries(main dog)