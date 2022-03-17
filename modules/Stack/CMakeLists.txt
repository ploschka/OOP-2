set(STACK_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Stack SHARED Stack.h StackElement.h)
set_target_properties(Stack PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(Stack PUBLIC ${STACK_INCLUDE_DIR})