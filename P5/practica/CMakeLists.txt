cmake_minimum_required(VERSION 3.23)
project(P5)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)

find_library(soil2_location NAMES libsoil2)
message(STATUS ${soil2_location})
add_library(SOIL2 STATIC IMPORTED)
set_target_properties(SOIL2 PROPERTIES IMPORTED_LOCATION /usr/local/lib/libsoil2-debug.a)
# target_include_directories(SOIL2 INTERFACE /usr/local/include/)
include_directories(/usr/include/stb)

find_library(assimp_location NAMES assimp)
message(STATUS ${assimp_location})
add_library(ASSIMP SHARED IMPORTED)
set_target_properties(ASSIMP PROPERTIES IMPORTED_LOCATION ${assimp_location})

add_executable(P5 Main_P5.cpp Shader.h Camera.h Mesh.h Model.h)

target_link_libraries(P5 glfw ASSIMP SOIL2 OpenGL::GL GLEW::GLEW glm::glm)
