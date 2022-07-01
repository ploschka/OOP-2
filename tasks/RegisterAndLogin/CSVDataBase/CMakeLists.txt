set(USER_DATABASE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(UserDataBase SHARED src/UserDataBase.cpp)
target_include_directories(UserDataBase PUBLIC ${USER_DATABASE_INCLUDE_DIR})

target_link_libraries(UserDataBase Parser)
