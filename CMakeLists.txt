cmake_minimum_required(VERSION 3.20)

project(T
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(T
    src/main.cpp
    src/lexer/lexer.cpp
    src/parser/parser.cpp
    src/compiler/compiler.cpp
    src/codegen/codegen.cpp
)

target_include_directories(T PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
