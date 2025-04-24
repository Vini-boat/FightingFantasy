cmake_minimum_required(VERSION 3.10)
project(FightingFantasy)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SRC_FILES
        ${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_executable(FightingFantasy ${SRC_FILES})
