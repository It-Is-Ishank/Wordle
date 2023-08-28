# Wordle Game Project

## Project Description

The Wordle Game Project is a C programming project that implements a simple text-based word guessing game. Players are tasked with guessing a 5-letter word within a limited number of attempts. The game provides hints in the form of letters ('G' for correct letter and position, 'Y' for correct letter but wrong position, '-' for incorrect letter) to guide players towards the correct answer.

## Goals

The primary goals of this project are:

1. Implement a functional word guessing game in C.
2. Demonstrate C programming concepts, including input handling, string manipulation, loops, and file I/O.
3. Provide an interactive and engaging experience for players.

## Specifications

The Wordle Game has the following specifications:

- The game is implemented in C programming language.
- The game randomly selects a 5-letter word from a list of words stored in a "words.txt" file.
- Players have a maximum of 6 attempts to guess the correct word.
- After each guess, the game provides hints ('G', 'Y', '-') to guide players towards the correct word.
- The game accepts player input, validates it, and provides appropriate feedback.
- At the end of the game, the player is given the option to play again or exit.

## Design

The project is organized as follows:

- The main game loop is implemented in the `game()` function.
- Player input and validation are handled by the `getInp()` function.
- Letter case conversion is performed by the `toLowerCase()` function.
- Checking the correctness of the guess is done by the `checkGuess()` function.
- The list of words is read from "words.txt" using file I/O.

## How to Run

To play the Wordle Game:

1. Compile the C code using your preferred compiler.
2. Ensure the "words.txt" file is present in the same directory as the compiled executable.
3. Run the executable to start the game.
4. Follow the on-screen instructions to play the game.

## Acknowledgments

The word list used in the game is sourced from the "words.txt" file included in the project.

---

**Note:** This README provides a brief overview of the project. For detailed code implementation, refer to the source code files provided in the repository.
