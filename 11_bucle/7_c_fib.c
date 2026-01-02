
#include <stdio.h>

int main(void) {
    int n;
    int count = 3;
    int f1 = 1, f2 = 1, fn = 1;

    printf("Enter N: ");
    scanf("%d", &n);

    if (n == 1 || n == 2) {
        printf("Fibonacci(%d) = 1\n", n);
        return 0;
    }

    do {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
        count++;
    } while (count <= n);

    printf("Fibonacci(%d) = %d\n", n, fn);

    return 0;
}

