set(LOGGER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(Logger SHARED src/Logger.cpp src/LoggerFactory.cpp)
target_include_directories(Logger PUBLIC ${LOGGER_INCLUDE_DIR})