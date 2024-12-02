cmake_minimum_required(VERSION 3.12)
project(spaceInvaders C)

set(CMAKE_C_STANDARD 11)

add_executable(spaceInvaders main.c menu.c)

find_package(SDL2 REQUIRED)

target_include_directories(spaceInvaders PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(spaceInvaders SDL2 SDL2_image SDL2_ttf)