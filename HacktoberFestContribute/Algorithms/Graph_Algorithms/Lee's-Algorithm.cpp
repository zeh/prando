#include <iostream>
#include <fstream>
#include <queue>
#include <deque>

using namespace std;

#define MAX_ROWS 1001
#define MAX_COLS 1001

typedef pair <int, int> Pair;

int cols, rows;
int grid[MAX_ROWS][MAX_COLS];
Pair src, dest;
queue <Pair> Q;

bool isValid(int i, int j)
{
    return (i >= 0 && i < rows &&
            j >= 0 && j < cols);
}

bool isBlocked(int i, int j)
{
    return grid[i][j] < 0;
}


void traceBack()
{
    deque <Pair> Path;
    int row = dest.first, col = dest.second;
    while(row != src.first || col != src.second)
    {
        bool found = false;
        Path.push_front(make_pair(row, col));
        for(int i = -1; i <= 1 && !found; i++)
            for(int j = -1; j <= 1 && !found; j++)
                if((i!=0 || j!=0) && isValid(i + row, j + col))
                {
                    if(grid[row + i][col + j] == grid[row][col] - 1)
                    {
                        row = row + i;
                        col = col + j;
                        found = true;
                    }
                }

    }
    Path.push_front(make_pair(row, col));
    cout<<"The path is:";
    while(!Path.empty())
    {
        Pair p = Path.front();
        Path.pop_front();
        cout<<"\n->("<<p.first<<' '<<p.second<<')';
    }
}

void leeAlgorithm()
{
    if(!isValid(src.first, src.second) || !isValid(dest.first, dest.second))
    {
        cout<<"Invalid starting / destination point";
        return;
    }
    if(isBlocked(src.first, src.second) || isBlocked(dest.first, dest.second))
    {
        cout<<"Starting / destionation point is blocked";
        return;
    }
    if(src.first == dest.first && src.second == dest.second)
    {
        cout<<"Already at the destionation";
        return;
    }
    Q.push(src);
    grid[src.first][src.second] = 1;
    while(!Q.empty())
    {
        Pair current = Q.front();
        Q.pop();
        int i = current.first, j = current.second;
        for(int di = -1; di <= 1; di++)
            for(int dj = -1; dj <= 1; dj++)
                if(dj!=0 || di!=0)
                {
                    int ci = i + di, cj = j + dj;
                    if(isValid(ci, cj))
                        if(grid[ci][cj] == 0 || grid[ci][cj] > grid[i][j] + 1)
                        {
                            grid[ci][cj] = grid[i][j] + 1;
                            Q.push(make_pair(ci, cj));
                        }
                }
    }
    if(grid[dest.first][dest.second])
        traceBack();
    else
        cout<<"Couldn't get to the destination";
}

int main()
{
    cin>>rows>>cols;

    /*Description of grid
     -1 --> The cell is blocked
      0 --> The cell is not blocked
    */
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            cin>>grid[i][j];

    int src_i, src_j, dest_i, dest_j;
    cin>>src_i>>src_j>>dest_i>>dest_j;

    src = make_pair(src_i, src_j);
    dest = make_pair(dest_i, dest_j);

    leeAlgorithm();
    return 0;
}
