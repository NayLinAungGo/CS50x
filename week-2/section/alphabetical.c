#include <cs50.h>
#include <stdio.h>

int main(void)
{
	string text = get_string("Input: ");
	for (int i = 0; text[i + 1] != '\0'; i++)
	{
		if (text[i] > text[i + 1])
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}
