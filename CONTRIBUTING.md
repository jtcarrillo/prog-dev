# Git Commit Guidelines

This document provides guidelines for git commit frequency and commit message formatting.
The commit messages written today will likely differ from those written in a year.
Nonetheless, developers are strongly recommended to follow the guidelines laid out
at the time of their commits.

## When to Commit

There are no hard rules about when to commit. There are discussions throughout the
internet on this topic the. Here's [one](https://softwareengineering.stackexchange.com/questions/74764/how-often-should-i-do-you-make-commits). That being said, this section is not as important to follow as the next.

Treat commits like punctuations: They mark the end of discrete work efforts. What
constitutes as a work effort may be large or small. You add a new function to a sensor class and it compiles, commit. You fixed a typo in a comment, commit.

Avoid committing broken code like you avoid incomplete sentences. Although sometimes it might be necessary, for example,
if you want someone else to look over your code.

You are not the Faulkner of programming. Avoid *run-on commits*. That is, commit often. For example,
if you are creating a new class, you should be able to break down its creation into smaller discrete
efforts.

## Commit Messages

These guidelines are primarily based on recommendations provided by Chris Beams in
his blog post ["How to Write a Commit Message"](https://chris.beams.io/posts/git-commit/).
Chris provides seven rules for writing great Git commit message. They are listed below.
The eighth is modified from *Angular*'s [contribution guidelines](https://github.com/angular/angular/blob/master/CONTRIBUTING.md#-commit-message-guidelines).  
 1. [Separate subject from body with a blank line](https://chris.beams.io/posts/git-commit/#separate)
 1. [Limit the subject line to 50 characters](https://chris.beams.io/posts/git-commit/#limit-50)
 1. [Capitalize the subject line](https://chris.beams.io/posts/git-commit/#capitalize)
 1. [Do not end the subject line with a period](https://chris.beams.io/posts/git-commit/#end)
 1. [Use the imperative mood in the subject line](https://chris.beams.io/posts/git-commit/#imperative). This means that subject lines should read like commands. As examples, each rule in this list is given in the imperative mood.
 1. [Wrap the body at 72 characters](https://chris.beams.io/posts/git-commit/#wrap-72). In other words, lines should be no longer than 72 characters. Some IDEs demarcate this limit.
 1. [Use the body to explain the _what_ and _why_ of the change](https://chris.beams.io/posts/git-commit/#why-not-how). Describe what changes where made. If possible, why. (It might be as simple as, "Typo removed to improve clarity")
 1. [Describe the type of commit](https://github.com/angular/angular/blob/master/CONTRIBUTING.md#-commit-message-guidelines). This helps with organization. See below for types list.

### Types

* **feature**:  Code change adds new feature (e.g. new function, class, etc)
* **docs**: Documentation only changes
* **fix**: A bug fix
* **refactor**: A code change that neither fixes a bug nor adds a feature
* **style**: Changes that do not affect the meaning of the code (white-space, formatting, missing semi-colons, etc)
* **test**: Adding missing tests or correcting existing tests

### Example 1
This comes from Chris's website.

        docs: Summarize changes in around 50 characters or less

        More detailed explanatory text, if necessary. Wrap it to about 72
        characters or so. In some contexts, the first line is treated as the
        subject of the commit and the rest of the text as the body. The
        blank line separating the summary from the body is critical (unless
        you omit the body entirely); various tools like `log`, `shortlog`
        and `rebase` can get confused if you run the two together.

        Explain the problem that this commit is solving. Focus on why you
        are making this change as opposed to how (the code explains that).
        change? Here's the place to explain them.

         Further paragraphs come after blank lines.

         - Bullet points are okay, too

         - Typically a hyphen or asterisk is used for the bullet, preceded
           by a single space, with blank lines in between, but conventions
           vary here



### Example 2
This sample commit message will be used when committing this markdown
document.

        docs: Add a git commit guidelines markdown

        Added a markdown file with git commit guidelines. The file discuses two
        major topics
        * when to commit messages.
        * how to write a commit message.
        Document includes links to internet sources.

        Addition of commit guidelines was deemed necessary as part of VANE’s
        redevelopment. Experience developing “old VANE,” now the VANE Native
        Sensor Engine, proved that the no rules approach was sloppy and
        unsustainable.
