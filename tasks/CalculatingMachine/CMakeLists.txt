add_subdirectory(CalcMachine)

add_executable(machine main.cpp)

target_link_libraries(machine CalcMachine BigInteger Stack Parser Logger)