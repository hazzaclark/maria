## COPYRIGHT (C) HARRY CLARK 2025
## LIGHTWEIGHT CODE EMITTER/GENERATOR FOR THE HTACHI SUPERH2

cmake_minimum_required(VERSION 3.20)

project(maria)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(maria
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cc"
)

target_include_directories(maria PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_compile_options(maria PRIVATE
    -Wall
    -Wextra
    -Wno-unused-parameter
)