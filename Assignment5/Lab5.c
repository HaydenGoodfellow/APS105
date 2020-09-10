#include <stdio.h>

// Initializing functions to be used later
int factorial (int n);
int choose (int n, int r);
int triangle (int numRows);

int main()
{
    // Infinite loop to allow as many inputs as wanted
    while (1)
    {
        // Defining variables
        int numRows;
        
        // Prompting user and scanning input
        printf("Enter the number of rows: ");
        scanf("%d", &numRows);
        
        // Escape case if user enters negative
        if (numRows < 0)
            break;
        
        // Printing triangle
        else
            triangle(numRows);
    }
    return 0;
}


int factorial (int n)
{
    // Defining variables
    int result;
    
    // Using recursion to calculate factorial
    if (n >= 1)
    {
        result = n*factorial(n - 1);
        return result;
    }
    
    // If user enters 0
    else if (n == 0)
        return 1;
    else 
        return 1;
}

int choose (int n, int r)
{
    // Defining vairables
    int comb;
    
    // Calculating the combination
    comb = factorial(n)/(factorial(r)*factorial(n - r));
    return comb;
}

int triangle (int numRows)
{
    // Defining variables
    int numCols, i, j, k;
    
    // Determining number of rows
    numCols = 6*numRows;
    
    // i iterates through rows, j through columns, k through number of cominations to print on each row 
    for (i = 0; i < numRows; i++)
    {
        for (j = 0; j < numCols; j++)
        {
            if (j == (numCols/2) - 3*i - 3)
            {
                for (k = 0; k <= i; k++)
                {
                    // Reserves 6 spaces for every number to properly space
                    printf("%-6d", choose(i,k));
                    while (k < i)
                    {
                        k++;
                        printf("%-6d", choose(i,k));
                    }
                }
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}