cmake_minimum_required(VERSION 3.11)
project(MarketManager)

file(GLOB_RECURSE SOURCES
    src/**/*.cpp
    main.cpp
)

add_executable(main ${SOURCES})