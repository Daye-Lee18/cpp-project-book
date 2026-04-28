# 06. 도형 관리 시스템

## 오늘 만들 것

공통 부모 클래스 `Shape`를 만들고, 원과 사각형의 넓이를 다형성으로 계산합니다.

## 필요한 개념

- 상속
- `virtual` 함수
- 다형성
- 포인터

## 최소 동작 코드

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

## Mission

- `Triangle` 클래스를 추가하세요.
- 각 도형의 이름도 출력하세요.
- `unique_ptr` 버전으로 개선하세요.

## 체크리스트

- 부모 클래스와 자식 클래스를 만들 수 있다.
- `virtual` 함수가 필요한 이유를 설명할 수 있다.
- 같은 타입의 포인터로 여러 자식 객체를 다룰 수 있다.

