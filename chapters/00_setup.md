# 00. 수업 준비

## 오늘 할 것

C++ 코드를 작성하고 컴파일해서 실행하는 기본 흐름을 확인합니다.

## 필요한 개념

- source file: 사람이 작성하는 `.cpp` 파일
- compile: 소스코드를 실행 가능한 프로그램으로 번역하는 과정
- executable: 컴파일 결과로 만들어지는 실행 파일
- terminal: 명령어로 프로그램을 실행하는 환경

## 최소 동작 코드

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, C++!" << endl;
    return 0;
}
```

## 컴파일과 실행

```bash
g++ main.cpp -o main
./main
```

## 체크리스트

- `.cpp` 파일을 만들 수 있다.
- `g++`로 컴파일할 수 있다.
- 실행 파일을 터미널에서 실행할 수 있다.

