#include <cs50.h>
#include <stdio.h>

void howl(int n);

int get_howl_length(void);

int main (void)
{
	int n = get_howl_length();
	howl(n);
}



int get_howl_length(void)
{

	int n;
	do
	{
		n = get_int("How long should I howl? ");
	}
	while (n < 1);
	return n;
}

void howl(int n)
{
	printf("A-h");
	for (int i = 0; i < n; i++)
	{
		printf("o");
	}
	printf("\n");
}
