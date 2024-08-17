#include <stdio.h>

/*Print Celsius-Fahrenheit table for Cel = 0, 20, ..., 300 */
int main() {
    float celsius, fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("%s \t %s\n", "Celsius", "Fahrenhient");
    celsius = lower;

    while (celsius <= upper) {
        fahr = ((9.0/5.0) * celsius) + (32.0);
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
