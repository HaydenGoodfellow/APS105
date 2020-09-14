#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lab7part2lib.h"

// Declaring functions
void initializeBoard (char board[][26], int numRows);
void printBoard (char board[][26], int numRows);
void printValueBoard (int valueBoard[][26], int numRows);
void resetValueBoard (int valueBoard[][26], int numRows);
bool positionInBounds (int numRows, char row, char col);
int checkLegalInDirection (char board[][26], int valueBoard[][26], int numRows, char colour, char row, char col, int deltaRow, int deltaCol);
int countAvailable (char board[][26], int valueBoard[][26], int numRows, char colour);
void initiateMove (char board[][26], int valueBoard[][26], int numRows, int moveNum, bool playerFirst, bool compFirst, char playerColour, char compColour);
void makeMove (char board[][26], int valueBoard[][26], int numRows, char colourMove, char rowMove, char colMove);
int checkNextTurn(char board[][26], int valueBoard[][26], int numRows, char compColour, char rowCheck, char colCheck);
void compMove (char board[][26], int valueBoard[][26], int numRows, char compColour);
bool isWinner (char board[][26], int valueBoard[][26], int numRows);
void declareWinner (char colour);

int main()
{
    char board[26][26];
    int valueBoard[26][26] = {{0}};
    int numRows, moveNum = 1;
    char compColour, playerColour;
    bool playerFirst = false, compFirst = false;
    
    // Prompting user and scanning input
    printf("Enter the board dimension: ");
    scanf("%d", &numRows);
    
    printf("Computer plays (B/W) : ");
    scanf(" %c", &compColour);
    
    // Initializing boards needed
    initializeBoard(board, numRows);
    resetValueBoard(valueBoard, numRows);
    
    // Determining what colour each player is and determining who goes first
    if (compColour == 'B')
    {
        playerColour = 'W';
        compFirst = true;
    }
    else if (compColour == 'W')
    {
        playerColour = 'B';
        playerFirst = true;
    }
    
    //printf("compColour == %c, playerColour == %c\n", compColour, playerColour);
    
    // Continues playing until someone wins
    while (isWinner(board, valueBoard, numRows) != true)
    {
        initiateMove(board, valueBoard, numRows, moveNum, playerFirst, compFirst, playerColour, compColour);
        moveNum++;
    }
    
    return 0;
}

// Function to initialize board to correct initial values... Not called later
void initializeBoard (char board[][26], int numRows)
{
    int r, c, a;
    char rowLetter = 'a', colLetter = 'a';
    
    // Prints top row of indices
    printf("  ");
    for (a = 0; a < numRows; a++, rowLetter++)
        printf("%c", rowLetter);
    printf("\n");
    
    for (r = 0; r < numRows; r++, colLetter++)
    {
        // Prints side column of indices
        printf("%c ", colLetter);
        for (c = 0; c < numRows; c++)
        {
            if (c == numRows/2 - 1 && r == numRows/2 - 1)
                board[r][c] = 'W';
            else if (c == numRows/2 - 1 && r == numRows/2)
                board[r][c] = 'B';
            else if (c == numRows/2 && r == numRows/2 - 1)
                board[r][c] = 'B';
            else if (c == numRows/2 && r == numRows/2)
                board[r][c] = 'W';
            else
                board[r][c] = 'U';
            printf("%c", board[r][c]);
        }
        printf("\n");
    }
}

// Prints board in current state
void printBoard (char board[][26], int numRows)
{
    int i, j, k;
    char rowLetter = 'a', colLetter = 'a';
    
    // Prints top row of indices
    printf("  ");
    for (k = 0; k < numRows; k++, rowLetter++)
        printf("%c", rowLetter);
    printf("\n");
    
    for (i = 0; i < numRows; i++)
    {
        // Prints side column of indices
        printf("%c ", colLetter);
        colLetter++;
        
        for (j = 0; j < numRows; j++)
            printf("%c", board[i][j]);
            
        printf("\n");
    }
}

// Prints board of values that computer uses to determine move
void printValueBoard (int valueBoard[][26], int numRows)
{
    int i, j, k;
    char rowLetter = 'a', colLetter = 'a';
    
    // Prints top row of indices
    printf("Value Board:\n");
    printf("  ");
    for (k = 0; k < numRows; k++, rowLetter++)
        printf("%3c", rowLetter);
    printf("\n");
    
    for (i = 0; i < numRows; i++)
    {
        printf("%c ", colLetter);
        colLetter++;
        
        for (j = 0; j < numRows; j++)
            printf("%3d", valueBoard[i][j]);
            
        printf("\n");
    }
}

