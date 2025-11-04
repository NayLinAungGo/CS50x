#include <cs50.h>
#include <stdio.h>

int main(void)
{
	string answer = get_string("What's your name? ");
	printf("hello, %s\n", answer);	
	int age = get_int("What's your age? ");
	printf("Your age is %i\n", age);
}
