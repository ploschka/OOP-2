add_executable(test BigIntegerTests.cpp KVCTests.cpp ParserTests.cpp StackTests.cpp)

add_subdirectory(googletest)

target_link_libraries(test gtest gtest_main BigInteger Parser KeyValueContainer Stack)
