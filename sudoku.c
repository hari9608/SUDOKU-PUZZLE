#include<stdio.h>
#define N 9
int sudoku[N][N];
int row;
int col;
int cho;
int isPresentInGrid(int, int, int);
int isPresentInRow(int, int);
int isPresentInCol(int, int);
void nextStep(int, int);
void solve(int, int);
void print();
int main()
{
	printf("|-----------------------------------------|\n|       WELCOME TO SUDOKU SOLVER          |\n|-----------------------------------------|\n| Do you want generate PUZZLE type 1      |\n|-----------------------------------------|\n| Do you want solve PUZZLE type 2         |\n|-----------------------------------------|\n| Enter any one option above 1 OR 2 	  |\n|-----------------------------------------|\n\n\t\t");
    scanf("%d",&cho);
    printf("\n");
    if(cho==1){
    	srand(time(0));
        sudoku[4][4]=sudoku[0][0]=sudoku[8][8]=(rand()%9)+1;
        solve(0,0);
    }
    else
    {   												//	 |-----------------------------------------|  |-----------------------------------------|
		printf("|-----------------------------------------|\n| Enter the sudoku values to solve if,    |\n| you don't no the values enter 0         |\n| -> \n");
        for(row=0;row<N;row++)
        {
            for(col=0;col<N;col++)
            {
                scanf("%d",&sudoku[row][col]);
            }
        }
        printf("");
        solve(0,0);
    }
}
int isPresentInRow(int row,int num)
{
    for(col=0;col<N;col++)
    {
        if(sudoku[row][col]==num)
        {
            return 0 ;
        }
    }
    return 1;
}
int isPresentInCol(int col,int num)
{
    for(row=0;row<N;row++)
    {
        if(sudoku[row][col]==num)
        {
            return 0;
        }
    }
    return 1;
}
int isPresentInGrid(int row,int col,int num)
{
    row=(row/3)*3 ;
    col=(col/3)*3;
    int r,c;
    for(r=0;r<3;r++)
    {
        for(c=0;c<3;c++)
        {
            if(sudoku[row+r][col+c]==num)
            {
                return 0;
            }
        }
    }
    return 1;
}
void nextStep(int row,int col)
{
    if(col<8)
    {
        solve(row,col+1);
    }
    else
    {
       solve(row+1,0);
    }
}
void solve(int row,int col)
{
    if(row>8)
    {
        print();
    }
    if(sudoku[row][col]!=0)
    {
        nextStep(row,col);
    }
    else
    {
        int val;
        for(val=1;val<=N;val++)
        {
            if((isPresentInRow(row,val)==1)&&(isPresentInCol(col,val)==1)&&(isPresentInGrid(row,col,val)==1))
            {
                sudoku[row][col]=val;
                nextStep(row,col);
            }
        }
        sudoku[row][col]=0;
    }
}
void print()
{
    printf("\n|-----------------------------------------|\n|                 SUDOKU                  |\n");
    for(row=0;row<N;row++)
	{
	    if(row==0)
		{
            printf("|-----------------------------------------|\n|             |             |             |\n");
        }
        if(row==3 || row==6)
		{
            printf("|             |             |             |\n|-------------|-------------|-------------|\n|             |             |             |\n");
        }
        for(col=0;col<N;col++)
		{
            if(col==0)
			{
                printf("|  ");
            }
            printf(" %d ",sudoku[row][col]);
            if(col==2 || col==5)
			{
                printf("  |  ");
            }
            if(col==8)
			{
                printf("  |");
            }
        }
        printf("\n");
    }
    printf("|             |             |             |\n|-----------------------------------------|\n");
    getch();
}
