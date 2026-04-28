# 02. 숫자 맞히기 게임

## 오늘 만들 것

컴퓨터가 만든 숫자를 사용자가 맞히는 업다운 게임을 만듭니다.

## 필요한 개념

- 조건문
- 반복문
- 난수
- Boolean 조건

## 최소 동작 코드

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int answer = rand() % 100 + 1;
    int guess;

    while (true) {
        cout << "Guess: ";
        cin >> guess;

        if (guess > answer) {
            cout << "Down" << endl;
        } else if (guess < answer) {
            cout << "Up" << endl;
        } else {
            cout << "Correct" << endl;
            break;
        }
    }

    return 0;
}
```

## Mission

- 시도 횟수를 출력하세요.
- 최대 7번까지만 시도할 수 있게 만드세요.
- 게임을 다시 시작하는 기능을 추가하세요.

## 체크리스트

- `while` 반복문을 사용할 수 있다.
- `break`로 반복문을 종료할 수 있다.
- 조건에 따라 다른 메시지를 출력할 수 있다.

