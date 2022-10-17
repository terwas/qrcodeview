cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(qrcodeview LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_library(${PROJECT_NAME} SHARED qrcodeview.cpp qrcodeview.h)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    qrencode
)
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")


if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    message("===")
endif()

# set(CMAKE_INSTALL_PREFIX "")