set(KEYVALUECONTAINER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_library(KeyValueContainer SHARED KVC.h)
set_target_properties(KeyValueContainer PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(KeyValueContainer PUBLIC ${KEYVALUECONTAINER_INCLUDE_DIR})