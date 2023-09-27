# Binary Grid Puzzle Solver 

## Description
The bingrid project is designed to solve binary grid puzzles. These puzzles consist of a grid filled with 1's, 0's, and unknowns (represented as '.'). The solver works by employing certain predefined rules to deduce the value of unknown spots in the grid until a solution is found or it is determined that the puzzle cannot be solved.


## Features
・　Parses input strings representing binary puzzles.

・　Utilizes multiple puzzle-solving rules, such as Pair and Oxo, to deduce unknown values.

・　Outputs the solution in a human-readable format or indicates if no solution can be found.

・　Integrates Address and Undefined Sanitizers for safer development.

## Compilation
### Production build 
```
make bingrid
```
or 
```
make all 
```

To clean up binaries:
```
make clean
```

Certainly! Here's a README.md for the bingrid puzzle solver you provided:

bingrid - Binary Grid Puzzle Solver
Description
The bingrid project is designed to solve binary grid puzzles. These puzzles consist of a grid filled with 1's, 0's, and unknowns (represented as '.'). The solver works by employing certain predefined rules to deduce the value of unknown spots in the grid until a solution is found or it is determined that the puzzle cannot be solved.

Features
Parses input strings representing binary puzzles.
Utilizes multiple puzzle-solving rules, such as Pair and Oxo, to deduce unknown values.
Outputs the solution in a human-readable format or indicates if no solution can be found.
Integrates Address and Undefined Sanitizers for safer development.
Compilation
The Makefile included has directives to produce two different builds:

Production Build: No warnings allowed, optimized.

bash
Copy code
make bingrid
Development Build: Includes sanitizers for better debugging.

bash
Copy code
make bingrid_dev
To build both versions, use:

bash
Copy code
make all
To clean up binaries:

bash
Copy code
make clean
Usage
After compilation, you can run the produced binary with the desired input. Note: As of now, the program reads the puzzle board from the code itself. Future iterations might support reading from files or standard input.

bash
Copy code
./bingrid
or for the development version:

bash
Copy code
./bingrid_dev
Contributing
Feel free to fork this repository and propose changes via pull requests. Make sure to test new features or changes before submitting.




