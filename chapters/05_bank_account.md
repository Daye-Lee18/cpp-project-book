# 05. 은행 계좌 시스템

## 오늘의 결과물

이번 장에서는 입금, 출금, 잔액 조회가 가능한 은행 계좌 클래스를 만듭니다.

실행 예시는 다음과 같습니다.

```text
Kim: 12000
```

이번 장의 핵심은 객체가 자신의 상태를 스스로 관리하게 만드는 것입니다. 잔액은 아무 코드에서나 직접 바꾸지 못하게 하고, 입금과 출금 함수로만 변경합니다.

## 오늘 배울 개념

- 생성자로 객체 초기화하기
- 멤버 변수를 <mark>private</mark>으로 보호하기
- 멤버 함수로 객체 상태 변경하기
- <mark>bool</mark> 반환값으로 성공과 실패 표현하기
- 캡슐화의 필요성 이해하기

## 1단계: 계좌 정보를 변수로 표현하기

먼저 계좌 주인과 잔액을 변수로 저장합니다.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string owner = "Kim";
    int balance = 10000;

    cout << owner << ": " << balance << endl;

    return 0;
}
```

이 방식은 간단하지만, 잔액을 아무 곳에서나 잘못 바꿀 수 있습니다.

## 2단계: BankAccount 클래스 만들기

계좌 주인과 잔액을 하나의 클래스로 묶습니다.

```cpp
class BankAccount {
private:
    string owner;
    int balance;
};
```

<mark>balance</mark>를 <mark>private</mark>에 두면 클래스 밖에서 직접 수정할 수 없습니다.

## 3단계: 생성자로 초기값 넣기

객체를 만들 때 주인 이름과 초기 잔액을 받습니다.

```cpp
class BankAccount {
private:
    string owner;
    int balance;

public:
    BankAccount(string ownerName, int initialBalance) {
        owner = ownerName;
        balance = initialBalance;
    }
};
```

사용은 다음처럼 합니다.

```cpp
BankAccount account("Kim", 10000);
```

## 4단계: 입금 함수 만들기

입금은 잔액을 증가시키는 동작입니다.

```cpp
void deposit(int amount) {
    balance += amount;
}
```

객체의 상태를 바꿀 때는 멤버 함수를 통해 바꿉니다.

## 5단계: 출금 실패 처리하기

출금은 잔액이 충분할 때만 성공해야 합니다. 성공 여부를 <mark>bool</mark>로 반환합니다.

```cpp
bool withdraw(int amount) {
    if (amount > balance) {
        return false;
    }

    balance -= amount;
    return true;
}
```

### 코드 읽기

- <mark>return false</mark>: 출금 실패를 뜻합니다.
- <mark>return true</mark>: 출금 성공을 뜻합니다.
- 실패한 경우에는 잔액을 바꾸지 않습니다.

## 프로젝트 v1: 계좌 만들고 출력하기

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

    void print() {
        cout << owner << ": " << balance << endl;
    }
};

int main() {
    BankAccount account("Kim", 10000);
    account.print();

    return 0;
}
```

## 프로젝트 v2: 입금 기능 추가하기

```cpp
void deposit(int amount) {
    balance += amount;
}
```

<mark>main</mark> 함수에서 다음처럼 호출합니다.

```cpp
account.deposit(5000);
```

## 프로젝트 v3: 출금 기능까지 완성하기

최종 코드는 다음과 같습니다.

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

## 자주 나는 에러

### private 멤버를 직접 바꾼 경우

```cpp
account.balance = 0;
```

<mark>balance</mark>는 <mark>private</mark>이므로 클래스 밖에서 직접 접근할 수 없습니다. 잔액 변경은 <mark>deposit</mark>과 <mark>withdraw</mark>를 통해 처리합니다.

### 출금 실패를 확인하지 않은 경우

```cpp
account.withdraw(50000);
```

함수가 <mark>bool</mark>을 반환한다면 결과를 확인하는 습관이 필요합니다.

```cpp
if (!account.withdraw(50000)) {
    cout << "Withdraw failed" << endl;
}
```

### 음수 입금을 허용한 경우

```cpp
account.deposit(-1000);
```

실제 프로그램이라면 입금액이 0보다 큰지 확인해야 합니다.

## Mission

- 출금 실패 메시지를 출력하세요.
- 입금액과 출금액이 0 이하이면 거부하세요.
- 계좌번호 멤버 변수를 추가하세요.
- 여러 계좌를 <mark>vector</mark>로 관리하세요.

## 체크리스트

- 생성자로 객체 초기값을 설정할 수 있다.
- 멤버 변수를 <mark>private</mark>으로 보호할 수 있다.
- 메서드를 통해 객체 상태를 변경할 수 있다.
- <mark>bool</mark> 반환값으로 성공과 실패를 표현할 수 있다.
- 캡슐화가 필요한 이유를 설명할 수 있다.
