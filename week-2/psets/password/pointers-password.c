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
	int passed[4] = {0}, passed_total = 0;
	// array of function pointer: return_type (*array_name[size])(input_type);
	int (*checkers[4])(int) = {isupper, islower, isdigit, ispunct};
	for (int i = 0; password[i] != '\0' && passed_total != 4; i++)
	{
		char c = password[i];
		for (int j = 0; j < 4; j++)
		{
			// Don't check again if the check is already passed.
			if (!passed[j] && checkers[j](c))
			{
				passed[j]++, passed_total++;
			}
		}
	}
	return (passed_total == 4);
}
