#include "cs50.h"
#include <stdio.h>

int main(void) {
    int n = get_int("Change owed: ");
    int coins = 0;
    while (n > 0) {
        if (n >= 25) {
            n -= 25;
            coins++;
        } else if (n >= 10) {
            n -= 10;
            coins++;
        } else if (n >= 5) {
            n -= 5;
            coins++;
        } else {
            n -= 1;
            coins++;
        }
    }

    return 0;
}
