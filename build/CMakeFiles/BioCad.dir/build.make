# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\itiro\Documentos\BioCad

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\itiro\Documentos\BioCad\build

# Include any dependencies generated for this target.
include CMakeFiles/BioCad.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BioCad.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BioCad.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BioCad.dir/flags.make

CMakeFiles/BioCad.dir/src/atendente.cpp.obj: CMakeFiles/BioCad.dir/flags.make
CMakeFiles/BioCad.dir/src/atendente.cpp.obj: CMakeFiles/BioCad.dir/includes_CXX.rsp
CMakeFiles/BioCad.dir/src/atendente.cpp.obj: C:/Users/itiro/Documentos/BioCad/src/atendente.cpp
CMakeFiles/BioCad.dir/src/atendente.cpp.obj: CMakeFiles/BioCad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\itiro\Documentos\BioCad\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BioCad.dir/src/atendente.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BioCad.dir/src/atendente.cpp.obj -MF CMakeFiles\BioCad.dir\src\atendente.cpp.obj.d -o CMakeFiles\BioCad.dir\src\atendente.cpp.obj -c C:\Users\itiro\Documentos\BioCad\src\atendente.cpp

CMakeFiles/BioCad.dir/src/atendente.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/BioCad.dir/src/atendente.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\itiro\Documentos\BioCad\src\atendente.cpp > CMakeFiles\BioCad.dir\src\atendente.cpp.i

CMakeFiles/BioCad.dir/src/atendente.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/BioCad.dir/src/atendente.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\itiro\Documentos\BioCad\src\atendente.cpp -o CMakeFiles\BioCad.dir\src\atendente.cpp.s

CMakeFiles/BioCad.dir/src/cliente.cpp.obj: CMakeFiles/BioCad.dir/flags.make
CMakeFiles/BioCad.dir/src/cliente.cpp.obj: CMakeFiles/BioCad.dir/includes_CXX.rsp
CMakeFiles/BioCad.dir/src/cliente.cpp.obj: C:/Users/itiro/Documentos/BioCad/src/cliente.cpp
CMakeFiles/BioCad.dir/src/cliente.cpp.obj: CMakeFiles/BioCad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\itiro\Documentos\BioCad\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BioCad.dir/src/cliente.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BioCad.dir/src/cliente.cpp.obj -MF CMakeFiles\BioCad.dir\src\cliente.cpp.obj.d -o CMakeFiles\BioCad.dir\src\cliente.cpp.obj -c C:\Users\itiro\Documentos\BioCad\src\cliente.cpp

CMakeFiles/BioCad.dir/src/cliente.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/BioCad.dir/src/cliente.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\itiro\Documentos\BioCad\src\cliente.cpp > CMakeFiles\BioCad.dir\src\cliente.cpp.i

CMakeFiles/BioCad.dir/src/cliente.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/BioCad.dir/src/cliente.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\itiro\Documentos\BioCad\src\cliente.cpp -o CMakeFiles\BioCad.dir\src\cliente.cpp.s

CMakeFiles/BioCad.dir/src/gerente.cpp.obj: CMakeFiles/BioCad.dir/flags.make
CMakeFiles/BioCad.dir/src/gerente.cpp.obj: CMakeFiles/BioCad.dir/includes_CXX.rsp
CMakeFiles/BioCad.dir/src/gerente.cpp.obj: C:/Users/itiro/Documentos/BioCad/src/gerente.cpp
CMakeFiles/BioCad.dir/src/gerente.cpp.obj: CMakeFiles/BioCad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\itiro\Documentos\BioCad\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/BioCad.dir/src/gerente.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BioCad.dir/src/gerente.cpp.obj -MF CMakeFiles\BioCad.dir\src\gerente.cpp.obj.d -o CMakeFiles\BioCad.dir\src\gerente.cpp.obj -c C:\Users\itiro\Documentos\BioCad\src\gerente.cpp

CMakeFiles/BioCad.dir/src/gerente.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/BioCad.dir/src/gerente.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\itiro\Documentos\BioCad\src\gerente.cpp > CMakeFiles\BioCad.dir\src\gerente.cpp.i

CMakeFiles/BioCad.dir/src/gerente.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/BioCad.dir/src/gerente.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\itiro\Documentos\BioCad\src\gerente.cpp -o CMakeFiles\BioCad.dir\src\gerente.cpp.s

