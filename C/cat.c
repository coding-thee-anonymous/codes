#include <stdio.h>
int main() {
    int a, b, area, perimeter;
    printf("enter length: ");
    scanf("%d", &a);

    printf("enter width: ");
    scanf("%d", &b);

    area = a * b;
    perimeter = 2 * (a + b);
    
    printf("area is: %d\n", area);
    printf("perimeter is: %d\n", perimeter);

    return 0;
}