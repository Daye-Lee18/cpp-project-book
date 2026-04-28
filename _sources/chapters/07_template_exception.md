# 07. 템플릿과 예외 처리

## 오늘의 결과물

이번 장에서는 여러 자료형을 담을 수 있는 `Box` 클래스를 만들고, 값이 없을 때 발생하는 오류를 예외로 처리합니다.

실행 예시는 다음과 같습니다.

```text
Error: Box is empty
10
```

이번 장의 핵심은 자료형이 달라도 같은 구조의 코드를 재사용하는 방법과, 정상 흐름으로 처리하기 어려운 오류를 분리하는 방법입니다.

## 오늘 배울 개념

- 함수 템플릿으로 자료형에 독립적인 함수 만들기
- 클래스 템플릿으로 여러 자료형을 담는 클래스 만들기
- `throw`로 오류 상황 알리기
- `try`, `catch`로 예외 처리하기
- `runtime_error`의 메시지 출력하기

## 1단계: int 값을 담는 Box 만들기

먼저 정수 하나를 저장하고 꺼내는 클래스를 만듭니다.

```cpp
#include <iostream>
using namespace std;

class IntBox {
private:
    int value;

public:
    void set(int v) {
        value = v;
    }

    int get() {
        return value;
    }
};

int main() {
    IntBox box;
    box.set(10);
    cout << box.get() << endl;

    return 0;
}
```

이 클래스는 `int`만 저장할 수 있습니다. `string`이나 `double`을 저장하려면 비슷한 클래스를 또 만들어야 합니다.

## 2단계: 함수 템플릿 이해하기

템플릿은 자료형을 나중에 정하게 해 줍니다.

```cpp
template <typename T>
T bigger(T a, T b) {
    if (a > b) {
        return a;
    }
    return b;
}
```

같은 함수로 여러 자료형을 처리할 수 있습니다.

```cpp
cout << bigger(3, 5) << endl;
cout << bigger(2.5, 1.2) << endl;
```

## 3단계: 클래스 템플릿으로 Box 만들기

`Box`도 템플릿으로 만들면 여러 자료형을 저장할 수 있습니다.

```cpp
template <typename T>
class Box {
private:
    T value;

public:
    void set(T v) {
        value = v;
    }

    T get() {
        return value;
    }
};
```

사용할 때 자료형을 정합니다.

```cpp
Box<int> intBox;
Box<string> stringBox;
```

## 4단계: 값이 없는 상태 표현하기

값을 넣기 전에 `get()`을 호출하면 문제가 생깁니다. 값이 있는지 확인하기 위해 `hasValue`를 둡니다.

```cpp
T value;
bool hasValue = false;

void set(T v) {
    value = v;
    hasValue = true;
}
```

## 5단계: 예외로 오류 처리하기

값이 없을 때는 `throw`로 오류를 알립니다.

```cpp
T get() {
    if (!hasValue) {
        throw runtime_error("Box is empty");
    }
    return value;
}
```

예외가 발생할 수 있는 코드는 `try` 안에 두고, `catch`에서 처리합니다.

```cpp
try {
    cout << box.get() << endl;
} catch (runtime_error& e) {
    cout << "Error: " << e.what() << endl;
}
```

## 프로젝트 v1: int 전용 Box

```cpp
#include <iostream>
using namespace std;

class IntBox {
private:
    int value;

public:
    void set(int v) {
        value = v;
    }

    int get() {
        return value;
    }
};

int main() {
    IntBox box;
    box.set(10);
    cout << box.get() << endl;

    return 0;
}
```

## 프로젝트 v2: 템플릿 Box

```cpp
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Box {
private:
    T value;

public:
    void set(T v) {
        value = v;
    }

    T get() {
        return value;
    }
};

int main() {
    Box<int> intBox;
    intBox.set(10);
    cout << intBox.get() << endl;

    Box<string> stringBox;
    stringBox.set("hello");
    cout << stringBox.get() << endl;

    return 0;
}
```

## 프로젝트 v3: 빈 Box 예외 처리하기

최종 코드는 다음과 같습니다.

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

## 자주 나는 에러

### 템플릿 자료형을 지정하지 않은 경우

```cpp
Box box;
```

클래스 템플릿을 사용할 때는 자료형을 지정합니다.

```cpp
Box<int> box;
```

### stdexcept 헤더를 빠뜨린 경우

```cpp
throw runtime_error("Box is empty");
```

`runtime_error`를 사용하려면 다음 헤더가 필요합니다.

```cpp
#include <stdexcept>
```

### 예외를 처리하지 않은 경우

`throw`가 실행되었는데 처리하지 않으면 프로그램이 비정상 종료될 수 있습니다. 예외가 예상되는 코드는 `try-catch`로 감쌉니다.

## Mission

- `Box<string>`을 만들어 문자열을 저장해 보세요.
- `clear()` 함수를 추가해 Box를 다시 비우세요.
- Generic Stack을 구현하세요.
- 빈 Stack에서 `pop()`할 때 예외를 발생시키세요.

## 체크리스트

- 템플릿으로 자료형에 독립적인 코드를 만들 수 있다.
- 클래스 템플릿을 사용할 때 자료형을 지정할 수 있다.
- `throw`로 오류 상황을 알릴 수 있다.
- `try-catch`로 예외를 처리할 수 있다.
- `e.what()`으로 예외 메시지를 출력할 수 있다.
