# Number Guessing Game
## Overview

This is a C program that implements a number guessing game with multiple difficulty levels and colorful terminal output. The user selects a range, and the program generates a random number within that range. The user then tries to guess the number within 10 attempts, with optional clues and a scoring system based on the number of tries.

## Features

- **Difficulty Levels:**  
  - Easy: Range < 100  
  - Medium: 100 ≤ Range < 1000  
  - Hard: 1000 ≤ Range ≤ 10000

- **Clues:**  
  - Option to reveal the number of digits in the random number.  
  - After 5 incorrect tries, option to reveal the last digit.

- **Scoring:**  
  - Score decreases with the number of attempts (from 100 down to 10).

- **Colorful Output:**  
  - Uses ANSI escape codes for colored and bold text.

- **Replay Option:**  
  - User can play multiple rounds.

- **Time Tracking:**  
  - Displays the time taken to guess the correct number.

## How to Compile

```sh
gcc b23me1017.c -o b23me1017
```

## How to Run

```sh
./b23me1017
```

## Usage

1. Enter the maximum range for the random number.
2. Choose whether to receive a clue about the number of digits.
3. Enter your guesses. After 5 incorrect tries, you can get a clue about the last digit.
4. Try to guess the number within 10 attempts.
5. View your score and time taken.
6. Choose to play again or exit.

## Example Output

```
Enter the MAX Range you want to guess from
500
You selected MEDIUM LEVEL
Do you want a clue? 'Y' or 'N'
Y
Number of digits is 3
Enter your Guess:
...
```

---
