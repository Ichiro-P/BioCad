cmake_minimum_required(VERSION 3.10)
project(BioCad LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES CONFIGURE_DEPENDS
    "src/*.cpp"
)

add_executable(BioCad ${SOURCES})


target_include_directories(BioCad PRIVATE include)