// Function to reset valueBoard at end of every turn
void resetValueBoard (int valueBoard[][26], int numRows)
{
    int i, j;
    
    for (i = 0; i < numRows; i++)
    {
        for (j = 0; j < numRows; j++)
        {
            //valueBoard[i][j] = 0;
            if (i == 0 || i == (numRows - 1) || j == 0 || j == (numRows - 1))
            {
                valueBoard[i][j] = 5;
                //printf("vb[%d][%d] = 10\n", i, j);
            }
            if ((i == 0 || i == (numRows - 1)) && (j == 0 || j == (numRows - 1)))
            {
                valueBoard[i][j] = 10;
                //printf("vb[%d][%d] = 10\n", i, j);
            }
            else if ((i == 1 || i == (numRows - 2)) && (j == 1 || j == (numRows - 2)))
            {
                valueBoard[i][j] = -2;
                //printf("vb[%d][%d] = -5\n", i, j);
            }
        }
    }
}

// Function to check if a given tile is in bounds
bool positionInBounds (int numRows, char row, char col)
{
    int rowNum, colNum;
    
    // Converting rol/col letters into numbers
    rowNum = row - 'a';
    colNum = col - 'a';
    
    if (rowNum < numRows && colNum < numRows && rowNum >= 0 && colNum >= 0)
        return true;
    else
        return false;
}

// Function to check if there's a legal move in a given direction and count the number of tiles that move would flip
int checkLegalInDirection(char board[][26], int valueBoard[][26], int numRows, char colour, char row, char col, int deltaRow, int deltaCol)
{
    int rowNum, colNum, flipCount = 0;
    char tempRow = row, tempCol = col;
    
    // Converting rol/col letters into numbers
    rowNum = tempRow - 'a';
    colNum = tempCol - 'a';
    //if (board[rowNum][colNum] == 'U')
    //{
        // Setting variables to next tile in the given direction
        rowNum += deltaRow;
        colNum += deltaCol;
        tempRow += deltaRow;
        tempCol += deltaCol;
        
        if (board[rowNum][colNum] != 'U')
        {
            // Checks if next tile in diection is the opposite colour of the player making the move and if it's in bounds
            while (board[rowNum][colNum] != colour && board[rowNum][colNum] != 'U' && positionInBounds(numRows, tempRow, tempCol) == true)
            {
                // Setting variables to next tile in the given direction
                rowNum += deltaRow;
                colNum += deltaCol;
                tempRow += deltaRow;
                tempCol += deltaCol;
                
                // Inceases flipcount
                flipCount++;
                //flipCount += valueBoard[rowNum][colNum];
                
                // Checks if next tile after opposite tile is a tile of the same colour as the player making the move and hence a valid move
                if (board[rowNum][colNum] == colour && positionInBounds(numRows, tempRow, tempCol) == true)
                {
                    return flipCount;
                }
            }
        }
    //}
    return 0;
}

// Function to count the number of available moves a given player has
int countAvailable (char board[][26], int valueBoard[][26], int numRows, char colour)
{
    int r, c, deltaRow, deltaCol, moveCount = 0;
    char rowCheck, colCheck;
    bool stop;
    
    // Loops through rows and colums looking for empty tiles
    for (r = 0; r < numRows; r++)
    {
        for (c = 0; c < numRows; c++)
        {
            if (board[r][c] == 'U')
            {
                // Sets bool used to escape from 2 loops
                stop = false;
                rowCheck = (char) r + 97;
                colCheck = (char) c + 97;
                for (deltaRow = -1; deltaRow <= 1 && stop != true; deltaRow++)
                {
                    for (deltaCol = -1; deltaCol <= 1 && stop != true; deltaCol++)
                    {
                        if ((deltaRow == 0 && deltaCol == 0) != 1)
                        {
                            // Checks if theres a valid move in the direction, increases the moveCount, then goes to next col
                            if (checkLegalInDirection(board, valueBoard, numRows, colour, rowCheck, colCheck, deltaRow, deltaCol) > 0)
                            {
                                moveCount++;
                                stop = true;
                            }
                            
                        }
                    }
                }
            }
        }
    }
    return moveCount;
}

