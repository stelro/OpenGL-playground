# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/stel/clion-2017.1.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/stel/clion-2017.1.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OpenGLBook.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGLBook.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGLBook.dir/flags.make

CMakeFiles/OpenGLBook.dir/main.cpp.o: CMakeFiles/OpenGLBook.dir/flags.make
CMakeFiles/OpenGLBook.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenGLBook.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGLBook.dir/main.cpp.o -c /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/main.cpp

CMakeFiles/OpenGLBook.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLBook.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/main.cpp > CMakeFiles/OpenGLBook.dir/main.cpp.i

CMakeFiles/OpenGLBook.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLBook.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/main.cpp -o CMakeFiles/OpenGLBook.dir/main.cpp.s

CMakeFiles/OpenGLBook.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/OpenGLBook.dir/main.cpp.o.requires

CMakeFiles/OpenGLBook.dir/main.cpp.o.provides: CMakeFiles/OpenGLBook.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/OpenGLBook.dir/build.make CMakeFiles/OpenGLBook.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/OpenGLBook.dir/main.cpp.o.provides

CMakeFiles/OpenGLBook.dir/main.cpp.o.provides.build: CMakeFiles/OpenGLBook.dir/main.cpp.o


CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.o: CMakeFiles/OpenGLBook.dir/flags.make
CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.o: ../ShaderProgram.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.o -c /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/ShaderProgram.cpp

CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/ShaderProgram.cpp > CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.i

CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/ShaderProgram.cpp -o CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.s

CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.o.requires:

.PHONY : CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.o.requires

CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.o.provides: CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.o.requires
	$(MAKE) -f CMakeFiles/OpenGLBook.dir/build.make CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.o.provides.build
.PHONY : CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.o.provides

CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.o.provides.build: CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.o


CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.o: CMakeFiles/OpenGLBook.dir/flags.make
CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.o: ../SOIL/src/image_DXT.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.o   -c /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/SOIL/src/image_DXT.c

CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/SOIL/src/image_DXT.c > CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.i

CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/SOIL/src/image_DXT.c -o CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.s

CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.o.requires:

.PHONY : CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.o.requires

CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.o.provides: CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.o.requires
	$(MAKE) -f CMakeFiles/OpenGLBook.dir/build.make CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.o.provides.build
.PHONY : CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.o.provides

CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.o.provides.build: CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.o


CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.o: CMakeFiles/OpenGLBook.dir/flags.make
CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.o: ../SOIL/src/image_helper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.o   -c /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/SOIL/src/image_helper.c

CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/SOIL/src/image_helper.c > CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.i

CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/SOIL/src/image_helper.c -o CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.s

CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.o.requires:

.PHONY : CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.o.requires

CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.o.provides: CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.o.requires
	$(MAKE) -f CMakeFiles/OpenGLBook.dir/build.make CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.o.provides.build
.PHONY : CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.o.provides

CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.o.provides.build: CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.o


CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.o: CMakeFiles/OpenGLBook.dir/flags.make
CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.o: ../SOIL/src/stb_image_aug.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.o   -c /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/SOIL/src/stb_image_aug.c

CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/SOIL/src/stb_image_aug.c > CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.i

CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/SOIL/src/stb_image_aug.c -o CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.s

CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.o.requires:

.PHONY : CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.o.requires

CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.o.provides: CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.o.requires
	$(MAKE) -f CMakeFiles/OpenGLBook.dir/build.make CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.o.provides.build
.PHONY : CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.o.provides

CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.o.provides.build: CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.o


CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.o: CMakeFiles/OpenGLBook.dir/flags.make
CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.o: ../SOIL/src/SOIL.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.o   -c /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/SOIL/src/SOIL.c

CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/SOIL/src/SOIL.c > CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.i

CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/SOIL/src/SOIL.c -o CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.s

CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.o.requires:

.PHONY : CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.o.requires

CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.o.provides: CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.o.requires
	$(MAKE) -f CMakeFiles/OpenGLBook.dir/build.make CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.o.provides.build
.PHONY : CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.o.provides

CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.o.provides.build: CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.o


# Object files for target OpenGLBook
OpenGLBook_OBJECTS = \
"CMakeFiles/OpenGLBook.dir/main.cpp.o" \
"CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.o" \
"CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.o" \
"CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.o" \
"CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.o" \
"CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.o"

# External object files for target OpenGLBook
OpenGLBook_EXTERNAL_OBJECTS =

OpenGLBook: CMakeFiles/OpenGLBook.dir/main.cpp.o
OpenGLBook: CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.o
OpenGLBook: CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.o
OpenGLBook: CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.o
OpenGLBook: CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.o
OpenGLBook: CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.o
OpenGLBook: CMakeFiles/OpenGLBook.dir/build.make
OpenGLBook: /usr/lib/x86_64-linux-gnu/libGLU.so
OpenGLBook: /usr/lib/x86_64-linux-gnu/libGL.so
OpenGLBook: CMakeFiles/OpenGLBook.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable OpenGLBook"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenGLBook.dir/link.txt --verbose=$(VERBOSE)
	/home/stel/clion-2017.1.1/bin/cmake/bin/cmake -E copy_directory /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/Shaders /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/cmake-build-debug/Shaders
	/home/stel/clion-2017.1.1/bin/cmake/bin/cmake -E copy_directory /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/Assets /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/cmake-build-debug/Assets

# Rule to build all files generated by this target.
CMakeFiles/OpenGLBook.dir/build: OpenGLBook

.PHONY : CMakeFiles/OpenGLBook.dir/build

CMakeFiles/OpenGLBook.dir/requires: CMakeFiles/OpenGLBook.dir/main.cpp.o.requires
CMakeFiles/OpenGLBook.dir/requires: CMakeFiles/OpenGLBook.dir/ShaderProgram.cpp.o.requires
CMakeFiles/OpenGLBook.dir/requires: CMakeFiles/OpenGLBook.dir/SOIL/src/image_DXT.c.o.requires
CMakeFiles/OpenGLBook.dir/requires: CMakeFiles/OpenGLBook.dir/SOIL/src/image_helper.c.o.requires
CMakeFiles/OpenGLBook.dir/requires: CMakeFiles/OpenGLBook.dir/SOIL/src/stb_image_aug.c.o.requires
CMakeFiles/OpenGLBook.dir/requires: CMakeFiles/OpenGLBook.dir/SOIL/src/SOIL.c.o.requires

.PHONY : CMakeFiles/OpenGLBook.dir/requires

CMakeFiles/OpenGLBook.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenGLBook.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenGLBook.dir/clean

CMakeFiles/OpenGLBook.dir/depend:
	cd /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/cmake-build-debug /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/cmake-build-debug /home/stel/workspace-gaming/OpenGL-playground/OpenGL_4_LightingMaps/cmake-build-debug/CMakeFiles/OpenGLBook.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenGLBook.dir/depend

