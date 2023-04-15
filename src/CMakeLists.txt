cmake_minimum_required(VERSION 3.5)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(untitled main.cpp ${MY_INCLUDE_DIR}/my-coordinates.h my-coordinates.cpp ${MY_INCLUDE_DIR}/my-command.h my-command.cpp)

target_include_directories(untitled PUBLIC ${MY_INCLUDE_DIR})

install(TARGETS untitled
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
