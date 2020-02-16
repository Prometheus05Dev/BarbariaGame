cmake_minimum_required(VERSION 3.15)
project(Barbaria)

set(CMAKE_CXX_STANDARD 17)


add_compile_options("-lGL -lGLEW -lglfw -ldl -lX11 -lpthread -lXrandr -lXi")
link_libraries("-lGL -lGLEW -lglfw -ldl -lX11 -lpthread -lXrandr -lXi")

add_executable(Barbaria main.cpp game/world/world.cpp game/world/generation/climate_zones.cpp game/world/generation/climate_zones.h game/world/world/chunk.cpp game/world/world/chunk.h game/world/world/block.cpp game/world/world/block.h api/loader.cpp api/loader.h engine/graphics/object.cpp engine/graphics/object.h engine/graphics/shader.cpp engine/graphics/shader.h)