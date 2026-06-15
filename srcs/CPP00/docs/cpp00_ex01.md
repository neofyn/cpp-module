## CPP00 ex01 - My Awesome PhoneBook

### Required Files
- `Makefile`
- `megaphone.cpp`

### Goal

Understand basic concept of C++ OOP by creating a program that behaves like a phonebook software. Implement two classes:
1. `PhoneBook` has an array of contacts, stores max. 8 contacts (adding the 9th contact will replace the oldest one by one).
> **Note:** dynamic allocation is forbidden. 
2. `Contact` stands for a phonebook contact

The phonebook must be instantiated as an instance of the `PhoneBook`class. Same thing for the contacts. Each one of them must be instantiated as an instance of the `Contact` class.

The program only accepts `ADD`, `SEARCH` and `EXIT`. Any other input is ignored.

Once a command has been correctly executed, the program waits for another one. It stops when the user inputs `EXIT`.


### Key Concepts
- `class`
- `private`/`public`
- member functions
- object arrays
- `std::string`
- `std::getline`
- `std::setw`
- encapsulation
- basic program loop

### Concepts Explanations - Core OOP Concepts

OOP stands for Object-Oriented Programming.

Object-oriented programming is about creating "objects", which can hold `data` and `functions` that work on that data.

#### Advantages of OOP
- OOP provides a clear structure to programs
- Makes code easier to maintain, reuse, and debug
- Helps keep your code DRY (Don't Repeat Yourself)
- Makes it possible to create full reusable applications with less code and shorter development time

> **Tip:** The DRY principle means you should avoid writing the same code more than once. Move repeated code into functions or classes and reuse it.

#### 1. Class

A **class** is a blueprint for creating objects.

In C, we often group data using a `struct`:
```c
typedef struct s_contact
{
	char *first_name;
	char *last_name;
	char *nickname;
}	t_contact;
```

In C++, a class can group both `data` + `functions` that work on that data.

##### Example
```cpp
class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;

public:
	void setFirstName(std::string firstName);
	std::string getFirstName(void) const;
};
```

Here, `Contact` is not one concrete contact yet. It is the `type` or `blueprint`.

When you create this:
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

For `ex01`, the contact fields should be private:
```cpp
std::string _firstName;
std::string _lastName;
std::string _nickname;
std::string _phoneNumber;
std::string _darkestSecret;
```
And the class should expose public functions to set or get them.


#### 4. Member Variables / Attributes
A member variable is a variable that belongs to a class.

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

This is not mandatory, but it makes the code easier to read because you can immediately see that the variable belongs to the object.

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

#### 5. Member Functions

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

#### 6. Constructor
A `constructor` is a special function that runs automatically when an object is created.

##### Example:
```cpp
class MyClass
{
    public:
        MyClass()   {   // Constructor
            cout << "Hello World!";
        }
};

int main() {
  MyClass myObj;    // Create an object of MyClass (this will call the constructor)
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

#### 7. Destructor
A **destructor** is a special function that runs automatically when an object is destroyedor goes out of scope to free resources like memory, files, or connections.
- Destructor neither requires any argument or returns any value.
- A destructor cannot be declared as static.
- A class can have only one destructor and cannot be overloaded.
- Destructors release resources and destroy objects in reverse order of creation.

##### Example:
```cpp
#include <iostream>
using namespace std;

class Test {
public:

    // User-Defined Constructor
    Test() {
        cout << "Constructor Called"
             << endl;
    }

    // User-Defined Destructor
    ~Test() {
        cout << "Destructor Called"
             << endl;
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
- A user-defined destructor releases memory or other resources before the object is destroyed.
- Writing a destructor in such cases prevents memory leaks.
```cpp
#include <iostream>
using namespace std;

class MyClass {
private:

    // Pointer to dynamically allocated memory
    int* data;

public:
    MyClass(int value) {
        data = new int;
        *data = value;
        cout << *data << endl;
    }

    // User-defined destructor: Free the dynamically allocated memory
    ~MyClass() {
        // Deallocate the dynamically 
        // allocated memory
        delete data;  
        cout << "Destructor: Memory deallocated";
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
using namespace std;

int count = 0;
class Test {
public:
    Test(){
        // Number of times constructor is called
        count++;
        cout << "No. of Object created: " << count << endl;
    }
    ~Test() {
        // It will print count in decending order
        cout << "No. of Object destroyed: " << count << endl;
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

#### 8. Arrays

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

#### 9. `std:string`
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

#### 10. `std::getline`
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


#### 11. `std::setw`
std::setw is used to control input/output width.

The subject requires the search table columns to be 10 characters wide, right-aligned, and separated by |.

To use `std::setw`, include:
```cpp
#include <iomanip>
```

Example:
```cpp
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

#### 12. Encapsulation
**Encapsulation** means hiding the internal data of a class and only allowing controlled access through public functions, commonly called getter/setter.

For example, we could later make setFirstName reject empty names:
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


### Address Operator (`&`)

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
`ref` is not a copy. It is another name for the same variable `name`. So if we change `ref`, it will also change `name`.sss
```cpp
ref = "Bob";
std::cout << name << std::endl
```

#### Function parameter without vs. with `&`
Suppose we have this:
```cpp
void printName(std::string name)
{
	std::cout << name << std::endl;
}
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