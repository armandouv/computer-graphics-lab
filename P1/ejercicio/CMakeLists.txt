cmake_minimum_required(VERSION 3.23)
project(P1)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_executable(P1 main.cpp Shader.h)

target_link_libraries(P1 glfw OpenGL::GL GLEW::GLEW)
