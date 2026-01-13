#include <cs50.h>
#include <stdio.h>

void print_row(int space, int bricks);
void print_bricks(int bricks);

int main(void)
{
	int n;
	do
	{
		n = get_int("Height: ");
	}
	while (n < 0);
	for (int i = 0; i < n; i++)
	{
		print_row(n - i, i);
	}

}

void print_row(int space, int bricks)
{
	for (int i = 0; i < space; i++)
	{
		printf(" ");
	}
	print_bricks(bricks);
	printf(" ");
	print_bricks(bricks);
	printf("\n");
}

void print_bricks(int bricks)
{
	for (int i = 0; i <= bricks; i++)
	{
		printf("#");
	}
}
