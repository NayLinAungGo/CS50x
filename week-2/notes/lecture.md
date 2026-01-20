# Lecture Notes
## Debugging: 2 Types of Errors
### Syntax Errors
Wouldn't compile at all.

### Logic Errors
Would compile but do the wrong thing.


## Compiling: 4 Stages of Compilation
### Pre-processing
* Removal of Comments
* Expansion of Macros
* Expansion of Header files

### Compiling
The pre-processed file is translated into Assembly language.

### Assembling 
The Assembler program converts the Assembly code into machine code (binary).

### Linking
The Linker links the pre-compiled machine code \
from the included libraries is combined with current code.
e.g. pre-compiled code stdio.c, cs50.c are linked with hello.c
The final executable file is then outputted.

## Arrays
### Typical Sizes for Data Types
* bool 1 byte
* int 4 bytes
* long 8 bytes
* float 4 bytes
* double 8 bytes
* char 1 byte
* string ? bytes

