cmake_minimum_required(VERSION 3.5)
project(s21_Viewer)

# for debug gtest in qt
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgcov --coverage")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options("-Wall" "-Wextra" "-Wpedantic" )
else()
    message("WE NEED GCC FOR CODE COVERAGE AND COMPILE OPTIONS REQUIRED BY SCHOOL")
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/modules)

#SETTINGS
cmake_path(APPEND SETTINGS_PATH "${CMAKE_BINARY_DIR}" "settings.conf")
#OBJ FILES FOR TESTS (NOT BE AVAILABLE AFTER SOURCE DELETING)
cmake_path(APPEND OBJECTS_PATH "${CMAKE_SOURCE_DIR}" "Model" "test")
configure_file(settings_path.h.in settings_path.h @ONLY)

add_subdirectory(View)
add_subdirectory(Controller)
add_subdirectory(Model)
add_subdirectory(dependencies)
include_directories(View)

# ---- DOCUMENTION GENERATION ----
find_package(Doxygen)
if (Doxygen_FOUND)
    set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C YES)
    set(DOXYGEN_EXTRACT_STATIC YES)
    set(DOXYGEN_EXTRACT_PRIVATE YES)
    set(DOXYGEN_EXCLUDE "buildRelease" "build" "dependencies")
    doxygen_add_docs(generate_docs)
endif()

# ---- CPACK FOR DIST ----
SET(CPACK_SOURCE_GENERATOR "TGZ")
SET(CPACK_SOURCE_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}")
SET(CPACK_SOURCE_IGNORE_FILES 
    "/build/;/buildDebug/;/buildRelease/;${CPACK_SOURCE_IGNORE_FILES}")
include(CPack)

add_executable(s21_Viewer main.cpp)

# ---- TEST COMPILATION ----
cmake_path(APPEND OBJECTS_PATH "${CMAKE_SOURCE_DIR}" "Model" "test")

# ---- FORMATTING ----
set(CLANG_FORMAT_EXCLUDE_PATTERNS  "build/" "dependencies/" ${CMAKE_BINARY_DIR})
find_package(ClangFormat)

target_link_libraries(${PROJECT_NAME} PUBLIC View)
