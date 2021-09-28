# Introductions to the basics


## Minimum Version 

The first line of every CMakeLists.txt is
 - cmake_minimum_required(VERSION 3.1)
 
which is the required name of the file CMake looks for. 

This line is special. The version of CMake will also dictate the policies, which define behavior changes. Starting in CMake 3.12, this supports a range, such as VERSION 3.1...3.15; this means you can support as low as 3.1 but have also tested it with the new policy settings up to 3.15. This is much nicer on users that need the better settings, and due to a trick in the syntax, it's backward compatible with older versions of CMake (though actually running CMake 3.1-3.11 will only set the 3.1 version of the policies in this example, since those versions didn't treat this specifically). New versions of policies tend to be most important for macOS and Windows users, who usually have a very recent version of CMake. 

## Setting a project

Every top-level CMake file will have the next line:
 
 - project(MyProject VERSION 1.0 DESCRIPTION "Very nice project" LANGUAGES CXX)
 
 The version sets a bunch of variables, like MyProject_VERSION and PROJECT_VERSION.
 
 The languages are C, CXX, Fortran, ASM, CUDA (CMake 3.8+), CSharp (3.8+), and SWIFT (CMake 3.15+ experimental). C CXX is the default. 
 
 You can add comments with the # character. 
 
 ## Making an executable
 
 - add_executable(one two.cpp three.h)
 
There are several things to unpack here. one is both the name of the executable file generated, and the name of the CMake target created. 

The source file list comes next. CMake is smart, and will only compile source file extensions. The headers will be, for most intents and purposes, ignored; the only reason to list them is to get them to show up in IDEs. 

## Make a library

 - add_library(one STATIC two.cpp three.h)
 
You get to pick a type of library, STATIC, SHARED, or MODULE. If you leave the choice off, the value of BUILD_SHARED_LIBS will be used to pick between STATIC and SHARED. 

Often you'll need to make a fictional target, that is, one where nothing needs to be compiled, for example. for a header-only library. That is called an INTERFACE library, and is another choice; the only difference is it cannot be followed by filenames. 

You can also make an ALIAS library with an existing library, which simply gives you a new name for a target. The one benefit to this is that you can make libraries with :: in the name. 

## Targets

 - target_include_directories(one PUBLIC include)
 
adds an include directory to a target. PUBLIC doesn't mean much for an executable; for a library it lets CMake know that any targets that link to this target must also need that include directory. Other options are PRIVATE (only affect the current target, not dependencies), and INTERFACE (only needed for dependencies). 

We can then chain targets:

 - add_library(another STATIC another.cpp another.h)
 - target_link_libraries(another PUBLIC one)
 
target_link_libraries is probably the most useful and confusing command in CMake. It takes a target (another) and adds a dependency if a target is given. If no target of that name (one) exists, then it adds a link to a library called one on your path (hence the name of the command). Or you can give it a full path to a library. Or a linker flag. 

Focus on using targets everywhere, and keywords everywhere, and you'll be fine. 

Targets can have include directories, linked libraries (or linked targets), compile options, compile definitions, compile features, and more. You can often get targets (and always make targets) to represent all the libraries you use. 


