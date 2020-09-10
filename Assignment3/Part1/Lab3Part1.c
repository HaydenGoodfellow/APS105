#include <stdio.h>

int main()
{
    // Defining variables
    int inputNumber, startValue;
    int numQuarters, numDimes, numNickels, numCents;
    
    // Infinite loop to allow calulation done as many times as needed
    while(1)
    {
        // Printing prompt and scanning input
        printf("Please give an amount in cents less than 100: ");
        scanf("%d", &inputNumber);
        
        // Storing initial value for later
        startValue = inputNumber;
        
        // Escape case
        if (inputNumber < 1 || inputNumber >= 100)
        {
            break;
        }
        
        // Performs calulations on inputted number to find number of coins
        else
        {
            for (numQuarters = 0; inputNumber >= 25; ++numQuarters)
                inputNumber -= 25;
            
            for (numDimes = 0; inputNumber >= 10; ++numDimes)
                inputNumber -= 10;
        
            for (numNickels = 0; inputNumber >= 5; ++numNickels)
                inputNumber -= 5;
    
            for (numCents = 0; inputNumber >= 1; ++numCents)
                inputNumber -= 1;
            
            // Prints start of end statement
            printf("%d cents: ", startValue);
            
            // Prints quarters if there are any
            if (numQuarters > 1)
                printf("%d Quarters", numQuarters);
            else if (numQuarters == 1)
                printf("%d Quarter", numQuarters);
                
            // Prints dimes if there are any and adds comma if there were quarters
            if (numDimes > 1 && numQuarters != 0)
                printf(", %d Dimes", numDimes);
            else if (numDimes == 1 && numQuarters != 0)
                printf(", %d Dime", numDimes);
            else if (numDimes > 1)
                printf("%d Dimes", numDimes);
            else if (numDimes == 1)
                printf("%d Dime", numDimes);
                
            // Prints nickels
            if (numNickels > 1 && (numQuarters != 0 || numDimes != 0))
                printf(", %d Nickels", numNickels);
            else if (numNickels == 1 && (numQuarters != 0 || numDimes != 0))
                printf(", %d Nickel", numNickels);
            else if (numNickels > 1)
                printf("%d Nickels", numNickels);
            else if (numNickels == 1)
                printf("%d Nickel", numNickels);
                
            // Prints cents
            if (numCents > 1 && (numQuarters != 0 || numDimes != 0 || numNickels != 0))
                printf(", %d Cents", numCents);
            else if (numCents == 1 && (numQuarters != 0 || numDimes != 0 || numNickels != 0))
                printf(", %d Cent", numCents);
            else if (numCents > 1)
                printf("%d Cents", numCents);
            else if (numCents == 1)
                printf("%d Cent", numCents);
                
            // Prints period and new line
            printf(".\n");
        }
    }
    
    // Prints goodbye and new line
    printf("Goodbye. \n");
	return 0;
}