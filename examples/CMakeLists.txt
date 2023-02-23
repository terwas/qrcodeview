cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(test LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets qrcodeview)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/qrcodeview)
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    DEPENDS qrcodeview
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:qrcodeview> $<TARGET_FILE_DIR:${PROJECT_NAME}>
)