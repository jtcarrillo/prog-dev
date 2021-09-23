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


