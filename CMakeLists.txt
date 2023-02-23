cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(qrcodeview)

set(CMAKE_INSTALL_BINDIR ${CMAKE_SOURCE_DIR}/build/bin)
set(CMAKE_INSTALL_LIBDIR ${CMAKE_SOURCE_DIR}/build/lib)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_DEBUG_POSTFIX d)

add_subdirectory(thirdparty)
add_subdirectory(qrcodeview)
add_subdirectory(qrcodeviewplugin)
add_subdirectory(examples)
