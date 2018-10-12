//Problem statement:
// A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. A rat starts from source and has to reach the destination. The rat can move only in two directions: forward and down.
// In the maze matrix, 0 means the block is a dead end and 1 means the block can be used in the path from source to destination.

#include<stdio.h> 

#define N 4  
  
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]); 

void printSolution(int sol[N][N]) 
{ 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", sol[i][j]); 
        printf("\n"); 
    } 
} 

bool isSafe(int maze[N][N], int x, int y){
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) 
        return true; 
  
    return false; 
}
bool solveMaze(int maze[N][N]){ 
    int sol[N][N] = { {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 0, 0} 
    }; 
  
    if(solveMazeUtil(maze, 0, 0, sol) == false){ 
        printf("Solution doesn't exist"); 
        return false; 
    } 
  
    printSolution(sol); 
    return true; 
} 

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]){
    if(x == N-1 && y == N-1){ 
        sol[x][y] = 1; 
        return true; 
    }  
    if(isSafe(maze, x, y) == true) { 
        sol[x][y] = 1; 
        if (solveMazeUtil(maze, x+1, y, sol) == true) 
            return true; 

        if (solveMazeUtil(maze, x, y+1, sol) == true) 
            return true; 
        sol[x][y] = 0; 
        return false; 
    }    
  
    return false; 
} 

int main() { 
    int maze[N][N]  =  { {1, 0, 0, 0}, 
        {1, 1, 0, 1}, 
        {0, 1, 0, 0}, 
        {1, 1, 1, 1} 
    }; 
  
    solveMaze(maze); 
    return 0; 
}