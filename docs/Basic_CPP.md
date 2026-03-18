# CPP Basics

## 1. Introduction

### 1.1 Statements and Program Structures
- A computer **program** is a sequence of instructions. A **statement** is a type of instructions for performing some action.
- Statement is the **smallest unit** of computation in C++ and end (mostly) in a semicolon.
- **Functions** is a collection of statements that get executed sequentially.
- Every C++ program must have a special function named `main`.
- The name of a function is called its **identifier**.

```c++
#include <iostream>

int main()
{
    std::cout << "Hello world!";
    return 0;
}
```
- The `#include` line is called **preprocessor directive** to indicate that we use the contents of `iostream` library, in this case the `std::cout`.
- `std::cout << "Hello world!";` reads as "`cout` send `Hello world` to the output stream."
  - `stdout:cout` is an output stream.
  - `<<` is called **insertion operator/stream insertion** and inserts data into the stream.
  - `Hello world!` is what you're inserting.

### 1.2 Comments
- `//` is used for single-line comments.
- `/* ... */` is used for multi-line comments.

### 1.3 Objects and Varibles
- **Data** is any information that can be moved, processed, or stored by a computer.
- A single piece of data is called a **value**.
- Values that are placed directly into the source code are called **literals**.
```c++
#include <iostream>

int main()
{
    std::cout << 5; // print the literal number `5`
    return 0;
}
```
- In C++, direct memory access is dicouraged. Instead, we access memory indirectly through objects.
- An **object** is a region of storage (typically RAM or a CPU register) that can hold a value. Objects also have associated **properties**.
- An object with a name is called a **variable**.
```c++
int x; // define a variable named x (of type int)
```
- At **runtime** (when the program is loaded into memory and run), each object is given an actual storage location (such as RAM or a CPU register). The process of reserving storage for an object's use is called **allocation**.
- There are multiple ways to define variables:
```c++
int a;
int b;
// is effectivelly the same as:
int a, b;

int a, int b; // wrong (compiler error)

int a; double b; // correct (but not recommended)
// correct and recommended
int a;
double b;
```

### 1.4 Variable Assignment and Initialization
- The process of giving a variable a value is called **assignment** (using the **assignment operator** `=`);
```c++
int width; // definition
width = 5; // assignment
width = 7; // another assignment
```
- These two steps can be combinded. The process of specifying an initial value for an object is called **initialization**, and the syntax used to initialize an object is called an **initializer**.
```c++
int width {5}; // define variable width and initialize with initial value 5
// {5} is the initializer
// 5 is the initial value
```
- There are 5 common forms of initialization in C++:
```c++
// Default-initialization (no initializer)
int a;

// Traditional initialization forms:
// copy-initialization
int b = 5;
// direct-initialization (used in explicit casting)
int c (6);

// Modern initialization forms (preferred?):
// direct-list-initialization (provide a way to  initialize objects with a list of values)
int d {7};
// value-initialization (empty braces)
int e {};
```
- List-initialization disallows **narrowing conversion**, means that you can only list-initialize a variable using a value that the variable can safely hold.
```c++
int a1 {4.5}; // compiler error: list-init does not allow narrowing conversion

int a2 = 4.5; // compiles: copy-init to value 4
int a3 (4.5); // compiles: direct-init to value 4
```
- This restriction on narrowing conversions only applies to the list-initialization, **not** to any subsequent assignments to the variable:
```c++
int a1 {4.5}; // compiler error: list-init does not allow narrowing conversion

a1 = 4.5; // okay: copy-assignment allows narrowing conversion of 4.5 to 4
```

- **Zero-initialization** happends when a variable is initialized using an empty set of braces, thus the value-initialization will implicitly initialize the variable to zero (or whatever value is closest to zero for a given type).
```c++
int width {}; //value-initialization/zero-initialization to value 0
```
- For class types, value-initialization (or default-initialization) may instead initialize the object to predefined default values, which may be non-zero.

### 1.5 `iostream`: `cout`, `cin` and `endl`

