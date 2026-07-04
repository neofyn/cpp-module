# C++ Modules Notes

# Table of Contents
- [C++ Modules Notes](#c-modules-notes)
- [Table of Contents](#table-of-contents)
- [General Notes](#general-notes)
	- [🔸Headers](#headers)
	- [🔸Name Formatting](#name-formatting)
	- [🔸Makefile](#makefile)
	- [🔸Organization](#organization)
- [📣 CPP00 ex00 - Megaphone](#-cpp00-ex00---megaphone)
	- [🔸Goal](#goal)
	- [🔸 Important Edge Case](#-important-edge-case)
	- [🔸 Concepts Explanations](#-concepts-explanations)
		- [1. Program arguments: `argc` and `argv`](#1-program-arguments-argc-and-argv)
		- [2. Output in C++: `std::`cout\`](#2-output-in-c-stdcout)
				- [Example](#example)
		- [3. Uppercasing characters \& casting safety](#3-uppercasing-characters--casting-safety)
				- [Example](#example-1)
		- [4. Notes on I/O and Strings](#4-notes-on-io-and-strings)
		- [5. Core Algorithm](#5-core-algorithm)
- [📖 CPP00 ex01 - My Awesome PhoneBook](#-cpp00-ex01---my-awesome-phonebook)
	- [🔸 Goal](#-goal)
	- [🔸 Key Concepts](#-key-concepts)
	- [🔸 Concepts Explanations - Core OOP Concepts](#-concepts-explanations---core-oop-concepts)
		- [Advantages of OOP](#advantages-of-oop)
		- [1. Class](#1-class)
				- [Example](#example-2)
			- [2. Object](#2-object)
			- [3. Access Specifiers](#3-access-specifiers)
				- [Example `private`](#example-private)
				- [Example `public`](#example-public)
		- [4. Member Variables / Attributes](#4-member-variables--attributes)
				- [Declaring Variables](#declaring-variables)
		- [5. Member Functions](#5-member-functions)
				- [Example](#example-3)
		- [6. Constructor](#6-constructor)
				- [Example:](#example-4)
				- [Constructor Rules](#constructor-rules)
			- [Constructor with Parameters](#constructor-with-parameters)
				- [Example](#example-5)
		- [7. Destructor](#7-destructor)
				- [Example:](#example-6)
				- [Syntax](#syntax)
				- [When do we need to write a user-defined destructor?](#when-do-we-need-to-write-a-user-defined-destructor)
				- [When is the destructor called?](#when-is-the-destructor-called)
		- [8. Arrays](#8-arrays)
		- [9. `std::string`](#9-stdstring)
		- [10. `std::getline`](#10-stdgetline)
		- [11. Handling EOF](#11-handling-eof)
		- [12. `std::setw`](#12-stdsetw)
		- [13. Encapsulation](#13-encapsulation)
	- [Supplement: Address Operator (`&`)](#supplement-address-operator-)
		- [1. Two common meanings of `&`](#1-two-common-meanings-of-)
			- [Meaning 1: address-of operator](#meaning-1-address-of-operator)
			- [Meaning 2: reference type](#meaning-2-reference-type)
	- [🔹Circular Buffer](#circular-buffer)
	- [`std::istringstream stream(input)`](#stdistringstream-streaminput)
		- [Program Flow](#program-flow)
- [🧟 CPP01 ex00 - BraiiiiiiinnnzzzZ](#-cpp01-ex00---braiiiiiiinnnzzzz)
	- [🔸 Goal](#-goal-1)
	- [🔸 Required Behavior](#-required-behavior)
	- [🔸 Concept Explanation](#-concept-explanation)
		- [1. Free Functions vs. Member Functions](#1-free-functions-vs-member-functions)
		- [2. `const` at the end of a function](#2-const-at-the-end-of-a-function)
			- [Important:](#important)
		- [3. Stack vs. Heap Allocation](#3-stack-vs-heap-allocation)
			- [3.1 Stack Allocation](#31-stack-allocation)
			- [3.2 Heap Allocation](#32-heap-allocation)
			- [3.3 When to use](#33-when-to-use)
			- [Constructor and Destructor Examples](#constructor-and-destructor-examples)
				- [Constructor Implementation in .cpp](#constructor-implementation-in-cpp)
				- [Deconstructor Implementation in .cpp](#deconstructor-implementation-in-cpp)
- [🧟 CPP01 ex01 - Moar brainz!](#-cpp01-ex01---moar-brainz)
- [💭 CPP01 ex02 - HI THIS IS BRAIN](#-cpp01-ex02---hi-this-is-brain)
	- [Goal](#goal-1)
	- [🔸When to use Pointers](#when-to-use-pointers)
			- [1. Optional Values (can be NULL)](#1-optional-values-can-be-null)
			- [2. Reseating (Change what it points to)](#2-reseating-change-what-it-points-to)
			- [3. Dynamic memory (heap)](#3-dynamic-memory-heap)
			- [4. Polymorphism](#4-polymorphism)
	- [🔸When to use References](#when-to-use-references)
			- [1. Clean syntax](#1-clean-syntax)
			- [2. Pass-by-reference (Used often in C++)](#2-pass-by-reference-used-often-in-c)
			- [3. Safer than pointers](#3-safer-than-pointers)
			- [4. No de-referncing required](#4-no-de-referncing-required)
			- [5. Clear intent](#5-clear-intent)
	- [🔸Safety Comparison](#safety-comparison)
			- [⚠️ Unsafe pointer version (Needs Defensive Checks):](#️-unsafe-pointer-version-needs-defensive-checks)
			- [✅ Safe reference version:](#-safe-reference-version)
	- [🔸Mental Model](#mental-model)
- [⚔️ CPP01 ex03 - Unnecessary Violence](#️-cpp01-ex03---unnecessary-violence)
	- [🔸 Goal](#-goal-2)
	- [🔸 Marking with const](#-marking-with-const)
	- [🔸Getter pattern](#getter-pattern)
	- [🔸Setter pattern](#setter-pattern)
	- [🔸Reference vs Pointer](#reference-vs-pointer)
- [✏️ CPP01 ex04 - Sed is for losers](#️-cpp01-ex04---sed-is-for-losers)
	- [🔸Goal](#goal-2)
	- [🔸File Streams](#file-streams)
	- [🔸Functions](#functions)
- [💢 CPP01 ex05 - Harl 2.0](#-cpp01-ex05---harl-20)
	- [🔸 Goal](#-goal-3)
	- [🔸Member Function Pointers](#member-function-pointers)
	- [🔸This](#this)
		- [Notable Resources🔸](#notable-resources)


# General Notes

## 🔸Headers
`#include <iostream>`
```cpp
std::cin 	// accept input from the standard input
std::cout 	// send data to the output stream.
			// buffered, may not print immediately.
std::cerr 	// like cout, but unbuffered, prints immediately
std::endl	// inserts a new line and flushes the stream(output buffer)
```
`#include <cctype>`
C++'s version of cctype.h. This is used for:
```cpp
std::isalpha(c)
std::isdigit(c)
std::isalnum(c)
std::isspace(c)
std::islower(c)
std::isupper(c)
std::isprint(c)
std::ispunct(c)
std::isxdigit(c)
std::isblank(c)
```
`#include <string>`
```cpp
std::string
```
`#include <iomanip>`
```cpp
//Output Formatting
std::setw // setting output width
std::left // align left
std::right // align right
std::setfill // fill character (default is space)

//Base Formatting
std::hex // convert to hex
std::dec // convert to dec
std::oct // convert to oct
```

## 🔸Name Formatting
Classes named with **PascalCase**
```cpp
class Zombie;
class PhoneBook;
class ContactManager;
```
Functions named with **camelCase**
```cpp
void addContact();
void randomChump();
Zombie* newZombie();
```
Private Members named with **camelCase**
```cpp
std::string name;
int contactCount;
```
Methods named with camelCase
Variables named with camelCase
Macros named with UPPER_CASE

## 🔸Makefile
Compile with `-Wall -Wextra -Werror -std=c++98`.

## 🔸Organization
- Declarations in `.hpp`
- Implementations in matching `.cpp`
- Do not use `using namespace std;`.
- Do not use `printf`.



# 📣 CPP00 ex00 - Megaphone

## 🔸Goal

The program recives command-line arguments and prints them in uppercase. If no argument is given, it prints:
`* LOUD AND UNBEARABLE FEEDBACK NOISE *`

## 🔸 Important Edge Case
Do not blindly add spaces between arguments. Quoted shell arguments can already contain spaces.


## 🔸 Concepts Explanations

### 1. Program arguments: `argc` and `argv`
Like in C, our `main` can receive command-line arguments like this:
```cpp
int main (int argc, char **argv)
// or
int main (int argc, char *argv[])
```
`argc` means argument count.
`argv` means argument vector.

In C++, how the arguments are passed is decided by the function, not the caller.
```cpp
static void make_uppercase(std::string &s)
```

### 2. Output in C++: `std::cout`
In C, we would use `printf("Hello \n");`.  In C++, we use:
```cpp
std::cout << "Hello" << std:endl;
```
You will write `std::` in front of the function names because these names live inside the `std` namespace. A `namespace` is like a named container/library for functions, classes, and objects.

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
> `std::cout << "\n"` looks performance wise better, but  `std::cout << std::endl` is better in performance sensitive code, as it doesn't occupy any memory and also if flushing of stream is required.

### 3. Uppercasing characters & casting safety

The `toupper` and `tolower` function take the `int` equivalent of one character as parameter and return an `int` that can either be another character or a value representing a boolean value: an `int` value of `0` means `false` and an `int` value different from `0` represents `true`.

##### Example
```cpp
char c = 'a'
char upper = std::toupper(c); // returns an int, not char
// to cast it back to char using C++-style cast
std::cout << static_cast<char>(std::toupper(c));

// Alternatively
unsigned char c = static_cast<unsigned char>(s[i]);
s[i] = static_cast<unsigned char>(std::toupper(c));
```

### 4. Notes on I/O and Strings
- `std::cout` is an object that keeps **state** (buffer, format flags, locale, error bits).
- s`td::endl` prints `\n` and **flushes**.
- When calling `std::toupper`, cast `chars` to `unsigned char` first to avoid UB with negative values.
- Convert C strings to `std::string` for easier manipulation; pass by reference when you need in-place edits.
- Use `std::getline` for safe, whole-line input; always handle **EOF** (Ctrl+D) gracefully.
- `std::setw` aligns table columns; truncate long fields manually (e.g., str.substr(0, 9) + ".").

### 5. Core Algorithm
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
# 📖 CPP00 ex01 - My Awesome PhoneBook

## 🔸 Goal
Implement two classes:
1. `PhoneBook` has an array of contacts, stores max. 8 contacts (adding the 9th contact will replace the oldest one by one). **Note:** dynamic allocation is forbidden.
1. `Contact` stands for a phonebook contact

The phonebook must be instantiated as an instance of the `PhoneBook`class. Same thing for the contacts. Each one of them must be instantiated as an instance of the `Contact` class.

The program only accepts `ADD`, `SEARCH` and `EXIT`. Any other input is ignored.

Once a command has been correctly executed, the program waits for another one. It stops when the user inputs `EXIT`.

## 🔸 Key Concepts
- `class`
- `private`/`public`
- member functions
- object arrays
- `std::string`
- `std::getline`
- `std::setw`
- encapsulation
- basic program loop

## 🔸 Concepts Explanations - Core OOP Concepts

Object-oriented programming (OOP) is about creating "objects", which can hold `data` and `functions` that work on that data.

### Advantages of OOP
- OOP provides a clear structure to programs
- Makes code easier to maintain, reuse, and debug
- Helps keep your code DRY (Don't Repeat Yourself)
- Makes it possible to create full reusable applications with less code and shorter development time

> **Tip:** The DRY principle means you should avoid writing the same code more than once. Move repeated code into functions or classes and reuse it.

### 1. Class

A **class** is a blueprint/template for creating objects. In C, we often group data using a `struct`:
```c
typedef struct s_contact
{
	char *first_name;
	char *last_name;
	char *nickname;
}	t_contact;
```

In C++, a class can group both `data` + `functions` that work on that data. A class lives in the **header (.hpp)** file, while it's member function definitions sit in the **.cpp** file using `ClassName::method` syntax.

**Access specifiers** are used to enforce encapsulation and thus keeping the data members either hidden (`private`) or exposed (`hidden`).

##### Example
```cpp
class Contact
{
private:
	std::string _firstName; // private members written with `_` at the beginning
	std::string _lastName;
	std::string _nickname;

public:
	void setFirstName(std::string firstName);
	std::string getFirstName(void) const;
};
```

Here, `Contact` is not one concrete contact yet. It is the `type` or `blueprint`.

When we create this:
```cpp
Contact contact;
```
Now `contact` is an **object**, meaning once actual instance of the `Contact` class.

#### 2. Object
An **object** is an actual instance create from a class.
```cpp
class Contact {
    // blueprint
}

// Objects of class Contact
Contact bob;
Contact alice;
```

Each object has it's own copy of the member variables. So:
```cpp
bob.setFirstName("Bob");
alice.setFirstName("Alice");
```
does not conflict, as `bob` and `alice` are separate `Contact` objects.


#### 3. Access Specifiers

Access specifiers control how the members (attributes and methods) of a class can be accessed.

In C++, there are three access specifiers:
- `public` - members are accessible from outside the class
- `private` - members cannot be accessed (or viewed) from outside the class
- `protected` - members cannot be accessed from outside the class, however, they can be accessed in inherited classes.

##### Example `private`
```cpp
class Contact {
	private:string _firstName;
}
```
This means outside code cannot do:
```cpp
contact.firstName = "Alice"; // not allowed
```
That is good. It protects the object from being changed randomly.

> **Note:** By default, all members of a class are `private` if you don't specify an access specifier.

> **Note:** It is possible to access private members of a class using a public method inside the same class. See **Encapsulation** on how to do this.

> **Tip:** It is considered good practice to declare your class attributes as private (as often as you can). This will reduce the possibility of yourself (or others) to mess up the code.


##### Example `public`
```cpp
class Contact
{
public:
	void setFirstName(std::string firstName);
};
```
now outside code can do:
```cpp
contact.setFirstName("Alice")
```

The usual idea is:
```cpp
private = internal data
public = controlled interface
```

### 4. Member Variables / Attributes
A **member variable** is a variable that belongs to a class.

```cpp
class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
};
```
`_firstName` and `_lastName` are member variables.

They are also sometimes called:
```cpp
attributes
fields
data members
properties
```

In C++, people often prefix private attributes with `_`:
```cpp
_firstName
_contactCount
_nextIndex
```

This is not mandatory, but it makes the code easier to read because you can immediately see that the variable belongs to **the** object.

In C++, there are different types of variables (defined with different keywords), for example:

- `int` - stores integers (whole numbers), without decimals, such as 123 or -123
- `double` - stores floating point numbers, with decimals, such as 19.99 or -19.99
- `char` - stores single characters, such as 'a' or 'B'. Char values are surrounded by single quotes
- `string` - stores text, such as "Hello World". String values are surrounded by double quotes
- `bool` - stores values with two states: true or false

##### Declaring Variables
To create a variable, specigy the type and assign it a value:
```cpp
type    variableName = value;
```

### 5. Member Functions

A **member functions** is a function that belongs to a class.

##### Example
```cpp
class Contact
{
public:
	void setFirstName(std::string firstName);
	std::string getFirstName(void) const;

private:
	std::string _firstName;
};
```
These two functions belong to `Contact`. You call them using an object:
```cpp
Contact contact;
contact.setFirstName("Alice");
```

### 6. Constructor
A `constructor` is a special function that runs automatically when an object is created.

##### Example:
```cpp
class MyClass
{
 	public:
		MyClass() {	// Constructor
			cout << "Hello World!"; // prints "Hello World" when the object is created
		}
};

int main() {
	MyClass myObj;	// Create an object of MyClass (this will call the constructor)
	return (0);
}
```
##### Constructor Rules
- The constructor has the **same name as the class.**
- It has **nor return type** (not even `void`).
- It usually declared **public**.
- It is **automatically called** when an object is created.

#### Constructor with Parameters
Constructors can also take parameters (just like regular functions), which can be useful for setting initial values for attributes.

##### Example

```cpp
class PhoneBook
{
public:
	PhoneBook(void); // Constructor

private:
	int _contactCount;
	int _nextIndex;
};
```
Implementation:
```cpp
PhoneBook::PhoneBook(void) : _contactCount(0), _nextIndex(0)
{
}
```
This is called `member initializer list`. It initializes member variables **before** the constructor body runs.

When you write:
```cpp
PhoneBook phoneBook;
```
the constructor runs automatically and initializes:
```cpp
_contactCount = 0;
_nextIndex = 0;
```
This is useful because we make sure our object starts in a valid state.

All constructors initializing members should be in the header-declared order.


### 7. Destructor
A **destructor** is a special function that runs automatically when an object is destroyedo r goes out of scope to free resources like memory, files, or connections.
- Destructor neither requires any argument or returns any value.
- A destructor cannot be declared as static.
- A class can have only one destructor and cannot be overloaded.
- Destructors release resources and destroy objects in reverse order of creation.

##### Example:
```cpp
#include <iostream>

class Test {
public:

// User-Defined Constructor
Test() {
	std::cout << "Constructor Called"
			<< std::endl;
}

// User-Defined Destructor
~Test() {
	std::cout << "Destructor Called"
			<< std::endl;
}
};
int main() {
	Test t;

	return 0;
}

// Output
Constructor Called
Destructor Called
```

##### Syntax
Destructors are automatically present in every C++ class but we can also redefine them using the following syntax.
```cpp
~className(){
  	// Body of destructor
}
```

##### When do we need to write a user-defined destructor?
- If we don’t write a destructor, the compiler provides a default one.
- The default destructor works fine for classes without dynamic memory or pointers.
- If a class has pointers or dynamically allocated memory, we must write a destructor.
- A user-defined destructor releases memory or other resources before the object is destroyed to prevents memory leaks.
```cpp
#include <iostream>

class MyClass {
private:

	// Pointer to dynamically allocated memory
	int* data;

public:
	MyClass(int value) {
		data = new int;
		*data = value;
		std::cout << *data << std::endl;
	}

	// User-defined destructor: Free the dynamically allocated memory
	~MyClass() {
		// Deallocate the dynamically
		// allocated memory
		delete data;
		std::cout << "Destructor: Memory deallocated";
	}
};

int main() {
	MyClass obj1(10);
	return 0;
}
```
> **Note**: When the object is destroyed, the destructor releases the dynamically allocated resources, which in this case is the pointer.

##### When is the destructor called?
1. When the function ends.
2. When the program ends.
3. When when a block containing local variables ends.
4. When a delete operator is called.
```cpp
#include <iostream>

int count = 0;
class Test {
public:
	Test(){
		// Number of times constructor is called
		count++;
		std::cout << "No. of Object created: " << std::count << std::endl;
	}
	~Test() {
		// It will print count in decending order
		std::cout << "No. of Object destroyed: " << count << std::endl;
		count--;
	}
};

int main() {
	Test t, t1, t2, t3;
	return 0;
}
```
Output:
```cpp
No. of Object created: 1
No. of Object created: 2
No. of Object created: 3
No. of Object created: 4
No. of Object destroyed: 4
No. of Object destroyed: 3
No. of Object destroyed: 2
No. of Object destroyed: 1
```

### 8. Arrays

Arrays are used to store multiple values in a single variable, instead of declaring separate variables for each value.

To declare an array, define the variable type, specify the name of the array followed by square brackets and specify the number of elements it should store. To insert values to it, we can use an array literal - place the values in a comma-separated list, inside curly braces:

```cpp
string cars[4];
string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
int myNum[3] = {10, 20, 30};
```

You access an array element by referring to the index number inside square brackets []. To change the value of a specific element, refer to the index number:
```cpp
string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
cout << cars[0]; // Outputs Volvo

cars[0] = "Opel";
cout << cars[0]; // Now outputs Opel instead of Volvo
```

### 9. `std::string`
Strings are used for storing text/characters. A `string` variable contains a collection of characters surrounded by double quotes (`""`). To use strings, you must include an additional header file in the source code, the `<string>` library:
```cpp
// Include the string library
#include <string>

// Create a string variable
string greeting = "Hello";

// Print the string
cout << greeting;
```
A string in C++ is actually an **object**, which contain functions that can perform certain operations on strings. For example, you can also concatenate strings with the `append()` function:
```cpp
string firstName = "John ";
string lastName = "Doe";
string fullName = firstName.append(lastName);
cout << fullName;
```

To get the length of a string, use the `length()` function:
```cpp
string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
cout << "The length of the txt string is: " << txt.length();
```
> **Note**: Tip: You might see some C++ programs that use the size() function to get the length of a string. This is just an alias of length(). It is completely up to you if you want to use length() or size().

### 10. `std::getline`
`std::getline` reads a whole line from input.
```cpp
std::string input;
std::getline(std::cin, input);
```

Our command loop will also use `std::getline`:
```cpp
while (true)
{
	std::cout << "Enter command: ";
	if (!std::getline(std::cin, command))
		break;
}
```
This also handles Ctrl-D cleanly. If input ends, the program exits instead of looping forever.

> **Warning**: mixing `std::cin >> input` and `std::getline` can cause bugs, because `std::cin >> `leaves the newline in the input buffer. For this project, the simplest clean solution is to use std:getline everywhere.

### 11. Handling EOF
In C++, with `std::getline`, you usually handle EOF by checking the result of g`etline` directly.
```cpp
#include <iostream>
#include <string>

int main() {
	std::string line;

	while (std::getline(std::cin, line)) {
		std::cout << "You entered: " << line << '\n';
	}

	std::cout << "EOF reached or input error occurred.\n";

	return 0;
}
```
This loop keeps reading lines from `stdin` until EOF or an input error happens.

For keyboard input:
```
Linux/macOS: Ctrl + D
Windows:     Ctrl + Z, then Enter
```
A common mistake is doing this:
```cpp
while (!std::cin.eof()) {
	std::getline(std::cin, line);
	// use line
}
```
Avoid that pattern. `eof()` only becomes true after a read fails, so it can cause bugs such as processing the last line twice or processing invalid data.



### 12. `std::setw`
`std::setw` is used to control input/output width.


Example:
```cpp
#include <iomanip>
std::cout << std::setw(10) << "Bob" << std::endl;

// Output: "       Bob"
```

For the phonebook table:
```cpp
std::cout << std::setw(10) << index << "|";
std::cout << std::setw(10) << firstName << "|";
std::cout << std::setw(10) << lastName << "|";
std::cout << std::setw(10) << nickname << std::endl;
```
Important: `std::setw(10)` only affects the next printed value.

This:
```cpp
std::cout << std::setw(10) << firstName << lastName;
```
will only applies width 10 fo `firstName`, not to `lastName`. So it needs to be repeated:
```cpp
std::cout << std::setw(10) << firstName;
std::cout << std::setw(10) << lastName;
```

Also, right allignment can be made explicit:
```cpp
std::cout << std::right << std::setw(10) << firstName;
```

### 13. Encapsulation
**Encapsulation** means hiding the internal data of a class and only allowing controlled access through public functions, commonly called getter/setter.

For example, we could later make `setFirstName` reject empty names:
```cpp
bool Contact::setFirstName(std::string firstName)
{
	if (firstName.empty())
		return false;
	_firstName = firstName;
	return true;
}

contact.setFirstName(firstName);
```
Now the class controls how its data changes.

So instead of designing everything in `main.cpp`, we split responsibilities:
```cpp
main.cpp    = command loop
PhoneBook   = add/search logic and contact array
Contact     = one contact's data
```

## Supplement: Address Operator (`&`)

### 1. Two common meanings of `&`

#### Meaning 1: address-of operator

When `&` is used in front of an existing variable in normal code, it means `the memory address of the variable`. This is the same idea as we know from C.
```cpp
std::string name = "Alice"
std::cout << &name << std::endl // will print the address of `name`
```

#### Meaning 2: reference type

When `&` appears in a type declaration, it means `the var with said type is a reference to a variable`.
```cpp
std::string& ref = name; // ref is a referecne to name
```
`ref` is not a copy. It is another name for the same variable `name`. So if we change `ref`, it will also change `name`.
```cpp
ref = "Bob";
std::cout << name << std::endl
```

## 🔹Circular Buffer
```cpp
oldestIndex = (oldestIndex + 1) % 8;
```

## `std::istringstream stream(input)`
This creates a stream from the string. A stream lets you read from a string like you read from `std::cin`.
For example:
```cpp
std::string input = "42";
std::istringstream stream(input);

int number;
stream >> number; // now number becomes 42
```

With `std::istringstream`, we can check more carefully:
```cpp
std::istringstream stream(input);
int parsedIndex;
char extra;

if (!(stream >> parsedIndex)) // Can the input be read as an integer? So "abc" fails.
	return false;

if (stream >> extra) // Is there anything extra after the number? So "1abc" fails.
	return false;
```
Compare them to `atoi`:
```cpp
atoi("0")      // returns 0
atoi("abc")    // returns 0
atoi("0abc")   // returns 0
```
With atoi, these are hard to separate.

But with `istringstream`, you can say:
```
"0"      -> valid
"abc"    -> invalid
"0abc"   -> invalid
```

### Program Flow
```cpp
start program
create empty PhoneBook
repeat:
	read command
	if ADD: add contact
	if SEARCH: search contact
	if EXIT: stop program
	otherwise: ignore input
```

# 🧟 CPP01 ex00 - BraiiiiiiinnnzzzZ

## 🔸 Goal
Understanding object lifetime, stack allocation, heap allocation, new, delete, constructors, and destructors.

## 🔸 Required Behavior
zombie announces itself like this:
```
<name>: BraiiiiiiinnnzzzZ...
```
For example:
```
Foo: BraiiiiiiinnnzzzZ...
```
The destructor must also print a message with the zombie name, so we can see when the zombie is destroyed.

## 🔸 Concept Explanation
### 1. Free Functions vs. Member Functions
A **member functions** is declared inside a class and belongs specifically to objects of that class. For example, the `announce()` function is declared inside the `Zombie class`, thus belongs to a `Zombie object`. So you call it like this:
```cpp
Zombie zombie("Bob");
zombie.announce();
```
or if you have a pointer:
```c
Zombie	*zombie = new Zombie("Bob");
zombie->announce();
```
And because `announce()` belongs to the class, it can directly access private members:
```c
void	Zombie::announce(void) const
{
	std::cout << _name << std::endl; // here _name is private
}
```

On the other hand `newZombie()` and `randomChump` are outside the class and are called `normal/free functions`. So we do not call them on a zombie object.We call them directly because they do not belong to a specific Zombie object:
```c
Zombie *zombie = newZombie("Bob");

randomChump("Alice");
```
They are declared ouside the Zombie class because they are helper functions and not actions that an existing zombie does.


### 2. `const` at the end of a function
```c
void announce(void) const;
```
The `const` at the end means:
> This function promises not to modify the current `Zombie` object.

So inside `announce`, we can read `_name`, but cannot change it. So this will lead to error:
```c
void Zombie::announce(void) const
{
	_name = "Changed"; // Error
}
```
#### Important:
A `const` after a member function means this function promises not to modify the object it is called on. Only class **member functions** can have this final `const`. A `const` object is **only** allowed to call member functions that are **also** marked `const`.

So in this exercise `announce` belongs to `Zombie` and promises not tochange this Zombie. This would be forbidden:
```c
void	Zombie::announce(void) const
{
	_name = "Other Bob"; // Error, because announce is const
}
```

### 3. Stack vs. Heap Allocation
In simple terms:
> **Stack allocation** means C++ automatically destroys the object when the funciton/block ends.
**Heap allocation** means we manually create the object with `new`, and we must manually destroy it with `delete`.

#### 3.1 Stack Allocation
Example:
```c
void randomChump(std::string name)
{
	Zombie zombie(name); //object created here
	zombie.announce();
} //object destroyed here
```
Here we create a `Zombie` object on the **stack**. That means the zombie lives only inside the **randomChump** function. When the function ends, C++ automatically calls the destructor:
```c
Zombie::~Zombie(void)
{
	std::cout << _name << " is destroyed" << std::endl;
}
```

#### 3.2 Heap Allocation
```c
Zombie *newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name); // creates a `Zombie` object on the heap
	return zombie;
}
```
Here a `Zombie` object is created using `new` and store in **heap**. The result is a pointer. A heap object does **not** disappear automatically when the function ends. So, using `new` is like telling C++:
> Allocate memory for a Zombie, construct it, and give me its address.

So later, we must **manually delete** it with:
```c
delete zombie;
```

This does two things:
1. Calls the destructor:
```c
Zombie::~Zombie(void)
```
2. Frees the heap memory back to the system

So the full flow is:
```c
Zombie	*zombie = new Zombie("Bob"); //create zombie on the heap

zombie->announce(); //use the zombie through its pointer

delete zombie; //destroy zombie and free its memory
```

#### 3.3 When to use
In general:

> Use **stack** when the object is only needed in the current function/block.
Use **heap** when the object must survive after the function returns.

When we create a new object with `new`:
 1. Allocates raw memory on the heap
 2. Calls the constructor on that memory
 3. Returns a pointer to that object

Then we destroy an object with `delete`:
 1. Call the destructor
 2. Free the heap memory


#### Constructor and Destructor Examples
##### Constructor Implementation in .cpp
```cpp
Zombie::Zombie(std::string name) : name(name)
{
 	std::cout << "A wild " << name << " has appeared!" << std::endl;
}
```

##### Deconstructor Implementation in .cpp
```cpp
Zombie::~Zombie()
{
	std::cout << name << " has been defeated!" << std::endl;
}
```

# 🧟 CPP01 ex01 - Moar brainz!
The subject asks us to implement:
```cpp
Zombie *zombieHorde(int N, std::string name);
```
This function must allocate N Zombie objects in one single allocation, initialize each zombie with the same name, and return a pointer to the first zombie. Then we must test it by calling announce() on each zombie and finally free the memory with delete[].

The important new concept compared to ex00 is this:
```cpp
new Zombie[N]
```
creates an array of objects on the heap, not just one object.

This means C++ must create N zombies first, before we give them names. Because of that, the class needs a default constructor:
```cpp
Zombie(void);
```
Therefore when we call:
```cpp
Zombie* horde = new Zombie[3];
```
The order of operation is as follows:
1. Allocate memory for 3 Zombies
2. create zombie[0] using Zombie()
3. create zombie[1] using Zombie()
4. create zombie[2] using Zombie()
5. Return pointer to first Zombie
6. Assign it to 'horde`

So if our class only has this constructor:
```cpp
Zombie(std::string name);
```
then new `Zombie[N]` cannot work, because C++ does not know what name to give each zombie during array creation. That is why we first create unnamed zombies, then assign names with `setName()`.

We then free the memory with:
```cpp
delete[] horde;
```

# 💭 CPP01 ex02 - HI THIS IS BRAIN

## Goal
The subject asks us to create:
```cpp
std::string string = "HI THIS IS BRAIN";
std::string *stringPTR = &string;
std::string &stringREF = string;
```
Then print the addresses and the values. The goal is to demystify references and compare them with pointers.

| Name        | What it is                      | What's inside            |
|-------------|---------------------------------|--------------------------|
| `str`       | actual object                   | the string value         |
| `stringPTR` | pointer `str`                   | address of `str`         |
| `stringREF` | reference (alias) to `str`      | the same object as `str` |

## 🔸When to use Pointers
A pointer is a variable that stores a memory address (like in C)

#### 1. Optional Values (can be NULL)
Useful when you want something to be optional, because they can be NULL.
```cpp
std::string * ptr = NULL;
```

#### 2. Reseating (Change what it points to)
```cpp
std::string a = "A";
std::string b = "B";

std::string* ptr = &a;
ptr = &b; // Reassignment/reseating of the pointer to the address of b.
```

#### 3. Dynamic memory (heap)
Heap allocations always require pointers.
```cpp
std::string* ptr = new std::string("Hello");
delete ptr;
```
#### 4. Polymorphism
Pointers are required for:
 - Inheritance
 - Virtual functions
 - Base class pointers
Note: References can do polymorphism too, but pointers are more flexible

## 🔸When to use References
A reference is just another name for the same object.
 - not a copy
 - not another object
 - not a pointer

It is literally an alias of the same object.

#### 1. Clean syntax
Instead of:
```cpp
void print(std::string* s)
{
	std::cout << *s;
}
```
You can do:
```cpp
void print(std::string& s)
{
	std::cout << s;
}
```
Cleaner and no de-referencing needed.

#### 2. Pass-by-reference (Used often in C++)
Without reference:
```cpp
void modify(std::string s); // Copies the string
```
With reference:
```cpp
void modify(std::string& s); // Modifies the original
```
This avoids copying large objects, and in C++ almost everything is passed by reference. Use it lots.

#### 3. Safer than pointers
**References:**
- Can't be NULL. Can't be uninitialized.
```cpp
std::string& ref;        // ❌ Must be initialized, does not compile
std::string& ref = NULL; // ❌ Illegal
```
- Can't be reseated like a pointer.

**Pointer:**
```cpp
std::string a = "A";
std::string b = "B";

std::string* ptr = &a;
ptr = &b;  // Allowed for pointers
```
**Reference:**
```cpp
std::string& ref = a; // Compiler cuarantees it refers to something real.
ref = b;   // Assigns value, DOES NOT reseat
```
It does not change what ref refers to. It copies b into a
This prevents accidental reseating and confusing ownership issues.

#### 4. No de-referncing required
With pointers:
```cpp
ptr->length();
(*ptr).length();`
```
With References:
```cpp
ref.length();
```
Cleaner code

#### 5. Clear intent
```cpp
void func(std::string& s);
```
 - `s` must exist
 - `s` will not be null
 - `s` refers to a real object

## 🔸Safety Comparison
#### ⚠️ Unsafe pointer version (Needs Defensive Checks):
```cpp
void print(std::string* s)
{
	if (s)
		std::cout << *s;
}
```
- needs null checks
- extra logic
- defensive programming
- `s` could be invalid.

#### ✅ Safe reference version:
```cpp
void print(std::string& s)
{
    std::cout << s;
}
```
- No null checks needed
- No crash risk because of invalid variables
- Cleaner code
- Safer

## 🔸Mental Model
 - `str`       -> The house
 - `stringPTR` -> A note with the house address
 - `stringREF` -> A second name on the house mailbox (It's the same house)

The key difference:
```
Pointer   -> stores an address and can be changed
Reference -> is an alias and must be initialized immediately
```

# ⚔️ CPP01 ex03 - Unnecessary Violence

## 🔸 Goal
First exercise where the difference between pointer and reference really matters. The subject asks for a Weapon class, then two humans: HumanA and HumanB. Both can attack with a weapon, but HumanA is always armed, while HumanB may start without a weapon. That is why this exercise asks us to think about when a Weapon should be stored as a reference and when it should be stored as a pointer.


## 🔸 Marking with const
The subject specifically requires getType() to return a constant reference to this string, not a copy.
```cpp
const std::string& getWeapon() const;
```
- `const std::string&` → `Returns const`: means the function returns the actual weapon type string by reference, but the caller cannot modify it directly.

So this is allowed:
```cpp
std::cout << club.getType() << std::endl;
```
But this is not allowed:
```cpp
club.getType() = "axe";
```
- `getWeapon()` → Function name
- `const` → `Function const`: means this function will not modify the object.

## 🔸Getter pattern
```cpp
const Type& getSomething() const;
```
## 🔸Setter pattern
```cpp
void setSomething(const Type& value);
```
## 🔸Reference vs Pointer
References cannot be reseated (changed to refer to a different object) after construction.
However, we can still modify the object that the reference refers to.
That is why we can do:
```cpp
sword.setType("New Sword Name");
```
Here the weapon object changes, not the reference.
HumanA still refers to the same object, but the object's internal data changed.
We cannot do:
```cpp
hero.weaponRef = wood;  // ❌ Illegal
```
This tries to change the reference. This is not allowed.

| Concept             | Meaning                                             |
|---------------------|-----------------------------------------------------|
| Reference           | Alias to an existing object                         |
| Reseating reference | Making it point to a different object (not allowed) |
| Modifying object    | Changing the object's internal data (allowed)       |

# ✏️ CPP01 ex04 - Sed is for losers

## 🔸Goal
Making a small C++ version of sed.
The subject asks for a program that takes:
```cpp
./replace <filename> <s1> <s2>
```
Then it creates:
```cpp
<filename>.replace
```
and writes the file content with every occurrence of s1 replaced by s2. We are not allowed to use C file functions and not allowed to use `std::string::replace`. So we use C++ file streams and manual string rebuilding.


## 🔸File Streams
|Object|Type|Description|
|---|---|---|
|`infile`|`std::ifstream`|Input file stream used to read data from a file|
|`outfile`|`std::ofstream`|Output file stream used to write data to a file|
|`cout`|`std::ostringstream`|Output only (like cout)|
## 🔸Functions
| Function | Type | Description |
|----------|------|-------------|
|`std::string::npos`|constant static member value|return the highest possible value for an element of type `size_t` and it is defined with `-1`. Actually means until the end of the string.|
|`std::ios::rdbuf() `|`std::ios` methode|get or set the underlying stream buffer associated with an input/outpyt stream..|
|`std::ios::bad() `|Returns true if the badbit error state flag is set for the stream.|This flag is set by operations performed on the stream when an error occurs while read or writing data, generally causing the loss of integrity of the stream.|
|`std::getline()`|Function|Read a full line from input into a `std::string`|
|`find()`|`std::string` method|Find a substring and return its position|
|`erase()`|`std::string` method|Remove characters from a string|
|`insert()`|`std::string` method|Insert characters into a string|
|`length()`|`std::string` method|Return the number of characters in a string|
|`empty()`|`std::string` method|check if a string is empty
|`c_str()`|`std::string` method|Converts `std::string` into a C-style string (const char *)|

# 💢 CPP01 ex05 - Harl 2.0

## 🔸 Goal
The subject wants a Harl class with four private functions:
```cpp
void debug(void);
void info(void);
void warning(void);
void error(void);
```
and one public function:
```cpp
void complain(std::string level);
```
The important rule: we should **not** solve this with a big if / else if / else chain. The subject specifically wants us to use pointers to member functions.

## 🔸Member Function Pointers
Member function pointers are different because they're not just a function.
They belong to a class
```cpp
class Harl
{
	private:
		void debug(void);
};
```
and need a specific object to run on.
```cpp
Harl harl;
harl.debug();
```
## 🔸This
`this` is a pointer to the current object.
It is a special implicit pointer avilable inside every non-static member function that points to the object the function was called on.

```cpp
class Harl
{
public:
    void complain()
    {
        // here "this" exists
    }
};
```
```cpp
Harl h;
h.complain();
```
Inside `complain()`, `this` points to the harl object, in this case, `h`.
Therefore
```cpp
this == &h
```
If you create 2 objects and use `this` in a function of one of the objects, it knows which function its referring to.

`this` is sometimes optional.
For example:
```cpp
void speak()
{
    this->name = "Dog";
}
```

It is not optional when variable names collide.
For example:
```cpp
class Player
{
private:
    int hp;

public:
    void setHp(int hp)
    {
        this->hp = hp;
    }
};
```
otherwise
```hp = hp```

In Harl,
```cpp
(this->*levelTable[i].func)();
```
The function pointer needs to know which object to run on.


Conceptually:
```cpp
levels[0]    = "DEBUG"    -> debug()
levels[1]    = "INFO"     -> info()
levels[2]    = "WARNING"  -> warning()
levels[3]    = "ERROR"    -> error()
```
Then `complain()` searches for the matching string and calls the matching function.

```cpp
typedef void (Harl::*ComplaintFunction)(void);
```
Read it like this:
```
ComplaintFunction is a type.
It represents a pointer to a Harl `member` function.
That member function takes no parameter and returns void.
```

In comparison to a normal function pointer:
```cpp
void (*function)(void);
```
### Notable Resources🔸
- https://cplusplus.com/reference/cctype/
