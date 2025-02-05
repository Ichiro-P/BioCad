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

# --- Configuração da cópia de recursos ---
set(RESOURCES_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/dados")
set(RESOURCES_TARGET "$<TARGET_FILE_DIR:BioCad>/dados")

# Comando para copiar recursivamente o diretório 'dados'
add_custom_command(
    TARGET BioCad POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "${RESOURCES_TARGET}"
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${RESOURCES_SOURCE}"
        "${RESOURCES_TARGET}"
    COMMENT "Copiando recursos para: ${RESOURCES_TARGET}"
)