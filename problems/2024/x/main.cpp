
//
// Created by - on 6/17/24.
//

#include <stdio.h>
#include "credit/cs50.h"

int main(void) {
    //  Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    //  Add the sum to the sum of the digits that weren’t multiplied by 2.
    //  If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    long cc_number = get_long("Credit card number: ");
    long cc_number_copy = cc_number;
    int sum = 0;
    int count = 0;

    while (cc_number_copy > 0) {
        int digit = cc_number_copy % 10;
        if (count % 2 == 0) {
            sum += digit;
        } else {
            int product = digit * 2;
            sum += product / 10 + product % 10;
        }
        cc_number_copy /= 10;
        count++;
    }


    return 0;
}
