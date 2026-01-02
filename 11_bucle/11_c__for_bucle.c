
#include <stdio.h>

int main(void) {

    for (int i = 1; i <= 9; i++) {          // rows
        for (int j = 1; j <= 9; j++) {      // columns
            printf("%d*%d=%-2d ", i, j, i * j);
        }
        printf("\n");
    }

    return 0;
}

