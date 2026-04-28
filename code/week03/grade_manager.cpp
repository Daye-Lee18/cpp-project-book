#include <iostream>
#include <string>
using namespace std;

double average(int scores[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += scores[i];
    }
    return static_cast<double>(total) / size;
}

int main() {
    const int SIZE = 3;
    string names[SIZE] = {"Kim", "Lee", "Park"};
    int scores[SIZE] = {90, 85, 92};

    for (int i = 0; i < SIZE; i++) {
        cout << names[i] << ": " << scores[i] << endl;
    }

    cout << "Average: " << average(scores, SIZE) << endl;
    return 0;
}

