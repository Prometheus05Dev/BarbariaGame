# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/janek/Downloads/clion-2019.3.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/janek/Downloads/clion-2019.3.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/janek/CLionProjects/Barbaria

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/janek/CLionProjects/Barbaria/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Barbaria.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Barbaria.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Barbaria.dir/flags.make

CMakeFiles/Barbaria.dir/main.cpp.o: CMakeFiles/Barbaria.dir/flags.make
CMakeFiles/Barbaria.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/janek/CLionProjects/Barbaria/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Barbaria.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Barbaria.dir/main.cpp.o -c /home/janek/CLionProjects/Barbaria/main.cpp

CMakeFiles/Barbaria.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Barbaria.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/janek/CLionProjects/Barbaria/main.cpp > CMakeFiles/Barbaria.dir/main.cpp.i

CMakeFiles/Barbaria.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Barbaria.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/janek/CLionProjects/Barbaria/main.cpp -o CMakeFiles/Barbaria.dir/main.cpp.s

CMakeFiles/Barbaria.dir/game/world/world.cpp.o: CMakeFiles/Barbaria.dir/flags.make
CMakeFiles/Barbaria.dir/game/world/world.cpp.o: ../game/world/world.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/janek/CLionProjects/Barbaria/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Barbaria.dir/game/world/world.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Barbaria.dir/game/world/world.cpp.o -c /home/janek/CLionProjects/Barbaria/game/world/world.cpp

CMakeFiles/Barbaria.dir/game/world/world.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Barbaria.dir/game/world/world.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/janek/CLionProjects/Barbaria/game/world/world.cpp > CMakeFiles/Barbaria.dir/game/world/world.cpp.i

CMakeFiles/Barbaria.dir/game/world/world.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Barbaria.dir/game/world/world.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/janek/CLionProjects/Barbaria/game/world/world.cpp -o CMakeFiles/Barbaria.dir/game/world/world.cpp.s

CMakeFiles/Barbaria.dir/game/world/generation/climate_zones.cpp.o: CMakeFiles/Barbaria.dir/flags.make
CMakeFiles/Barbaria.dir/game/world/generation/climate_zones.cpp.o: ../game/world/generation/climate_zones.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/janek/CLionProjects/Barbaria/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Barbaria.dir/game/world/generation/climate_zones.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Barbaria.dir/game/world/generation/climate_zones.cpp.o -c /home/janek/CLionProjects/Barbaria/game/world/generation/climate_zones.cpp

CMakeFiles/Barbaria.dir/game/world/generation/climate_zones.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Barbaria.dir/game/world/generation/climate_zones.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/janek/CLionProjects/Barbaria/game/world/generation/climate_zones.cpp > CMakeFiles/Barbaria.dir/game/world/generation/climate_zones.cpp.i

CMakeFiles/Barbaria.dir/game/world/generation/climate_zones.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Barbaria.dir/game/world/generation/climate_zones.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/janek/CLionProjects/Barbaria/game/world/generation/climate_zones.cpp -o CMakeFiles/Barbaria.dir/game/world/generation/climate_zones.cpp.s

CMakeFiles/Barbaria.dir/game/world/world/chunk.cpp.o: CMakeFiles/Barbaria.dir/flags.make
CMakeFiles/Barbaria.dir/game/world/world/chunk.cpp.o: ../game/world/world/chunk.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/janek/CLionProjects/Barbaria/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Barbaria.dir/game/world/world/chunk.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Barbaria.dir/game/world/world/chunk.cpp.o -c /home/janek/CLionProjects/Barbaria/game/world/world/chunk.cpp

CMakeFiles/Barbaria.dir/game/world/world/chunk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Barbaria.dir/game/world/world/chunk.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/janek/CLionProjects/Barbaria/game/world/world/chunk.cpp > CMakeFiles/Barbaria.dir/game/world/world/chunk.cpp.i

CMakeFiles/Barbaria.dir/game/world/world/chunk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Barbaria.dir/game/world/world/chunk.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/janek/CLionProjects/Barbaria/game/world/world/chunk.cpp -o CMakeFiles/Barbaria.dir/game/world/world/chunk.cpp.s

CMakeFiles/Barbaria.dir/game/world/world/block.cpp.o: CMakeFiles/Barbaria.dir/flags.make
CMakeFiles/Barbaria.dir/game/world/world/block.cpp.o: ../game/world/world/block.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/janek/CLionProjects/Barbaria/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Barbaria.dir/game/world/world/block.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Barbaria.dir/game/world/world/block.cpp.o -c /home/janek/CLionProjects/Barbaria/game/world/world/block.cpp

CMakeFiles/Barbaria.dir/game/world/world/block.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Barbaria.dir/game/world/world/block.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/janek/CLionProjects/Barbaria/game/world/world/block.cpp > CMakeFiles/Barbaria.dir/game/world/world/block.cpp.i

CMakeFiles/Barbaria.dir/game/world/world/block.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Barbaria.dir/game/world/world/block.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/janek/CLionProjects/Barbaria/game/world/world/block.cpp -o CMakeFiles/Barbaria.dir/game/world/world/block.cpp.s

