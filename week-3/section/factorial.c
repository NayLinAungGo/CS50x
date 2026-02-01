#include <cs50.h>
#include <stdio.h>

int factorial(int n);
int recursive_factorial(int n);

int main(void)
{
    int n = get_int("Number: ");
    printf("%i! = %i\n", n, recursive_factorial(n));
    return 0;
}

int recursive_factorial(int n)
{
    // Base case:
    if (n == 0)
        return 1;

    // Recursive case:
    return n * recursive_factorial(n - 1);
}

int iterative_factorial(int n)
{
    if (n == 0)
        return 1;

    for (int i = n - 1; i != 1; i--)
        n *= i;

    return n;
}
