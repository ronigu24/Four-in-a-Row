#include<stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "Main.h"

#define Rows 6
#define Columns 7

char mat[Rows][Columns]={'\0'};
int chose=0;
char shape= 'X';

void PrintBoard ()
{
	for (int i = 0; i < Rows; ++i) {
		printf("\n|");
		for (int j = 0; j < Columns; ++j) {
			if (mat[i][j]=='\0')
			{
				printf(" |");
			}
			else
				printf("%c|", mat[i][j]);
		}

	}
	printf("\n 1 2 3 4 5 6 7\n");
}

void check(int chose)
{
	bool empty=false;
	for(int i=Rows-1;i>-1;i--)
	{
		if(mat[i][chose-1]=='\0'&&empty==false)
		{
			push(chose);
			if (shape=='X')
			{
				mat[i][chose-1]='X';
				empty=true;
			}
			else
			{
				mat[i][chose-1]='O';
				empty=true;
			}
		}
	}
	if(empty==false)
		printf("Invalid input, this column is full. Please choose another one");
}

bool CheckWin ()
{
	for(int i=0;i<Rows;i++)
	{
		if((mat[i][0]==shape&&mat[i][1]==shape&&mat[i][2]==shape&&mat[i][3]==shape)||
				(mat[i][1]==shape&&mat[i][2]==shape&&mat[i][3]==shape&&mat[i][4]==shape)||
				(mat[i][2]==shape&&mat[i][3]==shape&&mat[i][4]==shape&&mat[i][5]==shape)||
				(mat[i][3]==shape&&mat[i][4]==shape&&mat[i][5]==shape&&mat[i][6]==shape))
		{
			return true;
		}
	}
	for(int j=0;j<Columns;j++)
	{
		if((mat[0][j]==shape&&mat[1][j]==shape&&mat[2][j]==shape&&mat[3][j]==shape)||
				(mat[1][j]==shape&&mat[2][j]==shape&&mat[3][j]==shape&&mat[4][j]==shape)||
				(mat[2][j]==shape&&mat[3][j]==shape&&mat[4][j]==shape&&mat[5][j]==shape))
		{
			return true;
		}
	}
	for(int i=0;i<Rows-3;i++)
	{
		for(int j=0;j<Columns-3;j++)
		{
			if((mat[i][j]==shape&&mat[i+1][j+1]==shape&&mat[i+2][j+2]==shape&&mat[i+3][j+3]==shape))
			{
				return true;
			}
		}
	}
	for(int i=0;i<Rows-3;i++)
	{
		for(int j=Columns-1;j>2;j--)
		{
			if((mat[i][j]==shape&&mat[i+1][j-1]==shape&&mat[i+2][j-2]==shape&&mat[i+3][j-3]==shape))
			{
				return true;
			}
		}
	}
	return false;
}


void undo()
{
	int place=pop();

	for(int i=0;i<Columns;i++)
	{
		if(mat[i][place-1]!='\0')
		{
			mat[i][place-1]='\0';
			i=Columns+1;;
		}
	}
}

int main()
{
	bool legal =true;
	bool Winner = false;
	printf("Welcome!\n");
	PrintBoard();
	while((Winner!=true)&&(!isfull())&&(legal==true))
	{
		printf("Player %c, please enter a column number (or 0 to undo)\n", shape);
		if(scanf("%d", &chose)!=1)
		{
			legal=false;
			printf("Invalid input, bye-bye!\n");
		}
		else
		{
			if(chose<0||chose>7)
			{
				printf("Invalid input, the number must be between 1 to 7\n");
			}
			else if(chose==0)
			{
				if(isempty())
				{
					printf("Board is empty - can't undo!\n");
				}
				else{
					undo();
					if(shape=='X')
						shape='O';
					else
						shape='X';
					PrintBoard();
				}
			}
			else
			{
				check(chose);
				PrintBoard();
				Winner=CheckWin();

				if(shape=='X')
					shape='O';
				else
					shape='X';
			}
		}
	}

	if(shape=='O'&&Winner)
	{
		printf("Player X wins!\n");
	}
	else if(shape=='X'&&Winner)
		printf("Player O wins!\n");
	else if (isfull())
		printf("It's a tie!\n");
	system("pause");
	return 0;
}



