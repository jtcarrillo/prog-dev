# Test-Driven Development Fundamentals

Module 1_Basics shows what TDD should look like in practice with a considerable number of concepts and good practices. This module will explore topics in more detail:

 - The definition of unit
 - The TDD cycle of re-green-refactor
 - The three rules of TDD
 
 ## Unit Test and TDD Fundamentals
 
 TDD results in unit tests. A unit test verifies the behavior of a code unit, where a unit is the smallest testable piece of an application. 
 
 A single unit test consists of a descriptive name and a series of code statements, conceptually divided into four ordered parts. 
 
 1. (Optional) Statements that set up a context for execution
 2. One or more statements to invoke the behavior you want to verify
 3. One or more statements to verify the expected outcome
 4. (Optional) Cleanup statements 
 
 Some people may refer to the three parts as Given-When-Then: Given a context, When the test executes some code, Then some behavior is verified. Other developers might call this breakdown Arrange-Act-Assert. 
 
 Typically you group related tests in a single source file. Google Mock, like most unit testing tools, allows you to logically group unit tests into fixtures. You might start with one fixture per C++ class being test-driven. 
 
 In contrast to plain ol' unit testing (POUT), TDD is a more concisely defined process that incorporates the activity of unit testing. When doing TDD, you write the tests first, you strive to keep the granularity of tests small and consistent and you seek myriad other benefits - most importantly the ability to safely change existing code. 
 
 You don't seek to write tests that cover a wide swath of functionality. The responsibility for such end-to-end tests lies elsewhere, perhaps in the realm of acceptance tests/customer tests or system tests. The term often used for such test against such aggregate code behavior is integration tests. Integration tests verify the code that must integrate with other code or with external entitites (the file system, databases, web protocols, and other APIs). In contrast, unit tests allow you to verify units in isolation from other code. 
 
 ## The TDD Cycle: Red-Green-Refactor
 
 When doing TDD, you repeat a short cycle of the following:
 
 1. Write a test ("red")
 2. Get the test to pass ("green")
 3. Optimize the design ("refactor")
 
You refactor when you improve your code's design without changing its behavior, something that having tests allows you to safely do. 

At each point in the TDD cycle, you must be able to answer many questions. 

* __*Write a small test.*__ What's the smallest possible piece of behavior you can increment the system by? Does the system already have that behavior? How can you concisely describe the behavior in the test's name? Does the interface expressed in the test represent the best possible way for client code to use the behavior? 
* __*Ensure the new test fails.*__ If it doesn't why not? Does the behavior already exist? Did you forget to compile? Did you take too large a step in the prior test? Is its assertion valid? 
* __*Write the code you think makes the test pass.*__ Are you writing no more code than needed to meet the current set of behaviors specified by the tests? Are you recognizing where the code you just wrote will need to be cleaned up? Are you following your team's standards? 
* __*Ensure all the tests pass.*__ If not, did you code things incorrectly, or is your specification incorrect? 
* __*Clean up the code changes you just made.*__ What do you need to do in order to get your code to follow team standards? Does your new code duplicate other code in the system that you should clean up, too? Does the code exhibit questionable smells? Are you following good design principles? What else do you know about design and clean code that you should apply here? Otherwise, is the design evolving in a good direction? Does your code change impact the design of other code areas that you should also change? 
* __*Ensure the test all still pass*__ Do you trust that you have adequate unit test coverage? Should you run a slower set of tests to have the confidence to move on? What's the next test? 

## The Three Rules of TDD

1. Write production code only to pass a failing unit test. 
2. Write no more of a unit test than sufficient to fail (compilation failures are failures). 
3. Write no more production code than necessary to pass the one failing unit test. 


 
