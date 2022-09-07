cmake_minimum_required(VERSION 3.23)
project(P2)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)

add_executable(P2 main.cpp Shader.h)

target_link_libraries(P2 glfw OpenGL::GL GLEW::GLEW glm::glm)
