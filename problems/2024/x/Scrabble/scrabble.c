#include <cs50.h>
#include <stdio.h>

string convert_to_upper(string word);
int calc_score(string word);
void print_winner(int p1_score, int p2_score);

int main() {
    string p1_word = get_string("Player 1: ");
    string p2_word = get_string("Player 2: ");

    p1_word = convert_to_upper(p1_word);
    p2_word = convert_to_upper(p2_word);

    int p1_score = calc_score(p1_word);
    int p2_score = calc_score(p2_word);

    print_winner(p1_score, p2_score);

    return 0;
}

string convert_to_upper(string word) {
    for(int i = 0; word[i] != '\0'; i++) {
        if(word[i] >= 'a' && word[i] <= 'z') {
            word[i] -= 32;
        }
    }
    return word;
}

int calc_score(string word) {
    int score = 0;

    for(int i = 0; word[i] != '\0'; i++) {
        if(word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U' || word[i] == 'L' || word[i] == 'N' || word[i] == 'R' || word[i] == 'S' || word[i] == 'T') {
            score += 1;
        } else if(word[i] == 'D' || word[i] == 'G') {
            score += 2;
        } else if(word[i] == 'B' || word[i] == 'C' || word[i] == 'M' || word[i] == 'P') {
            score += 3;
        } else if(word[i] == 'F' || word[i] == 'H' || word[i] == 'V' || word[i] == 'W' || word[i] == 'Y') {
            score += 4;
        } else if (word[i] == 'K') {
            score += 5;
        } else if(word[i] == 'J' || word[i] == 'X') {
            score += 8;
        } else if(word[i] == 'Q' || word[i] == 'Z') {
            score += 10;
        }
    }
    return score;
}

void print_winner(int p1_score, int p2_score) {
    if(p1_score > p2_score) {
        printf("Player 1 wins!\n");
    } else if(p1_score < p2_score) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}
