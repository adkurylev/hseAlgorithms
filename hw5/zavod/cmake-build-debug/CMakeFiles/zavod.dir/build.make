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
CMAKE_SOURCE_DIR = "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\zavod"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\zavod\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/zavod.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zavod.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zavod.dir/flags.make

CMakeFiles/zavod.dir/main.cpp.obj: CMakeFiles/zavod.dir/flags.make
CMakeFiles/zavod.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\zavod\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zavod.dir/main.cpp.obj"
	C:\MinGW\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\zavod.dir\main.cpp.obj -c "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\zavod\main.cpp"

CMakeFiles/zavod.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zavod.dir/main.cpp.i"
	C:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\zavod\main.cpp" > CMakeFiles\zavod.dir\main.cpp.i

CMakeFiles/zavod.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zavod.dir/main.cpp.s"
	C:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\zavod\main.cpp" -o CMakeFiles\zavod.dir\main.cpp.s

# Object files for target zavod
zavod_OBJECTS = \
"CMakeFiles/zavod.dir/main.cpp.obj"

# External object files for target zavod
zavod_EXTERNAL_OBJECTS =

zavod.exe: CMakeFiles/zavod.dir/main.cpp.obj
zavod.exe: CMakeFiles/zavod.dir/build.make
zavod.exe: CMakeFiles/zavod.dir/linklibs.rsp
zavod.exe: CMakeFiles/zavod.dir/objects1.rsp
zavod.exe: CMakeFiles/zavod.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\zavod\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable zavod.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\zavod.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zavod.dir/build: zavod.exe

.PHONY : CMakeFiles/zavod.dir/build

CMakeFiles/zavod.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\zavod.dir\cmake_clean.cmake
.PHONY : CMakeFiles/zavod.dir/clean

CMakeFiles/zavod.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\zavod" "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\zavod" "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\zavod\cmake-build-debug" "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\zavod\cmake-build-debug" "C:\Programming\C++\HSE\SE\2 semestr\Hometask\hw5\zavod\cmake-build-debug\CMakeFiles\zavod.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/zavod.dir/depend

