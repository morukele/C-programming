#include <stdio.h>
#include <math.h>

int main()
{
    int imageWidth = 1500;
    int imageHeight = 1000;

    double ratio = (double)imageWidth / (double)imageHeight;
    printf("Image Ratio: %lf\n", ratio);
}
