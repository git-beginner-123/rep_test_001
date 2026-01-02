
#include <stdio.h>

#define LAMP_COUNT 40

/* 
 * ROUND line prefix length:
 * "ROUNDxx : "  -> 10 characters
 * "BIT : "      -> 6  characters
 * Need 4 spaces padding after "BIT : "
 */

void printBitHeader(void) {
    printf("BIT : ");
    printf("    ");   // padding to align with "ROUNDxx : "

    for (int i = LAMP_COUNT - 1; i >= 0; i--) {
        printf("%2d ", i);
        if (i % 5 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

void printRoundLine(int round, unsigned long long lights) {
    printf("ROUND%02d : ", round);

    for (int i = LAMP_COUNT - 1; i >= 0; i--) {
        printf("%2d ", (int)((lights >> i) & 1ULL));
        if (i % 5 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main(void) {
    unsigned long long lights = 0;

    /* print BIT index line once */
    printBitHeader();

    /* rounds 1 ~ 40 */
    for (int round = 1; round <= LAMP_COUNT; round++) {

        for (int i = 0; i < LAMP_COUNT; i++) {
            if ((i + 1) % round == 0) {
                lights ^= (1ULL << i);   // XOR toggle
            }
        }

        printRoundLine(round, lights);
    }

    return 0;
}

