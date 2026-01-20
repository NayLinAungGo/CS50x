#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

#define SIZE 11

int calculate_points(char character);
int sum_points(string word);

int main(void)
{
	int sum_one = sum_points(get_string("Player 1: "));
	int sum_two = sum_points(get_string("Player 2: "));

	if (sum_one > sum_two)
	{
		printf("Player 1 wins!\n");
	}
	else if (sum_two > sum_one)
	{
		printf("Player 2 wins!\n");
	}
	else
	{
		printf("Tie!\n");
	}
}

int sum_points(string word)
{
	int sum = 0;
	for (int i = 0; word[i] != NULL; i++)
	{
		word[i] = (char)toupper((unsigned char)word[i]);
		sum += calculate_points(word[i]);
		//printf("Added to sum: %c +%ipts\n", word[i], calculate_points(word[i]));
	}
	return sum;
}

int calculate_points(char character)
{
	// A B C D E F G H I J K L M N O P  Q R S T U V W X Y  Z
	// 1 3 3 2 1 4 2 4 1 8 5 1 3 1 1 3 10 1 1 1 1 4 4 8 4 10
	char points[SIZE][SIZE] = {
		{0},
		{'A', 'E', 'I', 'L', 'N', 'O', 'R', 'S', 'T', 'U'},
		{'D', 'G'},
 		{'B', 'C', 'M', 'P'},
		{'F', 'H', 'V', 'W', 'Y'},
		{'K'},
		{0}, {0},
 		{'J', 'X'},
		{0},
		{'Q', 'Z'}
	};

    for (int i = 0; i < SIZE; i++)
	{
        for (int j = 0; j < SIZE; j++)
		{
            if (points[i][j] == character)
			{
                return i;
			}
		}
    }
    return 0;
}
