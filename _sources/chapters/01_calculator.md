# 01. 계산기 만들면서 배우는 기본 문법

## 오늘 만들 것

두 숫자와 연산자를 입력받아 결과를 출력하는 계산기를 만듭니다.

## 필요한 개념

- 변수와 자료형
- 산술 연산자
- 입력과 출력
- 조건문

## 최소 동작 코드

```cpp
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
        cout << a / b << endl;
    } else {
        cout << "Unknown operator" << endl;
    }

    return 0;
}
```

## Mission

- 0으로 나누는 경우를 처리하세요.
- `%` 연산을 추가하세요.
- 계산을 여러 번 반복하도록 바꾸세요.

## 체크리스트

- `cin`, `cout`을 사용할 수 있다.
- 변수의 자료형을 상황에 맞게 고를 수 있다.
- 조건문으로 연산자를 구분할 수 있다.

