## CPP00 ex00 - Megaphone

### Required Files
- `Makefile`
- `megaphone.cpp`

### Goal

The program recives command-line arguments and prints them in uppercase.
If no argument is given, it prints:
`* LOUD AND UNBEARABLE FEEDBACK NOISE *` 

### Key Concepts

- `argc` stores the number of command-line arguments.
- `argv` stores the actual arguments.
- `argv[0]` is the program name.
- Real user arguments start at `argv[1]`.
- Each `argv[i]` is a C-style string ending with `'\0'`.
- `std::cout` is the C++ output stream.
- `std::endl` prints a newline.
- `std::toupper` converts one character to uppercase.
- `std::` is needed because these names are inside the standard namespace.
- Do not use `using namespace std;`.
- Do not use `printf`.

### Important Edge Case
Do not blindly add spaces between arguments. Quoted shell arguments can already contain spaces.


### Concepts Explanations

#### 1. Program arguments: `argc` and `argv`
Your `main` can receive command-line arguments like this:
```cpp
int main (int argc, char **argv)
// or
int main (int argc, char *argv[])
```
`argc` means argument count. It tells you how many arguments were passed to the program.
`argv` means argument vector. It stores the actual arguments as C-style strings.

##### Example
```cpp
./megaphone hello world
```
Internally:
```cpp
argc      = 3

argv[0]   = "./megaphone"
argv[1]   = "hello"
argv[2]   = "world"
```

Important: `argv[0]` is the program name. The real user input starts at `argv[1]`.

So for this exercise, your loop should start from index `1`, not `0`.


#### 2. No-argument case
In case of no argument provided when theprogram is called:
```cpp
./megaphone
```
must print:
```cpp
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

#### 3. Output in C++: `std::`cout`
In C, you would use `printf("Hello \");`
In C++, you use:
```cpp
std::cout << "Hello" << std:endl;
```
You will write:
```cpp
std::cout
std::endl
std:toupper
```
because these names live inside the `std` namespace. A `namespace` is like a named container/library for functions, classes, and objects.

The subject forbids:
```cpp
using namespace std;
```

The '<<' operator sends data into the output stream.

##### Example
```cpp
std::cout << "Hello";
std::cout << " ";
std::cout << "world";
std::cout << std::endl;
```

This prints:
```cpp
Hello world
```

`std::endl` prints a newline and flushes the stream, whereas `std::cout << "\n"` just inserts a new line. You can also use `"\n"`, but `std::endl` is common and readable here.

> **Note:** 
> `std::cout << "\n"` looks performance wise better, but in real `std::cout << std::endl` is much better in C++; As it doesn't occupy any memory and also if flushing of stream is required. 

#### 4. Uppercasing characters: `std::toupper`

To use `std::toupper()` you need:
```cpp
#include <cctype>
```
This is `ctype.h` header declares a set of functions to classify and transform individual characters, e.g. `toupper` and `tolower`.

These functions take the `int` equivalent of one character as parameter and return an `int` that can either be another character or a value representing a boolean value: an `int` value of `0` means `false` and an `int` value different from `0` represents `true`.

##### Example
```cpp
char c = 'a'
char upper = std::toupper(c); // returns an int, not char

// to cast it back to char using C++-style cast
std::cout << static_cast<char>(std::toupper(c));
```


### 4. Core Algorithm
```cpp
1. If arc is 1:
        print "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
        return 0

2. Start form argument index 1.

3. For each argument:
        start from character index 0
        while the current character is not '\0':
            convert character to uppercase
            print it
            move to next character

4. After all arguments are printed:
        print newline

5. return 0
```





### Notable Resources
- https://cplusplus.com/reference/cctype/