- `std::out` can both print text,numbers, and values of variables
```c++
#include <iostream>

int main()
{
    std::cout = "Hello world!"; // print out "Hello world!"
    std::cout = 4; // print out 4

    int x {5};
    std::out << 5; // print out value of x (5)

    return 0;
}
```
- To print more than one thing on the same line, the insertion operator (`<<`) can be used multiple times in a single statement.
```c++
#include <iostream>

int main()
{
    std::cout << "Hello" << " world!";

    int x {5};
    std:cout << "x is equal to: " << x;

    return 0;
}
```
- One way to output a newline is to output `std::endl`.
```c++
#include <iostream>

int main()
{
    std::cout << "Hi!" << std::endl;
    std::cout << "My name is Alex." << std::endl;

    return 0;
}
```
- `std::out` is buffered, which means if your program crashes, aborts, or is paused (e.g. for debugging) before the buffer is flushed, any output still waiting in the buffere will not be displayed.
- To output a newline without flushing the output buffer, we use `\n` to move the cursor to the next line without causing a flush (perform better).
```c++
#include <iostream>

int main()
{
    int x {5};
    std::cout << "x is equal to: " << x << '\n';
    std::cout << "Yep."<< "\n";
    std::cout << "And that's all, folks!\n"

    return 0;
}
```
- `std::cin` reads input form keyboard. We typically use dthe extraction operator `>>` to put the input data in a variable.
```c++
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";

    int x {}; // define a var x to hold user input and value-initialize it
    std::cin >> x; // get number from keyboard and store it in variable x
    std::cout << "You've entered " << x << '\n';

    return 0;
}
```
```c++
#include <iostream>

int main()
{
    std::cout << "Enter two numbers sepaated by a space: ";

    int x {};
    int y {};

    std::cin >> x >> y; // get two numbers and store in variable x and y respectively

    std::cout << "You've entered " << x << " and " << y << '\n';

    return 0;
}
```
- `std::in` is buffered because it allows us to separate the entering of input from the extract of input. We can enter input once and then perform multiple extraction requests on it.
- Any non-extracted characters (including newlines) remain available for the next extraction attempt, e.g.:
```c++
int x {};
std:cin >> x;
```
- If the user types `5a`and enter, `5a\n` will be added to the buffer. `5` will be extracted, converted to an integer, and assigned to variable `x`. `a\n`will be left in the input buffer for the next extraction.
- If the user types `b` and enter, `b\n` will be added to the buffer. Because `b` is not a valid integer, no characters can be extracted, so this is an extraction failure. Variable `x` would be set to `0`, and future extractions will fail until the input stream is cleared.
- if `std::cin` is not in a good state due to a prior failed extraction, nothing happens here. The valuea of varible `x` is not altered.

### 1.6 Expressions
- An **expression** is an non-empty sequence of literals, variables, operators, and function calls that calculates a value.
- The process of executing an expression is called **evaluation**, and the resulting value produced is called the **return value**.
- **Side effect** is an observable effect of an operator or function beyond producing a return value.
  - Since assignment has the observable effect of canging the value of an object, this is considered a side effect.
  - Some operators (e.g. the assignment operator) are primarily used for their side effects (rather than the return value produced).
```c++
x = 5 // has the side effect of assigning 5 to x, evalates to x
x = 2 + 3 // has side effect of assigning 5 to x, evaluates to x
std:cout << x // has side effect of printing value of x to console, evaluates to std::cout
```

## 2. Functions
- The most basic syntax to define a **user-defined** function:
```c++
returnType functionName() // function header
{
    //function body
}
```
```c++
#include <iostream>

void doPrint()
{
    std::cout << "In doprint()\n";
}

int main()
{
    std::cout << "Starting main()\n";
    doPrint();
    std::cout << "Ending main()\n";

    return 0;
}
```
- C++ does **not support nested function**.
- In C++, there are two special requiremtns for `main()`:
  - `main()`is required to return an `int`.
  - Explicit function calls to `main()` are disallowed.
