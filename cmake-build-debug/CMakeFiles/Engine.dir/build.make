# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tntrol/CLionProjects/Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tntrol/CLionProjects/Engine/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Engine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Engine.dir/flags.make

CMakeFiles/Engine.dir/main.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tntrol/CLionProjects/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Engine.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/main.cpp.o -c /home/tntrol/CLionProjects/Engine/main.cpp

CMakeFiles/Engine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tntrol/CLionProjects/Engine/main.cpp > CMakeFiles/Engine.dir/main.cpp.i

CMakeFiles/Engine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tntrol/CLionProjects/Engine/main.cpp -o CMakeFiles/Engine.dir/main.cpp.s

CMakeFiles/Engine.dir/ecs_core/entity_manager.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/ecs_core/entity_manager.cpp.o: ../ecs_core/entity_manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tntrol/CLionProjects/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Engine.dir/ecs_core/entity_manager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/ecs_core/entity_manager.cpp.o -c /home/tntrol/CLionProjects/Engine/ecs_core/entity_manager.cpp

CMakeFiles/Engine.dir/ecs_core/entity_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/ecs_core/entity_manager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tntrol/CLionProjects/Engine/ecs_core/entity_manager.cpp > CMakeFiles/Engine.dir/ecs_core/entity_manager.cpp.i

CMakeFiles/Engine.dir/ecs_core/entity_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/ecs_core/entity_manager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tntrol/CLionProjects/Engine/ecs_core/entity_manager.cpp -o CMakeFiles/Engine.dir/ecs_core/entity_manager.cpp.s

CMakeFiles/Engine.dir/ecs_core/component_manager.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/ecs_core/component_manager.cpp.o: ../ecs_core/component_manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tntrol/CLionProjects/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Engine.dir/ecs_core/component_manager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/ecs_core/component_manager.cpp.o -c /home/tntrol/CLionProjects/Engine/ecs_core/component_manager.cpp

CMakeFiles/Engine.dir/ecs_core/component_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/ecs_core/component_manager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tntrol/CLionProjects/Engine/ecs_core/component_manager.cpp > CMakeFiles/Engine.dir/ecs_core/component_manager.cpp.i

CMakeFiles/Engine.dir/ecs_core/component_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/ecs_core/component_manager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tntrol/CLionProjects/Engine/ecs_core/component_manager.cpp -o CMakeFiles/Engine.dir/ecs_core/component_manager.cpp.s

CMakeFiles/Engine.dir/support_class/impl/component_container.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/support_class/impl/component_container.cpp.o: ../support_class/impl/component_container.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tntrol/CLionProjects/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Engine.dir/support_class/impl/component_container.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/support_class/impl/component_container.cpp.o -c /home/tntrol/CLionProjects/Engine/support_class/impl/component_container.cpp

CMakeFiles/Engine.dir/support_class/impl/component_container.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/support_class/impl/component_container.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tntrol/CLionProjects/Engine/support_class/impl/component_container.cpp > CMakeFiles/Engine.dir/support_class/impl/component_container.cpp.i

CMakeFiles/Engine.dir/support_class/impl/component_container.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/support_class/impl/component_container.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tntrol/CLionProjects/Engine/support_class/impl/component_container.cpp -o CMakeFiles/Engine.dir/support_class/impl/component_container.cpp.s

CMakeFiles/Engine.dir/support_class/impl/entity_container.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/support_class/impl/entity_container.cpp.o: ../support_class/impl/entity_container.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tntrol/CLionProjects/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Engine.dir/support_class/impl/entity_container.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/support_class/impl/entity_container.cpp.o -c /home/tntrol/CLionProjects/Engine/support_class/impl/entity_container.cpp

CMakeFiles/Engine.dir/support_class/impl/entity_container.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/support_class/impl/entity_container.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tntrol/CLionProjects/Engine/support_class/impl/entity_container.cpp > CMakeFiles/Engine.dir/support_class/impl/entity_container.cpp.i

CMakeFiles/Engine.dir/support_class/impl/entity_container.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/support_class/impl/entity_container.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tntrol/CLionProjects/Engine/support_class/impl/entity_container.cpp -o CMakeFiles/Engine.dir/support_class/impl/entity_container.cpp.s

CMakeFiles/Engine.dir/support_class/iterator.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/support_class/iterator.cpp.o: ../support_class/iterator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tntrol/CLionProjects/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Engine.dir/support_class/iterator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/support_class/iterator.cpp.o -c /home/tntrol/CLionProjects/Engine/support_class/iterator.cpp

