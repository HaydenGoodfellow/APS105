#include <stdio.h>

int main()
{
    // Defining vairables needed later
    int numRows, numCols, i, j, k;
    
    // Prompting user and scanning input
    printf("Enter the number of rows in the triangle: ");
    scanf("%d", &numRows);
    
    // Determining number of columns needed
    numCols = 2*numRows - 1;

    for (i = 0; i < numRows; i++)
    {
        // Printing bottom row
        if (i == numRows - 1)
        {
            for (k = 0; k < numCols; k++)
                printf("^");
        }
        
        // Printing non-bottom rows
        else
        {
            for (j = 0; j < numCols; j++)
            {
                if (j == (numCols/2) + i || j == (numCols/2) - i)
                    printf("^");
                else 
                    printf(" ");
            }
        }
        printf("\n");
        
    }
	return 0;
}