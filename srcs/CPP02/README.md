# CPP02

This project has been created as part of the 42 curriculum by fyudris.

## CPP02

Ad-hoc polymorphism, operator overloading, fixed-point numbers, and the Orthodox Canonical Form in C++98.

## Description

CPP02 introduces the Orthodox Canonical Form and operator overloading through the implementation of a custom fixed-point number class.

The project starts with a basic `Fixed` class that stores a raw fixed-point value, then extends it with integer and floating-point conversions, comparison operators, arithmetic operators, increment/decrement operators, and a simple point-in-triangle check using a `Point` class.

The project is written in C++98 and compiled with:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

## Goal

Understand how to design classes in Orthodox Canonical Form, how fixed-point numbers work internally, and how to overload operators so custom classes can behave like built-in numeric types.

## Key Concepts

```
Orthodox Canonical Form
Default constructor
Copy constructor
Copy assignment operator
Destructor
Fixed-point numbers
Raw bits and fractional bits
Integer and float conversion
roundf
Const correctness
Operator overloading
Comparison operators
Arithmetic operators
Pre-increment and post-increment
Pre-decrement and post-decrement
Static member functions
References and const references
Insertion operator overload
C++98-compatible code
Doxygen-style comments
```

## Exercises

```
ex00 - My First Class in Orthodox Canonical Form
ex01 - Towards a more useful fixed-point number class
ex02 - Now we’re talking
```

## Compilation

Enter an exercise folder and run:

```bash
make
```

Useful rules:

```bash
make
make clean
make fclean
make re
```

## Resources

- https://www.learncpp.com/
- https://www.w3schools.com/cpp/

## AI Usage

AI was used as a learning support tool during this project to better understand C++98 concepts, subject requirements, fixed-point number theory, Orthodox Canonical Form, and operator overloading. The final code was written, reviewed, tested, and adapted manually by the project author.