// Function to initiate move for next player
void initiateMove (char board[][26], int valueBoard[][26], int numRows, int moveNum, bool playerFirst, bool compFirst, char playerColour, char compColour)
{
    char rowMove, colMove;
    int row, col;
    
    // playerFirst & compFirst will be 0 or 1 and moveNum % 2 will be 0 or 1 so it cycles through the turns
    if (moveNum % 2 == playerFirst && countAvailable(board, valueBoard, numRows, playerColour) != 0)
    {
        
        printf("Enter move for colour %c (RowCol): ", playerColour);
        scanf(" %c%c", &rowMove, &colMove);
        
        makeMove(board, valueBoard, numRows, playerColour, rowMove, colMove);
        printBoard(board, numRows);
        
        //printf("%c (human) moves available: %d; %c (computer) moves available: %d\n", 
                //playerColour, countAvailable(numRows, playerColour), compColour, countAvailable(numRows, compColour));
        
        /*
        findSmartestMove(board, numRows, playerColour, &row, &col);
        printf("Testing AI move (row, col): %c%c\n", row, col);
        
        rowMove = (char) row + 97;
        colMove = (char) col+ 97;
        
        makeMove(board, valueBoard, numRows, playerColour, rowMove, colMove);
        printBoard(board, numRows);
        */
    }
    
    // Checks if player has a valid move    
    else if (moveNum % 2 == playerFirst && countAvailable(board, valueBoard, numRows, playerColour) == 0)
        printf("%c player has no valid move.\n", playerColour);
        
    else if (moveNum % 2 == compFirst)
    {
        compMove(board, valueBoard, numRows, compColour);
        
        //printf("%c (human) moves available: %d; %c (computer) moves available: %d\n", 
            //playerColour, countAvailable(numRows, playerColour), compColour, countAvailable(numRows, compColour));
    }
}

// Function to check if a move is valid and make move for a given player
void makeMove (char board[][26], int valueBoard[][26], int numRows, char colourMove, char rowMove, char colMove)
{
    int deltaRow, deltaCol, rowNum, colNum;
    bool invalidMoveFlag = true;
    char boardCopy[26][26];
    
    // Converting rol/col letters into numbers
    rowNum = rowMove - 'a';
    colNum = colMove - 'a';
    
    if (board[rowNum][colNum] == 'U')
    {
        for (deltaRow = -1; deltaRow <= 1; deltaRow++)
        {
            for (deltaCol = -1; deltaCol <= 1; deltaCol++)
            {
                if ((deltaRow == 0 && deltaCol == 0) != 1)
                {
                    // Checks if there's a valid move in a given direction
                    if (checkLegalInDirection(board, valueBoard, numRows, colourMove, rowMove, colMove, deltaRow, deltaCol) > 0)
                    {
                        // If there's a valid move then the flag switches to false
                        invalidMoveFlag = false;
                        
                        // Converting rol/col letters into numbers
                        rowNum = rowMove - 'a';
                        colNum = colMove - 'a';
                        
                        // Flips board tile to opposite colour
                        board[rowNum][colNum] = colourMove;
                        
                        // Infinite loop to flip as many tiles as needed
                        while(1)
                        {
                            // Setting variables to next tile in the given direction
                            rowNum += deltaRow;
                            colNum += deltaCol;
                            
                            // Checks if next tile in direction is opposite colour and flips if it is
                            if (board[rowNum][colNum] != colourMove)
                            {
                                board[rowNum][colNum] = colourMove;
                                //printf("switch rowNum = %d switch colNum = %d\n", rowNum, colNum);
                            }
                            else 
                                break;
                        } 
                    }
                }
            }
        }
    }
    // If the move was invalid it prints the winner and ends the game
    if (invalidMoveFlag == true)
    {
        printf("Invalid move.\n");
        if (colourMove == 'B')
            declareWinner('W');
        else if (colourMove == 'W')
            declareWinner('B');
        exit(EXIT_SUCCESS);
    }
}

int checkNextTurn(char board[][26], int valueBoard[][26], int numRows, char compColour, char rowCheck, char colCheck)
{
    int valueBCopy[26][26], i, j, moveVal = 0, deltaRow, deltaCol;
    char boardCopy[26][26], playerColour, maxR, maxC;
    
    maxR = (char) (numRows - 1) + 97;
    
    for (i = 0; i < numRows; i++)
    {
        for (j = 0; j < numRows; j++)
        {
            boardCopy[i][j] = board[i][j];
            valueBCopy[i][j] = valueBoard[i][j];
        }
    }
    
    makeMove(boardCopy, valueBCopy, numRows, compColour, rowCheck, colCheck);
    
    if (compColour == 'B')
        playerColour = 'W';
    else if (compColour == 'W')
        playerColour = 'B';
    
    if (countAvailable(boardCopy, valueBCopy, numRows, playerColour) == 0)
        moveVal += 100;
    
    for (deltaRow = -1; deltaRow <= 1; deltaRow++)
    {
        for (deltaCol = -1; deltaCol <= 1; deltaCol++)
        {
            if ((deltaRow == 0 && deltaCol == 0) != 1)
            {
                if (checkLegalInDirection(boardCopy, valueBCopy, numRows, playerColour, 'a', 'a', deltaRow, deltaCol) > 0)
                    moveVal += -5;
                else if (checkLegalInDirection(boardCopy, valueBCopy, numRows, playerColour, 'a', maxR, deltaRow, deltaCol) > 0)
                    moveVal += -5;
                else if (checkLegalInDirection(boardCopy, valueBCopy, numRows, playerColour, maxR, 'a', deltaRow, deltaCol) > 0)
                    moveVal += -5;
                else if (checkLegalInDirection(boardCopy, valueBCopy, numRows, playerColour, maxR, maxR, deltaRow, deltaCol) > 0)
                    moveVal += -5;
            }
        }
    }
    
    return moveVal;
}

