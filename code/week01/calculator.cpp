#include <iostream>
using namespace std;

int main() {
    double a, b;
    char op;

    cout << "Input: ";
    cin >> a >> op >> b;

    if (op == '+') {
        cout << a + b << endl;
    } else if (op == '-') {
        cout << a - b << endl;
    } else if (op == '*') {
        cout << a * b << endl;
    } else if (op == '/') {
        if (b == 0) {
            cout << "Cannot divide by zero" << endl;
        } else {
            cout << a / b << endl;
        }
    } else {
        cout << "Unknown operator" << endl;
    }

    return 0;
}

