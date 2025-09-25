#include <stdio.h>
#include <math.h>

int main()
{
    printf("Enter water pressure reading (mPa)\n");

    double pressureMPa;
    scanf("%lf", &pressureMPa);

    double pressureBars = pressureMPa * 10;
    if (fabs(pressureBars - 3.4) < 0.0001)
    {
        printf("Pipe has reached ideal pressure\n");
    }
    else
    {
        printf("Pipe is not at ideal pressure\n");
    }
}
