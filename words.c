#include <stdio.h>

/*
    Count lines, words, and characters in input
*/
#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */
#define BLANK ' '
#define NEWLINE '\n'
#define TAB '\t'
void count_words() {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == NEWLINE) {
            ++nl;
        }

        if (c == BLANK || c == NEWLINE || c == TAB) {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}

/*
    Print an input one word per line
*/
void print_word_per_line() {
    int c;
    while ((c = getchar()) != EOF) {
        if ( c == BLANK || c == NEWLINE || c == TAB) {
            // print a new line
            putchar('\n');
        } else {
            // we are still in the word
            // print the character of a word
            putchar(c);
        }
    }
}

int main() {
    // count_words();
    print_word_per_line();
    return 0;
}
