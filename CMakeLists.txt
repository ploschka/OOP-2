add_subdirectory(modules)

add_subdirectory(tasks)

add_executable(debug debug.cpp)

target_link_libraries(debug KeyValueContainer Stack)