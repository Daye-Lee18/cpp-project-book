# 08. Todo List와 STL, 파일 입출력

## 오늘의 결과물

이번 장에서는 할 일을 저장하고 파일로 내보낸 뒤 다시 읽어 오는 Todo List 프로그램을 만듭니다.

실행 예시는 다음과 같습니다.

```text
Study C++
Build project
```

이번 장의 핵심은 프로그램이 종료되어도 데이터를 남기는 방법입니다. <mark>vector</mark>에 저장한 할 일을 파일에 쓰고, 다시 파일에서 읽어 출력합니다.

## 오늘 배울 개념

- `vector`에 문자열 여러 개 저장하기
- `push_back`으로 데이터 추가하기
- `ofstream`으로 파일에 쓰기
- `ifstream`으로 파일에서 읽기
- `getline`으로 한 줄씩 읽기

## 1단계: 할 일 하나 출력하기

먼저 문자열 변수 하나에 할 일을 저장하고 출력합니다.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string todo = "Study C++";

    cout << todo << endl;

    return 0;
}
```

## 2단계: vector에 여러 할 일 저장하기

할 일이 여러 개라면 <mark>vector&lt;string&gt;</mark>을 사용합니다.

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> todos;
    todos.push_back("Study C++");
    todos.push_back("Build project");

    for (string todo : todos) {
        cout << todo << endl;
    }

    return 0;
}
```

### 코드 읽기

- `vector<string>`: 문자열을 여러 개 저장하는 컨테이너입니다.
- `push_back`: vector의 끝에 값을 추가합니다.
- `for (string todo : todos)`: todos 안의 값을 하나씩 꺼내 반복합니다.

## 3단계: 파일에 저장하기

<mark>ofstream</mark>을 사용하면 파일에 내용을 쓸 수 있습니다.

```cpp
#include <fstream>

ofstream out("todos.txt");
for (string todo : todos) {
    out << todo << endl;
}
out.close();
```

프로그램을 실행하면 같은 폴더에 <mark>todos.txt</mark> 파일이 만들어집니다.

## 4단계: 파일에서 읽기

<mark>ifstream</mark>을 사용하면 파일 내용을 읽을 수 있습니다.

```cpp
ifstream in("todos.txt");
string line;

while (getline(in, line)) {
    cout << line << endl;
}

in.close();
```

<mark>getline</mark>은 파일에서 한 줄을 읽어 <mark>line</mark>에 저장합니다. 읽을 줄이 없으면 반복문이 끝납니다.

## 5단계: 저장과 읽기 흐름 연결하기

Todo List 프로그램의 기본 흐름은 다음과 같습니다.

1. <mark>vector</mark>에 할 일을 저장합니다.
2. <mark>ofstream</mark>으로 파일에 씁니다.
3. <mark>ifstream</mark>으로 파일에서 다시 읽습니다.
4. 읽은 내용을 화면에 출력합니다.

## 프로젝트 v1: 메모리에 Todo 저장하기

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> todos;
    todos.push_back("Study C++");
    todos.push_back("Build project");

    for (string todo : todos) {
        cout << todo << endl;
    }

    return 0;
}
```

## 프로젝트 v2: 파일에 저장하기

```cpp
#include <fstream>
#include <iostream>
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

    return 0;
}
```

## 프로젝트 v3: 파일에서 다시 읽기

최종 코드는 다음과 같습니다.

```cpp
#include <fstream>
#include <iostream>
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

## 자주 나는 에러

### fstream 헤더를 빠뜨린 경우

```cpp
ofstream out("todos.txt");
```

파일 입출력을 사용하려면 다음 헤더가 필요합니다.

```cpp
#include <fstream>
```

### 파일을 열었는지 확인하지 않은 경우

실제 프로그램에서는 파일 열기에 실패할 수 있습니다.

```cpp
ifstream in("todos.txt");
if (!in) {
    cout << "File open failed" << endl;
}
```

### cin과 getline을 섞어 쓸 때 입력이 건너뛰어지는 경우

<mark>cin >> menu</mark> 다음에 <mark>getline</mark>을 바로 쓰면 남아 있는 줄바꿈 문자 때문에 입력이 건너뛰어질 수 있습니다. 이 경우 <mark>cin.ignore()</mark>가 필요합니다.

## Mission

- 메뉴를 추가해 할 일 추가, 목록 출력, 종료를 선택하게 만드세요.
- 완료 여부를 함께 저장하세요.
- 파일에서 기존 할 일을 불러온 뒤 새 할 일을 추가하세요.
- 파일 열기에 실패했을 때 메시지를 출력하세요.

## 체크리스트

- `vector`에 데이터를 추가할 수 있다.
- 범위 기반 <mark>for</mark>문으로 vector를 출력할 수 있다.
- `ofstream`으로 파일에 쓸 수 있다.
- `ifstream`으로 파일에서 읽을 수 있다.
- `getline`으로 한 줄씩 읽을 수 있다.
