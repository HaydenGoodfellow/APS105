#include <stdio.h>

int main()
{
    // Initializing variables 
    double number1, number2, result;
    char opperation;
    
    // Prompting user and scanning input
    printf("Enter first number: ");
    scanf("%lf", &number1);
    
    printf("Enter second number: ");
    scanf("%lf", &number2);
    
    printf("Enter calculation command (one of a, s, m, or d): ");
    scanf(" %c", &opperation);
    
    // Checking what opperation was entered and finding result
    if (opperation == 'a')
    {
        result = number1 + number2;
        printf("Sum of %.2lf and %.2lf is %.2lf\n", number1, number2, result);
    }
    
    else if (opperation == 's')
    {
        result = number1 - number2;
        printf("Difference of %.2lf from %.2lf is %.2lf\n", number1, number2, result);
    }
    
    else if (opperation == 'm')
    {
        result = number1 * number2;
        printf("Product of %.2lf and %.2lf is %.2lf\n", number1, number2, result);
    }
    
    else if (opperation == 'd')
    {
        // Division by zero edge case
        if (number2 == 0)
        {
            printf("Error, trying to divide by zero\n");
            return 0;
        }
        
        else
        {
            result = number1 / number2;
            printf("Division of %.2lf by %.2lf is %.2lf\n", number1, number2, result);
        }
    }
    // User enters unknown opperator
    else 
    {
        printf("Error, unknown calculation command given\n");
        return 0;
    }
    return 0;
}