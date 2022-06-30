set(CSVPARSER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(CSVParser SHARED src/CSVParser.cpp)
target_include_directories(CSVParser PUBLIC ${CSVPARSER_INCLUDE_DIR})
