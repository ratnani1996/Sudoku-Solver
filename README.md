# Sudoku-Solver
This is a simple sudoku program. You have to input the 9x9 sudoku manually, for blank spaces input value 0.
This solver uses backtracking algorithm.
What it does is it fills the unknown value with a valid number. A valid number in a sudoku is a number which does not lies in the whole row or column or in it's 3x3 grid.
It checks a number for it's validity then assign it with the value. The main catch here is if the number is not a valid number and can be placed at that particular time it places it with the invalid number and moves to the next. Then it later comes back to it's position and puts a number until a valid number is places, this is done with help of bactracking. This algorithm is repeated until we get the results.
