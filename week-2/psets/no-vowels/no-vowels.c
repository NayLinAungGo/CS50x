#include <cs50.h>
#include <stdio.h>

void print_char_without_vowel(char c);

int main(int argc, string argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s word\n", argv[0]);
		return 1;
	}

	printf("argc: %i\n", argc);
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			print_char_without_vowel(argv[i][j]);
		}
		printf(" ");
	}
	printf("\n");
	return 0;
}

void print_char_without_vowel(char c)
{
	switch (c)
	{
		case 'a':
			printf("6");
			break;

		case 'A':
			printf("6");
			break;

		case 'e':
			printf("3");
			break;

		case 'E':
			printf("3");
			break;

		case 'i':
			printf("1");
			break;

		case 'I':
			printf("1");
			break;

		case 'o':
			printf("0");
			break;

		case 'O':
			printf("0");
			break;

		default:
			printf("%c", c);
			break;
	}
	return;
}
