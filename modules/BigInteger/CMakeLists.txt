set(BIGINTEGER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(BigInteger SHARED src/BigInteger.cpp)
target_include_directories(BigInteger PUBLIC ${BIGINTEGER_INCLUDE_DIR})