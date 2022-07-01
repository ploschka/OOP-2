set(PARSER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(Parser SHARED src/Parser.cpp)
target_include_directories(Parser PUBLIC ${PARSER_INCLUDE_DIR})
