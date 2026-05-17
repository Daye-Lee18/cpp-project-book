# 04. 주소록 프로그램

## 오늘의 결과물

이번 장에서는 이름과 전화번호를 저장하는 주소록 프로그램을 만듭니다.

실행 예시는 다음과 같습니다.

```text
Kim - 010-1111-2222
Lee - 010-3333-4444
```

이번 장의 핵심은 관련 있는 데이터를 하나의 타입으로 묶고, 여러 객체를 <mark>vector</mark>에 저장하는 것입니다.

## 오늘 배울 개념

- <mark>class</mark>로 새 자료형 만들기
- 멤버 변수와 멤버 함수 구분하기
- 생성자로 객체 초기값 설정하기
- <mark>private</mark>과 <mark>public</mark>으로 접근 범위 나누기
- <mark>vector</mark>에 객체 여러 개 저장하기

## 1단계: 이름과 전화번호 출력하기

먼저 변수 두 개로 연락처 하나를 표현합니다.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name = "Kim";
    string phone = "010-1111-2222";

    cout << name << " - " << phone << endl;

    return 0;
}
```

이 방식은 연락처가 많아질수록 변수 관리가 어려워집니다.

## 2단계: 클래스로 연락처 묶기

이름과 전화번호는 항상 함께 다니는 데이터입니다. 이런 데이터는 클래스로 묶을 수 있습니다.

```cpp
class Contact {
public:
    string name;
    string phone;
};
```

사용은 다음처럼 합니다.

```cpp
Contact c;
c.name = "Kim";
c.phone = "010-1111-2222";
```

<details>
<summary><b>class 개념 더 알아보기</b></summary>

**클래스란?**
클래스는 "새로운 자료형을 직접 만드는 설계도"입니다. <mark>int</mark>, <mark>double</mark>처럼 C++가 미리 만들어 둔 타입 외에, 내가 필요한 타입(<mark>Contact</mark>, <mark>Student</mark>, <mark>Book</mark> 등)을 직접 정의할 수 있습니다.

**클래스 = 데이터 + 기능**
- **멤버 변수**: 객체가 가지는 데이터 (예: <mark>name</mark>, <mark>phone</mark>)
- **멤버 함수**: 객체가 할 수 있는 동작 (예: <mark>print()</mark>)

**객체란?**
설계도(class)로 찍어낸 실제 물건입니다.
```cpp
Contact c1;  // c1은 Contact라는 설계도로 만든 객체
Contact c2;  // c2도 같은 설계도로 만든 또 다른 객체
```
<mark>c1</mark>과 <mark>c2</mark>는 같은 종류지만 서로 다른 데이터를 가질 수 있습니다.

**왜 클래스를 쓸까?**
- 관련 있는 데이터를 한 덩어리로 묶을 수 있다 (이름과 전화번호를 따로 관리하지 않아도 됨)
- 데이터를 다루는 함수까지 함께 묶을 수 있다 (<mark>print()</mark>를 어디 두지 고민할 필요 없음)
- 같은 형태의 데이터를 여러 개 만들기 쉽다

**struct와의 차이**
<mark>struct</mark>도 데이터를 묶을 수 있지만, C++에서 <mark>class</mark>는 기본이 <mark>private</mark>, <mark>struct</mark>는 기본이 <mark>public</mark>입니다. 그 외에는 거의 같습니다.

</details>

## 3단계: 출력 기능을 멤버 함수로 만들기

연락처 출력 방식도 <mark>Contact</mark> 안에 넣을 수 있습니다.

```cpp
class Contact {
public:
    string name;
    string phone;

    void print() {
        cout << name << " - " << phone << endl;
    }
};
```

객체는 자신의 함수를 호출할 수 있습니다.

```cpp
c.print();
```

## 4단계: 생성자로 초기값 넣기

객체를 만든 뒤 값을 하나씩 넣는 대신, 생성자에서 처음 값을 받을 수 있습니다.

```cpp
class Contact {
public:
    string name;
    string phone;

    Contact(string n, string p) {
        name = n;
        phone = p;
    }

