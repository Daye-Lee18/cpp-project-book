# 03. 학생 성적 관리

## 오늘 만들 것

학생 점수를 저장하고 평균, 최고점, 최저점을 계산하는 프로그램을 만듭니다.

## 필요한 개념

- 배열
- 함수
- 참조
- 문자열

## 최소 동작 코드

```cpp
#include <iostream>
#include <string>
using namespace std;

double average(int scores[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += scores[i];
    }
    return static_cast<double>(total) / size;
}

int main() {
    const int SIZE = 3;
    string names[SIZE] = {"Kim", "Lee", "Park"};
    int scores[SIZE] = {90, 85, 92};

    for (int i = 0; i < SIZE; i++) {
        cout << names[i] << ": " << scores[i] << endl;
    }

    cout << "Average: " << average(scores, SIZE) << endl;
    return 0;
}
```

## Mission

- 최고점 학생을 출력하세요.
- 점수를 사용자 입력으로 받으세요.
- 등급 A/B/C/D/F를 출력하세요.

## 체크리스트

- 배열에 여러 값을 저장할 수 있다.
- 함수를 만들어 계산을 분리할 수 있다.
- 문자열과 숫자 데이터를 함께 다룰 수 있다.

