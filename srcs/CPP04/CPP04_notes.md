# CPP04 ex00 - Polymorphism
## 🔸 Subtype Polymorphism
You can use a base class or reference, but the program calls the derived class version of a function.
That means you can store a derived object behind a base pointer:
```cpp
Animal* a = new Dog();
a->makeSound();
```
Even though the pointer type is `Animal*`, we want the real object type to decide the function call. Since the real object is a `Dog`, the program should call `Dog::makeSound()`, not `Animal::makeSound()`.

This only happens if the base function is marked `virtual`:
```c
virtual void makeSound(void) const;
```

Without `virtual`, C++ chooses the function based on the type of pointer (`Animal*`), not the real object (`Dog`). With virtual, it checks the actual object the pointer is pointing to.
The code should print the sounds of Dog and Cat, not Animal.

## 🔸 Virtual Functions
in `Animal`, `makeSound()` is declared as:
```cpp
virtual void makeSound() const;
```
This tells C++, when calling through an `Animal*` or `Animal&`, use the real object's version.

`Dog` and `Cat` override this function.

## 🔸 Overriding
Dog and Cat should each provide their own version of makeSound().
It's the same function name, parameters, const.
```cpp
void makeSound() const;
```
If the signature is different, it may not override.
Overridding functions must have the same return type, parameters, and same mark as `const`.

## 🔸 Virtual Destructor
If you do:
```cpp
const Animal* a = new Dog();
delete a;
```
and the base destructor is not marked as `virtual`, deleting through the base pointer is wrong behavior.
For polymorphic base classes, the destructor should be virtual:
```cpp
virtual ~Animal();
```

## 🔸 Static Binding vs Dynamic Binding
without `virtual`:
- binding happens at compile time
- based on declare type
- this is what `WrongAnimal` shows

with `virtual`:
- binding happens at runtime
- based on real object type
- this is what `Animal` shows

## 🔸 WrongAnimal / WrongCat
`WrongAnimal::makeSound()` is not virtual.
Therefore:
```cpp
const WrongAnimal* w = new WrongCat();
w->makeSound();
```
calls `WrongAnimal::makeSound()` instead of
`WrongCat::makeSound()`

because dispatch is based on the pointer type, not the real object.

## 🔸 Copy constructor behavior / redundancy
When writing:
```cpp
Cat::Cat(const Cat& other) : Animal(other) {
}
```
you are already copying everything inside the object.
The `Animal` copy constructor already does:
```cpp
Animal::Animal(const Animal& other) {
	*this = other;
}
```

So when you execute
```cpp
Cat a = b;
```
The base copy constructor works, and nothing else needs to be added.
If you put `*this = other;` in the `Cat` copy constructor, it would copy the type twice. Once with `Animal(other)` and the other time with `*this = other` inside of the `Cat` copy constructor, which calls the operator overload `Cat::operator=(other)`

You would only need to put in extra stuff if `Cat` had extra data or member variables.

`Cat` does not introduce any new members beyond `Animal`, and `Animal(other)` already copies all the data (`type`), so not additional copying is needed.

However, operator overloads need to be implemented because Cat is a different class.

# CPP04 ex01 - I don’t want to set the world on fire
## 🔸 Deep Copy
Instead of copying the pointer itself, you copy the object it points to.
A bad shallow copy:
```cpp
this->_brain = other._brain;
```
A good deep copy:
```cpp
this->brain = new Brain(*other._brain);
```
If you only did a shallow copy, both copies would point to the same brain. With a deep copy, you create a brain for each animal.

#### Copy assignment operator example:
```cpp
Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        // this->type = other.type; This is a shallow copy and does not work
        Animal::operator=(other); // Copy base part
        delete this->brain // Clean old memory
        this->brain = new Brain(*other.brain); // Deep copy, copy the actual content
    }
    return *this;
}
```
We must:
- copy the type
- create a new brain
- copy its contents

# CPP04 ex02 - Abstract class
In Previous exercises, `Animal` was a normal base class.
But conceptually, that's weird. "Animal" is too generic. What exists is a Dog and Cat.
Instead of saying "Animal has a default generic behavior", we will now say "Animal is only a base concept. We will never create one directly.
This is what an abstract class is for.

## 🔸 Abstract Classes
An abstract class is a class that is meant to be a base class onl.
It's used to:
- define a common interface
- force derived classes to provide their own implementation
- prevent direct instantiation of the base class

We will no longer be allowed to do:
```cpp
Animal a;
Animal* a = new Animal();
```
But this will still be valid:
```cpp
Animal* a = new Dog();
Animal* b = new Cat();
```

## 🔸 Pure virtual functions
A pure virtual function is a virtual function with = 0.
Example:
```cpp
virtual void makeSound() const = 0;
```
This means:
- The function belongs to the base class interface
- The base class doesn't provide a usable implementation for it
- Every concrete derived class must override it

THat's what makes it abstract.

## 🔸 Virtual vs Pure Virtual
Virtual:
```cpp
virtual void makeSound() const;
```
This means:
- Derived classes can override it
- base class can still have its own implementation
- base class objects can still be created

Pure virtual function:
```cpp
virtual void makeSound() const = 0;
```
This means:
- Derived classes are expected to override it
- The class becomes abstract
- You can't instantiate the base class anymore

If a derived class does not override `makeSound()`, that derived class also becomes abstract.

## 🔸 Abstraction
Without abstraction, this is possible:
```cpp
Animal a; // Not allowed in abstraction
a.makeSound();
```
But we don't know what a generic animal sound would make.
If we make it abstract, it forces you to create something real, like a `Dog` or `Cat`, where `makeSound()` will always make sense.

An abstract idea acts like a contract.
Animal says:
- every derived animal must have a type
- every derived animal must know how to makeSound()

So `Animal defines what derived classes must do.
`Dog` and `Cat` define how they do it.

## 🔸 Polymorphism in Abstract classes
Works the same still.
```cpp
Animal* a = new Dog();
Animal* b = new Cat();

a->makeSound();
b->makeSound();
```
still calls the correct things
```cpp
Dog::makeSound()
Cat::makeSound()
```

## 🔸 Concrete class vs abstract class
#### Concrete class
A class you can instantiate:
```cpp
Dog dog;
Cat cat;
```
#### Abstract class
A class you cannot instantiate:
```cpp
Animal animal; // Error
```



