#include <cs50.h>
#include <stdio.h>

int fib(int n);
void print_reverse_fib_seq(int n);

int main(void)
{
    int n = get_int("Number: ");
    printf("fib: %i\n", fib(n));
    print_reverse_fib_seq(n);
}

void print_reverse_fib_seq(int n)
{
    if (n == 0)
    {
        printf("...\n");
        return;
    }
    printf("%i, ", fib(n));
    print_reverse_fib_seq(n - 1);
}

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return(fib(n - 1) + fib(n-2));
}
