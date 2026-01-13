#include <cs50.h>
#include <stdio.h>

int count_digits(int n);
int checksum(int n);

int main(void)
{
	long number = get_long("Number: ");
	int digits = count_digits(number);

	printf("number is %li and have %i digits\n", number, digits);
	checksum(number)
}

int checksum(long num)
{
	snprintf(char str[16], sizeof(str), "%d", num);
	int str_length = sizeof(str);
	for (int i = str_length--; i > 0; i - 2)
	{
		char multiplied_str[i] = str[i];
	}
}

int count_digits(int n)
{
	int count = 0;
	if (n == 0)
	{
		return 1;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return count;
}
