# Assignment 2 - Wash
Design due: Tuesday 2/12<br>
Final due: Thursday 2/21

# Goal
The goal of this assignment is to play with low-level file IO in C.

# Incomplete Analysis
Mr. Krabs needs a program to help him clean up and organize his files. 
In other words, he needs you to write a program named ```wash```. 
This program processes a list of files one at a time. 
The file's names are provided to the program on the command line. 
It supports the following commands. 

- 'c' cat, list the current file contents to ```/dev/tty``` 
- 'd' duplicate the current file, which creates a copy of the file 
- 'r' rename the current file 
- 'u' unlink the current file, which typically deletes the file 
- 't' truncate the current file, which makes the file length zero 
- 'a' append the current file to another file 
- 'l' last, display the last 100 bytes, or fewer if fewer exist, of the current file 
- 'm' mode, change the current file's access mode 
- 'n' next, goto the next file name 
- 'q' quit 

# Example Run

In the example run below, italized text was typed in by the user, the rest is output by the program

$ *ls -l*<br>
-rw-r--r-- 1 binkley binkley 16 Jan 30 16:05 a<br>
-rw-r--r-- 1 binkley binkley  8 Jan 30 16:05 b<br>
$ *wash a b*<br>
file a: command: *c*<br>
this is file a<br>
file a: command: *d*<br>
enter destination name: *aa*<br>
file a: command: *n*<br>
file b: command: *r*<br>
enter new name: *b2*<br>
file b: command: *q*<br>
$ *ls -l*<br>
total 56<br>
-rw-r--r--  1 binkley binkley 16 Jan 30 16:05 a<br>
-rw-r--r--  1 binkley binkley 16 Jan 30 16:07 aa<br>
-rw-r--r--  1 binkley binkley  8 Jan 30 16:05 b2<br>

# Design
Due: Tuesday 2/12

You likely don't have enough information to complete this assignment and ultimatly you will need to make sure your program works. Thus, your Design Phase has two tasks:
1. Come up with some questions you need answered. 
2. Come up with tests you should be running. 

Submit the following to GitHub:
1. A fully fleshed out black-box test plan for a single *wash* command. This plan should extend the one started in **testPlan.txt**.
2. A list of analysis questions in **questions.txt**.

# Additional Requirements
In addition to Mr. Krabs's requirements, I will impose a few of my own:
- Your program should include reasonable HCI such that the user does not have to guess what they are supposed to do.
- Your program should be silent on success (except where such silence conflicts with good HCI).
- You should include full error checking for all kernal and librariy calls. Use ```perror``` to print error messages.
- You may not use ```system```, ```fork```, or ```exec```.
- Follow good SE practices (e.g., function headers, variable naming conventions, etc.)

# Final Submission
Due: Thursday 2/21

Submit to GitHub:
1. All of your code (WITHOUT derivable files). 
2. A Makefile so that I can run ```make``` and not have to worry about how to compile your project. The Makefile must have at least two targets:
    - *wash* should create the ```wash``` executable
    - *clean* should clean up the directory to remove any derivable files
3. A file named **wash.out** that captures the output of you running your test plan after using the ```script``` command.
