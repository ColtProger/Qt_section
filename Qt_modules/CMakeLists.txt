cmake_minimum_required(VERSION 3.14)

project(Qt_modules LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Sql Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Sql Network)

add_executable(Qt_modules
  main.cpp
)
target_link_libraries(Qt_modules Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Sql)
target_link_libraries(Qt_modules Qt${QT_VERSION_MAJOR}::Network)

install(TARGETS Qt_modules
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
