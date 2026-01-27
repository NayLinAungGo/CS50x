# Lecture 2: Arrays

* [Debugging](#debugging)
    * [2 Types of Errors](#2-types-of-errors)
* [Compiling: 4 Stages of Compilation](#compiling-4-stages-of-compilation)
    * [Pre-processing](#pre-processing)
    * [Compiling](#compiling)
    * [Assembling](#assembling)
    * [Linking](#linking)
* [Arrays](#arrays)
    * [Strings](#strings)
    * [String Length](#string-length)
* [Command-Line Arguments](#command-line-arguments)
    * [Exit Status](#exit-status)

## Debugging

*Debugging* is the process of locating and removing bugs from your code.

One of the debugging techniques is *rubber duck debugging*,
where the programmer talk to an inanimate object (or themselves) to help think through the code and
why it is not working as intended.
When having challenges with the code, we should speak out loud.

### 2 Types of Errors

* Syntax Errors: wouldn't compile at all
* Logic Errors: would compile but do the wrong thing


## Compiling: 4 Stages of Compilation

A *compiler*, a specialized computer program that converts *source code* into machine code that can be understood by a computer.

### Pre-processing

* Removal of Comments
* Expansion of Macros
* Expansion of Header files

### Compiling

The pre-processed file is translated into Assembly language.

### Assembling

The *assembler* program converts the assembly code into machine code (binary).

### Linking

Finally, the pre-compiled machine code from the included libraries are combined with current code.
e.g. pre-compiled code stdio.c, cs50.c are linked with hello.c
The final executable is then outputted.


## Arrays

Each data type requires a certain amount of system resources
(these are typical sizes in the CS50 environment): 

* `bool` 1 byte
* `int` 4 bytes
* `long` 8 bytes
* `float` 4 bytes
* `double` 8 bytes
* `char` 1 byte
* `string` ? bytes

### Strings

A `string` is simply an `array` of values of type `char`: an array of characters.

String ends with a special character called a `NUL` character
(note: NUL with one L is the ‘\0’ character, different from NULL with two L’s.)

### String Length

A `string_length` function can be programmed by counting characters until NUL is located.

The `string.h` library, declared at the top of the file provides a function called strlen,
which calculates the length of the string passed to it:

    // Determines the length of a string using a function
    
    #include <cs50.h>
    #include <stdio.h>
    #include <string.h>
    
    int main(void)
    {
        // Prompt for user's name
        string name = get_string("Name: ");
        int length = strlen(name);
        printf("%i\n", length);
    }

This code *iterates* through each value in the string.
The program looks at each character. If the character is lowercase,
it subtracts 32 from the character’s ASCII value to convert it to uppercase.

    // Uppercases a string
    
    #include <cs50.h>
    #include <stdio.h>
    #include <string.h>
    
    int main(void)
    {
        string s = get_string("Before: ");
        printf("After:  ");
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                printf("%c", s[i] - 32);
            }
            else
            {
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }

When an ASCII lowercase letter (a-z) has 32 subtracted from it,
it results in the uppercase version of that same letter.
ASCII values chart:

     0 NUL    16 DLE    32      48 0    64 @    80 P    96 `   112 p 
     1 SOH    17 DC1    33 !    49 1    65 A    81 Q    97 a   113 q 
     2 STX    18 DC2    34 "    50 2    66 B    82 R    98 b   114 r 
     3 ETX    19 DC3    35 #    51 3    67 C    83 S    99 c   115 s 
     4 EOT    20 DC4    36 $    52 4    68 D    84 T   100 d   116 t 
     5 ENQ    21 NAK    37 %    53 5    69 E    85 U   101 e   117 u 
     6 ACK    22 SYN    38 &    54 6    70 F    86 V   102 f   118 v 
     7 BEL    23 ETB    39 '    55 7    71 G    87 W   103 g   119 w 
     8 BS     24 CAN    40 (    56 8    72 H    88 X   104 h   120 x 
     9 HT     25 EM     41 )    57 9    73 I    89 Y   105 i   121 y 
    10 LF     26 SUB    42 *    58 :    74 J    90 Z   106 j   122 z 
    11 VT     27 ESC    43 +    59 ;    75 K    91 [   107 k   123 { 
    12 FF     28 FS     44 ,    60 <    76 L    92 \   108 l   124 | 
    13 CR     29 GS     45 -    61 =    77 M    93 ]   109 m   125 } 
    14 SO     30 RS     46 .    62 >    78 N    94 ^   110 n   126 ~ 
    15 SI     31 US     47 /    63 ?    79 O    95 _   111 o   127 DEL 

`ctype.h` is another useful library that provides the `toupper` function.


## Command-Line Arguments

`Command-line arguments` are arguments that are passed to your program at the command line.

### Exit Status

When a program ends, a special exit code is provided to the computer.

When a program exits without error, a status code of `0` is provided to the computer.
Often, when an error occurs that results in the program ending, a status of `1` is provided to the computer.
