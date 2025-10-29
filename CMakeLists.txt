cmake_minimum_required(VERSION 3.11)
project(MarketManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE SOURCES
        src/*.cpp
        src/data/*.cpp
        src/models/*.cpp
        src/services/*.cpp
        src/Validator/*.cpp
        main.cpp
)

add_executable(main ${SOURCES})
