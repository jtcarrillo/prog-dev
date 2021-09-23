# Test-Driven Development [Ref 1] 

C++ remains one of the best choices for building high-performance solutions. One might think that the code quality on C++ systems should be high. Yet most C++ systems exhibit the same problems we all see time and time again, usually regardless of language. Like any language, C++ allows you to shoot yourself in the foot - but with C++ you sometimes don't realize you shot yourself until it's too late. 

 - Monstrous source files with thousands of lines
 - Member functions with hundreds or thousands of lines of inscrutable code
 - Volumes of dead code
 - Build times extending into several hours
 - High number of defects
 - Logic too convluted by quick fixes to be safely managed
 - Code duplicated across files, classes, and modules
 - Code riddled with long-obsolete coding practices
 
 Test-Driven Development (TDD) is a tool you can master and wield in order to help stave off system entropy. 
 
 ## Process
 
 A common misconception of TDD is that you first define all the tests before building an implementation. Instead, you focus on one test at a time and incrementally consider the next behavior to drive into the system from there. As a general approach to TDD, you seek to implement the next simplest rule in turn. What useful behavior will require the most straightforward, smallest increment of code to implement? 
 
 Each test you write in TDD and get to pass represents a new, working piece of behavior that you add to the system. Aside from getting an entire feature shipped, your passing tests represent your best measures of progress. You name each test to describe the small piece of behavior. 
 
 Uncle Bob's Three Rules of TDD:

- Write production code only to make a failing test pass. 
- Write no more of a unit test than sufficient to fail. Compilation failures are failures. 
- Write only the production code needed to pass the one failing test. 

In TDD, you practice safe coding by testing early and often, so you usually have but one reason to fail. Every time a test passes, it might be a good time to make a local commit. A good version control system allows you to commit easily every time the code is green (in other words, when all tests are passing). Part of the TDD mentality is that every passing test represents a proven piece of behavior that you've added to the system. It might not always be something you could ship, of course. But the more you think in such incremental terms and the more frequently you seek to integrate your locally proven behavior, the more successful you'll be. 

At any given point, your complete set of tests declare the behaviors you intend your system to have. That implies the converse: if no test describes a behavior, it either doesn't exist or isn't intended (or the tests do a poor job of describing behavior). 

The cycle of TDD, once again in brief, is to write a small test, ensure it fails, get it to pass, review and clean up the design (including that of the tests), and ensure the test all still pass. You repeat the cycle throughout the day, keeping it short to maximize the feecback it gives you. Though repetitive, it's not mindless - at each point you have many things to think about. 

A mantra surfaced in the early TDD days that says, "Test everything that can possibly break." This is a glib response to the oft-asked question, "What do I have to test?" Maybe the most important consideration is that we are test-driving, not testing. Using a testing technique, you would seek to exhaustively analyze the specification in question (and possibly the code) and devise tests that exhaustively cover the behavior. TDD is instead a technique for driving the design of the code. Your tests primarily serve the purpose of specifying the behavior of what you will build. The tests in TDD are almost a by-product of the process. They provide you with the necessary confidence to make subsequent changes to the code. The distinction between test-driving and testing may seem subtle. The important aspect is that TDD represents more of a sufficiency mentality. You write as many tests as you need to drive in the code necessary and no more. You write tests to describe the next behavior needed. If you know that the logic won't need to change any further, you stop writing tests. Of course, real experience provides the best determinant. Test-driving for confidence works great until you ship a defect. When you do, remind yourself to take smaller, safer steps. 

## Google Mock

Not only do we want to look at production code for refactoring opportunities, we want to look at the tests, too. If multiple tests require the same line of code to create a test istance, we're not happy with such duplication. It adds up quickly and often turns into more complex duplication. It also clutters the tests, detracting from what's important for a reader to understand. 

It's common for related tests to need common code. Google Mock lets us define a fixture class in which we can declare functions and member data for a related set of tests. (Technically, all Google Mock tests use a fixture that it generates behind the scenes). 

 - TEST() is useful when you want to write unit tests for static or global functions or simple classes
 - TEST_F() is useful when you need access to objects and subroutines in the unit test. 
    - To code a custom fixture, we change the TEST macro invocation to TEST_F, with the F standing for "Fixture." If we forget to use TEST_F, any test code attempting to use fixture member errors will fail compilation. 
 - TEST_P() is useful when you want to write tests with a parameter
 - ASSERT - fails fast, aborting the current function
 - EXPECT - continues after the failure

 
# Installing, Building, and Running

 - cmake -S . -B build
 - cmake --build build
 - cd build && ctest
 
 # Examples
 
 ## Soundex Class
 
Searching is a common need in many applications. An effective search should find matches even if the user misspells words. In this example, we will test a Soundex class that can improve the search capability in an application. The long-standing Soundex algorithm encodes words into a letter plus three digits, mapping similarly sounding words to the same encoding. Here are the rules for Soundex, 
 1. Retain the first letter. Drop all other occurrences of a, e, i, o, u, y, h, w.
 2. Replace consonants with digits (after the first letter). 
    * b, f, p, v: 1
    * c, g, j, k, q, s, x, z: 2
    * d, t : 3
    * l : 4
    * m, n : 5
    * r : 6
 3. If two adjacent letters encode to the same number, encoe them instead as a single number. Also, do so if two letters with the same number are separated by h or w (but code them twice if separated by a vowel). This rule applies to the first letter. 
 4. Stop when you have a letter and three digits. Zero-pad if needed. 


# Other Notes

 - Separating interface (what) from implementation (how) is an important aspect of design and provides a springboard for larger design choices. You want to consider similar restructurings every time you hit the refactoring step in TDD. 
 - The rule of thumb for TDD is one assert per test. Its a good idea that promotes focusing on the behavior of the tests, instead of centering tests around functions. 

# References

 1. [Modern C++ Programming with Test-Driven Development](https://pragprog.com/titles/lotdd/modern-c-programming-with-test-driven-development/)
