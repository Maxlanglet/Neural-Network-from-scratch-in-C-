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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.19.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.19.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/langletmaxime/Desktop/NN_C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/langletmaxime/Desktop/NN_C++

# Include any dependencies generated for this target.
include Image_Reader/CMakeFiles/Path_Loader.dir/depend.make

# Include the progress variables for this target.
include Image_Reader/CMakeFiles/Path_Loader.dir/progress.make

# Include the compile flags for this target's objects.
include Image_Reader/CMakeFiles/Path_Loader.dir/flags.make

Image_Reader/CMakeFiles/Path_Loader.dir/Path_Loader.cpp.o: Image_Reader/CMakeFiles/Path_Loader.dir/flags.make
Image_Reader/CMakeFiles/Path_Loader.dir/Path_Loader.cpp.o: Image_Reader/Path_Loader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/langletmaxime/Desktop/NN_C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Image_Reader/CMakeFiles/Path_Loader.dir/Path_Loader.cpp.o"
	cd /Users/langletmaxime/Desktop/NN_C++/Image_Reader && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Path_Loader.dir/Path_Loader.cpp.o -c /Users/langletmaxime/Desktop/NN_C++/Image_Reader/Path_Loader.cpp

Image_Reader/CMakeFiles/Path_Loader.dir/Path_Loader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Path_Loader.dir/Path_Loader.cpp.i"
	cd /Users/langletmaxime/Desktop/NN_C++/Image_Reader && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/langletmaxime/Desktop/NN_C++/Image_Reader/Path_Loader.cpp > CMakeFiles/Path_Loader.dir/Path_Loader.cpp.i

Image_Reader/CMakeFiles/Path_Loader.dir/Path_Loader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Path_Loader.dir/Path_Loader.cpp.s"
	cd /Users/langletmaxime/Desktop/NN_C++/Image_Reader && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/langletmaxime/Desktop/NN_C++/Image_Reader/Path_Loader.cpp -o CMakeFiles/Path_Loader.dir/Path_Loader.cpp.s

# Object files for target Path_Loader
Path_Loader_OBJECTS = \
"CMakeFiles/Path_Loader.dir/Path_Loader.cpp.o"

# External object files for target Path_Loader
Path_Loader_EXTERNAL_OBJECTS =

Image_Reader/libPath_Loader.a: Image_Reader/CMakeFiles/Path_Loader.dir/Path_Loader.cpp.o
Image_Reader/libPath_Loader.a: Image_Reader/CMakeFiles/Path_Loader.dir/build.make
Image_Reader/libPath_Loader.a: Image_Reader/CMakeFiles/Path_Loader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/langletmaxime/Desktop/NN_C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libPath_Loader.a"
	cd /Users/langletmaxime/Desktop/NN_C++/Image_Reader && $(CMAKE_COMMAND) -P CMakeFiles/Path_Loader.dir/cmake_clean_target.cmake
	cd /Users/langletmaxime/Desktop/NN_C++/Image_Reader && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Path_Loader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Image_Reader/CMakeFiles/Path_Loader.dir/build: Image_Reader/libPath_Loader.a

.PHONY : Image_Reader/CMakeFiles/Path_Loader.dir/build

Image_Reader/CMakeFiles/Path_Loader.dir/clean:
	cd /Users/langletmaxime/Desktop/NN_C++/Image_Reader && $(CMAKE_COMMAND) -P CMakeFiles/Path_Loader.dir/cmake_clean.cmake
.PHONY : Image_Reader/CMakeFiles/Path_Loader.dir/clean

Image_Reader/CMakeFiles/Path_Loader.dir/depend:
	cd /Users/langletmaxime/Desktop/NN_C++ && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/langletmaxime/Desktop/NN_C++ /Users/langletmaxime/Desktop/NN_C++/Image_Reader /Users/langletmaxime/Desktop/NN_C++ /Users/langletmaxime/Desktop/NN_C++/Image_Reader /Users/langletmaxime/Desktop/NN_C++/Image_Reader/CMakeFiles/Path_Loader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Image_Reader/CMakeFiles/Path_Loader.dir/depend

