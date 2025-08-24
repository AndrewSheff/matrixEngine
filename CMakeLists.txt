cmake_minimum_required(VERSION 3.10)
project(Game)

set(CMAKE_C_STANDARD 17)
include_directories("${CMAKE_SOURCE_DIR}/include")

if(MSVC)
    add_compile_options(/W4 /Zi /Iinclude)
else()
    add_compile_options(-Wall -Wextra -g -Iinclude)
endif()

set(SRC_FILES
    src/main.c
    src/screen.c
    src/entity.c
    src/object.c
    src/scene.c
 "include/terminal.h")

add_executable(game ${SRC_FILES}   "src/message.c" "include/message.h")