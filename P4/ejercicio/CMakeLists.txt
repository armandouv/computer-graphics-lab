cmake_minimum_required(VERSION 3.23)
project(P4)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)

add_executable(P4 Main_P4.cpp Shader.h)

target_link_libraries(P4 glfw OpenGL::GL GLEW::GLEW glm::glm)
