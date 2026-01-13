#include <cs50.h>
#include <stdio.h>

int main(void) {
	int cents, coins[] = {25, 10, 5, 1}, sum = 0;
	do {
		cents = get_int("Change owed: ");
	}
	while (cents < 0);

	for (int i = 0; i < 4; i++) {
		// Add no. coins that fit into current cents to sum.
		sum += cents / coins[i];
 		// Leave cents with the remainder from current coin.
		cents %= coins[i];
	}
	printf("%i\n", sum);
}
