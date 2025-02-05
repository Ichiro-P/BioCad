cmake_minimum_required(VERSION 3.10)
project(BioCad LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Lista de arquivos fonte
file(GLOB SOURCES CONFIGURE_DEPENDS
    "src/*.cpp"
)

# Executável principal
add_executable(BioCad ${SOURCES})

# Diretórios de include
target_include_directories(BioCad PRIVATE include)