# 01. 계산기 만들면서 배우는 기본 문법

## 오늘의 결과물

이번 장에서는 사용자가 입력한 식을 계산하는 콘솔 계산기를 만듭니다.

예를 들어 다음처럼 입력하면:

```text
10 + 3
```

프로그램은 다음 결과를 출력합니다.

```text
13
```

처음부터 완성된 계산기를 만들지는 않습니다. 출력하기, 값 저장하기, 입력받기, 조건 나누기를 차례대로 익힌 뒤 계산기 기능을 조금씩 키웁니다.

## 오늘 배울 개념

- `cout`으로 화면에 출력하기
- 변수에 값을 저장하기
- `cin`으로 사용자 입력 받기
- `if`, `else if`, `else`로 경우 나누기
- 나누기처럼 조심해야 하는 연산 처리하기

## 1단계: 화면에 글자 출력하기

C++ 프로그램은 보통 <mark>main</mark> 함수에서 시작합니다. 먼저 화면에 문장을 출력하는 가장 작은 프로그램을 작성해 봅니다.

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello Calculator" << endl;
    return 0;
}
```

### 코드 읽기

- `#include <iostream>`: 입력과 출력을 사용하기 위해 필요한 준비입니다.
- `int main()`: 프로그램이 시작되는 함수입니다.
- `cout`: 화면에 값을 출력할 때 사용합니다.
- `endl`: 줄을 바꿉니다.
- `return 0`: 프로그램이 정상적으로 끝났다는 뜻입니다.

### 바로 해보기

출력 문장을 다음처럼 바꾸고 다시 실행해 보세요.

```cpp
cout << "My first C++ program" << endl;
```

## 2단계: 숫자를 변수에 저장하기

계산기는 숫자를 기억해야 합니다. C++에서는 값을 저장할 때 변수를 사용합니다.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 3;

    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;

    return 0;
}
```

### 생각해 보기

- <mark>a</mark>와 <mark>b</mark>의 값을 바꾸면 출력 결과도 바뀝니다.
- `int`는 정수를 저장하는 자료형입니다.
- <mark>10 / 3</mark>의 결과가 <mark>3.333...</mark>이 아니라 <mark>3</mark>으로 나오는 이유는 <mark>int</mark>끼리 나누었기 때문입니다.

소수점 결과가 필요하면 <mark>double</mark>을 사용합니다.

```cpp
double a = 10;
double b = 3;
cout << a / b << endl;
```

## 3단계: 사용자에게 숫자 입력받기

매번 코드 안의 숫자를 고치는 계산기는 불편합니다. <mark>cin</mark>을 사용하면 실행 중에 사용자가 값을 입력할 수 있습니다.

```cpp
#include <iostream>
using namespace std;

int main() {
    double a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << a + b << endl;

    return 0;
}
```

### 실행 예시

```text
Enter two numbers: 10 3
13
```

<mark>cin >> a >> b;</mark> 는 사용자가 입력한 첫 번째 값을 <mark>a</mark>에, 두 번째 값을 <mark>b</mark>에 저장합니다.

## 4단계: 연산자 입력받기

계산기가 덧셈만 할 수 있으면 아직 부족합니다. 사용자가 <mark>+</mark>, <mark>-</mark>, <mark>*</mark>, <mark>/</mark> 중 어떤 연산을 원하는지도 입력하게 만듭니다.

```cpp
double a, b;
char op;

cout << "Input: ";
cin >> a >> op >> b;
```

입력을 다음처럼 받을 수 있습니다.

```text
10 + 3
```

여기서 <mark>a</mark>에는 <mark>10</mark>, <mark>op</mark>에는 <mark>'+'</mark>, <mark>b</mark>에는 <mark>3</mark>이 저장됩니다.

## 5단계: 조건문으로 계산 나누기

입력된 연산자에 따라 다른 계산을 해야 합니다. 이때 <mark>if</mark> 문을 사용합니다.

```cpp
if (op == '+') {
    cout << a + b << endl;
} else if (op == '-') {
    cout << a - b << endl;
} else {
    cout << "Unknown operator" << endl;
}
```

### 코드 읽기

- `op == '+'`: <mark>op</mark>에 저장된 값이 <mark>+</mark>인지 비교합니다.
- `else if`: 앞 조건이 아니면 다음 조건을 검사합니다.
- `else`: 어떤 조건에도 맞지 않을 때 실행됩니다.

`=`와 `==`는 다릅니다.

```cpp
op = '+';   // op에 '+'를 저장한다
op == '+';  // op가 '+'인지 비교한다
```

## 프로젝트 v1: 덧셈 계산기

먼저 두 숫자를 입력받아 더하는 계산기를 완성합니다.

```cpp
#include <iostream>
using namespace std;

int main() {
    double a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Result: " << a + b << endl;

    return 0;
}
```

## 프로젝트 v2: 사칙연산 계산기

이제 연산자까지 입력받아 사칙연산을 처리합니다.

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

## 프로젝트 v3: 0으로 나누기 막기

나눗셈에서는 한 가지 예외 상황을 조심해야 합니다. 어떤 수를 0으로 나누면 올바른 계산을 할 수 없습니다.

```cpp
if (op == '/') {
    if (b == 0) {
        cout << "Cannot divide by zero" << endl;
    } else {
        cout << a / b << endl;
    }
}
```

최종 코드는 다음과 같습니다.

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
        if (b == 0) {
            cout << "Cannot divide by zero" << endl;
        } else {
            cout << a / b << endl;
        }
    } else {
        cout << "Unknown operator" << endl;
    }

    return 0;
}
```

## 자주 나는 에러

### 세미콜론을 빼먹은 경우

```cpp
cout << a + b << endl
```

문장 끝에는 <mark>;</mark>를 붙여야 합니다.

```cpp
cout << a + b << endl;
```

### `=`와 `==`를 헷갈린 경우

```cpp
if (op = '+') {
```

조건을 비교할 때는 <mark>==</mark>를 사용합니다.

```cpp
if (op == '+') {
```

### 문자를 큰따옴표로 비교한 경우

```cpp
if (op == "+") {
```

<mark>char</mark> 값은 작은따옴표로 표현합니다.

```cpp
if (op == '+') {
```

## Mission

- <mark>%</mark> 연산을 추가하세요. 단, <mark>%</mark>는 정수끼리만 사용할 수 있습니다.
- 계산을 한 번만 하지 말고 사용자가 <mark>q</mark>를 입력할 때까지 반복하도록 바꾸세요.
- 결과를 출력할 때 <mark>Result: 13</mark>처럼 앞에 설명을 붙이세요.

## 체크리스트

- `cout`으로 원하는 문장을 출력할 수 있다.
- `cin`으로 숫자와 문자를 입력받을 수 있다.
- `int`와 `double`의 차이를 설명할 수 있다.
- `if`, `else if`, `else`로 경우를 나눌 수 있다.
- 0으로 나누는 상황을 조건문으로 막을 수 있다.