CMakeFiles/Barbaria.dir/api/loader.cpp.o: CMakeFiles/Barbaria.dir/flags.make
CMakeFiles/Barbaria.dir/api/loader.cpp.o: ../api/loader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/janek/CLionProjects/Barbaria/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Barbaria.dir/api/loader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Barbaria.dir/api/loader.cpp.o -c /home/janek/CLionProjects/Barbaria/api/loader.cpp

CMakeFiles/Barbaria.dir/api/loader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Barbaria.dir/api/loader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/janek/CLionProjects/Barbaria/api/loader.cpp > CMakeFiles/Barbaria.dir/api/loader.cpp.i

CMakeFiles/Barbaria.dir/api/loader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Barbaria.dir/api/loader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/janek/CLionProjects/Barbaria/api/loader.cpp -o CMakeFiles/Barbaria.dir/api/loader.cpp.s

CMakeFiles/Barbaria.dir/engine/graphics/object.cpp.o: CMakeFiles/Barbaria.dir/flags.make
CMakeFiles/Barbaria.dir/engine/graphics/object.cpp.o: ../engine/graphics/object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/janek/CLionProjects/Barbaria/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Barbaria.dir/engine/graphics/object.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Barbaria.dir/engine/graphics/object.cpp.o -c /home/janek/CLionProjects/Barbaria/engine/graphics/object.cpp

CMakeFiles/Barbaria.dir/engine/graphics/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Barbaria.dir/engine/graphics/object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/janek/CLionProjects/Barbaria/engine/graphics/object.cpp > CMakeFiles/Barbaria.dir/engine/graphics/object.cpp.i

CMakeFiles/Barbaria.dir/engine/graphics/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Barbaria.dir/engine/graphics/object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/janek/CLionProjects/Barbaria/engine/graphics/object.cpp -o CMakeFiles/Barbaria.dir/engine/graphics/object.cpp.s

CMakeFiles/Barbaria.dir/engine/graphics/shader.cpp.o: CMakeFiles/Barbaria.dir/flags.make
CMakeFiles/Barbaria.dir/engine/graphics/shader.cpp.o: ../engine/graphics/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/janek/CLionProjects/Barbaria/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Barbaria.dir/engine/graphics/shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Barbaria.dir/engine/graphics/shader.cpp.o -c /home/janek/CLionProjects/Barbaria/engine/graphics/shader.cpp

CMakeFiles/Barbaria.dir/engine/graphics/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Barbaria.dir/engine/graphics/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/janek/CLionProjects/Barbaria/engine/graphics/shader.cpp > CMakeFiles/Barbaria.dir/engine/graphics/shader.cpp.i

CMakeFiles/Barbaria.dir/engine/graphics/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Barbaria.dir/engine/graphics/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/janek/CLionProjects/Barbaria/engine/graphics/shader.cpp -o CMakeFiles/Barbaria.dir/engine/graphics/shader.cpp.s

# Object files for target Barbaria
Barbaria_OBJECTS = \
"CMakeFiles/Barbaria.dir/main.cpp.o" \
"CMakeFiles/Barbaria.dir/game/world/world.cpp.o" \
"CMakeFiles/Barbaria.dir/game/world/generation/climate_zones.cpp.o" \
"CMakeFiles/Barbaria.dir/game/world/world/chunk.cpp.o" \
"CMakeFiles/Barbaria.dir/game/world/world/block.cpp.o" \
"CMakeFiles/Barbaria.dir/api/loader.cpp.o" \
"CMakeFiles/Barbaria.dir/engine/graphics/object.cpp.o" \
"CMakeFiles/Barbaria.dir/engine/graphics/shader.cpp.o"

# External object files for target Barbaria
Barbaria_EXTERNAL_OBJECTS =

Barbaria: CMakeFiles/Barbaria.dir/main.cpp.o
Barbaria: CMakeFiles/Barbaria.dir/game/world/world.cpp.o
Barbaria: CMakeFiles/Barbaria.dir/game/world/generation/climate_zones.cpp.o
Barbaria: CMakeFiles/Barbaria.dir/game/world/world/chunk.cpp.o
Barbaria: CMakeFiles/Barbaria.dir/game/world/world/block.cpp.o
Barbaria: CMakeFiles/Barbaria.dir/api/loader.cpp.o
Barbaria: CMakeFiles/Barbaria.dir/engine/graphics/object.cpp.o
Barbaria: CMakeFiles/Barbaria.dir/engine/graphics/shader.cpp.o
Barbaria: CMakeFiles/Barbaria.dir/build.make
Barbaria: CMakeFiles/Barbaria.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/janek/CLionProjects/Barbaria/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Barbaria"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Barbaria.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Barbaria.dir/build: Barbaria

.PHONY : CMakeFiles/Barbaria.dir/build

CMakeFiles/Barbaria.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Barbaria.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Barbaria.dir/clean

CMakeFiles/Barbaria.dir/depend:
	cd /home/janek/CLionProjects/Barbaria/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/janek/CLionProjects/Barbaria /home/janek/CLionProjects/Barbaria /home/janek/CLionProjects/Barbaria/cmake-build-debug /home/janek/CLionProjects/Barbaria/cmake-build-debug /home/janek/CLionProjects/Barbaria/cmake-build-debug/CMakeFiles/Barbaria.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Barbaria.dir/depend