CMakeFiles/Engine.dir/support_class/iterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/support_class/iterator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tntrol/CLionProjects/Engine/support_class/iterator.cpp > CMakeFiles/Engine.dir/support_class/iterator.cpp.i

CMakeFiles/Engine.dir/support_class/iterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/support_class/iterator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tntrol/CLionProjects/Engine/support_class/iterator.cpp -o CMakeFiles/Engine.dir/support_class/iterator.cpp.s

CMakeFiles/Engine.dir/memory_manager/stack_allocator.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/memory_manager/stack_allocator.cpp.o: ../memory_manager/stack_allocator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tntrol/CLionProjects/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Engine.dir/memory_manager/stack_allocator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/memory_manager/stack_allocator.cpp.o -c /home/tntrol/CLionProjects/Engine/memory_manager/stack_allocator.cpp

CMakeFiles/Engine.dir/memory_manager/stack_allocator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/memory_manager/stack_allocator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tntrol/CLionProjects/Engine/memory_manager/stack_allocator.cpp > CMakeFiles/Engine.dir/memory_manager/stack_allocator.cpp.i

CMakeFiles/Engine.dir/memory_manager/stack_allocator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/memory_manager/stack_allocator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tntrol/CLionProjects/Engine/memory_manager/stack_allocator.cpp -o CMakeFiles/Engine.dir/memory_manager/stack_allocator.cpp.s

CMakeFiles/Engine.dir/memory_manager/linear_allocator.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/memory_manager/linear_allocator.cpp.o: ../memory_manager/linear_allocator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tntrol/CLionProjects/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Engine.dir/memory_manager/linear_allocator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/memory_manager/linear_allocator.cpp.o -c /home/tntrol/CLionProjects/Engine/memory_manager/linear_allocator.cpp

CMakeFiles/Engine.dir/memory_manager/linear_allocator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/memory_manager/linear_allocator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tntrol/CLionProjects/Engine/memory_manager/linear_allocator.cpp > CMakeFiles/Engine.dir/memory_manager/linear_allocator.cpp.i

CMakeFiles/Engine.dir/memory_manager/linear_allocator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/memory_manager/linear_allocator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tntrol/CLionProjects/Engine/memory_manager/linear_allocator.cpp -o CMakeFiles/Engine.dir/memory_manager/linear_allocator.cpp.s

# Object files for target Engine
Engine_OBJECTS = \
"CMakeFiles/Engine.dir/main.cpp.o" \
"CMakeFiles/Engine.dir/ecs_core/entity_manager.cpp.o" \
"CMakeFiles/Engine.dir/ecs_core/component_manager.cpp.o" \
"CMakeFiles/Engine.dir/support_class/impl/component_container.cpp.o" \
"CMakeFiles/Engine.dir/support_class/impl/entity_container.cpp.o" \
"CMakeFiles/Engine.dir/support_class/iterator.cpp.o" \
"CMakeFiles/Engine.dir/memory_manager/stack_allocator.cpp.o" \
"CMakeFiles/Engine.dir/memory_manager/linear_allocator.cpp.o"

# External object files for target Engine
Engine_EXTERNAL_OBJECTS =

Engine: CMakeFiles/Engine.dir/main.cpp.o
Engine: CMakeFiles/Engine.dir/ecs_core/entity_manager.cpp.o
Engine: CMakeFiles/Engine.dir/ecs_core/component_manager.cpp.o
Engine: CMakeFiles/Engine.dir/support_class/impl/component_container.cpp.o
Engine: CMakeFiles/Engine.dir/support_class/impl/entity_container.cpp.o
Engine: CMakeFiles/Engine.dir/support_class/iterator.cpp.o
Engine: CMakeFiles/Engine.dir/memory_manager/stack_allocator.cpp.o
Engine: CMakeFiles/Engine.dir/memory_manager/linear_allocator.cpp.o
Engine: CMakeFiles/Engine.dir/build.make
Engine: CMakeFiles/Engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tntrol/CLionProjects/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Engine.dir/build: Engine

.PHONY : CMakeFiles/Engine.dir/build

CMakeFiles/Engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Engine.dir/clean

CMakeFiles/Engine.dir/depend:
	cd /home/tntrol/CLionProjects/Engine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tntrol/CLionProjects/Engine /home/tntrol/CLionProjects/Engine /home/tntrol/CLionProjects/Engine/cmake-build-debug /home/tntrol/CLionProjects/Engine/cmake-build-debug /home/tntrol/CLionProjects/Engine/cmake-build-debug/CMakeFiles/Engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Engine.dir/depend

