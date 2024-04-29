#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

bool isSpring(const Date& date);
ifstream openFile(const string& filename);
Date findSpring(ifstream& file);
void printResult(const Date& earliestSpringDate);
