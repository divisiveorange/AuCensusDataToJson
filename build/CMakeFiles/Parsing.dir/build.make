# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/build

# Include any dependencies generated for this target.
include CMakeFiles/Parsing.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Parsing.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Parsing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Parsing.dir/flags.make

CMakeFiles/Parsing.dir/Main.cpp.o: CMakeFiles/Parsing.dir/flags.make
CMakeFiles/Parsing.dir/Main.cpp.o: /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/Main.cpp
CMakeFiles/Parsing.dir/Main.cpp.o: CMakeFiles/Parsing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Parsing.dir/Main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Parsing.dir/Main.cpp.o -MF CMakeFiles/Parsing.dir/Main.cpp.o.d -o CMakeFiles/Parsing.dir/Main.cpp.o -c /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/Main.cpp

CMakeFiles/Parsing.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Parsing.dir/Main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/Main.cpp > CMakeFiles/Parsing.dir/Main.cpp.i

CMakeFiles/Parsing.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Parsing.dir/Main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/Main.cpp -o CMakeFiles/Parsing.dir/Main.cpp.s

CMakeFiles/Parsing.dir/Trie.cpp.o: CMakeFiles/Parsing.dir/flags.make
CMakeFiles/Parsing.dir/Trie.cpp.o: /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/Trie.cpp
CMakeFiles/Parsing.dir/Trie.cpp.o: CMakeFiles/Parsing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Parsing.dir/Trie.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Parsing.dir/Trie.cpp.o -MF CMakeFiles/Parsing.dir/Trie.cpp.o.d -o CMakeFiles/Parsing.dir/Trie.cpp.o -c /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/Trie.cpp

CMakeFiles/Parsing.dir/Trie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Parsing.dir/Trie.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/Trie.cpp > CMakeFiles/Parsing.dir/Trie.cpp.i

CMakeFiles/Parsing.dir/Trie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Parsing.dir/Trie.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/Trie.cpp -o CMakeFiles/Parsing.dir/Trie.cpp.s

CMakeFiles/Parsing.dir/TrieElement.cpp.o: CMakeFiles/Parsing.dir/flags.make
CMakeFiles/Parsing.dir/TrieElement.cpp.o: /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/TrieElement.cpp
CMakeFiles/Parsing.dir/TrieElement.cpp.o: CMakeFiles/Parsing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Parsing.dir/TrieElement.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Parsing.dir/TrieElement.cpp.o -MF CMakeFiles/Parsing.dir/TrieElement.cpp.o.d -o CMakeFiles/Parsing.dir/TrieElement.cpp.o -c /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/TrieElement.cpp

CMakeFiles/Parsing.dir/TrieElement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Parsing.dir/TrieElement.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/TrieElement.cpp > CMakeFiles/Parsing.dir/TrieElement.cpp.i

CMakeFiles/Parsing.dir/TrieElement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Parsing.dir/TrieElement.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/TrieElement.cpp -o CMakeFiles/Parsing.dir/TrieElement.cpp.s

CMakeFiles/Parsing.dir/NameConversions.cpp.o: CMakeFiles/Parsing.dir/flags.make
CMakeFiles/Parsing.dir/NameConversions.cpp.o: /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/NameConversions.cpp
CMakeFiles/Parsing.dir/NameConversions.cpp.o: CMakeFiles/Parsing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Parsing.dir/NameConversions.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Parsing.dir/NameConversions.cpp.o -MF CMakeFiles/Parsing.dir/NameConversions.cpp.o.d -o CMakeFiles/Parsing.dir/NameConversions.cpp.o -c /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/NameConversions.cpp

CMakeFiles/Parsing.dir/NameConversions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Parsing.dir/NameConversions.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/NameConversions.cpp > CMakeFiles/Parsing.dir/NameConversions.cpp.i

CMakeFiles/Parsing.dir/NameConversions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Parsing.dir/NameConversions.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/NameConversions.cpp -o CMakeFiles/Parsing.dir/NameConversions.cpp.s

CMakeFiles/Parsing.dir/CreateJsons.cpp.o: CMakeFiles/Parsing.dir/flags.make
CMakeFiles/Parsing.dir/CreateJsons.cpp.o: /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/CreateJsons.cpp
CMakeFiles/Parsing.dir/CreateJsons.cpp.o: CMakeFiles/Parsing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Parsing.dir/CreateJsons.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Parsing.dir/CreateJsons.cpp.o -MF CMakeFiles/Parsing.dir/CreateJsons.cpp.o.d -o CMakeFiles/Parsing.dir/CreateJsons.cpp.o -c /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/CreateJsons.cpp

CMakeFiles/Parsing.dir/CreateJsons.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Parsing.dir/CreateJsons.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/CreateJsons.cpp > CMakeFiles/Parsing.dir/CreateJsons.cpp.i

CMakeFiles/Parsing.dir/CreateJsons.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Parsing.dir/CreateJsons.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/CreateJsons.cpp -o CMakeFiles/Parsing.dir/CreateJsons.cpp.s

# Object files for target Parsing
Parsing_OBJECTS = \
"CMakeFiles/Parsing.dir/Main.cpp.o" \
"CMakeFiles/Parsing.dir/Trie.cpp.o" \
"CMakeFiles/Parsing.dir/TrieElement.cpp.o" \
"CMakeFiles/Parsing.dir/NameConversions.cpp.o" \
"CMakeFiles/Parsing.dir/CreateJsons.cpp.o"

# External object files for target Parsing
Parsing_EXTERNAL_OBJECTS =

Parsing: CMakeFiles/Parsing.dir/Main.cpp.o
Parsing: CMakeFiles/Parsing.dir/Trie.cpp.o
Parsing: CMakeFiles/Parsing.dir/TrieElement.cpp.o
Parsing: CMakeFiles/Parsing.dir/NameConversions.cpp.o
Parsing: CMakeFiles/Parsing.dir/CreateJsons.cpp.o
Parsing: CMakeFiles/Parsing.dir/build.make
Parsing: CMakeFiles/Parsing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Parsing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Parsing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Parsing.dir/build: Parsing
.PHONY : CMakeFiles/Parsing.dir/build

CMakeFiles/Parsing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Parsing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Parsing.dir/clean

CMakeFiles/Parsing.dir/depend:
	cd /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/build /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/build /Users/alexandergarrity/documents/coding/projects/AuCensusDataToJson/build/CMakeFiles/Parsing.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Parsing.dir/depend

