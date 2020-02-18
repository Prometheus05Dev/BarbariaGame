cmake_minimum_required(VERSION 3.15)
project(Barbaria)

set(CMAKE_CXX_STANDARD 17)


add_compile_options("-lGL -lGLEW -lglfw -ldl -lX11 -lpthread -lXrandr -lXi")
link_libraries("-lGL -lGLEW -lglfw -ldl -lX11 -lpthread -lXrandr -lXi")

add_executable(Barbaria main.cpp game/world/world.cpp game/world/generation/climate_zones.cpp game/world/generation/climate_zones.h game/world/world/chunk.cpp game/world/world/chunk.h api/loader.cpp api/loader.h engine/graphics/shader.cpp engine/graphics/shader.h engine/graphics/object.cpp engine/graphics/object.h game/blocks/block.cpp game/blocks/block.h game/entities/entity.cpp game/entities/entity.h game/windows/gamewindow.cpp game/windows/gamewindow.h game/windows/framebuffer.cpp game/windows/framebuffer.h game/input/keyboard.cpp game/input/keyboard.h game/input/mouse.cpp game/input/mouse.h engine/graphics/camera.cpp engine/graphics/camera.h game.cpp game.h engine/utils/time.cpp engine/utils/time.h)