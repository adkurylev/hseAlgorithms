# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\damerau"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\damerau\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/damerau.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/damerau.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/damerau.dir/flags.make

CMakeFiles/damerau.dir/main.cpp.obj: CMakeFiles/damerau.dir/flags.make
CMakeFiles/damerau.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\damerau\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/damerau.dir/main.cpp.obj"
	C:\MinGW\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\damerau.dir\main.cpp.obj -c "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\damerau\main.cpp"

CMakeFiles/damerau.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/damerau.dir/main.cpp.i"
	C:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\damerau\main.cpp" > CMakeFiles\damerau.dir\main.cpp.i

CMakeFiles/damerau.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/damerau.dir/main.cpp.s"
	C:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\damerau\main.cpp" -o CMakeFiles\damerau.dir\main.cpp.s

# Object files for target damerau
damerau_OBJECTS = \
"CMakeFiles/damerau.dir/main.cpp.obj"

# External object files for target damerau
damerau_EXTERNAL_OBJECTS =

damerau.exe: CMakeFiles/damerau.dir/main.cpp.obj
damerau.exe: CMakeFiles/damerau.dir/build.make
damerau.exe: CMakeFiles/damerau.dir/linklibs.rsp
damerau.exe: CMakeFiles/damerau.dir/objects1.rsp
damerau.exe: CMakeFiles/damerau.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\damerau\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable damerau.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\damerau.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/damerau.dir/build: damerau.exe

.PHONY : CMakeFiles/damerau.dir/build

CMakeFiles/damerau.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\damerau.dir\cmake_clean.cmake
.PHONY : CMakeFiles/damerau.dir/clean

CMakeFiles/damerau.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\damerau" "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\damerau" "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\damerau\cmake-build-debug" "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\damerau\cmake-build-debug" "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\damerau\cmake-build-debug\CMakeFiles\damerau.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/damerau.dir/depend