    void print() {
        cout << name << " - " << phone << endl;
    }
};
```

이제 객체를 다음처럼 만들 수 있습니다.

```cpp
Contact c("Kim", "010-1111-2222");
```

## 5단계: private으로 데이터 보호하기

클래스 밖에서 멤버 변수를 마음대로 바꾸지 못하게 하려면 <mark>private</mark>에 둡니다. 대신 필요한 기능은 <mark>public</mark> 함수로 제공합니다.

```cpp
class Contact {
private:
    string name;
    string phone;

public:
    Contact(string n, string p) {
        name = n;
        phone = p;
    }

    void print() {
        cout << name << " - " << phone << endl;
    }
};
```

## 프로젝트 v1: 연락처 객체 하나 만들기

```cpp
#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string name;
    string phone;

public:
    Contact(string n, string p) {
        name = n;
        phone = p;
    }

    void print() {
        cout << name << " - " << phone << endl;
    }
};

int main() {
    Contact contact("Kim", "010-1111-2222");
    contact.print();

    return 0;
}
```

## 프로젝트 v2: vector에 여러 연락처 저장하기

<details>
<summary><b>vector 개념 더 알아보기</b></summary>

**vector란?**
<mark>vector</mark>는 "크기가 자동으로 늘어나는 배열"입니다. C++ 표준 라이브러리(STL)에서 제공합니다.

**배열과의 차이**
| 항목 | 배열 (<mark>int arr[3]</mark>) | vector (<mark>vector&lt;int&gt; v</mark>) |
| --- | --- | --- |
| 크기 변경 | 불가능 (고정) | 가능 (<mark>push_back</mark>으로 자동 확장) |
| 크기 알기 | 직접 변수로 관리 | <mark>v.size()</mark> |
| 함수에 전달 | 크기도 같이 넘겨야 함 | vector 하나만 넘기면 됨 |

**기본 사용법**
```cpp
vector<int> v;          // 빈 vector
v.push_back(10);        // 뒤에 값 추가 → [10]
v.push_back(20);        // → [10, 20]
v.push_back(30);        // → [10, 20, 30]

cout << v[0] << endl;   // 배열처럼 인덱스 접근 가능
cout << v.size() << endl; // 3
```

**<mark>vector&lt;T&gt;</mark>의 의미**
<mark>&lt;T&gt;</mark> 부분에는 저장할 값의 타입을 적습니다. 어떤 타입이든 담을 수 있습니다.
```cpp
vector<int> scores;        // 정수를 담는 vector
vector<string> names;      // 문자열을 담는 vector
vector<Contact> contacts;  // Contact 객체를 담는 vector
```

**범위 기반 for문**
vector를 처음부터 끝까지 돌 때는 짧게 쓸 수 있습니다.
```cpp
for (int x : v) {
    cout << x << endl;
}
```

**값 변경하기**
배열처럼 <mark>[]</mark>로 특정 자리의 값을 바꿀 수 있습니다. 단, 그 인덱스에 이미 값이 들어 있어야 합니다.
```cpp
vector<int> v = {10, 20, 30, 40};
v[2] = 99;              // → [10, 20, 99, 40]
v.at(2) = 77;           // 같은 동작이지만 범위를 벗어나면 예외 발생
```

```cpp
vector<int> v;          // 비어있음
v[0] = 1;               // ❌ 위험! 자리가 없는데 쓰기 → 미정의 동작
v.push_back(1);         // ✅ 먼저 자리를 만든 다음 사용
```

**값 삭제하기**
| 메서드 | 동작 | 예시 |
| --- | --- | --- |
| <mark>v.pop_back()</mark> | 맨 뒤 값 1개 삭제 | <mark>[10,20,30] → [10,20]</mark> |
| <mark>v.erase(v.begin() + i)</mark> | i번째 값 1개 삭제 | <mark>[10,20,30]</mark>에서 <mark>i=1</mark> → <mark>[10,30]</mark> |
| <mark>v.erase(v.begin()+a, v.begin()+b)</mark> | a부터 b 직전까지 구간 삭제 | <mark>[10,20,30,40]</mark>에서 <mark>(1,3)</mark> → <mark>[10,40]</mark> |
| <mark>v.clear()</mark> | 모든 값 삭제 (size = 0) | <mark>[10,20,30] → []</mark> |

```cpp
vector<int> v = {10, 20, 30, 40, 50};

