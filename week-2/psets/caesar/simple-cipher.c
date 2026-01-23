#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int key;

char cipher_char(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (((c - 'a' + key) % 26) + 'a');
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return (((c - 'A' + key) % 26) + 'A');
	}
	else
	{
		return c;
	}
}

void print_cipher(char text[])
{
	for (int i = 0; text[i] != '\0'; i++)
	{
		printf("%c", cipher_char(text[i]));
	}
}

int main(void)
{
	key = get_int("key: ") % 27;
	string text = get_string("plaintext:  ");
	
	key %= 27;

	printf("ciphertext: ");
	print_cipher(text);
	printf("\n");

	return 0;
}
