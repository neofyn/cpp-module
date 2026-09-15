# CPP05 - Repetition and Exception
Main topics:
- Exceptions
- `throw` / `try` / `catch`
- `std::exception`
- Nested exception classes
- `what()`
- Const member attributes
- Exception propagation
- Validation inside constructors

## ex00 - Mommy, when I grow up, I want to be a bureaucrat!
### 1. Exceptions
Normally, returning an error as a value is awkward, especially for constructor. Example:
```c
bool setGrade(int grade); // we did this normally

Bureaucrat bob("Bob", 0);
return false; // constructors cannot simply do this, cause constructor don't have return values.
```
Instead, we use **exception**.

The basic structure is:
```c
try
{
    // code that might fail
}
catch (...)
{
    // handle the failure
}
```
#### `throw`
> Something went wrong. Stop normal execution and look for a matching `catch`.

Example:
```c
if (grade < 1>)
    throw GradeTooHighException();
```
Execution immidiately leaves the current function. Anything after the `throw` in that function is not executed.

For example:
```c
std::cout << "before" << std::endl;
throw GradeTooHighException();
std::cout << "after" << std::endl;

// this will print `before` but never `after`;
```

### 2. `try` and `catch`
Code which might throw an exception goes inside a `try` block. Then we catch the exception in the matching catch block:
```c
try {
    Bereaucrat bob("Bob", 0);
} catch (const std::exception& e){
    std::cout <<e.what() << std::endl;
}
```

### 3. `std::exception`
The standard base class for exception is `std::exception` from `#include <exception>`. It contains a virtual function `what()` which describes the error.

Conceptually: `GradeTooHighException` is a type of `std::exception`. So we create:
```c
// GradeTooHighException inherits from std::exception
class GradeTooHighException : public std::exception
{
    public:
        virtual const char* what() const throw();
}
```
### 4. Why inherit publicly from `std::exception`?
We want this relationship:
```c
GradeTooHighException IS-A std::exception
```
Therefore:
```c
class GradeTooHighException : public std::exception
```
Public inheritance preserves that relationship. This allows:
```c
catch (const std::exception& e)
```
to catch our custom exception.


### 5. `what()`
`std::exception` provides:
```c
virtual const char* what() const throw();
```
We override it:
```c
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}
```
Then:
```c
catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
}
```
Breakdown:
|virtual | virtual function can be overwritten
| const char*  |  return value of the function as C-style string   |
| Bureaucrat::GradeTooHighException | nested exception classess (GradeTooHighException is declared inside Bureaucrat)     |
| what() | function name     |
| const    | calling this function will not modify the exception object    |
| throw()    | thiss function promises not to throw another exception (restricted to C++98. In modern C++11, we use `nexcept`)    |

```c
const char* Bureaucrat::GradeTooHighException::what() const throw()

```

### 6. Virtual Function
A `virtual` function allows C++ to decide which implementation to call based on the **actual object type**, instead of only looking at the pointer/reference type.

Here `std::exception::what()` is virtual. Therefore, when we catch our custom exception through a `std::exception&`

Example:
```c
catch (const std::exception& e)
{
    std::cout << e.what() << std::endl;
}
```
C++ will call the `what()` implementation of the custom exception class,e.g.: `GradeTooHighException::what()`
