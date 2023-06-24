#include <bits/stdc++.h>
using namespace std;

// function to check whether a position is safe or not in the maze
// it checks whether a position is 1 if so then it returns true otherwise false
bool isSafe(int **maze, int x, int y, int mazeRow, int mazeColumn)
{
    if (x < mazeRow && y < mazeColumn && maze[x][y] == 1)
    {
        return true;
    }
    return false;
}

// function to traverse the maze
// It stores the solution in a solution array
bool bricksAndBall(int **maze, int x, int y, int mazeRow, int mazeColumn, int **solutionMaze)
{
    // base case
    // update the last position with 1 when it is reached
    if (x == mazeRow - 1 && y == mazeColumn - 1)
    {
        solutionMaze[x][y] = 1;
        return true;
    }
    // update the current position with 1 in solutionMaze
    if (isSafe(maze, x, y, mazeRow, mazeColumn))
    {
        solutionMaze[x][y] = 1;
        // check the maze for the position down to it recursively
        if (bricksAndBall(maze, x + 1, y, mazeRow, mazeColumn, solutionMaze))
        {
            return true;
        }
        // check the maze for the position right to it recursively
        if (bricksAndBall(maze, x, y + 1, mazeRow, mazeColumn, solutionMaze))
        {
            return true;
        }
        // backtracking
        // if we cannot go anywhere update that position with 0 and backtrack
        solutionMaze[x][y] = 0;
        return false;
    }
    return false;
}

// Driver Code
int main()
{
    // maze row and maze column size input
    int mazeRow, mazeColumn;
    cout << "Enter the number of rows in the Maze: ";
    cin >> mazeRow;

    cout << "Enter the number of columns in the Maze: ";
    cin >> mazeColumn;

    // dynamic memory allocation for maze
    int **maze = new int *[mazeRow];
    for (int i = 0; i < mazeColumn; i++)
    {
        maze[i] = new int[mazeColumn];
    }

    // maze input
    cout << "Provide the Maze (0 for closed path and 1 for open path): " << endl;
    for (int i = 0; i < mazeRow; i++)
    {
        for (int j = 0; j < mazeColumn; j++)
        {
            cin >> maze[i][j];
        }
    }

    system("CLS");
    cout << "\t\t\t\t\t  MAZE" << endl;
    cout << endl
         << endl;

    for (int i = 0; i < mazeRow; i++)
    {
        cout << "\t\t\t\t\t";
        for (int j = 0; j < mazeColumn; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }

    // solution maze declaration and initialization
    int **solutionMaze = new int *[mazeRow];
    for (int i = 0; i < mazeRow; i++)
    {
        solutionMaze[i] = new int[mazeColumn];
        for (int j = 0; j < mazeColumn; j++)
            solutionMaze[i][j] = 0;
    }
    cout << endl;

    // bricksAndBall function call and display the solution Maze
    cout << "\t\t\t\t      SOLUTION MAZE" << endl;
    cout << endl
         << endl;

    if (bricksAndBall(maze, 0, 0, mazeRow, mazeColumn, solutionMaze))
    {
        for (int i = 0; i < mazeRow; i++)
        {
            cout << "\t\t\t\t\t";
            for (int j = 0; j < mazeColumn; j++)
            {
                cout << solutionMaze[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

// 1 0 1 0 1
// 1 1 1 1 1
// 1 1 0 1 0
// 0 0 0 1 1
// 1 1 1 0 1