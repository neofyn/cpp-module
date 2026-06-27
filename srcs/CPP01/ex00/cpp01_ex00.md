# CPP01 ex00 - BraiiiiiiinnnzzzZ

### Goal
Understanding object lifetime, stack allocation, heap allocation, new, delete, constructors, and destructors.

### Required Behavior
zombie announces itself like this:
```
<name>: BraiiiiiiinnnzzzZ...
```
For example:
```
Foo: BraiiiiiiinnnzzzZ...
```
The destructor must also print a message with the zombie name, so we can see when the zombie is destroyed.

### Learning Checklist
- [ ] how to create a class
- [ ] how constructors initialize objects
- [ ] how destructors show object destruction
- [ ] when to use stack allocation
- [ ] when to use heap allocation
- [ ] why heap objects need delete
- [ ] why returning the address of a local stack object is wrong
- [x] why `newZombie(`) and `randomChump()` are free functions vs. member functions

#### 1. Free Functions vs. Member Functions
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
---
On the other hand `newZombie()` and `randomChump` are outside the class and are called `normal/free functions`. So we do not call them on a zombie object.We call them directly because they do not belong to a specific Zombie object:
```c
Zombie *zombie = newZombie("Bob");

randomChump("Alice");
```
They are declared ouside the Zombie class because they are helper functions and not actions that an existing zombie does.


#### 2. `const` at the end of a function
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
##### Important:
A `const` after a member function means this function promises not to modify the object it is called on. Only class member functions can have this final `const`. A `const` object is **only** allowed to call member functions that are **also** marked `const`.

So in this exercise `announce` belongs to `Zombie` and promises not tochange this Zombie. This would be forbidden:
```c
void	Zombie::announce(void) const
{
	_name = "Other Bob"; // Error, because announce is const
}
```

#### 3. Stack vs. Heap Allocation
In simple terms:
> **Stack allocation** means C++ automatically destroys the object when the funciton/block ends.
**Heap allocation** means we manually create the object with `new`, and we must manually destroy it with `delete`.

##### 3.1 Stack Allocation
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

##### 3.2 Heap Allocation
```c
Zombie *newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name); // creates a `Zombie` object on the heap
	return zombie;
}
```
Here a `Zombie` object is created using `new` and store in **heap**. The result is a pointer. A heap object does **not** disappear automatically when the function ends. So, using `new` is like telling C++:
> Allocate memory for a Zombie, construct it, and give me its address.

So later, we must manually delete it with:
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

##### 3.3 When to use
In general:

> Use **stack** when the object is only needed in the current function/block.
Use **heap** when the object must survive after the function returns.
