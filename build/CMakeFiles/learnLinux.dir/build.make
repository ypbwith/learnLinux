# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /mnt/hgfs/workProject/learnLinux

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/workProject/learnLinux/build

# Include any dependencies generated for this target.
include CMakeFiles/learnLinux.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/learnLinux.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/learnLinux.dir/flags.make

CMakeFiles/learnLinux.dir/src/main/main.cpp.o: CMakeFiles/learnLinux.dir/flags.make
CMakeFiles/learnLinux.dir/src/main/main.cpp.o: ../src/main/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/workProject/learnLinux/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/learnLinux.dir/src/main/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learnLinux.dir/src/main/main.cpp.o -c /mnt/hgfs/workProject/learnLinux/src/main/main.cpp

CMakeFiles/learnLinux.dir/src/main/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learnLinux.dir/src/main/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/workProject/learnLinux/src/main/main.cpp > CMakeFiles/learnLinux.dir/src/main/main.cpp.i

CMakeFiles/learnLinux.dir/src/main/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learnLinux.dir/src/main/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/workProject/learnLinux/src/main/main.cpp -o CMakeFiles/learnLinux.dir/src/main/main.cpp.s

CMakeFiles/learnLinux.dir/src/main/main.cpp.o.requires:

.PHONY : CMakeFiles/learnLinux.dir/src/main/main.cpp.o.requires

CMakeFiles/learnLinux.dir/src/main/main.cpp.o.provides: CMakeFiles/learnLinux.dir/src/main/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/learnLinux.dir/build.make CMakeFiles/learnLinux.dir/src/main/main.cpp.o.provides.build
.PHONY : CMakeFiles/learnLinux.dir/src/main/main.cpp.o.provides

CMakeFiles/learnLinux.dir/src/main/main.cpp.o.provides.build: CMakeFiles/learnLinux.dir/src/main/main.cpp.o


CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.o: CMakeFiles/learnLinux.dir/flags.make
CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.o: ../src/easylogging++/easylogging++.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/workProject/learnLinux/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.o -c /mnt/hgfs/workProject/learnLinux/src/easylogging++/easylogging++.cc

CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/workProject/learnLinux/src/easylogging++/easylogging++.cc > CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.i

CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/workProject/learnLinux/src/easylogging++/easylogging++.cc -o CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.s

CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.o.requires:

.PHONY : CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.o.requires

CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.o.provides: CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.o.requires
	$(MAKE) -f CMakeFiles/learnLinux.dir/build.make CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.o.provides.build
.PHONY : CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.o.provides

CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.o.provides.build: CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.o


# Object files for target learnLinux
learnLinux_OBJECTS = \
"CMakeFiles/learnLinux.dir/src/main/main.cpp.o" \
"CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.o"

# External object files for target learnLinux
learnLinux_EXTERNAL_OBJECTS =

install/bin/learnLinux: CMakeFiles/learnLinux.dir/src/main/main.cpp.o
install/bin/learnLinux: CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.o
install/bin/learnLinux: CMakeFiles/learnLinux.dir/build.make
install/bin/learnLinux: install/lib/libmain.a
install/bin/learnLinux: CMakeFiles/learnLinux.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/hgfs/workProject/learnLinux/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable install/bin/learnLinux"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/learnLinux.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/learnLinux.dir/build: install/bin/learnLinux

.PHONY : CMakeFiles/learnLinux.dir/build

CMakeFiles/learnLinux.dir/requires: CMakeFiles/learnLinux.dir/src/main/main.cpp.o.requires
CMakeFiles/learnLinux.dir/requires: CMakeFiles/learnLinux.dir/src/easylogging++/easylogging++.cc.o.requires

.PHONY : CMakeFiles/learnLinux.dir/requires

CMakeFiles/learnLinux.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/learnLinux.dir/cmake_clean.cmake
.PHONY : CMakeFiles/learnLinux.dir/clean

CMakeFiles/learnLinux.dir/depend:
	cd /mnt/hgfs/workProject/learnLinux/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/workProject/learnLinux /mnt/hgfs/workProject/learnLinux /mnt/hgfs/workProject/learnLinux/build /mnt/hgfs/workProject/learnLinux/build /mnt/hgfs/workProject/learnLinux/build/CMakeFiles/learnLinux.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/learnLinux.dir/depend
