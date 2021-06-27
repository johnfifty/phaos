cmake_minimum_required(VERSION 3.14)
project(phaos LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(stb_image INTERFACE)
target_include_directories(stb_image SYSTEM INTERFACE third_party/stb_image)

add_executable(phaos
  src/main.cpp
)

target_include_directories(phaos PRIVATE src)
target_link_libraries(phaos stb_image)
target_compile_options(phaos PRIVATE -Weverything -Werror -std=c++20
    -Wno-c++98-compat
)