- The C++ standard only defines the meaning of 3 status codes: `0` or `EXIT_SUCCESS` and `EXIT_FAILURE`.
- `main()` will implicitly return `0` if no return statement is provided.
- C++ code compiles sequentially (top to bottom). So it can only reference a function that has been declared beforehand and known to be in the same file.
- Alternatively, we can use **forward declaration**.
```c++
#include <iostream>

int add(int x, int y); // forward declaration of add() (using a function declaration)

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n'; // this works because we forward declared add() above
    return 0;
}

int add(int x, int y)
{
    return x + y;
}
```
### The One Definition Rule (ODR)
1. Within a *file*, each function, variale, type, or template in a given scope can only have one definition. Definitions occuring in different scopes (e.g. local variable defined inside different functions, or functions defined inside different namespaces) do not violate this rule.
Violation will cause compiler to issue a **redefinition error**.
2. Within a *program*, each function or variable in a given scope can only have one definition. This rule exists because programs can have more than one file.
Violation will cause compiler to issue a **redefinition error**.
3. Types, templates, inline functions, and inline variables are allowed to have duplicate definitions in different files, so long each definition is identical.
Violation will cause **undefined behaviour**.

Example of a violation of part 1:
```c++
int add(int x, int y)
{
     return x + y;
}

int add(int x, int y) // violation of ODR, we've already defined function add(int, int)
{
     return x + y;
}

int main()
{
    int x{};
    int x{ 5 }; // violation of ODR, we've already defined x
}
```


# Core Concepts for Exercise 00

To complete this exercise, it is essential to understand how C++ handles input/output, namespaces, and basic string manipulation.

## 1. Namespaces and `std::`
In C, functions like `printf` are global. In C++, most standard library functions are grouped into `std` (standard) namespace to prevent naming collisions.
- **Accesing members:** Use the scope resolution operator `::` toaccess items in a namespace (e.g., `std:cout`).
- **Note:** The exercise instruction explicitly **forbid** using the `using namepace <name>` keyword. You must always use the explicit `std::` prefix.

### 1.1 What is a Namespace?
In C, all global functions and variables share a single global scope. If you have two libraries that both define a function named `print()`, you will face a **naming collision**, and your program will fail to link.

A **namespace** in C++ acts like a "container" for identifiers (functions, classes, variables). It creates a separate scope region that allows you to use the same name in different context without conflict.

### 1.2 The `std` Namespace
To prevent your code from accidentally conflicting with standard library functions, C++ moves almost all its standard functionality into a namespace called `std` (short for "standard").
- Instead of just `cout`, the full name is `std::cout`.
- The `::` is the **scope resolution operator**, which tells the compiler exactly which namespace to look in.

### 1.3 Accessing Namespaces
There are three ways to access items in a namespace, one of them is explicitely forbidden to use within the scope of this project:
| Method                 | Syntax Example          | Exercise Status |
| ---------------------- | ----------------------- | --------------- |
| Explicit Qualification | `std::cout << "Hello";` | REQUIRED        |
| Using-Declaration      | `using std::cout;`      | Check Rules     |****
| Using-Directive        | `using namespace std;`  | FORBIDDEN       |


### 1.4 Why `using namespace std;` is Forbidden
The `using namespace std;` directive "dumps" every single name from the `std` namespace into your global scope. This completely defeats the purpose of having namespaces.
- **Insidious Bugs:** If you update a library and it introduces a new function with the same name as one of yours, your program might suddenly stop compiling or, worse, change its behaviour silently.
- **Standard Practice:** In professional C++ development, you are expected to be explicit about where your functions come from.

### 1.5 Practical Example for ex00
For the "Megaphone" exercise, everytime you use a standard function or object, you must prefix it:
```C++
#include <iostream> // Header for I/O
#incldue <cctype>   // Header for character manipulation (like toupper)

int main(int argc, char **argv) {
    // Correct way: Explicitly use the std:: namespace
    std::cout << "MESSAGE";

    // Using a function from the standard library (C-style but in std)
    char c = std::toupper('a');
    return (0);
}
```

By following this "explicit qualification" rule, you ensure your code is compliant.

## 2. Input/Output Streams (`iostream`)
C++ uses "streams" for I/O instead of `printf` and `scanf`. You must include the `<iostream>` header.
- `std::cout`: Used for standard output.
- `<<` **(Insertion Operator):** Used to sed data to `std::cout`.
- `std:endl` vs `\n`: Both add a newline. `std:endl` also "flushes" the buffer (forces output immediately), which is slower than just using the `\n` character.
- **Example**:
```C++
#include <iostream>
int main() {
 std::cout << "Hello " <<
}
```
