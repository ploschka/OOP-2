set(KEYVALUECONTAINER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${KEYVALUECONTAINER_INCLUDE_DIR})

add_library(KeyValueContainer SHARED src/KeyValueContainer.cpp)