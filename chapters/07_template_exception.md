# 07. 템플릿과 예외 처리

## 오늘의 결과물

이번 장에서는 여러 자료형을 담을 수 있는 <mark>Box</mark> 클래스를 만들고, 값이 없을 때 발생하는 오류를 예외로 처리합니다.

실행 예시는 다음과 같습니다.

```text
Error: Box is empty
10
```

이번 장의 핵심은 자료형이 달라도 같은 구조의 코드를 재사용하는 방법과, 정상 흐름으로 처리하기 어려운 오류를 분리하는 방법입니다.

## 오늘 배울 개념

아래 토글을 펼치면 각 개념의 간단한 설명을 볼 수 있습니다.

<details>
<summary><b>함수 템플릿으로 자료형에 독립적인 함수 만들기</b></summary>

같은 동작이지만 자료형만 다른 함수를 여러 번 작성하는 것은 비효율적입니다. **함수 템플릿**은 자료형을 나중에 정할 수 있게 해 줍니다.

```cpp
template <typename T>
T bigger(T a, T b) {
    return (a > b) ? a : b;
}

bigger(3, 5);       // T = int
bigger(2.5, 1.2);   // T = double
```

<mark>T</mark>는 "어떤 자료형이든 들어올 수 있는 자리"라는 뜻이며, 컴파일러가 호출할 때마다 알맞은 자료형으로 함수를 만들어 줍니다.

</details>

<details>
<summary><b>클래스 템플릿으로 여러 자료형을 담는 클래스 만들기</b></summary>

클래스도 템플릿으로 만들면 자료형마다 새로 만들 필요가 없습니다.

```cpp
template <typename T>
class Box {
    T value;
public:
    void set(T v) { value = v; }
    T get() { return value; }
};
```

사용할 때 자료형을 지정합니다.

```cpp
Box<int> intBox;        // int를 담는 Box
Box<string> stringBox;  // string을 담는 Box
```

<mark>vector&lt;int&gt;</mark>, <mark>vector&lt;string&gt;</mark>처럼 표준 라이브러리도 같은 원리로 만들어져 있습니다.

</details>

<details>
<summary><b><code>throw</code>로 오류 상황 알리기</b></summary>

함수 안에서 정상적으로 처리할 수 없는 상황이 생기면, **예외(exception)** 를 던져서 호출한 쪽에 알릴 수 있습니다.

```cpp
if (!hasValue) {
    throw runtime_error("Box is empty");
}
```

<mark>throw</mark>가 실행되면 그 자리에서 함수 실행이 중단되고, 예외를 처리할 수 있는 곳까지 거슬러 올라갑니다. 반환값으로 오류를 표현하는 것보다 정상 흐름과 오류 흐름을 깔끔하게 분리할 수 있습니다.

</details>

<details>
<summary><b><code>try</code>, <code>catch</code>로 예외 처리하기</b></summary>

예외가 발생할 수 있는 코드는 <mark>try</mark> 블록으로 감싸고, <mark>catch</mark> 블록에서 처리합니다.

```cpp
try {
    cout << box.get() << endl;
} catch (runtime_error& e) {
    cout << "Error: " << e.what() << endl;
}
```

- `try`: "여기서 예외가 발생할 수 있다"고 표시
- `catch`: 발생한 예외를 받아서 처리
- `runtime_error& e`: 예외 객체를 참조로 받음 (복사 비용 절약)

예외가 잡히지 않으면 프로그램이 비정상 종료될 수 있으므로 반드시 처리해야 합니다.

</details>

<details>
<summary><b><code>runtime_error</code>의 메시지 출력하기</b></summary>

<mark>runtime_error</mark>는 <mark>&lt;stdexcept&gt;</mark> 헤더에 정의된 표준 예외 클래스입니다. 생성할 때 넘긴 문자열을 <mark>what()</mark> 함수로 꺼낼 수 있습니다.

```cpp
throw runtime_error("Box is empty");
// ...
catch (runtime_error& e) {
    cout << e.what() << endl; // "Box is empty"
}
```

<mark>what()</mark>은 모든 표준 예외(<mark>exception</mark>, <mark>logic_error</mark>, <mark>out_of_range</mark> 등)가 공통으로 가진 함수입니다. 어떤 예외인지 메시지로 확인할 수 있어 디버깅에 유용합니다.

</details>

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

이 클래스는 <mark>int</mark>만 저장할 수 있습니다. <mark>string</mark>이나 <mark>double</mark>을 저장하려면 비슷한 클래스를 또 만들어야 합니다.

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

<mark>Box</mark>도 템플릿으로 만들면 여러 자료형을 저장할 수 있습니다.

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

값을 넣기 전에 <mark>get()</mark>을 호출하면 문제가 생깁니다. 값이 있는지 확인하기 위해 <mark>hasValue</mark>를 둡니다.

```cpp
T value;
bool hasValue = false;

void set(T v) {
    value = v;
    hasValue = true;
}
```

## 5단계: 예외로 오류 처리하기

값이 없을 때는 <mark>throw</mark>로 오류를 알립니다.

```cpp
T get() {
    if (!hasValue) {
        throw runtime_error("Box is empty");
    }
    return value;
}
```

예외가 발생할 수 있는 코드는 <mark>try</mark> 안에 두고, <mark>catch</mark>에서 처리합니다.

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

<mark>runtime_error</mark>를 사용하려면 다음 헤더가 필요합니다.

```cpp
#include <stdexcept>
```

### 예외를 처리하지 않은 경우

<mark>throw</mark>가 실행되었는데 처리하지 않으면 프로그램이 비정상 종료될 수 있습니다. 예외가 예상되는 코드는 <mark>try-catch</mark>로 감쌉니다.

## Mission

- <mark>Box&lt;string&gt;</mark>을 만들어 문자열을 저장해 보세요.
- <mark>clear()</mark> 함수를 추가해 Box를 다시 비우세요.
- Generic Stack을 구현하세요.
- 빈 Stack에서 <mark>pop()</mark>할 때 예외를 발생시키세요.

## 체크리스트

- 템플릿으로 자료형에 독립적인 코드를 만들 수 있다.
- 클래스 템플릿을 사용할 때 자료형을 지정할 수 있다.
- `throw`로 오류 상황을 알릴 수 있다.
- `try-catch`로 예외를 처리할 수 있다.
- `e.what()`으로 예외 메시지를 출력할 수 있다.
