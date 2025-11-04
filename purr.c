#include <cs50.h>
#include <stdio.h>

void purr(int n);

int main(void)
{
	int n;
	do
	{
		n = get_int("How many times should I purr? ");
	}
	while (n < 1);
	purr(n);
}

void purr(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("purr\n");
	}
}
