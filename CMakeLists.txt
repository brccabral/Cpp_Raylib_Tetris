cmake_minimum_required(VERSION 3.28)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib 2.0 REQUIRED)

add_executable(${PROJECT_NAME} main.cpp
        ball.cpp
        ball.h)
target_link_libraries(${PROJECT_NAME} raylib)

set(resources_list)
file(GLOB resources_files resources/*)
list(APPEND resources_list ${resources_files})
file(COPY ${resources_files} DESTINATION "resources/")
