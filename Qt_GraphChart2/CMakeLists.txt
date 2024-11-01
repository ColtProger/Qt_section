cmake_minimum_required(VERSION 3.5)

project(Qt_GraphChart VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Concurrent Charts Core Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Concurrent Charts Core Gui)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        graphicchart.cpp
        graphicchart.h
      # formplot.cpp
      #  formplot.h
      #  formplot.ui
)

qt_add_executable(Qt_GraphChart  ${PROJECT_SOURCES})

target_link_libraries(Qt_GraphChart PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                            Qt${QT_VERSION_MAJOR}::Concurrent
                                            Qt${QT_VERSION_MAJOR}::Charts
                                            Qt${QT_VERSION_MAJOR}::Core
                                            Qt${QT_VERSION_MAJOR}::Gui
                                        )

