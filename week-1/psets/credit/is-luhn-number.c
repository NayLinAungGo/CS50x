#include <cs50.h>
#include <stdio.h>

long checksum(long num);

int main(void)
{
	long number = get_long("Number: ");

	if (checksum(number))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
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
