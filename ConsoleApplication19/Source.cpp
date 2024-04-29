#include "Header.h"

int main() {
    ifstream file = openFile("dates.txt");
    Date earliestSpringDate = findSpring(file);
    printResult(earliestSpringDate);
    file.close();

    return 0;
}
