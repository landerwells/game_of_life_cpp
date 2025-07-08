cmake_minimum_required(VERSION 3.31.6)
project(cpp_template_build)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

add_compile_options(-Wall -Wextra -pedantic)

add_executable(main main.cpp game_of_life.cpp)
