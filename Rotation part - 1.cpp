#include <iostream>
#include <vector>
using namespace std;

// Function to rotate a matrix by 90 degrees
vector<vector<int>> rotate90(const vector<vector<int>>& matrix) {
    int N = matrix.size();
    vector<vector<int>> rotated(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            rotated[j][N - i - 1] = matrix[i][j];
        }
    }
    return rotated;
}

// Function to rotate a matrix by 45 degrees and fill remaining with zeros
vector<vector<int>> rotate45(const vector<vector<int>>& matrix) {
    int N = matrix.size();
    int newSize = 2 * N - 1;
    vector<vector<int>> rotated(newSize, vector<int>(newSize, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            rotated[i + j][(newSize - 1) / 2 + i - j] = matrix[j][i];
        }
    }
    return rotated;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    vector<vector<int>> rotated45 = rotate45(matrix);
    cout << "\nMatrix Rotated by 45 Degrees:" << endl;
    printMatrix(rotated45);

    vector<vector<int>> rotated90 = rotate90(matrix);
    cout << "\nMatrix Rotated by 90 Degrees:" << endl;
    printMatrix(rotated90);

    return 0;
}

/*
Original Matrix:
1 2 3 
4 5 6 
7 8 9 

Matrix Rotated by 45 Degrees:
0 0 1 0 0 
0 4 0 2 0 
7 0 5 0 3 
0 8 0 6 0 
0 0 9 0 0 

Matrix Rotated by 90 Degrees:
7 4 1 
8 5 2 
9 6 3 

*/
