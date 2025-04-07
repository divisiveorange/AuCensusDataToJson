cmake_minimum_required(VERSION 3.28)
project(Parsing)

set(CMAKE_CXX_STANDARD 23)
include_directories(${PROJECT_SOURCE_DIR}/include) # If you placed it in an 'include' directory
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
endif()
add_executable(Parsing Main.cpp
        Trie.cpp
        Trie.h
        TrieElement.cpp
        TrieElement.h
        NameConversions.cpp
        NameConversions.h
        CreateJsons.cpp
        CreateJsons.h
)


