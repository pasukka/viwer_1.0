cmake_minimum_required(VERSION 3.5)
set(LIB_NAME "View")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS form)

add_compile_options(-Wno-deprecated-declarations)

include_directories(form)
include_directories(include)
include_directories(source)

include_directories(${PROJECT_SOURCE_DIR}/Controller)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

configure_file(../settings_path.h.in settings_path.h @ONLY)

file(GLOB SRC_FILES
        ${PROJECT_SOURCE_DIR}/${LIB_NAME}/form/*.ui
        ${PROJECT_SOURCE_DIR}/${LIB_NAME}/include/*.h
        ${PROJECT_SOURCE_DIR}/${LIB_NAME}/source/*.cpp
    )
add_library(${LIB_NAME} ${SRC_FILES})
target_include_directories(${LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/${LIB_NAME}/include)

target_link_libraries(${LIB_NAME} PUBLIC Controller)
target_link_libraries(${LIB_NAME} PUBLIC Qt${QT_VERSION_MAJOR}::Widgets)

include_directories(${PROJECT_SOURCE_DIR}/dependencies)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGLWidgets OpenGL)
    target_link_libraries(${LIB_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::OpenGLWidgets Qt${QT_VERSION_MAJOR}::OpenGL giflib)
endif()

target_include_directories(${LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/dependencies/gifimage ${PROJECT_SOURCE_DIR}/dependencies/giflib)
target_link_libraries(${LIB_NAME} PUBLIC giflib)
