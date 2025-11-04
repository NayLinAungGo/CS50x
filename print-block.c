#include <cs50.h>
#include <stdio.h>

int main(void)
{
	const int n = get_int("How big should the block be? ");

	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < n; i++)
		{
			printf("#");
		}
		printf("\n");
	}
}
