# CPP03 Study Notes

## Table of Contents
- [CPP03 ex00 - Aaaaand... OPEN!](#cpp03-ex00---aaaaand-open)
  - [🔸 ClapTrap State](#-claptrap-state)
  - [🔸 ClapTrap Attack](#-claptrap-attack)
  - [🔸 ClapTrap Take Damage](#-claptrap-take-damage)
  - [🔸 ClapTrap Repair](#-claptrap-repair)
  - [🔸 Objects are State Machines](#-objects-are-state-machines)
- [CPP03 ex01 - Serena, my love!](#cpp03-ex01---serena-my-love)
  - [🔸 Inheritance](#-inheritance)
  - [🔸 Protected vs Private](#-protected-vs-private)
  - [🔸 Altered Default State](#-altered-default-state)
  - [🔸 Constructor Chaining](#-constructor-chaining)
  - [🔸 Method Specialization / Overriding Functions](#-method-specialization--overriding-functions)
  - [🔸 Adding Functionality](#-adding-functionality)
  - [🔸 Copy and Assignment in Inheritance](#-copy-and-assignment-in-inheritance)
  - [🔸 Destruction Order](#-destruction-order)
- [CPP03 ex02 - Repetitive work](#cpp03-ex02---repetitive-work)
  - [🔸 Reusable Base Class](#-reusable-base-class)

# CPP03 ex00 - Aaaaand... OPEN!
Ex00 is about managing state and understanding object behavior
## 🔸 ClapTrap State
Each instance of ClapTrap has its own independent values.
```cpp
    std::string _name;
    int         _hitPoints; // starts at 10
    int         _energyPoints; // starts at 10
    int         _attackDamage; // starts at 0
```
The constructor defines the starting state of the object.

## 🔸 ClapTrap Attack
This function checks if ClapTrap is alive and if it has energy, reduces `_energyPoints`, then prints an attack message.

## 🔸 ClapTrap Take Damage
This checks if ClapTrap is alive, reduces the `_hitPoints` to zero but no more negative than that, and prints a damage message.

## 🔸 ClapTrap Repair
This does the alive check and energy check, increases `_hitPoints` by the `amount`, reduces the `_energyPoints`, and then prints the repair message.

## 🔸 Objects are State Machines
Actions will modify the state of the object, and that affects future actions, like the use of hit points and energy points being adjusted on the object.

# CPP03 ex01 - Serena, my love!
This exercise is about inheritence, base class vs derived class, code reuse, and specialization.

## 🔸 Inheritance
```cpp
class ScavTrap : public ClapTrap
```
A ScavTrap is a ClapTrap, but with extra behavior.
It inherits from ClapTrap:
```cpp
_name
_hitPoints
_energyPoints
_attackDamage
takeDamage()
beRepaired()
```

Inheritance is reuse and specialization. Same core structure but with new stats, behavior, and extra abilities.

## 🔸 Protected vs Private
To allow inheritance, we've changed `private` member functions into `protected` member functions in the .hpp files.
```cpp
protected:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
```
Private is not accessible in child classes, but protected is.
## 🔸 Altered Default State
ScavTrap slters its default state, having more hp, energy, and higher damage. it "redefines ClapTrap's identity".

## 🔸 Constructor Chaining
```cpp
ScavTrap(std::string name) : ClapTrap(name)
```
1. ClapTrap constructor runs
2. ScavTrap constructor runs

## 🔸 Method Specialization / Overriding Functions
We override functions like `attack()`, and give it a new message.
This is called "method specialization"

## 🔸 Adding Functionality
We gave ScavTrap a special function called `guardGate()` that exists only here and not in the normal ClapTraps.

## 🔸 Copy and Assignment in Inheritance
```cpp
ScavTrap(const ScavTrap& other) : ClapTrap(other)

ClapTrap::operator=(other);
```
We reuse base class logic to prevent duplicate code and ensure correct copying of inherited members.

## 🔸 Destruction Order
Whenever a ScavTrap is destroyed, the ScavTrap destructor is called first, and then the ClapTrap destructor. The derivative always gets created last and destroyed first. (The reverse order of construction.)

# CPP03 ex02 - Repetitive work
## 🔸 Reusable Base Class
By creating FragTrap as a derivative of ClapTrap, we show that multiple different classes can inherit from the same base class.
We can:
- Reuse behavior (`attack`, `takeDamage`, `beRepaired`)
- Override or extend selectively (`attack`, `guardGate`)
- Have different stats


## More About Inheritance
The main idea:
> Inheritance lets one class reuse the attributes and functions of another class, then add or change only what is different.

Assume we have:
```c
ClapTrap  = base robot
ScavTrap  = special ClapTrap
FragTrap  = another special ClapTrap
DiamondTrap = mix of ScavTrap and FragTrap
```
### 1. What inheritance means
Through inheritance we can avoid writing the repetitive/common parts of the classes and have all child classes inherit the same basic state from the (more abstract/generalized) parent class.

With inheritance, we write the common part only once. Here we have `ClapTrap` as the parent class:
```c
class ClapTrap
{
protected:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

public:
	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
```
Then `ScavTrap` can reuse it:
```c
class ScavTrap : public ClapTrap
{
public:
	void guardGate(void);
};
```
And we can also have another class `FragTrap` inherits from `ClapTrap`:
```c
class FragTrap : public ScavTrap
{
public:
	void highFivesGuys(void);
};
```

So inheritance means:
```
ScavTrap has everything a ClapTrap has,
plus ScavTrap-specific behavior.

FragTrap has everything a ClapTrap has,
plus FragTrap-specific behavior.
```

## 2. Access Specifier
Used to control the visibility and accessibility of class members. There are three types: `public`, `protected`, and `private`:

- **public inheritance**: Makes the public and protected members of the base class public and protected in the derived class respectively.The same level of access is preserved in the derived class.

  | Base Class    | Child Class |
  | -------- | ------- |
  | public  | public    |
  | protected | protected     |
  | private | not accessible     |


- **protected inheritance**: Make the public and protected members of the base class protected in the derived class. Restricts the access to the members outside the class hierarchy, while keeping them accessible within the class and its derived classes.
  | Base Class    | Child Class |
  | -------- | ------- |
  | public  | protected    |
  | protected | protected     |
  | private | not accessible     |

- **private inheritance**: Both the public and protected members of the base class private in the derived class. TThese members can no longer be accessed from objects of the derived class, only from within the derived class itself (essentially turning all inherited members into private members of the derived class).
  | Base Class    | Child Class |
  | -------- | ------- |
  | public  | private    |
  | protected | private     |
  | private | not accessible     |

```c
class Base {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;
};

class PublicDerived : public Base {
    // publicVar is public
    // protectedVar is protected
    // privateVar is not accessible
};

class ProtectedDerived : protected Base {
    // publicVar is protected
    // protectedVar is protected
    // privateVar is not accessible
};

class PrivateDerived : private Base {
    // publicVar is private
    // protectedVar is private
    // privateVar is not accessible
};
```

## 3. Multiple inheritance and the diamond problem

Right now we have:
```
      ClapTrap
      /      \
ScavTrap   FragTrap
```
In ex03, you create:
```c
class DiamondTrap : public ScavTrap, public FragTrap
```
```
Now the shape becomes:

        ClapTrap
        /      \
   ScavTrap   FragTrap
        \      /
      DiamondTrap
```
That is the **diamond**.

The problem is that without virtual inheritance, DiamondTrap gets **two** ClapTrap parts:
```c
DiamondTrap object
{
	ScavTrap part
	{
		ClapTrap part
	}

	FragTrap part
	{
		ClapTrap part
	}
}
```
So there are two _names, two _hitPoints, two _energyPoints, two _attackDamages.

Then this becomes ambiguous:
```c
diamond.attack("enemy");

// or

diamond.takeDamage(10);
```
The compiler may not know whether to use the `ClapTrap` part from `ScavTrap` or the one from `FragTrap`.

That is the diamond problem.

## 4. Virtual inheritance preview

To fix that, you can make `ScavTrap` and `FragTrap` **virtually inherit** from `ClapTrap`:
```c
class ScavTrap : virtual public ClapTrap
class FragTrap : virtual public ClapTrap
```
Then DiamondTrap gets only one shared ClapTrap part:
```c
DiamondTrap object
{
	one shared ClapTrap part
	ScavTrap part
	FragTrap part
	DiamondTrap part
}
```


