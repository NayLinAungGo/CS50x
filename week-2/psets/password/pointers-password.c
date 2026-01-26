#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

bool valid(string password)
{
	int flags[4] = {0}, (*checkers[4])(int) = {isupper, islower, isdigit, ispunct};
	for (int i = 0, j = 0; password[i] != '\0'; i++)
	{
		char c = password[i];
		// TODO run checker[x][c] IF flag[x] != 0
		if (flags[j] != 0)
		{
			if (checkers[j](c))
			{
				flags[j]++;
				j++;
			}
		}
		if (j = 4)
		{
			return true;
		}
	}
	for (int i = 0; i <= 3; i++)
	{
		if (!flags[i])
		{
			return false;
		}
	}
	return true;
}
