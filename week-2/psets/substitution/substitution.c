#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, string argv[])
{
	if (argc != 2)
	{
		return 1;
		printf("Usage: %s key\n", argv[0]);
	}

	if (argv[1][25 + 1] != '\0')
	{
		//printf("Key contain less or more characters than needed\n");
		return 2;
	}

	int letter_set[26] = {0};
	for (int i = 0; argv[1][i] != '\0'; i++)
	{
		char c = argv[1][i];
		if (!isalpha(c))
		{
			//printf("Key contains non-alphabetic characters\n");
			return 3;
		}

		int c_offset;
		if (islower(c))
		{
			//printf("Converted %c", argv[1][i]);
			argv[1][i] = toupper(argv[1][i]);
			//printf(" to %c\n", argv[1][i]);
			c_offset = c - 'a';
		}
		else
		{
			c_offset = c - 'A';
		}
		// If offset of char c index is already set in letter_set
		if (letter_set[c_offset])
		{
			//printf("Key contains repeated character: %c\n", c);
			return 4;
		}
		letter_set[c_offset]++;
	}

	string text= get_string("plaintext:  ");
	printf("ciphertext: ");
	for (int i = 0; text[i] != '\0'; i++)
	{
		char c = text[i];
		if (isupper(c))
		{
			printf("%c", argv[1][c - 'A']);
		}
		else if (islower(c))
		{
			printf("%c", tolower(argv[1][c - 'a']));
		}
		else
		{
			printf("%c", c);
		}
	}
	printf("\n");

	return 0;
}
