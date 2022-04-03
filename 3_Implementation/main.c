#include<stdio.h>
#define N 3
void initializeBoard(char board[N][N])
{
	int i=0,j=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			board[i][j]=' ';
		}
	}
}
void printBoard(char board[N][N])
{
	int i=0,j=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%c |",board[i][j]);
		}
		printf("\n");
		for(j=0;j<N;j++)
		{
			printf("---");
		}
		printf("---");
			printf("\n");
	}
}
int checkInDiagonal(char board[N][N])
{
	int i=0,j=0;
	for(i=1;i<N;i++)
	{
		if(board[i][i]!=board[i-1][i-1])
		{
			return 0;
		}
	}
	return 1;
}
int checkWinPossiblityForRow(char board[N][N],int row)
{
	int j=0;
	for(;j<N-1;j++)
	{
		if(board[row][j]!=board[row][j+1])
		{
			return 0;
		}
	}
	return 1;
}
int checkWinPossiblityForClm(char board[N][N],int clm)
{
	int j=0;
	for(;j<N-1;j++)
	{
		if(board[j][clm]!=board[j+1][clm])
		{
			return 0;
		}
	}
	return 1;
}
int checkCacheForRowAndClm(char board[N][N],char boardCacheDetails[2][N],int row,int rowPos,char playerSignChar)
{
		if(boardCacheDetails[row][rowPos]==' ')
		{
			boardCacheDetails[row][rowPos]=playerSignChar;
		}
		else if(boardCacheDetails[row][rowPos]!=playerSignChar &&boardCacheDetails[row][rowPos]!='-1')
		{
		    boardCacheDetails[row][rowPos]='-1';
		}
		else
		{
			return (row==0)?checkWinPossiblityForRow(board,rowPos):checkWinPossiblityForClm(board,rowPos);
		}
		return 0;
}
int main()
{
	char board[N][N];
	char boardCacheDetails[2][N];
	int totalAvailableBlocks=N*N;
	initializeBoard(board);
	initializeBoard(boardCacheDetails);
	char playerName1[16],playerName2[16];
	printf("Enter the Player Name1:");
	scanf("%s",playerName1);
	printf("\nEnter the Player Name2:");
	scanf("%s",playerName2);
	printf("\nLets Start The game.....\nFor %s: O \nFor %s: X\n",playerName1,playerName2);
	int playerFlag=0;
	char playerSignChar;
    int rowPos=0,clmPos=0;
    while(totalAvailableBlocks>0)
    {
    	printBoard(board);
    	if(playerFlag==0)
    	{
    		playerSignChar='X';
    		printf("\nChance For %s......\n",(playerFlag==1)?playerName1:playerName2);
		}
		else
		{
			playerSignChar='O';
			printf("\nChance For %s......\n",(playerFlag==1)?playerName1:playerName2);
        }
        printf("\nEnter the row position and column position of the board:");
    	scanf("%d%d",&rowPos,&clmPos);
    	rowPos=rowPos-1;
    	clmPos=clmPos-1;
    	board[rowPos][clmPos]=playerSignChar;
    	if(rowPos==clmPos&&checkInDiagonal(board))
    	{
    		goto win;
		}
	    if(checkCacheForRowAndClm(board,boardCacheDetails,0,rowPos,playerSignChar))
	    {
	    	goto win;
		}
		if(checkCacheForRowAndClm(board,boardCacheDetails,1,clmPos,playerSignChar))
	    {
	    	goto win;
		}
    	playerFlag=!playerFlag;
    	totalAvailableBlocks--;
	}
    win:
    	    printBoard(board);
    		printf("%s is win",(playerFlag==1)?playerName1:playerName2);
}
