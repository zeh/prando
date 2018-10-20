#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("sudoku.in");

#define N 9

int grid[N][N];

bool FindUnassignedLocation(int &row, int &col);
bool isSafe(int row, int col, int num);

bool SolveSudoku()
{
    int row, col;
    if (!FindUnassignedLocation(row, col))
       return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(num, row, col))
        {
            grid[row][col] = num;
            if (SolveSudoku())
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

bool FindUnassignedLocation(int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

bool SafeInRow(int num, int row)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return false;
    return true;
}

bool SafeInCol(int num, int col)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return false;
    return true;
}

bool SafeInBox(int num, int boxStartRow, int boxStartCol)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return false;
    return true;
}

bool isSafe(int num, int row, int col)
{
    return SafeInRow(num, row) &&
           SafeInCol(num, col) &&
           SafeInBox(num, row - row%3 , col - col%3);
}

void printGrid()
{
    for (int row = 0; row < N; row++)
    {
       for (int col = 0; col < N; col++)
             cout<<grid[col][row]<<' ';
        cout<<endl;
    }
}

int main()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N ;j++)
            fin>>grid[i][j];
    if (SolveSudoku() == true)
          printGrid();
    else
         cout<<"No solution exists";
    return 0;
}