v.pop_back();                 // [10, 20, 30, 40]
v.erase(v.begin() + 1);       // [10, 30, 40]  (인덱스 1번 삭제)
v.erase(v.begin(), v.begin() + 2);  // [40]   (앞 2개 삭제)
v.clear();                    // []
```

**값 끼워넣기**
원하는 위치 사이에 값을 끼워넣을 수도 있습니다.
```cpp
vector<int> v = {10, 20, 40};
v.insert(v.begin() + 2, 30);  // 인덱스 2 자리에 30 삽입 → [10, 20, 30, 40]
```

**자주 쓰는 유틸리티**
```cpp
v.size();        // 현재 들어 있는 값의 개수
v.empty();       // 비어있으면 true
v.front();       // 첫 번째 값
v.back();        // 마지막 값
v.resize(10);    // 크기를 10으로 맞춤 (모자라면 0으로 채움, 넘치면 잘림)
```

**주의: 반복문 안에서 erase**
for문으로 vector를 돌면서 <mark>erase</mark>로 지우면 인덱스가 한 칸씩 당겨져서 값을 건너뛸 수 있습니다.
```cpp
// ❌ 위험: 짝수만 지우려고 했지만 일부를 건너뜀
for (int i = 0; i < v.size(); i++) {
    if (v[i] % 2 == 0) v.erase(v.begin() + i);
}

// ✅ 뒤에서부터 돌면 안전
for (int i = v.size() - 1; i >= 0; i--) {
    if (v[i] % 2 == 0) v.erase(v.begin() + i);
}
```

**왜 배열 대신 vector를 쓸까?
- 연락처가 몇 개 들어올지 미리 모를 때도 유연하게 늘릴 수 있다
- 크기를 따로 관리하지 않아도 된다
- 일반적으로 더 안전하고 쓰기 편하다

**주의**
<mark>vector</mark>를 쓰려면 <mark>#include &lt;vector&gt;</mark>를 꼭 추가해야 합니다.

</details>

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Contact {
private:
    string name;
    string phone;

public:
    Contact(string n, string p) {
        name = n;
        phone = p;
    }

    void print() {
        cout << name << " - " << phone << endl;
    }
};

int main() {
    vector<Contact> contacts;
    contacts.push_back(Contact("Kim", "010-1111-2222"));
    contacts.push_back(Contact("Lee", "010-3333-4444"));

    for (Contact c : contacts) {
        c.print();
    }

    return 0;
}
```

## 프로젝트 v3: 입력받은 연락처 추가하기

연락처를 코드에 고정하지 않고 사용자에게 입력받을 수 있습니다.

```cpp
string name;
string phone;

cout << "Name: ";
cin >> name;
cout << "Phone: ";
cin >> phone;

contacts.push_back(Contact(name, phone));
```

## 자주 나는 에러

### private 멤버에 직접 접근한 경우

```cpp
contact.name = "Park";
```

<mark>name</mark>이 <mark>private</mark>이면 클래스 밖에서 직접 접근할 수 없습니다. 값을 바꾸는 기능이 필요하면 public 멤버 함수를 만들어야 합니다.

### vector 헤더를 빠뜨린 경우

```cpp
vector<Contact> contacts;
```

<mark>vector</mark>를 사용하려면 파일 위쪽에 다음 코드를 추가해야 합니다.

```cpp
#include <vector>
```

### 생성자 인자 개수가 맞지 않는 경우

```cpp
Contact c("Kim");
```

생성자가 이름과 전화번호 두 개를 받도록 되어 있다면 두 값을 모두 전달해야 합니다.

```cpp
Contact c("Kim", "010-1111-2222");
```

## Mission

- 이메일 멤버 변수를 추가하세요.
- 이름으로 연락처를 검색하는 함수를 만드세요.
- 사용자가 연락처를 여러 개 입력할 수 있게 만드세요.
- 연락처 개수를 출력하세요.

## 체크리스트

- 클래스를 정의할 수 있다.
- 객체를 생성하고 멤버 함수를 호출할 수 있다.
- 생성자로 객체 초기값을 설정할 수 있다.
- <mark>private</mark>과 <mark>public</mark>의 차이를 설명할 수 있다.
- <mark>vector</mark>에 객체를 저장하고 반복문으로 출력할 수 있다.
