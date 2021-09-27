# Introduction to Modern CMake

Modern CMake = CMake 3.4+ (maybe even CMake 3.21+)

It's clean, powerful, and elegant, so you can spend most of your time coding, not adding lines to an unreadable, unmaintainable Make (Or CMake 2) file. CMake 3.11+ is supposed to be significantly faster as well. 

Every IDE supports CMake (or CMake supports that IDE). More packages use CMake than any other system. 

## Why do I need a good build system? 

 - You want to avoid hard-coding paths
 - You need to build a package on more than one computer
 - You want to use CI (continuous integration)
 - You need to support different OSs (maybe even just flavors of Unix)
 - You want to support multiple compilers
 - You want to use an IDE, but maybe not all of the time
 - You want to describe how your program is structure logically, not flags and commands
 - You want to use a library
 - You want to use tools, like Clang-Tidy, to help you code
 - You want to use a debugger

## Versions

You should at least use a CMake that came out after your compiler, since it needs to know compiler flags, etc, for that version. And, since CMake will dumb itself down to the minimum required version in your CMake file, installing a new CMake, even system wide, is pretty safe. 


## Installation

 - macOS - brew install cmake
 - windows - download CMake from KitWare
 - linux - ~ $ wget -qO- "https://cmake.org/files/v3.21/cmake-3.21.1-linux-x86_64.tar.gz" | tar --strip-components=1 -xz -C ~/.local

## Pip Installation

This is also provided as an official package. It's a rather new method, and might fail on some systems, but works really well when it works. 

pip install cmake


# Running CMake

## Builds & Installs

Unless otherwise noted, you should always make a build directory and build from there. You can technically do an in-source build, but you'll have to be careful not to overwrite files or add them to git, so just don't. 

Classic CMake Build Procedure:
 - mkdir build
 - cd build
 - cmake ../
 - make

or 

 - mkdir build
 - cd build
 - cmake ../
 - cmake --build

or 

 - cmake -S . -B build
 - cmake --build build


Installation Procedure (from build directory) (pick one):
 - make install
 - cmake --build --target install
 - cmake --install    #(CMake 3.15+ only)

Installation Procedure (from source directory) (pick one):
 - make -C build install
 - cmake --build build --target install
 - cmake --install build   #(CMake 3.15+ only)


Side note:
 - you can use -v for verbose builds
 - you can use -j N for parallel builds on N cores (CMake 3.12+)
 - you can use --target or -t to pick a target (CMake 3.15+)

## Selecting Compilers

Selecting a compiler must be done on the first run in an empty directory. 

 - CC=clang CXX=clang++ cmake ../

This sets the environment variables in bash for CC and CXX, and CMake will respect those variables. 

## Picking a generator

You can build with a variety of tools; make is usually the default. To see all the tools CMake knows about on your system, run 

 - cmake --help
 
 and you can pick with -G"My Tool" (quotes only needed if spaces are in the tool name). You should pick a tool on your first CMake call in a directory, just like the compiler. Feel free to have several build directories, like build/ and buildXcode. Note that makefiles will only run in parallel if you explicitly pass a number of threads, such as make -j2, while Ninja will automatically run in parallel. 
 
 ## Verbose and partial builds
 
 Not really CMake, but if you are using a command line tool like make, you can get verbose builds:
 
 - VERBOSE=1 make
 
 You can also build just a part of a build by specifying a target, such as the name of a library or executable you've defined in CMake and make will just build that target. 
 
 ## Options
 
 CMake has support for cached options. A Variable in CMake can be marked as "cached," which means it will be written to the cache (a file called CMakeCache.txt in the build directory) when it is encountered. You can preset (or change) the value of a cached option on the command line with -D. When CMake looks for a cached variable, it will use the existing value and will not overwrite it. 
 
 ### Standard options
 
 These are common CMake options to most packages:
  
 - **DCMAKE_BUILD_TYPE=** Pick from Release, RelWithDebInfo, Debug, or sometimes more.
 - **DCMAKE_INSTALL_PREFIX=** the location to install to. System install on UNIX would often be /usr/local (the default), user directories are often ~/.local, or you can pick a folder
 - **DBUILD_SHARED_LIBS=** You can set this ON or OFF to control the default for shared libraries 
 - **DBUILD_TESTING=** this is a common name for enabling tests, not all packages use it though, sometimes with good reason. 
 
 ## Debugging your CMake files
 
Verbose output for the build was already mentioned, but you can also see verbose CMake configurre output too. The --trace option will print every line of CMake that is run. Since this is very verbose, CMake 3.7 added --trace-source="filename", which will print out every executed line of just the file you are interested in when it runs. If you select the name of the file you are interested in debugging (usually by selecting the parent directory when debugging a CMakeLists.txt, since all of those have the same name), you can just see the lines in that file. Very useful!

# Do's and Don'ts

## CMake Antipatterns

 - **Do not use global functions:** This includes link_directories, include_libraries, and similar.
 - **Don't add unneeded PUBLIC requirements:** You should avoid forcing something on users that is not required (-Wall). Make these PRIVATE instead. 
 - **Don't GLOB files:** Make or another tool will not know if you add files without rerunning CMake. 
 - **Link to built files directly:** Always link to targets if available. 
 - **Never skip PUBLIC/PRIVATE when linking:** This causes all future linking to be keyword-less. 
 
 ## CMake Patterns
 
 - **Treak CMake as code:** It is code. It should be as clean and readable as all other code. 
 - **Think in targets:** Your targets should represent concepts. Make an (IMPORTED) INTERFACE target for anything that should stay together and link to that. 
 - **Export your interface:** You should be able to run from build or install. 
 - **Write a Config.cmake file:** This is what a library author should do to support clients. 
 - **Make ALIAS targets to keep usage consistent:** Using add_subdirectory and find_package should provide the same targets and namespaces. 
 - **Combine common functionality into clearly documented functions or macros:** Functions are better usually. 
 - **Use lowercase function names:** CMake functions and macros can be called lower or upper case. Always use lower case. Upper case is for variables. 
 - **Use cmake_policy and/or range of versions:** Policies change for a reasonl Only piecemeal set OLD policies if you have to. 


