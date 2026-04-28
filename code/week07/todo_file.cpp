#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> todos;
    todos.push_back("Study C++");
    todos.push_back("Build project");

    ofstream out("todos.txt");
    for (string todo : todos) {
        out << todo << endl;
    }
    out.close();

    ifstream in("todos.txt");
    string line;
    while (getline(in, line)) {
        cout << line << endl;
    }
    in.close();

    return 0;
}

