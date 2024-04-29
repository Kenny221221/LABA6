
#include "Header.h"

int main() {
    setlocale(LC_ALL, "RU");
    string filename = "matrix.txt";

    vector<vector<int>> matrix = readSquareMatrixFromFile(filename);

    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}