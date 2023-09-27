# Binary Grid Puzzle Solver 

Description
The bingrid project is designed to solve binary grid puzzles. These puzzles consist of a grid filled with 1's, 0's, and unknowns (represented as '.'). The solver works by employing certain predefined rules to deduce the value of unknown spots in the grid until a solution is found or it is determined that the puzzle cannot be solved.


A Binary Grid is a 2D square grid of cells, each of which is either empty, or contains the
value 0 or 1. A set of rules governs what is legal in a valid board :

• Each cell should contain either a zero or a one.

• No more than two of the same number can appear consecutively in a row or a column.

• There must be an equal number of 0s and 1s in each row and column - this means that the height/width of the puzzle must be even.

Given these rules1 we can deduce some principles to help us find a solution:

Pairs : If two of the same number (0s or 1s) are in adjacent cells (either horizontally or vertically) then the two surrounding cells on either side must  be the other number, otherwise there would be three of the same number in sequence.

OXO : If there are two of the same number with a gap of one empty cell between them (horizontally or vertically), then the opposite number must be in the empty cell (otherwise we’d have three of the same number in sequence).

Counting : If all of a particular number have been found in a row (or column) - that is 3 if the grid is a 6x6, then the remaining 3 unknown cells must all contain the other number. 
