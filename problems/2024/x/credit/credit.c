#include <cs50.h>
#include <stdio.h>

int main(void) {
    //  Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    //  Add the sum to the sum of the digits that weren’t multiplied by 2.
    //  If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    long cc_number = get_long("Credit card number: ");
    long cc_number_copy = cc_number;
    int sum = 0;
    int count = 0;


    while(cc_number_copy > 0) {
        int digit = cc_number_copy % 10;
        if(count % 2 == 0) {    // every other digit gets added together starting from the second to last digit
            sum += digit;
        } else {
            int product = digit * 2;    // multiply every other digit by 2 starting from the last digit
            sum += product / 10 + product % 10;
        }
        cc_number_copy /= 10;
        count++;
    }

    if(sum % 10 == 0) {
        if(count == 15 && (cc_number / 10000000000000 == 34 || cc_number / 10000000000000 == 37)) {
            printf("AMEX\n");
        } else if(count == 16 && (cc_number / 100000000000000 == 51 || cc_number / 100000000000000 == 52 || cc_number / 100000000000000 == 53 || cc_number / 100000000000000 == 54 || cc_number / 100000000000000 == 55)) {
            printf("MASTERCARD\n");
        } else if((count == 13 || count == 16) && (cc_number / 1000000000000 == 4 || cc_number / 1000000000000000 == 4)) {
            printf("VISA\n");
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }

    return 0;
}
