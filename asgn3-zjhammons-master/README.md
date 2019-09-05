# Assignment 3 - A list of WHAT?
Design Due: Tuesday 2/26    
Final Due: Thursday 3/14

# Goal
To gain experience with:
* a linked list in C
* structs in C

# Problem
You are CTO of LUM Games and you have two hot new games coming to market. The first game is a card game and the second is a soccer game. In both cases, these games involve collections of objects (i.e., a hand of cards or a team a players). You are going to be responsible for implementing both collections using a linked list.

# Analysis
*\[Software Engineers first attempt to determine **WHAT** is to be done (analysis) before determining **HOW** to do it (design).\]*

## What is a card?
A card includes a suit: Spades, Hearts, Diamonds, Clubs, and a rank: 2-9, Jack, Queen, King, Ace.

## What is a soccer player?
A Soccer player is represented by a position, a uniform number, and a number of goals scored.

## What operations should our linked list support?
You must be able to do the following with your list:
* Create an empty list
* Insert at the beginning
* Insert at the end
* Find an object in the list
* Print the list
* Delete an item from the list

I have provided the skeleton of a main program to demonstrate functionality of the list. This skeleton will need major changes.

# Design
Design Due: Tuesday 2/26

1. Create a set of milestones. Each milestone should include a test case or test cases to ensure that you have correctly reached that milestone before moving on to the next bit of coding. These milestones would be good times to commit to GitHub (you can see commits using the ```git log``` command, if you are curious).  Test cases should have the same form as in assignment 2: in, out, rationale. Place your milestones in ***milestones.txt*** in your GitHub repo. 
2. Come up with additional analysis questions that you need answered. Place these questions in ***questions.txt*** in your GitHub repo.

# Final submission
Final Due: Thursday 3/14

Your GitHub repo should contain:
1. A ```Makefile``` that I can use to run ```make clean``` and ```make all``` to remove derivable files and create all needed executables, respectively. You should generate two (2) executables: one for cards and one for soccer players. I have provided a file that should serve as an execellent starting point. You may not need to make any changes depending on your implementation.
2. The files created in your Design and all necessary source code. 
3. A file named [Design.md](Design.md "Design of the list") that contains Markdown decribing any design decisions you made.
4. *Either* ***script.out*** (from the ```script``` command) or ***script.sh*** (a stand alone bash script) to demonstrate at least the first six (6) of your test cases for your final products.
5. A file named ***memwatch.log*** containing the output of memwatch for the cleanest of your two programs. The goal is no anomalies.
