# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/going/Rony/Udacity/CppND-Route-Planning-Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/going/Rony/Udacity/CppND-Route-Planning-Project/build

# Include any dependencies generated for this target.
include thirdparty/pugixml/CMakeFiles/pugixml.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include thirdparty/pugixml/CMakeFiles/pugixml.dir/compiler_depend.make

# Include the progress variables for this target.
include thirdparty/pugixml/CMakeFiles/pugixml.dir/progress.make

# Include the compile flags for this target's objects.
include thirdparty/pugixml/CMakeFiles/pugixml.dir/flags.make

thirdparty/pugixml/CMakeFiles/pugixml.dir/codegen:
.PHONY : thirdparty/pugixml/CMakeFiles/pugixml.dir/codegen

thirdparty/pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o: thirdparty/pugixml/CMakeFiles/pugixml.dir/flags.make
thirdparty/pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o: /home/going/Rony/Udacity/CppND-Route-Planning-Project/thirdparty/pugixml/src/pugixml.cpp
thirdparty/pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o: thirdparty/pugixml/CMakeFiles/pugixml.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/going/Rony/Udacity/CppND-Route-Planning-Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object thirdparty/pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o"
	cd /home/going/Rony/Udacity/CppND-Route-Planning-Project/build/thirdparty/pugixml && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT thirdparty/pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o -MF CMakeFiles/pugixml.dir/src/pugixml.cpp.o.d -o CMakeFiles/pugixml.dir/src/pugixml.cpp.o -c /home/going/Rony/Udacity/CppND-Route-Planning-Project/thirdparty/pugixml/src/pugixml.cpp

thirdparty/pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pugixml.dir/src/pugixml.cpp.i"
	cd /home/going/Rony/Udacity/CppND-Route-Planning-Project/build/thirdparty/pugixml && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/going/Rony/Udacity/CppND-Route-Planning-Project/thirdparty/pugixml/src/pugixml.cpp > CMakeFiles/pugixml.dir/src/pugixml.cpp.i

thirdparty/pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pugixml.dir/src/pugixml.cpp.s"
	cd /home/going/Rony/Udacity/CppND-Route-Planning-Project/build/thirdparty/pugixml && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/going/Rony/Udacity/CppND-Route-Planning-Project/thirdparty/pugixml/src/pugixml.cpp -o CMakeFiles/pugixml.dir/src/pugixml.cpp.s

# Object files for target pugixml
pugixml_OBJECTS = \
"CMakeFiles/pugixml.dir/src/pugixml.cpp.o"

# External object files for target pugixml
pugixml_EXTERNAL_OBJECTS =

/home/going/Rony/Udacity/CppND-Route-Planning-Project/lib/libpugixml.a: thirdparty/pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o
/home/going/Rony/Udacity/CppND-Route-Planning-Project/lib/libpugixml.a: thirdparty/pugixml/CMakeFiles/pugixml.dir/build.make
/home/going/Rony/Udacity/CppND-Route-Planning-Project/lib/libpugixml.a: thirdparty/pugixml/CMakeFiles/pugixml.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/going/Rony/Udacity/CppND-Route-Planning-Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library /home/going/Rony/Udacity/CppND-Route-Planning-Project/lib/libpugixml.a"
	cd /home/going/Rony/Udacity/CppND-Route-Planning-Project/build/thirdparty/pugixml && $(CMAKE_COMMAND) -P CMakeFiles/pugixml.dir/cmake_clean_target.cmake
	cd /home/going/Rony/Udacity/CppND-Route-Planning-Project/build/thirdparty/pugixml && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pugixml.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
thirdparty/pugixml/CMakeFiles/pugixml.dir/build: /home/going/Rony/Udacity/CppND-Route-Planning-Project/lib/libpugixml.a
.PHONY : thirdparty/pugixml/CMakeFiles/pugixml.dir/build

thirdparty/pugixml/CMakeFiles/pugixml.dir/clean:
	cd /home/going/Rony/Udacity/CppND-Route-Planning-Project/build/thirdparty/pugixml && $(CMAKE_COMMAND) -P CMakeFiles/pugixml.dir/cmake_clean.cmake
.PHONY : thirdparty/pugixml/CMakeFiles/pugixml.dir/clean

thirdparty/pugixml/CMakeFiles/pugixml.dir/depend:
	cd /home/going/Rony/Udacity/CppND-Route-Planning-Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/going/Rony/Udacity/CppND-Route-Planning-Project /home/going/Rony/Udacity/CppND-Route-Planning-Project/thirdparty/pugixml /home/going/Rony/Udacity/CppND-Route-Planning-Project/build /home/going/Rony/Udacity/CppND-Route-Planning-Project/build/thirdparty/pugixml /home/going/Rony/Udacity/CppND-Route-Planning-Project/build/thirdparty/pugixml/CMakeFiles/pugixml.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : thirdparty/pugixml/CMakeFiles/pugixml.dir/depend

