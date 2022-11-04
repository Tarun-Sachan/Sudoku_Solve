Introduction

This is a simple C++ program which give one of the possible solution for any given valid Sudoku Puzzles.

    Sudoku Solver
        Getting Started (Usage)
        How It Works
        Tools

Sudoku-Solver

This is a program which solves 9x9 Sudoku puzzles. Written completely in C++ and built from scratch, this program reads input from a user. It employs concepts such as backtracking and recursion.

Getting Started

    Simply download the sudoku-solver.cpp file found in the Sudoku-Solver/ directory. Run it using any standard C++ compiler. In case of any errors or compatibility issues, submit an issue in this git.

    Once downloaded, compiled and run; the program will require the user to input the Sudoku puzzle into it. There are two ways to do this.

        The user can either input the values manually one-by-one when the program is running.

        The user can write all the values into a file, seperated by whitespaces and provide the input at once.

        9 0 0 0 2 0 7 5 0 
        6 0 0 0 5 0 0 4 0 
        0 2 0 4 0 0 0 1 0 
        2 0 8 0 0 0 0 0 0 
        0 7 0 5 0 9 0 6 0 
        0 0 0 0 0 0 4 0 1 
        0 1 0 0 0 5 0 8 0 
        0 9 0 0 7 0 0 0 4 
        0 8 2 0 4 0 0 0 6

    Once solved, the Sudoku puzzles shall be displayed like this.

    9 4 1  | 3 2 6  | 7 5 8
    6 3 7  | 1 5 8  | 2 4 9
    8 2 5  | 4 9 7  | 6 1 3
    ---------------------------
    2 6 8  | 7 1 4  | 3 9 5
    1 7 4  | 5 3 9  | 8 6 2
    3 5 9  | 6 8 2  | 4 7 1
    ---------------------------
    4 1 3  | 2 6 5  | 9 8 7
    5 9 6  | 8 7 3  | 1 2 4
    7 8 2  | 9 4 1  | 5 3 6

How It Works

This particular algorithm employs the use of backtracking, one of the more common methods to solve Sudoku puzzles. I've written a simple algorithm to give an idea of how the program works.

    Start.
    We start with the first empty cell.
    We generate a list of possible valid values that can be filled in that cell.
    We iterate over this list and start with the first value. This value is placed in the required cell.
    We move on to the next cell. We again generate a list of possibilities. However, if no list can be generated, then this means that there is something wrong     with the value of the previous cell. We then move back to the previous cell and place the next value on the generated list in the cell now. We repeat this       step until the current cell has a valid value placed inside it.
    We stop when we reach the 81st cell (the last cell in a Sudoku puzzle) and have placed a valid value.
    The puzzle has now been solved.
    Stop.


Future Direction

    Right now, the Sudoku Solver is just a CLI application with a I/O interface. However, if we could make a GUI interface which takes inputs that would make it easier for the user to input valuse.
    I was thinking to make a random Sudoku puzzle generator which user has to solve in a given timeframe according to difficulty selected. The generated sudoku will be totally random with a GUI instead of CLI.
    

Tools

    Visual Studio Code
    

