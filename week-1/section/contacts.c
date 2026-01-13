#include <cs50.h>
#include <stdio.h>

int main(void)
{
	string name = get_string("Name: ");
	int age = get_int("Age: ");
	string phone = get_string("Phone No.: ");
	string addr = get_string("Home Address: ");

	printf("New contact: %s, %i, lives in %s and can be reached at %s.", name, age, addr, phone);
}
