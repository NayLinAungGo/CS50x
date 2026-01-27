# Loops
## 3 Types of loops
### while loop

*Infinite* loop:

    while (true)
    {
    
    }

The code will execute repeatedly
until it is broken out (as with a break; statement)

    while (boolean-expr)
    {
    
    }

Only if the **boolean-expr** evaluates to true,
the code will execute repeatedly until **boolean-expr** evaluates to false.

### do-while loop

   do
   {
   
   }
   while (boolean-expr);

The code will execute at least once, and then,
if the **boolean-expr** evaluates to true,
will go back and repeat that process until **boolean-expr** evaluates to false.

### for loop

    for (start; expr; increment)
    {
    
    }

The statement(s) in **start** are executed. Then, **expr** is checked.
If it evaluates to true, the body of the loop executes.
If it evaluates to false, the body of the loop does not execute.
The statement(s) in **increment** are executed, and then **expr** is checked again.
