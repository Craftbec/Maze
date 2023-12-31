cmake_minimum_required(VERSION 3.5)

project(Maze VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets OpenGLWidgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGLWidgets)

set(PROJECT_SOURCES
        ./project/main.cc
        ./project/view/mainwindow.cc
        ./project/view/mainwindow.h
        ./project/view/glwidget_maze.h
        ./project/view/glwidget_maze.cc
        ./project/view/mainwindow.ui
        ./project/model/maze.cc
        ./project/model/state_maze.cc
        ./project/model/state_cave.cc
        ./project/model/trasformation_points.cc
        ./project/model/solution.cc
        ./project/model/cave.cc
        ./project/view/glwidget_cave.h
        ./project/view/glwidget_cave.cc
        ./project/view/window_cave.h
        ./project/view/window_cave.cc
        ./project/view/window_cave.ui
        ./project/controller/controller_maze.cc
        ./project/controller/controller_cave.cc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Maze
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Maze APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Maze SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Maze
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Maze PRIVATE Qt${QT_VERSION_MAJOR}::Widgets PRIVATE Qt${QT_VERSION_MAJOR}::OpenGLWidgets)

set_target_properties(Maze PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Maze)
endif()
