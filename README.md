# Summarize the project and what problem it was solving.
The Item Tracker Program is a C++ program that analyzes item purchase data from a grocery store. The main problem it addresses is the need for a simple way to track how often each item is purchased. By reading input data from a file and presenting various outputs frequencies, search results, and a histogram, it helps store staff or managers understand shopping trends and item popularity.

## Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

Potential enhancements include:
Error handling improvements: Use exception handling (try-catch) instead of simple if checks for file I/O failures.
Case-insensitive search: Users might enter item names in different cases, so normalizing the input would make searching more reliable.

## Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

The most challenging part was handling file input/output and ensuring the menu loop worked seamlessly with user input, especially handling invalid input types strings when expecting numbers. I overcame this by Carefully validating user input using cin.fail() Referring to C++ documentation and tutorials for fstream usage and by Testing edge cases manually.

## What skills from this project will be particularly transferable to other projects or course work?

Basic object-oriented programming principles and Creating readable and maintainable code and problem solving
These skills are fundamental and will transfer well to any project involving data parsing, user interfaces, or foundational programming.

## How did you make this program maintainable, readable, and adaptable?

Each function has a single responsibility, improving readability and reusability. Descriptive naming Functions and variables use clear, self-explanatory names.
Proper use of inline comments and consistent formatting helps others quickly understand the code. using object oriented method hleps fix problems faster.


## Menu Options

1: Search for a specific item's frequency
2: Print all item frequencies
3: Print a histogram of item frequencies
4: Exit the program


## Files

- `Source.cpp`: The main source code file
- `CS210_Project_Three_Input_File.txt`: Input file containing a list of purchased items (one per line or space-separated)
- `frequency.dat`: Output file that stores item frequencies



