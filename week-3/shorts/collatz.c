#include <cs50.h>
#include <stdio.h>

int my_collatz(int n);
int doug_collatz(int n);

int main(void)
{
	int n = 5000;
	printf("No: %i\n", n);
	printf("My Collatz: %i\n", my_collatz(n));
	printf("Doug's Collatz: %i\n", doug_collatz(n));
	return 0;
}

int my_collatz(int n)
{
	static int sum = 0;
	// base case
	if (n == 1)
		return sum;

	sum++; // keep track of the no. steps.
	// recursive cases
	if ((n % 2) == 0)
		return my_collatz(n / 2);
	return my_collatz(3 * n + 1);
}

int doug_collatz(int n)
{
	if (n == 1)
		return 0;
	else if ((n % 2) == 0)
	{
		printf("n is now: %i\n", n);
		return 1 + doug_collatz(n / 2);
	}
	return 1 + doug_collatz(3*n + 1);
}
