#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Contact {
private:
    string name;
    string phone;

public:
    Contact(string n, string p) {
        name = n;
        phone = p;
    }

    void print() {
        cout << name << " - " << phone << endl;
    }
};

int main() {
    vector<Contact> contacts;
    contacts.push_back(Contact("Kim", "010-1111-2222"));
    contacts.push_back(Contact("Lee", "010-3333-4444"));

    for (Contact c : contacts) {
        c.print();
    }

    return 0;
}

