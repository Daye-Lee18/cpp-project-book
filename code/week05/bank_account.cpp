#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string owner;
    int balance;

public:
    BankAccount(string ownerName, int initialBalance) {
        owner = ownerName;
        balance = initialBalance;
    }

    void deposit(int amount) {
        balance += amount;
    }

    bool withdraw(int amount) {
        if (amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }

    void print() {
        cout << owner << ": " << balance << endl;
    }
};

int main() {
    BankAccount account("Kim", 10000);
    account.deposit(5000);
    account.withdraw(3000);
    account.print();
    return 0;
}

