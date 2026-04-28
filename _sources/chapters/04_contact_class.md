# 04. 주소록 프로그램

## 오늘의 결과물

이번 장에서는 이름과 전화번호를 저장하는 주소록 프로그램을 만듭니다.

실행 예시는 다음과 같습니다.

```text
Kim - 010-1111-2222
Lee - 010-3333-4444
```

이번 장의 핵심은 관련 있는 데이터를 하나의 타입으로 묶고, 여러 객체를 `vector`에 저장하는 것입니다.

## 오늘 배울 개념

- `class`로 새 자료형 만들기
- 멤버 변수와 멤버 함수 구분하기
- 생성자로 객체 초기값 설정하기
- `private`과 `public`으로 접근 범위 나누기
- `vector`에 객체 여러 개 저장하기

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

## 3단계: 출력 기능을 멤버 함수로 만들기

연락처 출력 방식도 `Contact` 안에 넣을 수 있습니다.

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

클래스 밖에서 멤버 변수를 마음대로 바꾸지 못하게 하려면 `private`에 둡니다. 대신 필요한 기능은 `public` 함수로 제공합니다.

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

`name`이 `private`이면 클래스 밖에서 직접 접근할 수 없습니다. 값을 바꾸는 기능이 필요하면 public 멤버 함수를 만들어야 합니다.

### vector 헤더를 빠뜨린 경우

```cpp
vector<Contact> contacts;
```

`vector`를 사용하려면 파일 위쪽에 다음 코드를 추가해야 합니다.

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
- `private`과 `public`의 차이를 설명할 수 있다.
- `vector`에 객체를 저장하고 반복문으로 출력할 수 있다.
