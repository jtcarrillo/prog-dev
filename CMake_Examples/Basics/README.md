# Introductions to the basics

The first line of every CMakeLists.txt is
 - cmake_minimum_required(VERSION 3.1)
 
which is the required name of the file CMake looks for. 

This line is special. The version of CMake will also dictate the policies, which define behavior changes. Starting in CMake 3.12, this supports a range, such as VERSION 3.1...3.15; this means you can support as low as 3.1 but have also tested it with the new policy settings up to 3.15. This is much nicer on users that need the better settings, and due to a trick in the syntax, it's backward compatible with older versions of CMake (though actually running CMake 3.1-3.11 will only set the 3.1 version of the policies in this example, since those versions didn't treat this specifically). New versions of policies tend to be most important for macOS and Windows users, who usually have a very recent version of CMake. 


