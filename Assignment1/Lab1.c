#include <stdio.h>
#include <math.h>

int main()
{
    // Defines variables needed
    double inputNumber[3], sum, mean, standardDeviation;
    int i;
    // Prints message and recieves input numbers 
    printf("Enter three numbers: ");
    scanf("%lf %lf %lf", &inputNumber[0], &inputNumber[1], &inputNumber[2]);
    // Computes mean 
    mean = (inputNumber[0] + inputNumber[1] + inputNumber[2]) / 3.00;
    // Calculates the sum in the numerator of the variance 
    for (i = 0; i < 3; i++)
        sum += pow((inputNumber[i] - mean),2);
    // Calculates the standard deviation by taking the square root of the variance
    standardDeviation = sqrt(sum/2);
    // Prints final results 
    printf("The mean is %.2lf and the standard deviation is %.2lf\n", mean, standardDeviation);
    return 0;
}