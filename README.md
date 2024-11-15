
# Master Mind

classic code-breaking game Mastermind, designed for two players. In this game:

Objective: Player 1 creates a secret code consisting of 5 unique digits (0-9), while Player 2 tries to guess this code within a limited number of attempts.

Gameplay:

Player 1 inputs a secret code, which remains hidden from Player 2.
Player 2 then has up to 20 attempts to guess the code, receiving feedback after each attempt:
Good Place: Indicates the number of digits that are both correct and in the correct position.
Bad Place: Shows the number of correct digits that are in the wrong position.
Joker Feature: After several failed attempts, Player 2 can use a "Joker" to reveal one digit of the code, with limited usage per game.
Difficulty Levels:

The game offers three difficulty levels:
Baby: An introductory level to ease into the rules.
Normal: A standard difficulty where hints are limited.
Nightmare: The highest difficulty (yet to be fully implemented), which might impose additional challenges like restricted guesses or extra constraints.
Scoring: Scores are calculated based on the number of attempts made by Player 2 and saved to a file for each level.

This game emphasizes logical deduction and memory, challenging players to crack the code using minimal hints within a limited number of tries.






## Features
 - Three difficulty levels: Baby, Normal, and Nightmare, each with unique challenges.
- Joker option for limited hints, allowing Player 2 to reveal a specific digit after multiple failed attempts.
- Real-time feedback on guesses, showing correct numbers in both right and wrong positions.
- Scoring system based on attempts, with scores saved to files for tracking performance.
- Color-coded text to enhance readability and make gameplay more engaging.

# Tech Stack
- C Programming Language for core game logic and console operations.
- Standard Libraries (stdio.h, stdlib.h) for input/output and system commands.
- ANSI Escape Codes for adding color to text and improving user experience.
- File Handling for saving player scores in text files.
