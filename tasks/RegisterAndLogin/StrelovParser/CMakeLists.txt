set(STRELOV_PARSER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(StrelovParser SHARED src/StrelovParser.cpp src/StrelovParserAdapter.cpp)
target_include_directories(StrelovParser PUBLIC ${STRELOV_PARSER_INCLUDE_DIR})

target_link_libraries(StrelovParser Parser)
