# 06. 도형 관리 시스템

## 오늘의 결과물

이번 장에서는 여러 도형의 넓이를 같은 방식으로 계산하는 도형 관리 시스템을 만듭니다.

실행 예시는 다음과 같습니다.

```text
12
78.5
```

이번 장의 핵심은 서로 다른 클래스의 객체를 부모 타입으로 함께 다루는 것입니다. 사각형과 원은 계산 방법이 다르지만, 둘 다 `area()`라는 같은 이름의 함수로 넓이를 구하게 만듭니다.

## 오늘 배울 개념

- 부모 클래스와 자식 클래스 만들기
- 상속으로 공통 규칙 표현하기
- `virtual` 함수와 `override` 사용하기
- 포인터로 자식 객체 다루기
- 동적 할당한 객체를 `delete`로 정리하기

## 1단계: 사각형 넓이 구하기

먼저 사각형 하나의 넓이를 구하는 클래스를 만듭니다.

```cpp
#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    double area() {
        return width * height;
    }
};

int main() {
    Rectangle rect(3, 4);
    cout << rect.area() << endl;

    return 0;
}
```

## 2단계: 원 클래스 추가하기

원은 반지름으로 넓이를 계산합니다.

```cpp
class Circle {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double area() {
        return 3.14 * radius * radius;
    }
};
```

사각형과 원은 내부 데이터가 다르지만, 둘 다 `area()`라는 함수를 가질 수 있습니다.

## 3단계: 공통 부모 클래스 만들기

도형들이 공통으로 가져야 하는 기능을 부모 클래스에 적습니다.

```cpp
class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};
```

### 코드 읽기

- `virtual`: 자식 클래스의 함수가 실행될 수 있게 합니다.
- `= 0`: 부모 클래스에서는 구현하지 않고, 자식 클래스가 반드시 구현해야 한다는 뜻입니다.
- `virtual ~Shape()`: 부모 포인터로 삭제할 때 안전하게 정리되도록 합니다.

## 4단계: 상속으로 도형 만들기

자식 클래스는 `Shape`를 상속하고 `area()`를 구현합니다.

```cpp
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() override {
        return width * height;
    }
};
```

`override`는 부모 클래스의 가상 함수를 자식 클래스에서 다시 정의한다는 뜻입니다.

## 5단계: vector에 여러 도형 저장하기

사각형과 원은 서로 다른 타입입니다. 하지만 둘 다 `Shape`의 자식이므로 `Shape*`로 함께 저장할 수 있습니다.

```cpp
vector<Shape*> shapes;
shapes.push_back(new Rectangle(3, 4));
shapes.push_back(new Circle(5));
```

사용이 끝난 객체는 직접 정리해야 합니다.

```cpp
for (Shape* shape : shapes) {
    delete shape;
}
```

## 프로젝트 v1: 도형 하나의 넓이 계산하기

```cpp
#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() {
        return width * height;
    }
};

int main() {
    Rectangle rect(3, 4);
    cout << rect.area() << endl;

    return 0;
}
```

## 프로젝트 v2: 부모 클래스 도입하기

```cpp
class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};
```

사각형과 원은 `Shape`를 상속합니다.

```cpp
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() override {
        return 3.14 * radius * radius;
    }
};
```

## 프로젝트 v3: 여러 도형 관리하기

최종 코드는 다음과 같습니다.

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() override {
        return 3.14 * radius * radius;
    }
};

int main() {
    vector<Shape*> shapes;
    shapes.push_back(new Rectangle(3, 4));
    shapes.push_back(new Circle(5));

    for (Shape* shape : shapes) {
        cout << shape->area() << endl;
    }

    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
```

## 자주 나는 에러

### 부모 클래스의 소멸자를 virtual로 만들지 않은 경우

부모 포인터로 자식 객체를 삭제할 때는 부모 소멸자를 `virtual`로 만드는 것이 안전합니다.

```cpp
virtual ~Shape() {}
```

### override 함수 이름이 틀린 경우

```cpp
double areas() override {
    return width * height;
}
```

부모 클래스의 함수 이름은 `area()`입니다. 이름이 다르면 재정의가 아닙니다.

### delete를 빠뜨린 경우

`new`로 만든 객체는 사용이 끝나면 `delete`해야 합니다.

```cpp
for (Shape* shape : shapes) {
    delete shape;
}
```

## Mission

- `Triangle` 클래스를 추가하세요.
- 각 도형의 이름도 함께 출력하세요.
- 사용자에게 도형 종류와 값을 입력받아 추가하세요.
- `unique_ptr`를 사용해 `delete`가 필요 없는 버전으로 개선하세요.

## 체크리스트

- 부모 클래스와 자식 클래스를 만들 수 있다.
- 순수 가상 함수의 의미를 설명할 수 있다.
- `override`를 사용해 자식 클래스에서 함수를 재정의할 수 있다.
- 같은 타입의 포인터로 여러 자식 객체를 다룰 수 있다.
- `new`로 만든 객체를 `delete`로 정리해야 함을 설명할 수 있다.
