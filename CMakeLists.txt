cmake_minimum_required(VERSION 3.19)

project(secret-santa LANGUAGES CXX VERSION 1.0.1)

add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
