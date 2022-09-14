cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(hello VERSION 1.0)

file (GLOB_RECURSE sudoku_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file (GLOB_RECURSE sudoku_HEADERS CONFIGURE_DEPENDS "src/*.h")

set (sudoku_INCLUDE_DIRS "")
foreach (_headerFile ${sudoku_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND sudoku_INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES sudoku_INCLUDE_DIRS)

add_executable(sudoku.exe ${sudoku_SOURCES})
target_include_directories(sudoku.exe PRIVATE ${sudoku_INCLUDE_DIRS})
