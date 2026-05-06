# 02. 숫자 맞히기 게임

## 오늘의 결과물

이번 장에서는 컴퓨터가 정한 숫자를 사용자가 맞히는 업다운 게임을 만듭니다.

실행 예시는 다음과 같습니다.

```text
Guess: 50
Up
Guess: 75
Down
Guess: 63
Correct. Attempts: 3
```

이번 장의 핵심은 같은 작업을 여러 번 반복하는 방법입니다. 숫자를 한 번 입력받고 끝내는 프로그램에서 시작해, 맞힐 때까지 계속 입력받는 게임으로 키워 갑니다.

## 오늘 배울 개념

- `while` 반복문 사용하기
- 조건문을 반복문 안에서 사용하기
- `break`로 반복문 끝내기
- 난수로 매번 다른 정답 만들기
- 시도 횟수처럼 상태를 누적하기

## 1단계: 한 번만 추측하기

먼저 정답을 코드 안에 정해 두고, 사용자가 숫자를 한 번 입력하게 만듭니다.

```cpp
#include <iostream>
using namespace std;

int main() {
    int answer = 42;
    int guess;

    cout << "Guess: ";
    cin >> guess;

    if (guess == answer) {
        cout << "Correct" << endl;
    } else {
        cout << "Wrong" << endl;
    }

    return 0;
}
```

### 코드 읽기

- `answer`: 컴퓨터가 정한 정답입니다.
- `guess`: 사용자가 입력한 숫자입니다.
- `guess == answer`: 두 값이 같은지 비교합니다.

### 바로 해보기

`answer` 값을 다른 숫자로 바꾸고 실행해 보세요.

## 2단계: Up과 Down 출력하기

정답인지 아닌지만 알려주면 게임이 어렵습니다. 입력한 숫자가 너무 큰지 작은지 알려주면 사용자가 다음 숫자를 고를 수 있습니다.

```cpp
if (guess > answer) {
    cout << "Down" << endl;
} else if (guess < answer) {
    cout << "Up" << endl;
} else {
    cout << "Correct" << endl;
}
```

### 생각해 보기

- `guess > answer`: 사용자가 너무 큰 숫자를 입력했습니다.
- `guess < answer`: 사용자가 너무 작은 숫자를 입력했습니다.
- 마지막 `else`: 크지도 작지도 않으므로 정답입니다.

## 3단계: 반복해서 입력받기

게임은 정답을 맞힐 때까지 계속되어야 합니다. 이때 `while` 반복문을 사용합니다.

```cpp
while (true) {
    cout << "Guess: ";
    cin >> guess;

    if (guess == answer) {
        cout << "Correct" << endl;
        break;
    }
}
```

`while (true)`는 계속 반복하라는 뜻입니다. 반복을 끝내고 싶을 때는 `break`를 사용합니다.

## 4단계: 난수로 정답 만들기

정답이 항상 같으면 게임이 금방 지루해집니다. `rand()`를 사용하면 실행할 때마다 다른 숫자를 만들 수 있습니다.

```cpp
#include <cstdlib>
#include <ctime>

srand(time(0));
int answer = rand() % 100 + 1;
```

### 코드 읽기

- `rand()`: 임의의 정수를 만듭니다.
- `% 100`: 결과를 0부터 99 사이로 줄입니다.
- `+ 1`: 범위를 1부터 100 사이로 바꿉니다.
- `srand(time(0))`: 프로그램을 실행할 때마다 다른 난수 흐름을 사용하게 합니다.

## 프로젝트 v1: 고정 정답 게임

정답을 코드에 직접 넣은 버전입니다.

```cpp
#include <iostream>
using namespace std;

int main() {
    int answer = 42;
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

## 프로젝트 v2: 난수 정답 게임

이제 정답을 1부터 100 사이의 난수로 만듭니다.

```cpp
#include <cstdlib>
#include <ctime>
#include <iostream>
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

## 프로젝트 v3: 시도 횟수 출력하기

게임을 몇 번 만에 맞혔는지 알려주면 더 완성된 프로그램이 됩니다.

```cpp
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
```

## 자주 나는 에러

### `break`를 빼먹은 경우

정답을 맞혀도 반복문이 끝나지 않습니다.

```cpp
if (guess == answer) {
    cout << "Correct" << endl;
}
```

정답을 맞힌 순간 반복을 끝내야 합니다.

```cpp
if (guess == answer) {
    cout << "Correct" << endl;
    break;
}
```

### `srand`를 반복문 안에 넣은 경우

난수 초기화는 프로그램 시작 부분에서 한 번만 합니다.

```cpp
srand(time(0));
```

### 범위를 잘못 만든 경우

```cpp
int answer = rand() % 100;
```

이 코드는 0부터 99까지 나올 수 있습니다. 1부터 100까지 만들려면 다음처럼 작성합니다.

```cpp
int answer = rand() % 100 + 1;
```

## Mission

- 최대 7번까지만 시도할 수 있게 만드세요.
- 사용자가 맞히지 못하면 정답을 출력하세요.
- 한 게임이 끝난 뒤 다시 시작할지 물어보세요.

## 체크리스트

- `while` 반복문을 사용할 수 있다.
- `break`로 반복문을 종료할 수 있다.
- 조건에 따라 `Up`, `Down`, `Correct`를 출력할 수 있다.
- `rand()`로 1부터 100 사이의 난수를 만들 수 있다.
- 시도 횟수를 변수에 누적할 수 있다.
