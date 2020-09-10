#include <stdio.h>

int main()
{
    // Declaring variables needed
    char inputChar1, inputChar2, inputChar3, inputChar4;
    char *bandColour1, *bandColour2, *bandColour3, *bandColour4, *ohmType;
    double value1, value2, value3, value4, combinedValue, totalValue;
    
    // Printing and recieveing user input
    printf("Please enter the 1st band: \n");
    scanf(" %c", &inputChar1);
    printf("Please enter the 2nd band: \n");
    scanf(" %c", &inputChar2);
    printf("Please enter the multiplier band: \n");
    scanf(" %c", &inputChar3);
    printf("Please enter the tolerance band: \n");
    scanf(" %c", &inputChar4);
    
    // Assigning value and name of 1st band to user input 
    if (inputChar1 == 'k' || inputChar1 == 'K')
    {
        value1 = 0;
        bandColour1 = "Black";
    }
    else if (inputChar1 == 'b' || inputChar1 == 'B')
    {
        value1 = 1;
        bandColour1 = "Brown";
    }
    else if (inputChar1 == 'r' || inputChar1 == 'R')
    {
        value1 = 2;
        bandColour1 = "Red";
    }
    else if (inputChar1 == 'o' || inputChar1 == 'O')
    {
        value1 = 3;
        bandColour1 = "Orange";
    }
    else if (inputChar1 == 'e' || inputChar1 == 'E')
    {
        value1 = 4;
        bandColour1 = "Yellow";
    }   
    else if (inputChar1 == 'g' || inputChar1 == 'G')
    {
        value1 = 5;
        bandColour1 = "Green";
    }
    else if (inputChar1 == 'u' || inputChar1 == 'U')
    {
        value1 = 6;
        bandColour1 = "Blue";
    }
    else if (inputChar1 == 'v' || inputChar1 == 'V')
    {
        value1 = 7;
        bandColour1 = "Violet";
    }
    else if (inputChar1 == 'y' || inputChar1 == 'Y')
    {
        value1 = 8;
        bandColour1 = "Grey";
    }
    else if (inputChar1 == 'w' || inputChar1 == 'W')
    {
        value1 = 9;
        bandColour1 = "White";
    }


    // Assigning value and name of 2nd band to user input 
    if (inputChar2 == 'k' || inputChar2 == 'K')
    {
        value2 = 0;
        bandColour2 = "Black";
    }
    else if (inputChar2 == 'b' || inputChar2 == 'B')
    {
        value2 = 1;
        bandColour2 = "Brown";
    }
    else if (inputChar2 == 'r' || inputChar2 == 'R')
    {
        value2 = 2;
        bandColour2 = "Red";
    }
    else if (inputChar2 == 'o' || inputChar2 == 'O')
    {
        value2 = 3;
        bandColour2 = "Orange";
    }
    else if (inputChar2 == 'e' || inputChar2 == 'E')
    {
        value2 = 4;
        bandColour2 = "Yellow";
    }   
    else if (inputChar2 == 'g' || inputChar2 == 'G')
    {
        value2 = 5;
        bandColour2 = "Green";
    }
    else if (inputChar2 == 'u' || inputChar2 == 'U')
    {
        value2 = 6;
        bandColour2 = "Blue";
    }
    else if (inputChar2 == 'v' || inputChar2 == 'V')
    {
        value2 = 7;
        bandColour2 = "Violet";
    }
    else if (inputChar2 == 'y' || inputChar2 == 'Y')
    {
        value2 = 8;
        bandColour2 = "Grey";
    }
    else if (inputChar2 == 'w' || inputChar2 == 'W')
    {
        value2 = 9;
        bandColour2 = "White";
    }
    
    
    // Assigning value and name of 3rd band to user input 
    if (inputChar3 == 'k' || inputChar3 == 'K')
    {
        value3 = 1;
        bandColour3 = "Black";
    }
    else if (inputChar3 == 'b' || inputChar3 == 'B')
    {
        value3 = 10;
        bandColour3 = "Brown";
    }
    else if (inputChar3 == 'r' || inputChar3 == 'R')
    {
        value3 = 100;
        bandColour3 = "Red";
    }
    else if (inputChar3 == 'o' || inputChar3 == 'O')
    {
        value3 = 1000;
        bandColour3 = "Orange";
    }
    else if (inputChar3 == 'e' || inputChar3 == 'E')
    {
        value3 = 10000;
        bandColour3 = "Yellow";
    }   
    else if (inputChar3 == 'g' || inputChar3 == 'G')
    {
        value3 = 100000;
        bandColour3 = "Green";
    }
    else if (inputChar3 == 'u' || inputChar3 == 'U')
    {
        value3 = 1000000;
        bandColour3 = "Blue";
    }
    else if (inputChar3 == 'v' || inputChar3 == 'V')
    {
        value3 = 10000000;
        bandColour3 = "Violet";
    }
    else if (inputChar3 == 'l' || inputChar3 == 'L')
    {
        value3 = 0.1;
        bandColour3 = "Gold";
    }
    else if (inputChar3 == 's' || inputChar3 == 'S')
    {
        value3 = 0.01;
        bandColour3 = "Silver";
    }
    
    
    // Assigning value and name of 4th band to user input 
    if (inputChar4 == 'k' || inputChar4 == 'K')
    {
        value4 = 0;
        bandColour4 = "Black";
    }
    else if (inputChar4 == 'b' || inputChar4 == 'B')
    {
        value4 = 1;
        bandColour4 = "Brown";
    }
    else if (inputChar4 == 'r' || inputChar4 == 'R')
    {
        value4 = 2;
        bandColour4 = "Red";
    }
    else if (inputChar4 == 'g' || inputChar4 == 'G')
    {
        value4 = 0.5;
        bandColour4 = "Green";
    }
    else if (inputChar4 == 'u' || inputChar4 == 'U')
    {
        value4 = 0.25;
        bandColour4 = "Blue";
    }
    else if (inputChar4 == 'v' || inputChar4 == 'V')
    {
        value4 = 0.1;
        bandColour4 = "Violet";
    }
    else if (inputChar4 == 'y' || inputChar4 == 'Y')
    {
        value4 = 0.05;
        bandColour4 = "Grey";
    }
    else if (inputChar4 == 'l' || inputChar4 == 'L')
    {
        value4 = 5;
        bandColour4 = "Gold";
    }
    else if (inputChar4 == 's' || inputChar4 == 'S')
    {
        value4 = 10;
        bandColour4 = "Silver";
    }

    // Creating concatenated value of 1st and 2nd band 
    combinedValue = 10*value1 + value2;
    
    // Calulating total resistance
    totalValue = combinedValue*value3;
    
    // Determining units of resistor band and rounding to appropriate values
    if (totalValue < 1000)
    {
        ohmType = "Ohms";
    }
    else if (totalValue >= 1000 && totalValue < 1000000)
    {
        ohmType = "KOhms";
        totalValue = totalValue / 1000;
    }
    else if (totalValue >= 1000000)
    {
        ohmType = "MOhms";
        totalValue = totalValue / 1000000;
    }
    
    // Printing final statements
    printf("Resistor bands: %s %s %s %s\n", bandColour1, bandColour2, bandColour3, bandColour4);
    printf("Resistance: %.2lf %s +/- %.2lf%%\n", totalValue, ohmType, value4);
    
    return 0;
}