set(CALCMACHINE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_library(CalcMachine SHARED CalcMachine.h CalcCommands.h CalcCommandFactory.h)
set_target_properties(CalcMachine PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(CalcMachine PUBLIC ${CALCMACHINE_INCLUDE_DIR})

target_link_libraries(CalcMachine KeyValueContainer)
