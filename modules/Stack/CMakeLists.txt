set(STACK_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(Stack SHARED src/Stack.cpp src/StackElement.cpp)
target_include_directories(Stack PUBLIC ${STACK_INCLUDE_DIR})