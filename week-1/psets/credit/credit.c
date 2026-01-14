#include <cs50.h>
#include <stdio.h>

#define TRILLION 1000000000000L

long checksum(long num);

int main(void)
{
	long number = get_long("Number: ");

	// Guard Clause: number must be from 13 digits to 16 digits and pass checksum
	if (number >= TRILLION && number < (10000 * TRILLION) && checksum(number))
	{
		number /= TRILLION; // Truncate number by 13 digits. 

		// American Express: 15 digits; start w/ 34 or 37
		if ((number / 10) == 34 || (number / 10) == 37)
			{
				printf("AMEX\n");
			}
		// MasterCard: 16 digits; start w/ 51, 52, 53, 54, or 55
		else if ((number / 100) >= 51 && (number / 100) <= 55)
			{
				printf("MASTERCARD\n");
			}
		// Visa: 13 or 16 digits; start w/ 4
		else if (number == 4 || (number / 1000) == 4)
			{
				printf("VISA\n");
			}
	}
	else 
	{
		printf("INVALID\n");
	}
}

long checksum(long num)
{
	int sum = 0;
	while (num > 0)
	{
		// Add 1st digit to sum.
		sum += num % 10;
		num /= 10;

		// Double 2nd digit then add the individual digits together to sum.
		int doubled = (num % 10) * 2;
		sum += (doubled % 10) + (doubled / 10);
		num /= 10;
	}
	return (sum % 10 == 0);
}
