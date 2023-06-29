cmake_minimum_required(VERSION 3.12)

# Set c++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# languages
project(Lux LANGUAGES CXX)

# Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

# 子项目（顺序无关紧要）
add_subdirectory(Base)
add_subdirectory(MySQL)
add_subdirectory(Redis)



