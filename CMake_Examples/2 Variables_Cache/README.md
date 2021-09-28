# Variables and the Cache

## Local Variables

A local variable is set like this:

 - set(MY_VARIABLE "value")

The names of variables are usually all caps, and the value follows. You access a variable by using ${}, such as ${MY_VARIABLE}. 

CMake has the concept of scope; you can access the value of the variable after you set it as long as you are in the same scope. If you leave a function or a file in a sub directory, the variable will no longer be defined. You can set a variable in the scope immediately above your current one with PARENT_SCOPE at the end. 

Lists are simply a series of values when you set them:

 - set(MY_LIST "one" "two")

which internally become ; separated values. So this is an identical statement:

 - set(MY_LIST "one;two")
 
 The list command has utilities for working with lists. Note that an unquote value in CMake is the same as a quoted one if there are no spaces in it; this allows you to skip the quotes most of the time when working with value that you know could not contain spaces. 
 
 When a variable is expanded using ${} syntax, all the same rules about spaces apply. Be especially careful with paths; paths may contain a space at any time and should always be quoted when they are a variable (never write ${MY_PATH}, always should be "${MY_PATH}").
 
 ## Cache Variables
 
 If you want to set a variable from the command line, CMake offers a variable cache. Some variables are already here, like CMAKE_BUILD_TYPE. The syntax for declaring a variable and setting it if it is not already set is:
 
  - set(MY_CACHE_VARIABLE "VALUE" CACHE STRING "Description")
  
This will not replace an existing value. This is so that you can set these on the command line and not have them overridden when the CMake file executes. If you want to use these variables as a make-shift global variable, then you can do:

 - set(MY_CACHE_VARIABLE "VALUE" CACHE STRING "" FORCE)
 - mark_as_advanced(MY_CACHE_VARIABLE)
 
The first line will cause the value to be set no matter what, and the second line will keep the variable from showing up in the list of variables. This is so common, you can alsu use the INTERNAL type to do the same thing. 

 - set(MY_CACHE_VARIABLE "VALUE" CACHE INTERNAL "")
 
Since BOOL is such a common variable type, you can set it more succintly with the shortcut:

 - option(MY_OPTION "This is settable from the command line" OFF)
 
## Environmental variables

You can also set(ENV{variable_name} value) and get $ENV{variable_name} environment variables, though it is generally a very good idea to avoid them. 

## The Cache

The cache is actually just a test file, CMakeCache.txt, that gets created in the build directory when you run CMake. This is how CMake remembers anything you set, so you don't have to re-list your options every time you rerun CMake. 

## Properties

The other way CMake stores information is in properties. This is like a variable, but it is attached to some other items, like a directory or a target. A global property can be useful uncached global variable. Many target properties are initialized from a matching variable with CMAKE_ at the front. So setting CMAKE_CXX_STANDARD, for example, will mean that all new targets created will have CXX_STANDARD set to that when they are created. There are two ways to set properties: 

 - set_property(TARGET TargetName PROPERTY CXX_STANDARD 11)
 - set_target_properties(TargetName PROPERTIES CXX_STANDARD 11)
 
The first form is more genera, and can set multiple targets/fils/tests at once, and has useful options. The second is a shortcut for setting several properties on one target. And you can get properties similarly:

 - get_property(ResultVariable TARGET TargetName PROPERTY CXX_STANDARD)



