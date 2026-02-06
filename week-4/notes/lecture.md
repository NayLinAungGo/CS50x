# Lecture 3: Memory

## Hexadecimal

Base-8 can be represented by arabic numerals

    0 1 2 3 4 5 6 7 8 9

Base-16---also called hexadecimal---uses some alphabets

    0 1 2 3 4 5 6 7 8 9 A B C D E F

Addresses in computer memory are indexed in hexadecimal notation
which is prefixed with `0x` for clarity. e.g. `0x10` for 16th index


## Pointers

In C two operators that relate to memory are:

* `&` Provides the address of something stored in memory
* `\*` Instructs the compiler to go to a location in memory

Pointers are variables that piont to the address of a another variable

```c
int n = 50;
int *p = &n; // pointer *p points to the address of n
```
