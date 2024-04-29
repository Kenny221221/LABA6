#include "Header.h"

vector<vector<int>> readSquareMatrixFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "������ �������� �����: " << filename << endl;
        return {};
    }

    vector<vector<int>> matrix;
    string line;
    int numRows = 0;
    while (getline(inFile, line)) {
        vector<int> row;
        istringstream iss(line);
        int num;
        while (iss >> num) {
            row.push_back(num);
        }
        matrix.push_back(row);
        numRows++;
        if (line.find("  ") != string::npos) {
            cout << "�������� ������ �������." << endl;
            return {};
        }
    }

    inFile.close();

    int numCols = matrix.empty() ? 0 : matrix[0].size();
    if (numRows != numCols) {
        cout << "������: ������� �� ����� �� �������� ����������." << endl;
        return {};
    }

    return matrix;
}


