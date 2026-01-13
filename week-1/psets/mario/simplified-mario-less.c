#include <cs50.h>
#include <stdio.h>

int main(void) {
	int n;
	do n = get_int("Height: "); while (n < 0);

	for (int i = 1; i <= n; i++) {
		printf("%*s", n - i, "");
		for (int x = 0; x < i; x++) { printf("#"); }
		printf("\n");
	}
}
