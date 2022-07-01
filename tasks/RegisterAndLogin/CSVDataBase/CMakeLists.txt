set(DATABASE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(DataBase SHARED src/DataBase.cpp)
target_include_directories(DataBase PUBLIC ${DATABASE_INCLUDE_DIR})

target_link_libraries(DataBase StrelovParser)
