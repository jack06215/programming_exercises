#include <vector>
#include <iostream>

using namespace std;

void printBoundary(vector<vector<int>>& arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || j == 0 || i == cols - 1 || j == cols - 1) {
                cout << arr[i][j] << " ";
            }
            else {
                cout << " "
                    << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> arr = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 1, 2, 3, 4 }, { 5, 6, 7, 8 } };
    printBoundary(arr, 4, 4);
    return 0;
}