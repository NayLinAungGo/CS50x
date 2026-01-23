#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void print_cipher(char text[], int key);

int main(int argc, string argv[])
{
	if (argc != 2)
	{
		printf("Missing command-line argument\n");
		return 1;
	}

	int key = 0;
	for (int i = 0; argv[1][i] != '\0'; i++)
	{
		if (!isdigit(argv[1][i]))
		{
			printf("Usage: %s key\n", argv[0]);
			return 1;
		}
		//printf("%ith digit: %c\n", i, argv[1][i]);
		// Shift key by 10 if key != 0
		key *= 10;
		// Subtracting by char '0' convert the char to int.
		key += argv[1][i] - '0';
	}
	key %= 27;

	string text = get_string("plaintext:  ");

	printf("ciphertext: ");
	print_cipher(text, key);
	printf("\n");

	return 0;
}

void print_cipher(char text[], int key)
{
	for (int i = 0; text[i] != '\0'; i++)
	{
		char c = text[i];
		if (c >= 'a' && c <= 'z')
		{
			c = ((c - 'a' + key) % 26) + 'a';
		}
 		else if (c >= 'A' && c <= 'Z')
		{
			c = ((c - 'A' + key) % 26) + 'A';
		}
		printf("%c", c);
	}
}