CMakeFiles/BioCad.dir/src/main.cpp.obj: CMakeFiles/BioCad.dir/flags.make
CMakeFiles/BioCad.dir/src/main.cpp.obj: CMakeFiles/BioCad.dir/includes_CXX.rsp
CMakeFiles/BioCad.dir/src/main.cpp.obj: C:/Users/itiro/Documentos/BioCad/src/main.cpp
CMakeFiles/BioCad.dir/src/main.cpp.obj: CMakeFiles/BioCad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\itiro\Documentos\BioCad\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/BioCad.dir/src/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BioCad.dir/src/main.cpp.obj -MF CMakeFiles\BioCad.dir\src\main.cpp.obj.d -o CMakeFiles\BioCad.dir\src\main.cpp.obj -c C:\Users\itiro\Documentos\BioCad\src\main.cpp

CMakeFiles/BioCad.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/BioCad.dir/src/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\itiro\Documentos\BioCad\src\main.cpp > CMakeFiles\BioCad.dir\src\main.cpp.i

CMakeFiles/BioCad.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/BioCad.dir/src/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\itiro\Documentos\BioCad\src\main.cpp -o CMakeFiles\BioCad.dir\src\main.cpp.s

CMakeFiles/BioCad.dir/src/tela.cpp.obj: CMakeFiles/BioCad.dir/flags.make
CMakeFiles/BioCad.dir/src/tela.cpp.obj: CMakeFiles/BioCad.dir/includes_CXX.rsp
CMakeFiles/BioCad.dir/src/tela.cpp.obj: C:/Users/itiro/Documentos/BioCad/src/tela.cpp
CMakeFiles/BioCad.dir/src/tela.cpp.obj: CMakeFiles/BioCad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\itiro\Documentos\BioCad\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/BioCad.dir/src/tela.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BioCad.dir/src/tela.cpp.obj -MF CMakeFiles\BioCad.dir\src\tela.cpp.obj.d -o CMakeFiles\BioCad.dir\src\tela.cpp.obj -c C:\Users\itiro\Documentos\BioCad\src\tela.cpp

CMakeFiles/BioCad.dir/src/tela.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/BioCad.dir/src/tela.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\itiro\Documentos\BioCad\src\tela.cpp > CMakeFiles\BioCad.dir\src\tela.cpp.i

CMakeFiles/BioCad.dir/src/tela.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/BioCad.dir/src/tela.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\itiro\Documentos\BioCad\src\tela.cpp -o CMakeFiles\BioCad.dir\src\tela.cpp.s

# Object files for target BioCad
BioCad_OBJECTS = \
"CMakeFiles/BioCad.dir/src/atendente.cpp.obj" \
"CMakeFiles/BioCad.dir/src/cliente.cpp.obj" \
"CMakeFiles/BioCad.dir/src/gerente.cpp.obj" \
"CMakeFiles/BioCad.dir/src/main.cpp.obj" \
"CMakeFiles/BioCad.dir/src/tela.cpp.obj"

# External object files for target BioCad
BioCad_EXTERNAL_OBJECTS =

BioCad.exe: CMakeFiles/BioCad.dir/src/atendente.cpp.obj
BioCad.exe: CMakeFiles/BioCad.dir/src/cliente.cpp.obj
BioCad.exe: CMakeFiles/BioCad.dir/src/gerente.cpp.obj
BioCad.exe: CMakeFiles/BioCad.dir/src/main.cpp.obj
BioCad.exe: CMakeFiles/BioCad.dir/src/tela.cpp.obj
BioCad.exe: CMakeFiles/BioCad.dir/build.make
BioCad.exe: CMakeFiles/BioCad.dir/linkLibs.rsp
BioCad.exe: CMakeFiles/BioCad.dir/objects1.rsp
BioCad.exe: CMakeFiles/BioCad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\itiro\Documentos\BioCad\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable BioCad.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BioCad.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BioCad.dir/build: BioCad.exe
.PHONY : CMakeFiles/BioCad.dir/build

CMakeFiles/BioCad.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BioCad.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BioCad.dir/clean

CMakeFiles/BioCad.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\itiro\Documentos\BioCad C:\Users\itiro\Documentos\BioCad C:\Users\itiro\Documentos\BioCad\build C:\Users\itiro\Documentos\BioCad\build C:\Users\itiro\Documentos\BioCad\build\CMakeFiles\BioCad.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/BioCad.dir/depend

