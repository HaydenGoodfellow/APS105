#include <stdio.h>
#include <math.h>

// Initializing functions to be called later
long long convertDecimalToBinary (long long inputDec);
long long convertBinaryToDecimal (long long inputBin);

int main()
{
    // Defining variables needed
    long long inputBin, inputDec;
    char choice;
    
    // Prompts user for input and scans it in 
    printf("Enter B for conversion of Binary to Decimal, OR\nEnter D for conversion of Decimal to Binary: ");
    scanf(" %c", &choice);
    
    // Checks if user entered B and prints conversion if they did
    if (choice == 'B')
    {
        printf("Enter your number: ");
        scanf("%lld", &inputBin);
        printf("%lld in binary = %lld in decimal\n", inputBin, convertBinaryToDecimal(inputBin));
    }
    
    // Checks if user entered D and prints conversion if they did
    else if (choice == 'D')
    {
        printf("Enter your number: ");
        scanf("%lld", &inputDec);
        printf("%lld in decimal = %lld in binary\n", inputDec, convertDecimalToBinary(inputDec));
    }
    
    // If invalid input
    else
    {
        printf("Invalid input; Goodbye");
        return -1;
    }
	return 0;
}

// Defining decimal to binary function
long long convertDecimalToBinary (long long inputDec)
{
    long long remainder = 0, outputBin = 0;
    double i = 0;
    while (inputDec != 0)
    {
        // Finds remainder which will be 0 or 1 and adds it to output binary in the appropiate column
        remainder = inputDec%2;
        outputBin += remainder * pow(10, i);
        inputDec /= 2;
        i++;
    }
    return outputBin;
}

// Defining binary to decimal function
long long convertBinaryToDecimal (long long inputBin)
{
    long long outputDec = 0, endDigit = 0;
    double j = 0;
    while (inputBin != 0)
    {
        // Finds last digit of the binary number (0 or 1) and multiples it by its decimal equivalent then adds to output decimal
        endDigit = inputBin%10;
        outputDec += endDigit*pow(2,j);
        inputBin /= 10;
        j++;
    }
    return outputDec;
}