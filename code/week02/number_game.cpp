#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    srand(time(0));
    int answer = rand() % 100 + 1;
    int guess;
    int count = 0;

    while (true) {
        cout << "Guess: ";
        cin >> guess;
        count++;

        if (guess > answer) {
            cout << "Down" << endl;
        } else if (guess < answer) {
            cout << "Up" << endl;
        } else {
            cout << "Correct. Attempts: " << count << endl;
            break;
        }
    }

    return 0;
}

