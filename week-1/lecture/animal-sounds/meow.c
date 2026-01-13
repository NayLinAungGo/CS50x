#include <cs50.h>
#include <stdio.h>

void meow(void);

int main(void)
{
	int i = get_int("How many times should I meow? ");
	for(; i > 0; i--)
	{
		meow();
	}
}

void meow(void)
{
	printf("meow\n");
}
