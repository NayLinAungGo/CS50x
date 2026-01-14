# Magic Numbers
C provides **preprocessor directive** (also called **macro**)\
for creating symbolic constants.
    #define NAME REPLACEMENT

If #include is similar to copy/paste,\
then #define is analogous to find/replace.

For example,
    #define PI 3.14159265
At the time the program is compiled,\
\#define goes through the code and replaces **PI** with ``3.14159265''.
