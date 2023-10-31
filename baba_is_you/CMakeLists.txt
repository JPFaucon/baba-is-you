cmake_minimum_required(VERSION 3.5)

project(baba_is_you VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-std=c++20 -pedantic-errors -Wall -Wuninitialized")

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
qt_add_resources(RCC_SOURCES resources.qrc)

set(PROJECT_SOURCES
        widget.h widget.cpp widget.ui

        main.cpp

        controller.h
        controller.cpp
        view.h
        view.cpp
        gtile.h
        gtile.cpp

        model/enums.h
        model/board.h model/board.cpp
        model/component.h model/component.cpp
        model/game.h model/game.cpp
        model/material.h model/material.cpp
        model/rule.h model/rule.cpp
        model/text.h model/text.cpp
        model/tile.h model/tile.cpp
        model/direction.h
        model/position.h model/position.cpp

        observer/observer.h
        observer/subject.h observer/subject.cpp

        utils/levelreader.h utils/levelreader.cpp
        utils/savedlevelreader.h utils/savedlevelreader.cpp
        utils/enumsutility.h utils/enumsutility.cpp
        utils/directionutility.h utils/directionutility.cpp

        tests/tests.h tests/tests.cpp

        ${RCC_SOURCES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(baba_is_you
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET baba_is_you APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(baba_is_you SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(baba_is_you
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(baba_is_you PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(baba_is_you PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(baba_is_you)
endif()
