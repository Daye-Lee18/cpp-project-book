# 03. 학생 성적 관리

## 오늘의 결과물

이번 장에서는 여러 학생의 이름과 점수를 저장하고 평균 점수를 계산하는 성적 관리 프로그램을 만듭니다.

실행 예시는 다음과 같습니다.

```text
Kim: 90
Lee: 85
Park: 92
Average: 89
```

이번 장의 핵심은 같은 종류의 데이터를 여러 개 저장하고, 반복문과 함수로 계산을 분리하는 것입니다.

## 오늘 배울 개념

- 배열에 여러 값 저장하기
- `for` 반복문으로 배열 순회하기
- `string`으로 이름 저장하기
- 함수로 계산 코드 분리하기
- 정수 나눗셈과 실수 나눗셈 구분하기

## 1단계: 점수 하나 출력하기

먼저 학생 한 명의 이름과 점수를 출력합니다.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name = "Kim";
    int score = 90;

    cout << name << ": " << score << endl;

    return 0;
}
```

### 코드 읽기

- `string`: 문자열을 저장하는 자료형입니다.
- `int`: 정수 점수를 저장합니다.
- `<<`: 여러 값을 이어서 출력할 수 있습니다.

## 2단계: 배열로 여러 점수 저장하기

학생이 여러 명이면 변수도 여러 개 필요합니다. 같은 종류의 값이 많을 때는 배열을 사용합니다.

```cpp
int scores[3] = {90, 85, 92};

cout << scores[0] << endl;
cout << scores[1] << endl;
cout << scores[2] << endl;
```

배열의 위치는 0부터 시작합니다. <mark>scores[0]</mark> 은 첫 번째 점수입니다.

## 3단계: 반복문으로 배열 출력하기

배열의 모든 값을 출력할 때는 <mark>for</mark> 반복문을 사용하면 코드가 짧아집니다.

```cpp
const int SIZE = 3;
int scores[SIZE] = {90, 85, 92};

for (int i = 0; i < SIZE; i++) {
    cout << scores[i] << endl;
}
```

### 코드 읽기

- `const int SIZE = 3`: 배열 크기를 이름으로 표현합니다.
- `i = 0`: 첫 번째 위치부터 시작합니다.
- `i < SIZE`: 배열 범위를 넘지 않을 때만 반복합니다.
- `i++`: 다음 위치로 이동합니다.

## 4단계: 이름과 점수 함께 출력하기

이름 배열과 점수 배열을 같은 인덱스로 맞추면 한 학생의 정보를 함께 다룰 수 있습니다.

```cpp
const int SIZE = 3;
string names[SIZE] = {"Kim", "Lee", "Park"};
int scores[SIZE] = {90, 85, 92};

for (int i = 0; i < SIZE; i++) {
    cout << names[i] << ": " << scores[i] << endl;
}
```

<mark>names[1]</mark> 과 <mark>scores[1]</mark> 은 둘 다 두 번째 학생인 Lee의 정보입니다.

## 5단계: 평균 계산을 함수로 분리하기

평균 계산 코드를 함수로 만들면 <mark>main</mark> 함수가 더 읽기 쉬워집니다.

```cpp
double average(int scores[], int size) {
    int total = 0;

    for (int i = 0; i < size; i++) {
        total += scores[i];
    }

    return static_cast<double>(total) / size;
}
```

### 코드 읽기

- `int scores[]`: 정수 배열을 함수로 받습니다.
- `size`: 배열에 값이 몇 개 있는지 알려줍니다.
- `total += scores[i]`: 총합에 현재 점수를 더합니다.
- `static_cast<double>(total)`: 실수 나눗셈이 되도록 변환합니다.

## 프로젝트 v1: 점수 목록 출력하기

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    const int SIZE = 3;
    string names[SIZE] = {"Kim", "Lee", "Park"};
    int scores[SIZE] = {90, 85, 92};

    for (int i = 0; i < SIZE; i++) {
        cout << names[i] << ": " << scores[i] << endl;
    }

    return 0;
}
```

## 프로젝트 v2: 평균 출력하기

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    const int SIZE = 3;
    string names[SIZE] = {"Kim", "Lee", "Park"};
    int scores[SIZE] = {90, 85, 92};
    int total = 0;

    for (int i = 0; i < SIZE; i++) {
        cout << names[i] << ": " << scores[i] << endl;
        total += scores[i];
    }

    cout << "Average: " << static_cast<double>(total) / SIZE << endl;

    return 0;
}
```

## 프로젝트 v3: 평균 함수를 사용하기

최종 코드는 다음과 같습니다.

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

## 자주 나는 에러

### 배열 범위를 넘은 경우

```cpp
cout << scores[3] << endl;
```

크기가 3인 배열의 인덱스는 <mark>0</mark>, <mark>1</mark>, <mark>2</mark>만 사용할 수 있습니다.

### 정수 나눗셈으로 평균을 구한 경우

```cpp
return total / size;
```

소수점 평균이 필요하면 둘 중 하나를 <mark>double</mark>로 바꿔야 합니다.

```cpp
return static_cast<double>(total) / size;
```

### 배열 크기를 함수 안에서 모르는 경우

배열을 함수로 넘기면 함수는 배열 크기를 자동으로 알지 못합니다. 그래서 <mark>size</mark>도 함께 전달합니다.

```cpp
double average(int scores[], int size)
```

## Mission

- 최고점 학생의 이름과 점수를 출력하세요.
- 최저점 학생의 이름과 점수를 출력하세요.
- 점수를 코드에 미리 넣지 말고 사용자 입력으로 받으세요.
- 점수에 따라 A/B/C/D/F 등급을 출력하세요.

## 체크리스트

- 배열에 여러 값을 저장할 수 있다.
- 배열 인덱스가 0부터 시작한다는 것을 설명할 수 있다.
- `for` 반복문으로 배열 전체를 순회할 수 있다.
- 함수를 만들어 평균 계산을 분리할 수 있다.
- `static_cast<double>`이 필요한 상황을 설명할 수 있다.
