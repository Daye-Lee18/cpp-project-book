# 08. Todo List와 STL, 파일 입출력

## 오늘 만들 것

할 일을 추가, 출력, 완료 처리하고 파일에 저장하는 Todo List 프로그램을 만듭니다.

## 필요한 개념

- `vector`
- `string`
- `fstream`
- `algorithm`
- 파일 저장과 불러오기

## 최소 동작 코드

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> todos;
    todos.push_back("Study C++");
    todos.push_back("Build project");

    ofstream out("todos.txt");
    for (string todo : todos) {
        out << todo << endl;
    }
    out.close();

    ifstream in("todos.txt");
    string line;
    while (getline(in, line)) {
        cout << line << endl;
    }
    in.close();

    return 0;
}
```

## Mission

- 메뉴를 추가하세요.
- 완료 여부를 저장하세요.
- 파일에서 기존 할 일을 불러온 뒤 새 할 일을 추가하세요.

## 체크리스트

- `vector`에 데이터를 추가할 수 있다.
- `ofstream`으로 파일에 쓸 수 있다.
- `ifstream`으로 파일에서 읽을 수 있다.

