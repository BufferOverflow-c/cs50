#include <cs50.h>
#include <stdio.h>
#include <math.h>

void calculate_text(int *letters, int *words, int *sentences, string text);
float compute_index(float letters, float sentences);
void print_grade(int grade);

int main() {

    string text = get_string("Text: ");
    int letters = 0;
    int words = 0;
    int sentences = 0;

    calculate_text(&letters, &words, &sentences, text);
    print_grade((int)compute_index((100.0*((float)letters)/(float)words), (100.0*((float)sentences)/(float)words)));

    return 0;
}

void calculate_text(int *letters, int *words, int *sentences, string text) {
    for(int i = 0; text[i] != '\0'; i++) {
        if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            *letters += 1;
        } else if(text[i] == ' ') {
            *words += 1;
        } else if(text[i] == '.' || text[i] == '!' || text[i] == '?') {
            *sentences += 1;
        }
    }
    *words += 1;
}

float compute_index(float letters, float sentences) {
    return round(0.0588 * letters - 0.296 * sentences - 15.8);
}

void print_grade(int grade) {
    if(grade < 1) {
        printf("Before Grade 1\n");
    } else if(grade >= 1 && grade < 16) {
        printf("Grade %i\n", grade);
    } else {
        printf("Grade 16+\n");
    }
}
