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
	int flags[4] = {0};
	for (int i = 0; password[i] != '\0'; i++)
	{
		char c = password[i];
		if (isupper(c))
		{
			flags[0]++;
		}
		else if (islower(c))
		{
			flags[1]++;
		}
		else if (isdigit(c))
		{
			flags[2]++;
		}
		else
		{
			flags[3]++;
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
