add_executable(test tests.cpp)

add_subdirectory(googletest)

target_link_libraries(test gtest gtest_main)
