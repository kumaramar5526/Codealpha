#include <iostream>
using namespace std;

const int GRID_SIZE = 9;

// Function to print the Sudoku grid
void printGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to check if a number can be placed in a specific cell
bool isSafe(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num) {
    // Check if the number is not in the current row
    for (int x = 0; x < GRID_SIZE; x++)
        if (grid[row][x] == num)
            return false;

    // Check if the number is not in the current column
    for (int x = 0; x < GRID_SIZE; x++)
        if (grid[x][col] == num)
            return false;

    // Check if the number is not in the current 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int grid[GRID_SIZE][GRID_SIZE]) {
    int row = -1, col = -1;
    bool isEmpty = false;

    // Find an empty cell
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty)
            break;
    }

    // No empty cell left, puzzle solved
    if (!isEmpty)
        return true;

    // Try placing numbers 1-9 in the empty cell
    for (int num = 1; num <= GRID_SIZE; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively solve the rest of the grid
            if (solveSudoku(grid))
                return true;

            // Backtrack if placing num does not lead to a solution
            grid[row][col] = 0;
        }
    }

    return false;
}

// Main function to test the Sudoku solver
int main() {
    int grid[GRID_SIZE][GRID_SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Original Sudoku Puzzle:" << endl;
    printGrid(grid);

    if (solveSudoku(grid)) {
        cout << "\nSolved Sudoku Puzzle:" << endl;
        printGrid(grid);
    } else {
        cout << "No solution exists for the given Sudoku puzzle." << endl;
    }

    return 0;
}
