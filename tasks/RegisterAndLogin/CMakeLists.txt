add_subdirectory(StrelovParser)

add_subdirectory(CSVDataBase)

add_executable(register register.cpp)

add_executable(login login.cpp)

target_link_libraries(register Logger UserDataBase StrelovParser KeyValueContainer)

target_link_libraries(login Logger UserDataBase StrelovParser KeyValueContainer)
