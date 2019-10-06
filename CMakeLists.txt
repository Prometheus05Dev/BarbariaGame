cmake_minimum_required(VERSION 3.15)
project(BarbariaCLion)

set(CMAKE_CXX_STANDARD 17)
add_compile_options("-lGL -lGLEW -lglfw -ldl")
link_libraries("-lGL -lGLEW -lglfw -ldl")
add_executable(BarbariaCLion main.cpp api/python/python.cpp api/python/python.h api/java/java.cpp api/java/java.h api/lua/lua.cpp api/lua/lua.h)
