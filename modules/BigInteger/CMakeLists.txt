set(BIGINTEGER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${BIGINTEGER_INCLUDE_DIR})

add_library(BigInteger SHARED src/BigInteger.cpp)