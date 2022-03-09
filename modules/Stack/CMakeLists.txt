set(STACK_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${STACK_INCLUDE_DIR})

add_library(Stack SHARED src/Stack.cpp src/StackElement.cpp)