#include <cs50.h>
#include <stdio.h>

int main(void)
{
	int i = get_int("How many times should I meow? ");
	for(; i > 0 ; i--)
	{
		printf("meow\n");
	}
}
