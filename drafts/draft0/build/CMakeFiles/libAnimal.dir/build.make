# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/benson/cpp_ws/drafts/draft0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/benson/cpp_ws/drafts/draft0/build

# Include any dependencies generated for this target.
include CMakeFiles/libAnimal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libAnimal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libAnimal.dir/flags.make

CMakeFiles/libAnimal.dir/Animal.cpp.o: CMakeFiles/libAnimal.dir/flags.make
CMakeFiles/libAnimal.dir/Animal.cpp.o: ../Animal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/benson/cpp_ws/drafts/draft0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libAnimal.dir/Animal.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libAnimal.dir/Animal.cpp.o -c /home/benson/cpp_ws/drafts/draft0/Animal.cpp

CMakeFiles/libAnimal.dir/Animal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libAnimal.dir/Animal.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/benson/cpp_ws/drafts/draft0/Animal.cpp > CMakeFiles/libAnimal.dir/Animal.cpp.i

CMakeFiles/libAnimal.dir/Animal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libAnimal.dir/Animal.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/benson/cpp_ws/drafts/draft0/Animal.cpp -o CMakeFiles/libAnimal.dir/Animal.cpp.s

# Object files for target libAnimal
libAnimal_OBJECTS = \
"CMakeFiles/libAnimal.dir/Animal.cpp.o"

# External object files for target libAnimal
libAnimal_EXTERNAL_OBJECTS =

liblibAnimal.a: CMakeFiles/libAnimal.dir/Animal.cpp.o
liblibAnimal.a: CMakeFiles/libAnimal.dir/build.make
liblibAnimal.a: CMakeFiles/libAnimal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/benson/cpp_ws/drafts/draft0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblibAnimal.a"
	$(CMAKE_COMMAND) -P CMakeFiles/libAnimal.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libAnimal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libAnimal.dir/build: liblibAnimal.a

.PHONY : CMakeFiles/libAnimal.dir/build

CMakeFiles/libAnimal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libAnimal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libAnimal.dir/clean

CMakeFiles/libAnimal.dir/depend:
	cd /home/benson/cpp_ws/drafts/draft0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/benson/cpp_ws/drafts/draft0 /home/benson/cpp_ws/drafts/draft0 /home/benson/cpp_ws/drafts/draft0/build /home/benson/cpp_ws/drafts/draft0/build /home/benson/cpp_ws/drafts/draft0/build/CMakeFiles/libAnimal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libAnimal.dir/depend

