# Why C++?


C++ of today provides programmers the ability to write expressive and robust code while still having the ability to target almost any hardware platform or real-time requirement. In short, C++ is a highly portable language which offers zero-cost abstractions. Furthermore, C++ provides programmers with the ability to write and manage large, expressive, and robust code bases. 

## Zero-cost abstractions

Active code bases grow. The more developers working on a code base, the larger the code base becomes. We need abstractions such as functions, classes, data structures, layers, and so on in order to manage the complexity of a large-scale code base. But constantly adding abstractions and new levels of indirection comes at a price - efficiency. This is where zero-cost abstractions plays its role. A lot of the abstraction offered by C++ comes at a very low price. At a minimum, C++ offers efficienct alternatives at hot spots where performance really is a concern. 

## Programming languages and machine code abstractions

In order to relieve programmers from dealing with computer-related terms, modern programming languages use abstractions so that a list of strings, for example, can be handled and thought of as a list of strings rather than a list of addresses that we may easily lose track of if we make the slightest typo. Not only do the abstractions relieve the programmers from bugs, they also make the code more expressive by using concepts from the domain of the application. In other words, the code is expressed in terms that are closer to a spoken language than if expressed with abstract programming keywords. 

Many of the modern C++ language features can be seen as abstraction of basic C functionality and, on top of that, basic C++ functionality: 

* C++ classses are abstractions of C-structs and regular functions
* C++ polymorphism is the abstraction of function pointers
* C++ lambda functions are abstractions of C++ classes
* Templtes are abstractions of generating C++ code

What distinguishes C++ from most other languages is that, while the other languages have implemented abstractions at the cost of runtime performance, C++ has always strived to implement its abstractions at zero cost at runtime. 

## Portability

C++ has been a popular and comprehensive language for a long time. It's high compatible with C and very little has been depreciated in the language, for better or worse. The history and design of C++ has made it to a highly portable language, and the evolution of modern C++ has ensured that it will stay that way for a long time to come. 

## Robustness

In addition to performance, expressiveness, and portability, C++ offers a set of language feature that gives the programmer the ability to write robust code. Robustness does not refer to strength in the programming language itself - it's possible to write robust code in any language. However, strict ownership of resources, const correctness, value semantics, type safety, and deterministic destruction of objects are some of the features offered by C++ that makes it easier to write robust code. That is, the ability to write functions, classes, and libraries that are easy to use and hard to misuse. 

## Competing languages and performance

Some programming languages compile to bytecode, which is then compiled to machine code while the application is executing, whereas C++ directly compiles the source code to machine code. Although bytecode and just-in-time compilers may theoretically be able to achieve the same (or theoretically, even better) performanc than precompiled machine code, as of today, they simply do not. 

Secondly, some programming languages handle dynamic memory in a completely different manner from C++. In Java, memory is automatically deallocated by a garbage collector, whereas a C++ program handles memory deallocations by itself. The garbage collector does prevent memory leaks but at the cost of performance and predictability. 

Thirdly, some programming languages place all its objects in separate hap allocations, whereas C++ allows the programmer to place objects both on the stack and on the heap. In C++ it's also possible to create multiple objects in one single heap allocation. This can be huge performance gain for two reasons: objects can be created without always allocating dynamic memory, and multiple related objects can be placed adjacent to one another in memory. 



# Examples

- [x] Abstractions
- [x] Heap Allocations
- [ ] Const Correctness
- [ ] Exception Safety
- [ ] References
- [ ] Resource Acquisition
- [ ] Strict Interfaces
- [ ] Value Semantics

## Abstractions (Abstractions.cpp)

C++ and C are nowadays two completely different languages. Still, C++ is highly compatible with C and has inherited a lot of its syntax and idioms from C. 

(Abstraction.cpp) Although the C++ version is still more of a robot language than a human language, a lot of programming lingo is gone. Here are some of the noticeable differences between the preceding two code snippets:

* The pointers to raw memory addresses are not visible at all. 
* The std::list<std::string> container is an abstraction of string_elem_t
* The std::count() method is an abstraction of both the for loop and the if condition
* the std::string class is (among other things) an abstraction of char* and strcmp

Basically, both version of num_hamlet() translate to roughly the same machine code, but the language feature of C++ makes it possible to let the libraries hide computer related terminology such as pointers.

## Heap Allocation (Heap_Allocation.cpp)

This example demonstrates how C++ can minimize heap allocation by:

1. Creating objects on the stack
2. Allocate multiple objects in one heap allocation

The C++ vector contains the actual Car objects placed in one contiguous memory block, whereas the equivalent in Java isa contiguous memory block of references to Car objects. In Java, the objects has been allocated separately, which means that they can be located anywhere in the heap. 

This affects the performance as Java has to execute seven allocations instead of one. It also means that whenver the application iterates the list, there is a performance win for C++, since accessing nearby memory locations is faster than accessing several random spots in memory. 

Reminder:

A stack is a special area of computer's memory which stores temporary variables created by a function. In stack, variables are declared, stored, and initialized during runtime. It is a temporary storage memory. When the computing task is complete, the memory of the variable will be automatically erased. The stack section mostly contains methods, local variable, and reference variables. 

The heap is a memory used by programming languages to store global variables. By defaul, all global variable are stored in heap memory space. It support dynamic memory allocation. The heap is not managed automatically for you and is not as tightly managed by the CPU. It is more like a free-floating region of memory. 

Key Differences:

- Stack is linear data structure whereas Heap is a hierarchical data structure. 
- Stack memory will never become fragmented wheras Heap memory can become fragmented as blocks of memory are first allocated and then freed. 
- Stack accesses local variables only while Heap allows you to access variables globally. 
- Stack variables can't be resized whereas Heap variables can be resized. 
- Stack memory is allocated in a contiguous block whereas Heap memory is allocated in any random order. 
- Stack doesn't require to de-allocate variables whereas in Heap de-allocation is needed. 
- Stack allocation and deallocation are done by compiler instructions whereas Heap allocation and deallocation is done by the programmer. 

# References

[C++ High Performance](https://github.com/PacktPublishing/Cpp-High-Performance)
