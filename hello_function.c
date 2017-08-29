#include <stdio.h>


int add_demo(int x, int y)
{
    return x + y;
}

int main(void)
{
    int x, y, z;

    printf("Please enter a number - x: ");
    scanf("%d", &x);

    printf("Please enter a number - y: ");
    scanf("%d", &y);

    z = add_demo(x, y);
    printf("x + y = %d\n", z);

    return 0;
}
