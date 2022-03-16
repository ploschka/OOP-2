set(KEYVALUECONTAINER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(KeyValueContainer SHARED src/KVC.cpp src/KVE.cpp)
target_include_directories(KeyValueContainer PUBLIC ${KEYVALUECONTAINER_INCLUDE_DIR})