#include <cs50.h>
#include <stdio.h>

int main(void)
{
	int cents;
	do
	{
		cents = get_int("Change owed: ");
	}
	while (cents < 0);

	int coins[] = {25, 10, 5, 1}; 
	int sum = 0;
	for (int i = 0; cents > 0; i++)
	{
		// subtract cents incrementally from the biggest coin to lowest
		while (cents >= coins[i])
		{
			cents -= coins[i];
			// increment sum everytime a coin is subtracted
			sum++;
		}
	}
	printf("%i\n", sum);
}
