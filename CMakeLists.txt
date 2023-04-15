cmake_minimum_required(VERSION 3.5)

project("Surgical operation" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

install(TARGETS untitled
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
