#include <cs50.h>
#include <stdio.h>

void print_row(int bricks);

int main(void)
{
	int height;
	do {
		height = get_int("Height: ");
	}
	while (height <= 0);
	
	for (int i = 1; i <= height; i++)
	{
		print_row(i);
	}	
}

void print_row(int bricks)
{
	for (int i = 0; i < bricks; i++)
	{
		printf("#");
	}
	printf("\n");
}
