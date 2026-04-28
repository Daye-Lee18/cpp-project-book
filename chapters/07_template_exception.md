# 07. 템플릿과 예외 처리

## 오늘 만들 것

여러 자료형을 담을 수 있는 간단한 Generic Box를 만들고, 잘못된 접근을 예외로 처리합니다.

## 필요한 개념

- function template
- class template
- `try`, `catch`, `throw`
- 예외 객체

## 최소 동작 코드

```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Box {
private:
    T value;
    bool hasValue = false;

public:
    void set(T v) {
        value = v;
        hasValue = true;
    }

    T get() {
        if (!hasValue) {
            throw runtime_error("Box is empty");
        }
        return value;
    }
};

int main() {
    Box<int> box;

    try {
        cout << box.get() << endl;
    } catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    box.set(10);
    cout << box.get() << endl;
    return 0;
}
```

## Mission

- `Box<string>`을 만들어 보세요.
- Generic Stack을 구현하세요.
- 빈 Stack에서 pop할 때 예외를 발생시키세요.

## 체크리스트

- 템플릿으로 자료형에 독립적인 코드를 만들 수 있다.
- `throw`로 오류 상황을 알릴 수 있다.
- `try-catch`로 예외를 처리할 수 있다.

