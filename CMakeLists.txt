project(OOP-2)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(modules)

add_subdirectory(tasks)

add_executable(debug debug.cpp)

target_link_libraries(debug KeyValueContainer Stack BigInteger Logger CSVParser)
