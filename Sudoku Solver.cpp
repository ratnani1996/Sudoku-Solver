
#include<iostream>
using namespace std;
int sudoku[9][9];
void solvesudoku(int,int);
int checkrow(int row,int num)
{
        //This function checks whether we can put the number in the row of the Sudoku or not
    int column;
    for(column=0;column<9;column++)
        if(sudoku[row][column]==num)
            return 0 ;  //If the number is found already present at certain location we return zero
    return 1;   //If the number is not found anywhere we return 1
}
int checkcolumn(int column,int num)
{       //This function checks whether we can put the number in the column of the Sudoku or not
    int row;
    for(row=0;row<9;row++)
        if(sudoku[row][column]==num)
            return 0;//If the number is found already present at certain location we return zero
    return 1;//If the number is not found anywhere we return 1
}
int checkgrid(int row,int column,int num)
{       //This function checks whether we can put the number in the 3*3 grid or not
        //We get the starting row and column for the 3*3 grid
    row=(row/3)*3 ;
    column=(column/3)*3;
    int r,c;
    for(r=0;r<3;r++)
        for(c=0;c<3;c++)
            if(sudoku[row+r][column+c]==num)
                return 0;   //If the number is found already present at certain location we return zero
    return 1;   //If the number is not found anywhere we return 1
}
void navigate(int row,int column)
{   //Function to move to the next cell in case we have filled one cell
    if(column<8)
        solvesudoku(row,column+1);
    else
        solvesudoku(row+1,0);
}
void display()
{
    int row,column;
    cout<<"THE SOLVED SUDOKU \n";
    for(row=0;row<9;row++)
    {
        for(column=0;column<9;column++)
        cout<<sudoku[row][column]<<" ";
        cout<<"\n";
    }
}

void solvesudoku(int row,int column)
{
    if(row>8) //if all the rows are filled base case is hit
        display();
    if(sudoku[row][column]!=0)
        navigate(row,column);   //if the value at the cell is not zero then move to next cell
    else
    {
        int entry;
        for(entry=1;entry<=9;entry++)
        {
            if((checkrow(row,entry)==1)&&(checkcolumn(column,entry)==1)&&(checkgrid(row,column,entry)==1))
            {
                sudoku[row][column]=entry;
                navigate(row,column);
            }
        }
        sudoku[row][column]=0;  //backtrack when no valid number is found
    }

}
int main()
{
    int row,column;
    cout<<"Enter the desired sudoku and enter 0 for unknown entries\n";
    for(row=0;row<9;row++)
    {
        for(column=0;column<9;column++)
            cin>>sudoku[row][column];
    }
    solvesudoku(0,0);   //start with row 0 and column 0
}

