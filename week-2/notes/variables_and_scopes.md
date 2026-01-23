# Variables & Scopes
## Variable Scope

Scope is a characteristic of a variable that defines \
from which functions that variable may be accessed.

* Local variabbles: can only be accessed within the functions \
in which they are created.
* Global variables: can be accessed by any function.

### Local Variables

Here, x is local to the function triple().
No other function can refer to that variable, \
not even main(). result is local to main().

    int triple(int x); // declaration

    int main(void)
    {
        int result = triple(5);
    }

    int triple(int x)
    {
        return x * 3;
    }

### Global Variables

If a variable is declared outside of all functions, \
any function may refer to it.

    int triple(int x); // declaration

    #include <stdio.h>

    float global = 0.5050;

    int main(void)
    {
        triple();
        printf(“%f\n”, global);
    }

    void triple(void)
    {
        global *= 3;
    }
