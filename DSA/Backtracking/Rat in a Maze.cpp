#include <bits/stdc++.h>
using namespace std;
#define N 4

bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 1);
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    // base: reached bottom-right cell
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y)) {
        sol[x][y] = 1;                     // make move (choose)

        // Try moving RIGHT
        if (solveMazeUtil(maze, x, y + 1, sol)) return true;

        // Try moving DOWN
        if (solveMazeUtil(maze, x + 1, y, sol)) return true;

        // If neither worked -> backtrack (undo move)
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    int sol[N][N] = {0};

    if (solveMazeUtil(maze, 0, 0, sol)) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) cout << sol[i][j] << " ";
            cout << '\n';
        }
    } else cout << "No path found\n";
}
