# CPP02 Study Notes

- [CPP02 ex00 - My First Class in Orthodoc Canonical Form](#cpp02-ex00---my-first-class-in-orthodoc-canonical-form)
  - [🔸 Orthodoc Canonical Form](#-orthodoc-canonical-form)
      - [1. Default Constructor](#1-default-constructor)
      - [2. Copy Constructor](#2-copy-constructor)
      - [3. Copy Assignment operator](#3-copy-assignment-operator)
      - [Deconstructor](#deconstructor)
  - [🔸 Operator Overloading](#-operator-overloading)
  - [🔸 Fixed-point Numbers](#-fixed-point-numbers)
      - [Advantages and Disadvantages of Fixed-point Numbers](#advantages-and-disadvantages-of-fixed-point-numbers)
  - [🔸 Static Class Members](#-static-class-members)
  - [🔸 Object Lifecycle](#-object-lifecycle)
  - [🔸 Naming Conventions](#-naming-conventions)
  - [🔸 Returning Fixed&](#-returning-fixed)
  - [🔸 Operators are Functions](#-operators-are-functions)

- [CPP02 ex01 - Towards a more useful fixed-point number class](#cpp02-ex01---towards-a-more-useful-fixed-point-number-class)
  - [🔸 Goal](#-goal)
  - [🔸 Why we scale numbers](#-why-we-scale-numbers)
  - [🔸 Operator<<](#-operator)

  - [🔸 Increasing Precision](#-increasing-precision)
  - [🔸 `int` Constructor](#-int-constructor)
  - [🔸 Converting from `int`](#-converting-from-int)
  - [🔸 Converting from float](#-converting-from-float)
  - [🔸 Converting back to float](#-converting-back-to-float)
  - [🔸Simple mental model:](#simple-mental-model)
  - [🔸 Operator<< Fixed Function](#-operator-fixed-function)
  - [🔸 Known operator<< Functions](#-known-operator-functions)
  - [🔸 IEEE-754 Floating Point](#-ieee-754-floating-point)
      - [Scientific Notation](#scientific-notation)
      - [How a float is stored in memory](#how-a-float-is-stored-in-memory)
      - [How a float vs double is stored in memory](#how-a-float-vs-double-is-stored-in-memory)
      - [Floating Point numbers are inexact](#floating-point-numbers-are-inexact)
      - [Precision limits](#precision-limits)
      - [Integer scaled by a constant](#integer-scaled-by-a-constant)
      - [Printing converts binary into decimal](#printing-converts-binary-into-decimal)
      - [Alogrithms](#alogrithms)

- [CPP02 ex02 - Now we're talking](#cpp02-ex02---now-were-talking)
  - [🔸 Goal](#-goal-1)
  - [🔸 Operator Overloading](#-operator-overloading-1)
  - [🔸 Core arithmetic idea](#-core-arithmetic-idea)
  - [🔸 Multiplication](#-multiplication)
      - [Why Shift Right](#why-shift-right)
  - [🔸 Division](#-division)
      - [Why shift left](#why-shift-left)
  - [🔸 Pre-increment (++i)](#-pre-increment-i)
  - [🔸 Post-increment (i++)](#-post-increment-i)
  - [🔸 Accuracy vs Precision](#-accuracy-vs-precision)
    - [Accuracy](#accuracy)
    - [Precision](#precision)
    - [Very important difference](#very-important-difference)
    - [Why `roundf()` is about accuracy](#why-roundf-is-about-accuracy)
    - [Why _fractionalBits is about precision](#why-_fractionalbits-is-about-precision)
    - [How this appears in ex02](#how-this-appears-in-ex02)



# CPP02 ex00 - My First Class in Orthodoc Canonical Form
## 🔸 Orthodoc Canonical Form
These will be used from now on. Every class must include:
1. **Default constructor**
2. **Copy constructor**
3. **Copy assignment operator**
4. **Deconstructor**

For `Fixed` class, that means:
```cpp
Fixed();							// default constructor
Fixed(const Fixed &other);			// copy constructor
Fixed &operator=(const Fixed &other);	// copy assignment operator
~Fixed();						// destructor
```

#### 1. Default Constructor
Creates an object with no parameters. Implementation:
```cpp
Fixed::Fixed(){}
```
Example:
```cpp
Fixed a;
```

#### 2. Copy Constructor
Creates a new object from another object. Example:
```cpp
Fixed a;
Fixed b(a);
```
This calls:
```cpp
Fixed::Fixed(const Fixed& other)
```

#### 3. Copy Assignment operator
This assigns values between existing objects. Example:
```cpp
Fixed a;
Fixed b;

b = a; // replacing current b's value with a's value
```
This calls:
```cpp
Fixed& Fixed::operator=(const Fixed& other)
```
`operator=` is the copy assignment operator.
For built in types like `int`, C++ knows what to do:
```cpp
int a = 5;
int b = 10;
a = b;
```
However when you make your own classes, the compiler needs instructions
```cpp
Fixed& operator=(const Fixed& other);
```
Example:
```cpp
Fixed a;
Fixed b;
b = a; // operator= called
```
C++ also translates `b = a` into
```cpp
b.operator=(a);
```

#### Deconstructor
Runs when an object is destroyed. Frees memory and cleans up resources.
```cpp
{
	Fixed a
} // Deconstructor called here automatically when init in stack

delete a; // manually delete when init in heap
```

## 🔸 Operator Overloading
This means giving special behavior to operators like `+`, `<<`, `>>`, `==` etc.
If we create a class, then try to use a standard defined operator, it gives an error because the compiler doesn't know what behaviours are expected with our custom made class.

## 🔸 Fixed-point Numbers
A number that can represent **decimals**, but internally it is stored as an **integer**. The “point” is called fixed because the number of decimal/fractional bits is always the same. For example, with **8 fractional bits**, the number is internally scaled by:
```cpp
2^8 = 256
```
Meaning:
```c
real value = raw value / 256
raw value  = real value * 256
```

### Simple example
Imagine you want to store: `10.0` Our `Fixed` class does not store `10.0` directly.

It stores:
```c
10 * 256 = 2560
```c
So internally:
```
_rawBits = 2560;
```
When we want to print it again:
```c
2560 / 256 = 10.0
```
So the user sees: `10`.

### Example with decimal

For:
```c
Fixed c(42.42f);
```
We calculate:
```c
42.42 * 256 = 10859.52
```
But `_rawBits` is an `int`, so it cannot store `.52`.

So we round:
```c
roundf(10859.52) = 10860
```
Then internally:
```c
_rawBits = 10860;
```
When converting back:
```c
10860 / 256 = 42.421875
```
So it prints approximately:
```c
42.4219
```
That is why fixed-point numbers can be close to decimals, but not always exact.

### Why use fixed-point?

Fixed-point is useful when you want decimal-like values but still want to use integer storage/calculation.

It is common in areas like:
- graphics
- audio processing
- embedded systems
- games
- financial-like calculations

The advantage is that the position of the fractional part is predictable.

### Fixed-point vs integer vs float
**Integer**
```c
int x = 42;
```
Can store whole numbers:
```
42
-5
100
```
But cannot store decimals:
```
42.42
```
**Floating-point**
```c
float x = 42.42f;
```
Can store very small and very large values, but the decimal point “floats”.

It has flexible range, but calculations can have surprising rounding issues.

### Fixed-point
```c
Fixed x(42.42f);
```
Stores decimals using an integer and a fixed scale.

#### Advantages and Disadvantages of Fixed-point Numbers
|Property |Fixed      |Float          |
|---------|-----------|---------------|
|Speed    |fast       |slower         |
|Precision|predictable|rounding errors|
|Range    |smaller    |large          |

## 🔸 Static Class Members
```cpp
static const int fractionalBits = 8
```
- All objects share the same value.
- Const means it cannot be modified.
- Static means it's shared by the whole class. (There is only one copy for the class, not per object, and all objects refer to it in one place in memory.)

## 🔸 Object Lifecycle
```cpp
Fixed a; // Default constructor
Fixed b(a); // Copy constructor
Fixed c; // Default constructor
c = b; // Copy assignment operator
```

## 🔸 Naming Conventions
| Thing | Style | Example |
|-------|-------|---------|
| Class | UpperCamelCase | Fixed |
| Function | lowerCamelCase | getRawBits() |
| Member variable | _lowerCamelCase | _rawBits |
| Local variable | lowerCamelCase | rawValue |

Note about using underscores:
Do not use double underscores like `__rawBits`. This is reserved for the compiler.

## 🔸 Returning Fixed&
The copy assignment operator returns `Fixed&`, meaning it returns a reference to the current object.

If we just return without the `&`, it would do this:
1. Assignment runs.
2. A new Fixed object is created. (We don't want this, it's extra work.)
3. That object is returned.
4. temporary object destroyed.

So when the function returns a referenced to the object, we would pair it with:
```cpp
return *this
```
The function would then do this:
1. Operator= runs
2. object updated
3. return reference to object

This also enables assignment chaining:
```cpp
a = b = c;
```
```cpp
b = c // (returns reference to b)
a = b
```

## 🔸 Operators are Functions
In C++ operators are functions.
Syntax:
```cpp
returnType ClassName::functionName(parameters)
Fixed& Fixed::operator=(const Fixed& other)
```
`Fixed&` - Return type
`Fixed::` - Class name. Function belongs to Fixed class
`operator=` - Function name.
Other operator function names that can be used:
```cpp
operator=
operator+
operator-
operator==
operator<
operator<<
```
When a compiler sees:
```cpp
a = b
```
It translates into something like:
```
a.operator=(b);
```
`(const Fixed& other)` - Parameter list
`Fixed` - The argument type
`&` - it's passed by reference
`const` - The function promises not to modify other
`other` - The parameter name



# CPP02 ex01 - Towards a more useful fixed-point number class
## 🔸 Goal
In ex01, the subject asks  to add constructors from `int` and `float`, conversion functions `toFloat()` and `toInt()`, and an overload for `operator<<`. `roundf` is authorized for this exercise.

## 🔸 Why we scale numbers
`_rawBits` is just an int, but we want to represent decimal numbers.
So we store numbers like this:
```c
stored_value = real_value * (2^_fractionalBits)
```
Since:
```c
2^8 = 256
```
we store:
```c
original_value * 256
```
For example:
```c
5.25 * 256 = 1344
```
so:
```c
_rawBits = 1344
```
In C++, this operation is equal to bit-shifting to the left:
```cpp
1 << 8
```
means:
```cpp
265
```
So when we initialize a `Fixed` object from an integer:
```cpp
Fixed b(10)
```
`10` is not the actuall value that we store. We actually store:
```cpp
10 * 256 = 2560

_rawBits = 2560;
```

Then when converting back to float:
```cpp
2560 / 256 = 10.0
```

## 🔸 Operator<<
Because shifting left by 8 is the same as multiplying by 256.
```cpp
10 << 8 = 2560
```
We use `<<` instead of `*`/multiplication because:
- It reflects bit-level fixed-point math (bit manipulation, bit shifting) instead of arithmetic
- It matches the fractional bits concept (We understand that it's related to `_fractionalBits`)
- It's common in low-level programming
- Historically it was faster than `*` (no performance gain today because modern compilers optimize this automatically)
- It scales automatically with `_fractionalBits`



## 🔸 `int` Constructor
This runs when you construct `Fixed` from an `int`.
```cpp
Fixed a(10);
```
Here, 10 is an integer, but `Fixed` stores values in `_rawBits` using fixed-point representation.
The internal value of `_fractionalBits` is 8.
Therefore, `2^8 = 256`.
So we take the real value (10) and multiply it by 256.
This is the equivalent of bitshifting 8 spaces to the left.

## 🔸 Converting from `int`
When we construct an int, we shift the into to make room for fractional bits
Conversion Example using the `int 5`

|Step|Operation|Binary|Decimal|
|----|---------|------|-------|
|Original int|5|0000000000000101|5|
|Shift left 8 bits|5 << 8|0000010100000000|1280|
|Equivalent math|5 * 256|0000010100000000|1280|

Therefore when we look at the code:
```cpp
_rawBits = value << _fractionalBits;
```
it means:
```c
value * (2 ^ fractionalBits)
```

Stored `_rawBits` example:
|Real number|Stored number in `_rawBits`|
|-----------|---------------------------|
|1|256|
|2|512|
|5|1280|
|10|2560|

## 🔸 Converting from float
When converting from a `float`, we still need the same scaling idea as bit shifting, but we cannot shift the `float` directly. So we calculate the shift value separately, then multiply.
 However, bit shifting (`<<`, `>>`) only works on integers types like `int`, `long`, `unsigned int`.
The compiler won't allow to shift a float because it's stored in a different way in memory, using "IEEE 754" format.
Syntax:
```
sign | exponent | mantissa
```
Example:
```
5.25
0 | 10000001 | 01010000000000000000000
```
We cannot shift `float` this directly because of how the binaries are constructed. Therefore we first compute:
```cpp
1 << _fractionalBits // fine cause 1 is int
```
Now the expression becomes
```
value * 256
```
which is valid because `float * int = float`.

## 🔸 Converting back to float
To convert a real value into the stored raw value:
```c
rawBits = real_value * scale
```

In code:
```c
_rawBits = roundf(real_value * (1 << _fractionalBits));
```
To convert the stored raw value back to a real float:
```c
real_value = rawBits / scale
```
In code:
```c
return static_cast<float>(this->_rawBits) / (1 << _fractionalBits);
```
We cast `_rawBits` to `float` because _rawBits is an `int`.

If both operands are integers, C++ performs integer division and removes the decimal part.

Example:
```c
10860 / 256
```
Both values are integers, so the result becomes:
```
42
```
But we want:
```c
42.421875
```
So we cast before division:
```c
static_cast<float>(10860) / 256
```
Now the division is floating-point division:
```c
42.421875
```
We only need to cast one side because if one operand is `float`, C++ automatically converts the other operand to `float` too.

Do not cast after the division:
```c
static_cast<float>(this->_rawBits / (1 << _fractionalBits))
```
This is wrong because the integer division already happened before the cast.

Because:
```c
static_cast<float>(10860 / 256)
```
becomes:
```c
static_cast<float>(42)
```
which gives:
```c
42.0
```
But:
```c
static_cast<float>(10860) / 256
```
gives:
```c
42.421875
```
## 🔸Simple mental model:

`int` value can use bit shift:
```cpp
value << 8
```
because it is an integer.

`float` value cannot use bit shift:
```cpp
value << 8 // impossible
```
so we do:
```cpp
value * (1 << 8)
```
which becomes:
```cpp
value * 256
```
That is the float-safe version of scaling.



## 🔸 Operator<< Fixed Function
Defines how a `Fixed` object is printed to an output
stream by converting it to a float and sending it to the stream.

It is a non-member operator because the left operand is `std::ostream`, not Fixed.

C++ let's us use operator syntax. So this:
```cpp
operator<<(std::cout, a);
```
can be written more naturally as:
```cpp
std::cout << a;
```
Many classes implement their output operator like this:
```cpp
std::ostream& operator<<(std::ostream& out, const MyClass& obj)
{
    out << obj.someValue();
    return out;
}
```
They convert the object to something the stream already knows how to print, which is how an infinite recursion doesn't happen.
After defining this, `std::cout` now understands one more type.
For example:
```cpp
Fixed a(5.25f);
std::cout << a;
```

## 🔸 Known operator<< Functions
This example:
```cpp
std::cout << 5 << " hello " << 3.14 << std::endl;
```
uses many different overloads of `operator<<` for different types.
These are all functions that look like this:
```cpp
std::ostream& operator<<(std::ostream& out, TYPE value);
```
Each overload handles a different `TYPE`

## 🔸 IEEE-754 Floating Point
References:
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html

Computers store numbers using bits, and for `int`s this is simple.
But `float`ing point numbers (numbers with decimals) are much harder
They store these using a format called IEEE-754 floating point.

#### Scientific Notation
Floating point numbers are Scientific notation in binary.
A floating point number is stored like this:
```
value = sign * mantissa * 2^exponent
```
Decimal scientific notation example:
```
1234 = 1.234 * 10^3
```
Binary floating point does the same:
```
1.101 * 2^5
```
#### How a float is stored in memory
So every float is stored as 3 parts.
|Part     |Description           |
|---------|----------------------|
|Sign     |Positive or Negative  |
|Exponent |How big the number is |
|Mantissa |The precision digits  |

A 32-bit float looks like this:
```
seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm
1   8              23
```
Example:
```
0 10000001 01100000000000000000000
```
|Part     |Description          |
|---------|---------------------|
|Sign     |0 = positive         |
|Exponent |power of 2           |
|Mantissa |Digits of the number |

#### How a float vs double is stored in memory
|type   |bits   |sign |exponent |mantissa |
|-------|-------|-----|---------|---------|
|float  |32-bit |1    |8        |23       |
|double |64-bit |1    |11       |52       |

#### Floating Point numbers are inexact
Some decimal numbers can't be represented exactly in binary.
`0.1` would have binary representation of `0.00011001100110011...`
This causes rounding errors.

If you add `0.1 + 0.2`, you would expect `3`, but you actuall get `0.30000000000000004`.
Internally, the computer is adding approximations:
```
0.10000000149
+
0.20000000298
```
This is not good for comparisons or for finances. Tiny rounding differences exist.

#### Precision limits
Floats have limited precision.

A float has 32 bits and precision of ~7 decimal digits.
a double has 64 bits and has precision of ~15 decimal digits.

#### Integer scaled by a constant
We use fixed point numbers to avoid floating point issues.
Instead of storing `3.5`, we store an integer scaled by a constant.
```
3.5 -> 896
3.5 * 256 = 896
```
In our project, `_rawBits` stores the scaled integer value.
The scaling factor is `(1 << _fractionalBits)`.
If `_fractionalBits = 8`:
```
(1 << 8) = 256
```
So internally, `_rawBits = value * 256`

#### Printing converts binary into decimal
1. Take the binary value stored in memory
2. Convert it to decimal digits
3. Print a decimal approximation
This introduces rounding.
So what gets printed may look like:
`0.100000001` or `0.099999999` depending on the algorithm and precision.

#### Alogrithms
Algorithms must
- round correctly
- avoid printing unnecessary digits
- be fast

Modern languages use special algorithms like:
- Dragon4
- Grisu
- Ryu

# CPP02 ex02 - Now we're talking

## 🔸 Goal
Add comparison operators, arithmetic operators, pre/post increment and decrement, and static min/max overloads to your Fixed class. It also says the increment/decrement must change the value by the smallest representable epsilon, which with 8 fractional bits is `1 / 256 = 0.00390625.`

## 🔸 Operator Overloading
Operator overloading means you teach C++ how an (already existing) operator should behave with your own class. So we define:
```c
Fixed Fixed::operator+(Fixed const &rhs) const;
// so a + b becomes
a.operator+(b)
```

## 🔸 Core arithmetic idea
```
_rawBits = real_value * 256 (because 2^8 is 256)
real_value = _rawBits / 256
```

## 🔸 Multiplication
```cpp
(static_cast<long>(rawA) * rawB) >> 8
```
1. Cast to long
   	- Prevents overflow during multiplication.
2. Multiply raw values
```
rawA * rawB
```
3. Shift right by 8
	- Divide by 256 to fix scaling
#### Why Shift Right
```c
rawA = a * 256
rawB = b * 256

rawA * rawB = a * b * 256 * 256 // double 256 from both a and b
```
But we want to store the result only as `rawResult = (a * b) * 256`. We have one too many `256`, hence:
```
(rawA * rawB) / 256
```
which is
```
(rawA * rawB) >> 8
```

## 🔸 Division
```cpp
(static_cast<long>(rawA) << 8) /rawB
```
1. Cast to long
	- Prevents overflow
2. Shift left by 8
	- increase precision (multiply by 256)
3. Divide
#### Why shift left
```
(rawA / rawB) = (a * 256) / (b * 256) = a / b
```
but we want to store the result `rawResult = (a / b) * 256`
So we multiply first
```
(rawA * 256) / rawB
```
which is
```
(rawA << 8) / rawB
```

## 🔸 Pre-increment (++i)
```cpp
Fixed& Fixed::operator++() {
    ++this->_rawBits;
    return *this;
}
```
1. Increment `_rawBits`
2. Return the current updated object (no copy needed)

## 🔸 Post-increment (i++)
```cpp
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++this->_rawBits;
    return temp;
}
```
1. Copy the current value
2. Increment `_rawBits`
3. Return old value


## 🔸 Accuracy vs Precision
### Accuracy
How close you are to the real/intended value.
```c
Fixed c(42.42f);
```
The true value we want is `42.42`. But our fixed point class cannot store every possible decimal. It stores an integer raw value with **8 fractional bits**:
```c
scale = 2^8 = 256
```

So:
```c
42.42 * 256 = 10859.52
```

But `_rawBits` is an `int`, so it cannot store `10859.52`. With `roundf()`:
```c
roundf(10859.52) = 10860 // this is what we store
```

When converting back:
```c
10860 / 256 = 42.421875
```

Difference with the original value:
```c
42.421875 - 42.42 = 0.001875
```

So the value is **not exact**, but it is **quite close**.

That closeness is **accuracy**.

### Precision
How small the steps are between representable values.
```c
static const int _fractionalBits = 8;
```

That means the smallest possible step is:
```c
1 / 256 = 0.00390625
```

So the `Fixed` class can represent values like:
```c
0
0.00390625
0.0078125
0.01171875
0.015625
...
```
But it cannot represent every decimal between them.
**More fractional bits** means **smaller steps**, therefore **more precision**.

### Very important difference
Imagine we want to store `42.42`. Our class stores:
```c
42.421875
```
This is **precise** in the sense that the class knows the value exactly as one of its allowed fixed-point steps.

But it is **not perfectly accurate** because the intended value was 42.42.

So:
```c
Stored value: 42.421875
Precision:   step size is 1/256
Accuracy:    error is 0.001875 away from 42.42
```

### Why `roundf()` is about accuracy
Without roundf():
```c
42.42 * 256 = 10859.52
```
If we directly store it as an int, C++ truncates:
```c
10859.52 -> 10859 // automatically rounding up / removes the decimals
```
Then:
```c
10859 / 256 = 42.41796875
```
Error:
```c
42.42 - 42.41796875 = 0.00203125
```
With `roundf()`:
```c
10860 / 256 = 42.421875
```
Error:
```c
42.421875 - 42.42 = 0.001875
```
So `roundf()` gives the **nearest representable fixed-point value**. That makes the stored value more accurate.

### Why _fractionalBits is about precision

This line controls precision:
```c
static const int _fractionalBits = 8;
```
Because:
```c
precision step = 1 / 2 ^ _fractionalBits
```
For this project:
```c
1 / 2^8 = 1 / 256 = 0.00390625
```
If you had only 4 fractional bits:
```c
1 / 16 = 0.0625
```
Less precise.

If you had 16 fractional bits:
```c
1 / 65536 = 0.0000152588
```
More precise.

But there is a **tradeoff**: if you use more bits for decimals, you have fewer bits left for the whole-number part, so the range becomes smaller.

### How this appears in ex02

This output from ex02:
```c
0
0.00390625
0.00390625
0.00390625
0.0078125
```
comes from precision.

When you do:
```c
++a;
```
you increase `_rawBits` by 1.

Since:
```c
real value = rawBits / 256
```
then:
```c
1 raw step = 1 / 256 = 0.00390625
```
So `++a `does not add 1.0.

It adds the `smallest representable amount`:
```
0.00390625
```
That is your `fixed-point precision`.

## 🔸 Increasing Precision
With `_fractionalBits` is set to 8, we have
```
[ 24 bits integer ][ 8 bits fraction ] = 32 bits
```
When we change our `_fractionalBits` to a higher number, like 10:
```
[ 22 bits integer ][ 10 bits fraction ]
2^10 = 1024
```
Our smallest step becomes smaller and more precise, but our maximum integer/range becomes smaller and we can't express as big of a number.


## Example `float`
### Storing 42.42f
```c
Fixed c(42.42f);
```
Step by step:
```c
value = 42.42
scale = 1 << 8 = 256

value * scale = 42.42 * 256
              = 10859.52
```
But `_rawBits` is an `int`, so it cannot store:
```c
10859.52
```
It needs a whole number.

So we use `roundf():`
```c
roundf(10859.52) = 10860
```
Then:
```
_rawBits = 10860
```

That raw integer means:
```c
10860 / 256 = 42.421875
```

## Retrieving `_rawbits` as float

When you call:
```c
c.toFloat()
```
your function does:
```c
float Fixed::toFloat(void) const
{
	return (static_cast<float>(_rawBits) / (1 << _fractionalBits));
}
```
Step by step:
```c
_rawBits = 10860
scale = 256

10860 / 256 = 42.421875
```
So:
```c
std::cout << c << std::endl;
```
prints approximately:
```c
42.4219
```
### Why not exactly 42.42?

Because with 8 fractional bits, your fixed-point class can only represent steps of:
```c
1 / 256 = 0.00390625
```
So it can represent values like:
```c
42.4140625
42.41796875
42.421875
42.42578125
```
But not every decimal exactly.

42.42 falls between two possible fixed-point values:
```c
42.41796875
42.421875
```
`roundf()` chooses the closer raw value.

So it stores:
```c
42.421875
```
which is close to 42.42.

### Float process summary
Float to Fixed:
1. Take the float value.
2. Multiply it by 256.
3. Round to the nearest whole number.
4. Store that whole number in _rawBits.

Fixed back to float:
1. Take _rawBits.
2. Convert it to float.
3. Divide by 256.
4. Return the decimal representation.


Memory trick:

To store float: multiply by 256 and round.
To retrieve float: divide by 256.
