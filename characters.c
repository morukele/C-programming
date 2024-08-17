#include <stdio.h>

#define BACKSPACE '\b'
#define BACKSLASH '\\'
#define NEWLINE '\n'
#define TAB '\t'
#define BLANK ' '

/*
    A program to count blanks, tabs, and newlines.
*/
void count() {
    long c, nl, bl, tb;
    nl = 0;
    bl = 0;
    tb = 0;
    // EOF is ctrl + D
    while ((c = getchar()) != EOF) {
        if (c == NEWLINE) {
            ++nl;
        } else if (c == TAB) {
            ++tb;
        } else if (c == BLANK) {
            ++bl;
        }
    }

    printf("new lines: %ld\n", nl);
    printf("tabs: %ld\n", tb);
    printf("blanks: %ld\n", bl);
}

/*
    A function to copy input to output,
    replacing each string with one or more blanks by a single blank
*/
void copy_replace_blanks() {
    int c;
    while ((c = getchar()) != EOF) {
        // if encounter a first blank
        if(c == BLANK) {
            // enter this block
            // if encounter more consecutive blanks, do nothing
            while((c = getchar()) == BLANK);
            // write only a single blank
            putchar(BLANK);
        }
        // write the normally
        putchar(c);
    }

    printf("Program ended successfully...\n");
}

/*
    A program to copy its input to its output,
    replacing each tab by \t, each backspace by \b,
    each backslash by \\.
*/
void copy_replace_complex() {
    int c;

    while ((c = getchar()) != EOF) {
        // check for tab
        if(c == TAB) {
            putchar('\\');
            putchar('t');
        } else if(c == BACKSPACE) {
            putchar('\\');
            putchar('b');
        } else if(c == BACKSLASH) {
            putchar('\\');
            putchar('\\');
        }
        putchar(c);
    }
}

int main() {
    // copy_replace_blanks();
    // count();
    copy_replace_complex();
    return 0;
}
