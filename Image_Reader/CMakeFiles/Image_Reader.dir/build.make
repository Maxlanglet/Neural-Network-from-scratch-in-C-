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
include Image_Reader/CMakeFiles/Image_Reader.dir/depend.make

# Include the progress variables for this target.
include Image_Reader/CMakeFiles/Image_Reader.dir/progress.make

# Include the compile flags for this target's objects.
include Image_Reader/CMakeFiles/Image_Reader.dir/flags.make

Image_Reader/CMakeFiles/Image_Reader.dir/Image_Reader.cpp.o: Image_Reader/CMakeFiles/Image_Reader.dir/flags.make
Image_Reader/CMakeFiles/Image_Reader.dir/Image_Reader.cpp.o: Image_Reader/Image_Reader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/langletmaxime/Desktop/NN_C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Image_Reader/CMakeFiles/Image_Reader.dir/Image_Reader.cpp.o"
	cd /Users/langletmaxime/Desktop/NN_C++/Image_Reader && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Image_Reader.dir/Image_Reader.cpp.o -c /Users/langletmaxime/Desktop/NN_C++/Image_Reader/Image_Reader.cpp

Image_Reader/CMakeFiles/Image_Reader.dir/Image_Reader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Image_Reader.dir/Image_Reader.cpp.i"
	cd /Users/langletmaxime/Desktop/NN_C++/Image_Reader && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/langletmaxime/Desktop/NN_C++/Image_Reader/Image_Reader.cpp > CMakeFiles/Image_Reader.dir/Image_Reader.cpp.i

Image_Reader/CMakeFiles/Image_Reader.dir/Image_Reader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Image_Reader.dir/Image_Reader.cpp.s"
	cd /Users/langletmaxime/Desktop/NN_C++/Image_Reader && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/langletmaxime/Desktop/NN_C++/Image_Reader/Image_Reader.cpp -o CMakeFiles/Image_Reader.dir/Image_Reader.cpp.s

# Object files for target Image_Reader
Image_Reader_OBJECTS = \
"CMakeFiles/Image_Reader.dir/Image_Reader.cpp.o"

# External object files for target Image_Reader
Image_Reader_EXTERNAL_OBJECTS =

Image_Reader/libImage_Reader.a: Image_Reader/CMakeFiles/Image_Reader.dir/Image_Reader.cpp.o
Image_Reader/libImage_Reader.a: Image_Reader/CMakeFiles/Image_Reader.dir/build.make
Image_Reader/libImage_Reader.a: Image_Reader/CMakeFiles/Image_Reader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/langletmaxime/Desktop/NN_C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libImage_Reader.a"
	cd /Users/langletmaxime/Desktop/NN_C++/Image_Reader && $(CMAKE_COMMAND) -P CMakeFiles/Image_Reader.dir/cmake_clean_target.cmake
	cd /Users/langletmaxime/Desktop/NN_C++/Image_Reader && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Image_Reader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Image_Reader/CMakeFiles/Image_Reader.dir/build: Image_Reader/libImage_Reader.a

.PHONY : Image_Reader/CMakeFiles/Image_Reader.dir/build

Image_Reader/CMakeFiles/Image_Reader.dir/clean:
	cd /Users/langletmaxime/Desktop/NN_C++/Image_Reader && $(CMAKE_COMMAND) -P CMakeFiles/Image_Reader.dir/cmake_clean.cmake
.PHONY : Image_Reader/CMakeFiles/Image_Reader.dir/clean

Image_Reader/CMakeFiles/Image_Reader.dir/depend:
	cd /Users/langletmaxime/Desktop/NN_C++ && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/langletmaxime/Desktop/NN_C++ /Users/langletmaxime/Desktop/NN_C++/Image_Reader /Users/langletmaxime/Desktop/NN_C++ /Users/langletmaxime/Desktop/NN_C++/Image_Reader /Users/langletmaxime/Desktop/NN_C++/Image_Reader/CMakeFiles/Image_Reader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Image_Reader/CMakeFiles/Image_Reader.dir/depend
