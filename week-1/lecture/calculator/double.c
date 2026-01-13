#include <cs50.h>
#include <stdio.h>

int main(void)
{
	long x = get_int("x: ");

	printf("%li\n", x * 2);
}
