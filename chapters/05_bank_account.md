# 05. 은행 계좌 시스템

## 오늘 만들 것

입금, 출금, 잔액 조회가 가능한 은행 계좌 클래스를 만듭니다.

## 필요한 개념

- 생성자
- 소멸자
- 접근 제어자
- 캡슐화

## 최소 동작 코드

```cpp
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
```

## Mission

- 출금 실패 메시지를 출력하세요.
- 계좌번호를 추가하세요.
- 여러 계좌를 `vector`로 관리하세요.

## 체크리스트

- 생성자로 객체 초기값을 설정할 수 있다.
- 멤버 변수를 `private`으로 보호할 수 있다.
- 메서드를 통해 객체 상태를 변경할 수 있다.

