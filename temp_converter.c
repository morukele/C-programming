#include <stdio.h>

/*
Symbolic constants to make reading the program easier.
It is different from variables because there is no decleration and initialization step required.
*/
#define LOWER 0     /* lower limit of table */
#define UPPER 300   /* upper limit */
#define STEP 20 /* step size */

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */
int main() {
    int fahr;

    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}
