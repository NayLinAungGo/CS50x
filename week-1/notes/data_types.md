# Data Types & Variables
## The 5 primary types in C
### int

Integers always take up **4 bytes (32 bits)**.
int range from -2^(31) -- 0 -- 2^(31)-1

### unsigned int

Unsigned Integers range from 0 -- 2^(32)-1

### char

Characters take up **1 bytes (8 bits)**.

### float

Floating points value take up **4 bytes (32 bits)**.

### double

Double data type are *double precision*
They take up **8 bytes (64 bits)**

### void

Void is a *type*, but not a *data type*.
It is a placeholder for ``nothing''.


## CS50 library specific data types
### bool

Boolean value: **true** or **false**

### string

A series of characters.


## Creating & using variables
### Creating
    int number;
    char letter;
To have multiple variables of the same type:
    int height, width;
    float sqrt2, pi;

### Using
    int number; // declaration
    number = 17; // assignment
Or simultaneously declaring and setting the value of a variable:
    int number = 17; // initialization
