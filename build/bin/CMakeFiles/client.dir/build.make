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
CMAKE_SOURCE_DIR = /home/winter/workspace/Tinyhttpd/mywork

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/winter/workspace/Tinyhttpd/mywork/build

# Include any dependencies generated for this target.
include bin/CMakeFiles/client.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/client.dir/flags.make

bin/CMakeFiles/client.dir/client.c.o: bin/CMakeFiles/client.dir/flags.make
bin/CMakeFiles/client.dir/client.c.o: ../src/client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/winter/workspace/Tinyhttpd/mywork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object bin/CMakeFiles/client.dir/client.c.o"
	cd /home/winter/workspace/Tinyhttpd/mywork/build/bin && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/client.dir/client.c.o   -c /home/winter/workspace/Tinyhttpd/mywork/src/client.c

bin/CMakeFiles/client.dir/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/client.dir/client.c.i"
	cd /home/winter/workspace/Tinyhttpd/mywork/build/bin && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/winter/workspace/Tinyhttpd/mywork/src/client.c > CMakeFiles/client.dir/client.c.i

bin/CMakeFiles/client.dir/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/client.dir/client.c.s"
	cd /home/winter/workspace/Tinyhttpd/mywork/build/bin && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/winter/workspace/Tinyhttpd/mywork/src/client.c -o CMakeFiles/client.dir/client.c.s

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/client.c.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

../bin/client: bin/CMakeFiles/client.dir/client.c.o
../bin/client: bin/CMakeFiles/client.dir/build.make
../bin/client: bin/CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/winter/workspace/Tinyhttpd/mywork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../../bin/client"
	cd /home/winter/workspace/Tinyhttpd/mywork/build/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/client.dir/build: ../bin/client

.PHONY : bin/CMakeFiles/client.dir/build

bin/CMakeFiles/client.dir/clean:
	cd /home/winter/workspace/Tinyhttpd/mywork/build/bin && $(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/client.dir/clean

bin/CMakeFiles/client.dir/depend:
	cd /home/winter/workspace/Tinyhttpd/mywork/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/winter/workspace/Tinyhttpd/mywork /home/winter/workspace/Tinyhttpd/mywork/src /home/winter/workspace/Tinyhttpd/mywork/build /home/winter/workspace/Tinyhttpd/mywork/build/bin /home/winter/workspace/Tinyhttpd/mywork/build/bin/CMakeFiles/client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/client.dir/depend

