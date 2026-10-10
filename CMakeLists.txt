cmake_minimum_required(VERSION 3.20)
project(SecondFish CXX C)

set(CMAKE_CXX_STANDARD 20)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

# Change glad.c to gl.c here:
add_library(glad 3rdparty/glad/src/glad.c)
target_include_directories(glad PUBLIC 3rdparty/glad/include)

add_executable(SecondFish main.cpp)
target_link_libraries(SecondFish PRIVATE
        glfw
        glad
        OpenGL::GL
)