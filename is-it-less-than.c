#include <cs50.h>
#include <stdio.h>

int main(void)
{
	int x = get_int("What's the value of x? ");
	int y = get_int("What\'s the value of y? ");
	if (x != y)
	{
		if (x > y)
		{
			printf("x is less than y\n");
		}
		else
		{
			printf("x is not less than y\n");
		}
	}
	else
	{
		printf("x is equal to y\n");
	}
}
