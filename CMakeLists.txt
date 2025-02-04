cmake_minimum_required(VERSION 3.10)
project(BioCad LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(BioCad
    src/main.cpp
    src/atendente.cpp
)

set(RESOURCES_DIR ${CMAKE_SOURCE_DIR}/dados)

add_custom_command(
    TARGET BioCad POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${RESOURCES_DIR} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dados
)

target_include_directories(BioCad PRIVATE ${CMAKE_SOURCE_DIR}/include)