#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1, y = 2;
    int *p_x = malloc(sizeof(x)), *p_y = malloc(sizeof(y));
    if (p_x == NULL || p_y == NULL)
        return 1;

    p_x = &x; p_y = &y;

    printf("x is %i, y is %i\n", x, y);

    swap(p_x, p_y);

    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
