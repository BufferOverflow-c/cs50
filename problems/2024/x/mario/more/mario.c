#include <stdio.h>
#include <cs50.h>

int main(void) {

    int n = 0;

    do {
        n = get_int("Size: ");
    } while (n < 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i + j < n - 1) {
                printf(" ");
            } else {
                printf("#");
            }
        }

        printf(" ");

        for(int j = 0; j < n; j++) {
            if(j <= i) {
                printf("#");
            }
        }

        printf("\n");
    }

    return 0;
}
