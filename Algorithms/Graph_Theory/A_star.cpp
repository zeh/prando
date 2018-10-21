#include <iostream>
#include <fstream>
#include <deque>
#include <queue>
#include <cmath>

using namespace std;

#define MAX_ROWS 1001
#define MAX_COLS 1001

typedef pair<int, int> Pair;
typedef pair<double, Pair> pPair;

int rows, cols;
int grid[MAX_ROWS][MAX_COLS], closedSet[MAX_ROWS][MAX_COLS];

pair < int, int > dest, src;
deque <pPair> openSet;

struct cell
{
    int parent_i = -1, parent_j = -1;
    double f = -1, g, h;
} cells[MAX_ROWS][MAX_COLS];

bool isValid(int row, int col)
{
    return (row >= 0 && row < rows &&
            col >= 0 && col < cols);
}

bool isDestination(int row, int col)
{
    if(row == dest.first && col == dest.second)
        return true;
    return false;
}

bool isBlocked(int row, int col)
{
    if(grid[row][col])
        return true;
    return false;
}

double returnHValue(int row, int col)
{
    return ((double)sqrt((row - dest.first)*(row - dest.first) +
                         (col - dest.second)*(col - dest.second)));
}

double neighborDist(int dx, int dy)
{
    return (dx == 0 || dy == 0) ? 1.0 : sqrt(2);
}

void tracePath()
{
    cout<<"\nThe path is ";
    int row = dest.first;
    int col = dest.second;

    deque<Pair> Path;
    while(row != src.first || col != src.second)
    {
        Path.push_front(make_pair(row, col));
        int temp_row = cells[row][col].parent_i;
        int temp_col = cells[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }
    Path.push_front(make_pair(row, col));
    while(Path.size())
    {
        Pair p = Path.front();
        Path.pop_front();
        cout<<"\n->("<<p.first<<' '<<p.second<<")";
    }

}

void A_Star()
{
    if(!isValid(src.first, src.second) || !isValid(dest.first, dest.second))
    {
        cout<<"Invalid source / destination\n";
        return;
    }
    if(isBlocked(src.first, src.second)|| isBlocked(dest.first, dest.second))
    {
        cout<<"Source / destination is blocked\n";
        return;
    }
    if(isDestination(src.first, src.second))
    {
        cout<<"We are already at the destination\n";
        return;
    }
    int i, j;
    i = src.first, j = src.second;
    cells[i][j].parent_i = i;
    cells[i][j].parent_j = j;
    cells[i][j].f = cells[i][j].h = returnHValue(i, j);

    openSet.push_front(make_pair(0.0, make_pair(i, j)));
    bool foundDest = false;
    while(openSet.size() && !foundDest)
    {
        int i_min = openSet.size() - 1;
        for(i = openSet.size() - 2; i >= 0; i--)
            if(openSet[i].first < openSet[i_min].first)
                i_min = i;
        pPair p = openSet[i_min];
        openSet.erase(openSet.begin() + i_min);
        i = p.second.first;
        j = p.second.second;
        closedSet[i][j] = 1;
        if(isDestination(i, j))
        {
            foundDest = true;
            tracePath();
        }
        else
            for(int dy = -1; dy <= 1; dy++)
                for(int dx = -1; dx <= 1; dx++)
                    if(!(dx == 0 && dy == 0))
                        if(isValid(i + dy, j + dx) && !isBlocked(i + dy, j + dx))
                            if(!closedSet[i + dy][j + dx])
                            {
                                int di = i + dy, dj = j + dx;
                                int tempG = cells[i][j].g + neighborDist(dx, dy);
                                if(cells[di][dj].f == -1 || cells[di][dj].g > tempG)
                                {
                                    bool isInOpenSet = !(cells[di][dj].f == -1);
                                    cells[di][dj].g = tempG;
                                    if(!cells[di][dj].h)
                                        cells[di][dj].h = returnHValue(di, dj);
                                    cells[di][dj].f = cells[di][dj].g + cells[di][dj].h;
                                    cells[di][dj].parent_i = i;
                                    cells[di][dj].parent_j = j;
                                    if(!isInOpenSet)
                                        openSet.push_front(make_pair(cells[di][dj].f, make_pair(di, dj)));
                                }
                            }
    }
    if(!foundDest)
        cout<<"Could find path to destination\n";

}

int main()
{
    cin>>rows>>cols;
    
    /* Description of the Grid- 
     1--> The cell is blocked 
     0--> The cell is not blocked    
     */
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols ; j++)
            cin>>grid[i][j];
    int src_i, src_j, dest_i, dest_j;
    cin>>src_i>>src_j>>dest_i>>dest_j;
    src = make_pair (src_i, src_j);
    dest = make_pair (dest_i, dest_j);
    A_Star();
    return 0;
}
