#include <iostream>

using namespace std;

#define MAX_ROWS 1001
#define MAX_COLS 1001

int rows, cols, i_start, j_start, bestStep;
int chess_board[MAX_ROWS][MAX_COLS], best_board[MAX_ROWS][MAX_COLS];

const int di[]= {2, 2,1, 1,-1,-1,-2,-2},
                dj[]= {1,-1,2,-2, 2,-2, 1,-1};

int countMoves(int i, int j)
{
    int s = 0, ii, jj;
    for(int k = 0; k < 8; k++)
    {
        ii = i + di[k], jj = j + dj[k];
        if(ii >= 0 && ii < rows && jj >= 0 && jj < cols && chess_board[ii][jj] == 0)
            s++;
    }
    return s;
}

void greedy(int strictly = 0)
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            chess_board[i][j] = 0;
    int step = 1;
    int i = i_start, j = j_start;
    while(1)
    {
        chess_board[i][j] = step;
        int minimum = 10, pos = -1;
        for(int k = 0; k < 8; k++)
        {
            int ii = i + di[k], jj = j + dj[k];
            if(ii >= 0 && ii < rows && jj >= 0 && jj < cols && chess_board[ii][jj] == 0)
            {
                int moveCount = countMoves(ii, jj);
                if(strictly)
                {
                    if(minimum > moveCount)
                        minimum = moveCount, pos = k;
                }
                else if(minimum <= moveCount)
                    minimum = moveCount, pos = k;
            }
        }
        if(pos == -1)
            break;
        else
            i = i + di[pos], j = j + dj[pos], step++;
    }
    if(step > bestStep)
    {
        bestStep = step;
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                best_board[i][j] = chess_board[i][j];
    }
}

int main()
{
    cin>>rows>>cols;
    cin>>i_start>>j_start;
    greedy();
    if(bestStep != rows*cols)
        greedy(1);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0 ; j < cols; j++)
            cout<<best_board[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