// Function to find the correct computer move and make it, also checks if there is any valid moves at all, also prints board after move
void compMove(char board[][26], int valueBoard[][26], int numRows, char compColour)
{
    int r, c, deltaRow, deltaCol, flipCount, maxFlip = -100, rMax, cMax;
    char rowCheck, colCheck, rowMove, colMove;
    bool hasMove = false;
    
    for (r = 0; r < numRows; r++)
    {
        for (c = 0; c < numRows; c++)
        {   
            if (board[r][c] == 'U')
            {
                flipCount = 0;
                
                // Converting row/col numbers to letters
                rowCheck = (char) r + 97;
                colCheck = (char) c + 97;
                for (deltaRow = -1; deltaRow <= 1; deltaRow++)
                {
                    for (deltaCol = -1; deltaCol <= 1; deltaCol++)
                    {
                        if ((deltaRow == 0 && deltaCol == 0) != 1)
                        {
                            // Counts the number of tiles flipped then stores that value in a copy of the board
                            flipCount += checkLegalInDirection(board, valueBoard, numRows, compColour, rowCheck, colCheck, deltaRow, deltaCol);
                        }
                    }
                }
                if (flipCount > 0)
                    flipCount += checkNextTurn(board, valueBoard, numRows, compColour, rowCheck, colCheck);
    
                valueBoard[r][c] += flipCount;
            }
        }
    }
    
    printValueBoard(valueBoard, numRows);
    
    // Checks through the tiles and looks for highest value one
    for (r = 0; r < numRows; r++)
    {
        for (c = 0; c < numRows; c++)
        {
            rowCheck = (char) r + 97;
            colCheck = (char) c + 97;
            for (deltaRow = -1; deltaRow <= 1; deltaRow++)
            {
                for (deltaCol = -1; deltaCol <= 1; deltaCol++)
                {
                    if ((deltaRow == 0 && deltaCol == 0) != 1)
                    {
                        if (valueBoard[r][c] > maxFlip && checkLegalInDirection(board, valueBoard, numRows, compColour, rowCheck, colCheck, deltaRow, deltaCol) > 0)
                        {
                            hasMove = true;
                            maxFlip = valueBoard[r][c];
                            rMax = r;
                            cMax = c;
                        }
                    }
                }
            }
        }
    }
    
    // Checks if the computer has a valid move somewhere and makes the move
    if (hasMove == true)
    {
        // Converting row/col numbers to letters
        rowMove = (char) rMax + 97;
        colMove = (char) cMax + 97;
        
        printf("Comp moving to [%c][%c]\n", rowMove, colMove);
        makeMove(board, valueBoard, numRows, compColour, rowMove, colMove);
        printf("Computer places %c at %c%c.\n", compColour, rowMove, colMove);
        printBoard(board, numRows);
        resetValueBoard(valueBoard, numRows);
    }
    
    // If comp has no valid moves
    else 
        printf("%c player has no valid move.\n", compColour);
}

// Checks if game is over and prints winner if someone has won
bool isWinner (char board[][26], int valueBoard[][26], int numRows)
{
    int i, j, blackTiles = 0, whiteTiles = 0;
    
    // Checks if either player has no moves
    if (countAvailable(board, valueBoard, numRows, 'B') == 0 || countAvailable(board, valueBoard, numRows, 'W') == 0)
    {
        for (i = 0; i < numRows; i++)
        {
            for (j = 0; j < numRows; j++)
            {
                // Counts number of tiles for each player
                if (board[i][j] == 'B')
                    blackTiles++;
                else if (board[i][j] == 'W')
                    whiteTiles++;
            }
        }
        
        // If neither player has a move whoever has more tiles wins
        if (countAvailable(board, valueBoard, numRows, 'B') == 0 && countAvailable(board, valueBoard, numRows, 'W') == 0)
        {
            if (blackTiles > whiteTiles)
                declareWinner('B');
            else if (whiteTiles > blackTiles)
                declareWinner('W');
            else if (blackTiles == whiteTiles)
                declareWinner('T');
            return true;
        }
        
        // If black has no tiles and no moves then white wins
        else if (countAvailable(board, valueBoard, numRows, 'B') == 0 && blackTiles == 0)
        {
            declareWinner('W');
            return true;
        }
        // If white has no tiles and no moves then black wins
        else if (countAvailable(board, valueBoard, numRows, 'W') == 0 && whiteTiles == 0)
        {
            declareWinner('B');
            return true;
        }
    }
    return false;
}

// Function to declare a winner
void declareWinner (char colour)
{
    printf("%c player wins.\n", colour);
}