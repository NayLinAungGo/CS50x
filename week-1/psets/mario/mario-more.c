#include <cs50.h>
#include <stdio.h>

void print_char(char c, int times);

int main(void)
{
	int height;
	do
	{
		height = get_int("Height: ");
	}
	while (height < 0);

	for (int i = 0; i < height; i++)
	{
		int row = i + 1; // Current row no.

		// Print: left padding; bricks; gap; bricks.
		print_char(' ', height - row);
		print_char('#', row);
		printf(" ");
		print_char('#', row);
		printf("\n");
	}
}

void print_char(char c, int times)
{
	for (int i = 0; i < times; i++)
	{
		printf("%c", c);
	}
}
