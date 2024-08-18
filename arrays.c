#include <stdio.h>

#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */
#define BLANK ' '
#define NEWLINE '\n'
#define TAB '\t'
#define MAXWORD 20 /* maximum lenght of words the program can handle */
#define CHARS 128

/* count digits, white spaace, others */
void count_digit_whitespace_and_others() {
    int c, i, nwhite, nother;
    int ndigit[10];

    // initialize varables
    nwhite = nother = 0;
    for (i = 0; i < 10; i++) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++ndigit[c-'0'];
        } else if (c == ' ' || c == '\n' || c == '\t') {
            ++nwhite;
        } else {
            ++nother;
        }
    }

    printf("digits =");
    for (i = 0; i < 10; ++i) {
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);
}

/*
    This program can run without tracking the state.
    But then state machines rock!
*/
void print_histogram_for_lenght_of_words() {
    // nw is the lenght of the word
    int c, nw, state;
    int lenghts[MAXWORD + 1] = {0};

    state = OUT;
    nw = 0;
    while ((c = getchar()) != EOF) {
        // if you encounter a space, tab or new line, the word has ended.
        if (c == BLANK || c == NEWLINE || c == TAB) {
            // check if we were in a word before the space
            if (state == IN) {
                if (nw <= MAXWORD) {
                    // if the word is within the character of accepted words
                    // increase the count of the lenght of the word
                    lenghts[nw]++;
                }
                nw = 0; // reset the word count
            }
            // set the state to out
            state = OUT;
        } else {
            // set state to in and increase the lenght of the word
            state = IN;
            nw++;
        }
    }
    // printing the histogram
    printf("Word lenght histogram:\n");
    for (int i = 1; i <= MAXWORD; i++) {
        printf("%2d: ", i);
        for (int j = 0; j < lenghts[i]; j++) {
            printf("#");
        }
        printf("\n");
    }
}

void print_histogram_for_freq_of_different_characters_of_input() {
    int c = 0;
    int freq[CHARS] = {0}; // the choice of 256 is abiturary.

    while ((c = getchar()) != EOF) {
        // character is already an int, so just map the array with it and increase as necessary
        if (c < CHARS) {
            freq[c]++;
        }
    }

    // print the historgram
    printf("Character frequency historgram:\n");
    for (int i = 0; i < CHARS; i++) {
        if (freq[i] > 0) {
            putchar(i);
            putchar(' ');
            for (int j = 0; j < freq[i]; j++) {
                putchar('#');
            }
            putchar('\n');
        }
    }
}

int main() {
    // count_digit_whitespace_and_others();
    // print_histogram_for_lenght_of_words();
    print_histogram_for_freq_of_different_characters_of_input();
}
