#include "Header.h"

bool isSpring(const Date& dt) {
    return dt.month >= 3 && dt.month <= 5;
}

ifstream openFile(const string& fileName) {
    setlocale(LC_ALL, "RU");
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Невозможно открыть файл." << endl;
        exit(1);
    }
    return file;
}

Date findSpring(ifstream& file) {
    Date earliestDate = { 0, 0, 9999 };

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        char delimiter;
        Date dt;
        if (iss >> dt.day >> delimiter >> dt.month >> delimiter >> dt.year) {
            if (isSpring(dt) && (dt.year < earliestDate.year ||
                (dt.year == earliestDate.year && dt.month < earliestDate.month) ||
                (dt.year == earliestDate.year && dt.month == earliestDate.month && dt.day < earliestDate.day))) {
                earliestDate = dt;
            }
        }
    }
    return earliestDate;
}

void printResult(const Date& earliestDate) {
    setlocale(LC_ALL, "RU");
    if (earliestDate.year != 9999) {
        cout << "Самая ранняя весенняя дата: " << earliestDate.day << "/" << earliestDate.month << "/" << earliestDate.year << endl;
    }
    else {
        cout << "В файле отсутствуют весенние даты." << endl;
    }
}
