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
CMAKE_SOURCE_DIR = /home/benson/cpp_ws/drafts/class_/base_

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/benson/cpp_ws/drafts/class_/base_/build

# Include any dependencies generated for this target.
include CMakeFiles/salesdata.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/salesdata.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/salesdata.dir/flags.make

CMakeFiles/salesdata.dir/Sales_data.cpp.o: CMakeFiles/salesdata.dir/flags.make
CMakeFiles/salesdata.dir/Sales_data.cpp.o: ../Sales_data.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/benson/cpp_ws/drafts/class_/base_/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/salesdata.dir/Sales_data.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/salesdata.dir/Sales_data.cpp.o -c /home/benson/cpp_ws/drafts/class_/base_/Sales_data.cpp

CMakeFiles/salesdata.dir/Sales_data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/salesdata.dir/Sales_data.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/benson/cpp_ws/drafts/class_/base_/Sales_data.cpp > CMakeFiles/salesdata.dir/Sales_data.cpp.i

CMakeFiles/salesdata.dir/Sales_data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/salesdata.dir/Sales_data.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/benson/cpp_ws/drafts/class_/base_/Sales_data.cpp -o CMakeFiles/salesdata.dir/Sales_data.cpp.s

# Object files for target salesdata
salesdata_OBJECTS = \
"CMakeFiles/salesdata.dir/Sales_data.cpp.o"

# External object files for target salesdata
salesdata_EXTERNAL_OBJECTS =

libsalesdata.a: CMakeFiles/salesdata.dir/Sales_data.cpp.o
libsalesdata.a: CMakeFiles/salesdata.dir/build.make
libsalesdata.a: CMakeFiles/salesdata.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/benson/cpp_ws/drafts/class_/base_/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libsalesdata.a"
	$(CMAKE_COMMAND) -P CMakeFiles/salesdata.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/salesdata.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/salesdata.dir/build: libsalesdata.a

.PHONY : CMakeFiles/salesdata.dir/build

CMakeFiles/salesdata.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/salesdata.dir/cmake_clean.cmake
.PHONY : CMakeFiles/salesdata.dir/clean

CMakeFiles/salesdata.dir/depend:
	cd /home/benson/cpp_ws/drafts/class_/base_/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/benson/cpp_ws/drafts/class_/base_ /home/benson/cpp_ws/drafts/class_/base_ /home/benson/cpp_ws/drafts/class_/base_/build /home/benson/cpp_ws/drafts/class_/base_/build /home/benson/cpp_ws/drafts/class_/base_/build/CMakeFiles/salesdata.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/salesdata.dir/depend

