#include <stdio.h>
#include <stdbool.h>

void initializeBoard (int numRows);
void alterBoard (char colour, char row, char col);
void printBoard (int numRows);
bool positionInBounds (int numRows, char row, char col);
bool checkLegalInDirection (int numRows, char colour, char row, char col, int deltaRow, int deltaCol);
void checkAvailable (int numRows, char colour);
void makeMove (int numRows, char colourMove, char rowMove, char colMove);

char board[][26];

int main()
{
    while (1)
    {
        int numRows;
        char colour, rowAlter, colAlter, colourMove, rowMove, colMove;
        
        printf("Enter the board dimension: ");
        scanf("%d", &numRows);
        initializeBoard(numRows);
        
        printf("Enter board configuration: \n");
        while (1)
        {
            scanf(" %c%c%c", &colour, &rowAlter, &colAlter);
            if (colour != '!' && rowAlter != '!' && colAlter != '!')
                alterBoard(colour, rowAlter, colAlter);
            else 
                break;
        }
        printBoard(numRows);
        
        printf("Available moves for W: \n");
        checkAvailable (numRows, 'W');
        
        printf("Available moves for B: \n");
        checkAvailable (numRows, 'B');
        
        printf("Enter a move: \n");
        scanf(" %c%c%c", &colourMove, &rowMove, &colMove);
        makeMove(numRows, colourMove, rowMove, colMove);
        
        printBoard(numRows);
    }
    return 0;
}

void initializeBoard (int numRows)
{
    int r, c, a;
    char rowLetter = 'a', colLetter = 'a';
    
    printf("  ");
    for (a = 0; a < numRows; a++, rowLetter++)
        printf("%c", rowLetter);
    printf("\n");
    
    for (r = 0; r < numRows; r++, colLetter++)
    {
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

void alterBoard (char colour, char row, char col)
{
    int rowNum, colNum;
    
    rowNum = row - 'a';
    colNum = col - 'a';
    printf("rowNum = %i, colNum = %i\n", rowNum, colNum);
    if (colour == 'B')
        board[rowNum][colNum] = 'B';
    else if (colour == 'W')
        board[rowNum][colNum] = 'W';
}

void printBoard (int numRows)
{
    int i, j, k;
    char rowLetter = 'a', colLetter = 'a';
    
    printf("  ");
    for (k = 0; k < numRows; k++, rowLetter++)
        printf("%c", rowLetter);
    printf("\n");
    
    for (i = 0; i < numRows; i++)
    {
        printf("%c ", colLetter);
        colLetter++;
        
        for (j = 0; j < numRows; j++)
            printf("%c", board[i][j]);
            
        printf("\n");
    }
}

bool positionInBounds (int numRows, char row, char col)
{
    int rowNum, colNum;
    rowNum = row - 'a';
    colNum = col - 'a';
    
    if (rowNum < numRows && colNum < numRows && rowNum >= 0 && colNum >= 0)
        return true;
    else
        return false;
}

bool checkLegalInDirection(int numRows, char colour, char row, char col, int deltaRow, int deltaCol)
{
    int rowNum, colNum;
    char tempRow = row, tempCol = col;
    rowNum = tempRow - 'a';
    colNum = tempCol - 'a';
    
    rowNum += deltaRow;
    colNum += deltaCol;
    tempRow += deltaRow;
    tempCol += deltaCol;
    
    while (board[rowNum][colNum] != colour && board[rowNum][colNum] != 'U' && positionInBounds(numRows, tempRow, tempCol) == true)
    {
        rowNum += deltaRow;
        colNum += deltaCol;
        tempRow += deltaRow;
        tempCol += deltaCol;
        
        if (board[rowNum][colNum] == colour && positionInBounds(numRows, tempRow, tempCol) == true)
        {
            printf("%c%c\n", row, col);
            return true;
        }
    }
    return false;
}

void checkAvailable (int numRows, char colour)
{
    int r, c, deltaRow, deltaCol;
    char rowCheck, colCheck;
    bool stop;
    for (r = 0; r < numRows; r++)
    {
        for (c = 0; c < numRows; c++)
        {
            if (board[r][c] == 'U')
            {
                stop = false;
                rowCheck = (char) r + 97;
                colCheck = (char) c + 97;
                for (deltaRow = -1; deltaRow <= 1 && stop != true; deltaRow++)
                {
                    for (deltaCol = -1; deltaCol <= 1 && stop != true; deltaCol++)
                    {
                        if ((deltaRow == 0 && deltaCol == 0) != 1)
                            if (checkLegalInDirection(numRows, colour, rowCheck, colCheck, deltaRow, deltaCol) == true)
                                stop = true;
                    }
                }
            }
        }
    }
}

void makeMove (int numRows, char colourMove, char rowMove, char colMove)
{
    int deltaRow, deltaCol, rowNum, colNum;
    bool flag;
    
    for (deltaRow = -1; deltaRow <= 1; deltaRow++)
    {
        for (deltaCol = -1; deltaCol <= 1; deltaCol++)
        {
            if ((deltaRow == 0 && deltaCol == 0) != 1)
            {
                if (checkLegalInDirection(numRows, colourMove, rowMove, colMove, deltaRow, deltaCol) == true)
                {
                    flag = 1;
                    rowNum = rowMove - 'a';
                    colNum = colMove - 'a';
                    
                    board[rowNum][colNum] = colourMove;
                    
                    while(1)
                    {
                        rowNum += deltaRow;
                        colNum += deltaCol;
                        printf("%c\n", board[rowNum][colNum]);
                        
                        if (board[rowNum][colNum] != colourMove)
                        {
                            board[rowNum][colNum] = colourMove;
                            printf("switch rowNum = %d switch colNum = %d\n", rowNum, colNum);
                        }
                        else 
                            break;
                    } 
                }
            }
        }
    }
    if (flag == 1)
        printf("Valid move.\n");
    else 
        printf("Invalid move.\n");
}