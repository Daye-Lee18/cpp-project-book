# 04. 주소록 프로그램

## 오늘 만들 것

이름, 전화번호, 이메일을 저장하는 `Contact` 클래스를 만들고 여러 연락처를 관리합니다.

## 필요한 개념

- class
- 객체
- 멤버 변수
- 멤버 함수
- `vector`

## 최소 동작 코드

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

## Mission

- 이메일 멤버 변수를 추가하세요.
- 이름으로 연락처를 검색하세요.
- 사용자가 연락처를 입력할 수 있게 만드세요.

## 체크리스트

- 클래스를 정의할 수 있다.
- 객체를 생성할 수 있다.
- `private`과 `public`의 차이를 설명할 수 있다.

