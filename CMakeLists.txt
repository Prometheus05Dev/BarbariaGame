cmake_minimum_required(VERSION 3.15)
project(Barbaria)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
                    libraries/assimp-5.0.1/include/assimp)

set(ZLIB_LIBRARIES zlibstatic)
set(ENABLE_BOOST_WORKAROUND ON)
set(BUILD_STATIC_LIB ON)
set(BUILD_ASSIMP_TOOLS  ON)
set(ASSIMP_BUILD_STATIC_LIB ON)

add_subdirectory(libraries/assimp-5.0.1)

add_compile_options("-lGL -lGLEW -lglfw -ldl -lX11 -lpthread -lXrandr -lXi")
link_libraries("-lGL -lGLEW -lglfw -ldl -lX11 -lpthread -lXrandr -lXi")

add_executable(Barbaria main.cpp game/world/world.cpp game/world/generation/climate_zones.cpp game/world/generation/climate_zones.h game/world/world/chunk.cpp game/world/world/chunk.h api/loader.cpp api/loader.h engine/graphics/shader.cpp engine/graphics/shader.h game/blocks/block.cpp game/blocks/block.h game/entities/entity.cpp game/entities/entity.h game/windows/gamewindow.cpp game/windows/gamewindow.h game/windows/framebuffer.cpp game/windows/framebuffer.h game/input/keyboard.cpp game/input/keyboard.h game/input/mouse.cpp game/input/mouse.h engine/graphics/camera.cpp engine/graphics/camera.h game.cpp game.h engine/utils/time.cpp engine/utils/time.h engine/graphics/object.cpp engine/graphics/object.h engine/graphics/texture.cpp engine/graphics/texture.h
        game/world/factions/faction.cpp game/world/factions/lotr/southrons.cpp game/world/factions/lotr/corsairs.cpp game/world/factions/lotr/variags.cpp game/world/factions/lotr/mordor.cpp game/world/factions/lotr/gondorians.cpp game/world/factions/lotr/rohirrim.cpp game/world/factions/lotr/easterlings.cpp game/world/factions/lotr/dorwinions.cpp game/world/factions/lotr/dunlending.cpp game/world/factions/lotr/ents.cpp game/world/factions/lotr/huorns.cpp game/world/factions/lotr/lossoth.cpp game/world/factions/lotr/isengard.cpp game/world/factions/lotr/high_elves.cpp game/world/factions/lotr/wood_elves.cpp game/world/factions/lotr/dunedain_north.cpp game/world/factions/lotr/hobbits.cpp game/world/factions/lotr/barrow_wights.cpp game/world/factions/lotr/dwarves.cpp game/world/factions/lotr/gundabad.cpp game/world/factions/lotr/moria_orcs.cpp game/world/factions/lotr/dol_guldur.cpp)
target_link_libraries(Barbaria assimp)