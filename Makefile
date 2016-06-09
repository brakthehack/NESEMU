# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /home/brak/software/cmake-3.5.2-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/brak/software/cmake-3.5.2-Linux-x86_64/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/brak/dev/NESEMU

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/brak/dev/NESEMU

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/home/brak/software/cmake-3.5.2-Linux-x86_64/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/home/brak/software/cmake-3.5.2-Linux-x86_64/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/brak/dev/NESEMU/CMakeFiles /home/brak/dev/NESEMU/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/brak/dev/NESEMU/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named nesemu

# Build rule for target.
nesemu: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 nesemu
.PHONY : nesemu

# fast build rule for target.
nesemu/fast:
	$(MAKE) -f CMakeFiles/nesemu.dir/build.make CMakeFiles/nesemu.dir/build
.PHONY : nesemu/fast

cpu/adc.o: cpu/adc.cpp.o

.PHONY : cpu/adc.o

# target to build an object file
cpu/adc.cpp.o:
	$(MAKE) -f CMakeFiles/nesemu.dir/build.make CMakeFiles/nesemu.dir/cpu/adc.cpp.o
.PHONY : cpu/adc.cpp.o

cpu/adc.i: cpu/adc.cpp.i

.PHONY : cpu/adc.i

# target to preprocess a source file
cpu/adc.cpp.i:
	$(MAKE) -f CMakeFiles/nesemu.dir/build.make CMakeFiles/nesemu.dir/cpu/adc.cpp.i
.PHONY : cpu/adc.cpp.i

cpu/adc.s: cpu/adc.cpp.s

.PHONY : cpu/adc.s

# target to generate assembly for a file
cpu/adc.cpp.s:
	$(MAKE) -f CMakeFiles/nesemu.dir/build.make CMakeFiles/nesemu.dir/cpu/adc.cpp.s
.PHONY : cpu/adc.cpp.s

cpu/cpu.o: cpu/cpu.cpp.o

.PHONY : cpu/cpu.o

# target to build an object file
cpu/cpu.cpp.o:
	$(MAKE) -f CMakeFiles/nesemu.dir/build.make CMakeFiles/nesemu.dir/cpu/cpu.cpp.o
.PHONY : cpu/cpu.cpp.o

cpu/cpu.i: cpu/cpu.cpp.i

.PHONY : cpu/cpu.i

# target to preprocess a source file
cpu/cpu.cpp.i:
	$(MAKE) -f CMakeFiles/nesemu.dir/build.make CMakeFiles/nesemu.dir/cpu/cpu.cpp.i
.PHONY : cpu/cpu.cpp.i

cpu/cpu.s: cpu/cpu.cpp.s

.PHONY : cpu/cpu.s

# target to generate assembly for a file
cpu/cpu.cpp.s:
	$(MAKE) -f CMakeFiles/nesemu.dir/build.make CMakeFiles/nesemu.dir/cpu/cpu.cpp.s
.PHONY : cpu/cpu.cpp.s

cpu/cpu6502.o: cpu/cpu6502.cpp.o

.PHONY : cpu/cpu6502.o

# target to build an object file
cpu/cpu6502.cpp.o:
	$(MAKE) -f CMakeFiles/nesemu.dir/build.make CMakeFiles/nesemu.dir/cpu/cpu6502.cpp.o
.PHONY : cpu/cpu6502.cpp.o

cpu/cpu6502.i: cpu/cpu6502.cpp.i

.PHONY : cpu/cpu6502.i

# target to preprocess a source file
cpu/cpu6502.cpp.i:
	$(MAKE) -f CMakeFiles/nesemu.dir/build.make CMakeFiles/nesemu.dir/cpu/cpu6502.cpp.i
.PHONY : cpu/cpu6502.cpp.i

cpu/cpu6502.s: cpu/cpu6502.cpp.s

.PHONY : cpu/cpu6502.s

# target to generate assembly for a file
cpu/cpu6502.cpp.s:
	$(MAKE) -f CMakeFiles/nesemu.dir/build.make CMakeFiles/nesemu.dir/cpu/cpu6502.cpp.s
.PHONY : cpu/cpu6502.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/nesemu.dir/build.make CMakeFiles/nesemu.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/nesemu.dir/build.make CMakeFiles/nesemu.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/nesemu.dir/build.make CMakeFiles/nesemu.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... nesemu"
	@echo "... cpu/adc.o"
	@echo "... cpu/adc.i"
	@echo "... cpu/adc.s"
	@echo "... cpu/cpu.o"
	@echo "... cpu/cpu.i"
	@echo "... cpu/cpu.s"
	@echo "... cpu/cpu6502.o"
	@echo "... cpu/cpu6502.i"
	@echo "... cpu/cpu6502.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

