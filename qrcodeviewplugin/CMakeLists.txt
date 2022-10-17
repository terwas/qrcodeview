cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(qrcodeviewplugin LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Designer)

add_library(${PROJECT_NAME} SHARED qrcodeviewplugin.cpp qrcodeviewplugin.h)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Designer
    qrcodeview
)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/qrcodeview)
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")