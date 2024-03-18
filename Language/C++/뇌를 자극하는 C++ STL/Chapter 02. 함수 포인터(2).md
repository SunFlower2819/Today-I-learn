# 🔵함수 포인터의 종류

C++에서 함수는 정적 함수와 멤버 함수로 나눌 수 있다.

> 정적 함수: 전역 함수, namespace 내의 전역 함수, static 멤버 함수

함수 호출은 세 가지가 있다.
1. 정적 함수 호출(정적 함수)
2. 객체로 멤버 함수 호출(멤버 함수) : `p1.Print();`
3. 객체의 주소로 멤버 함수 호출(멤버 함수) : `p2->Print();` // p2는 포인터

---
## ❤️정적 함수 호출

```cpp
#include <iostream>
using namespace std;

void Print(int n)
{
	cout << "전역함수: " << n << endl;
}

namespace A
{
	void Print(int n)
	{
		cout << "namespace A 전역 함수: " << n << endl;
	}
}

class Point
{
public:
	static void Print(int n)
	{
		cout << "Point 클래스의 정적 멤버 함수: " << n << endl;
	}
};

int main()
{
	void (*pf)(int);    // 정적 포인터 선언
	 
	Print(10);          // 1.namespace 없는 전역 함수 호출
	A::Print(20);       // 2.namespace A의 전역 함수 호출
	Point::Print(30);   // 3.Point 클래스의 정적 멤버 함수 호출

	pf = Print;         
	pf(10);             // 1.함수 포인터로 namespace 없는 전역 함수 호출

	pf = A::Print;
	pf(20);             // 2.함수 포인터로 namespace A의 전역 함수 호출

	pf = Point::Print;
	pf(30);             // 3. 함수 포인터로 Point 클래스의 정적 멤버 함수 호출

	return 0;
}
```

## ❤️객체와 주소로 멤버 함수 호출

멤버 함수 포인터는 함수 포인터 선언에 어떤 클래스의 멤버 함수를 가리킬 것인지 클래스 이름을 지정해야 한다.

`void Point::Print(int n)`인 멤버 함수의 포인터는 `void (Point::*pf)(int)`처럼 선언한다. 

✅그러면 애초에 함수 포인터의 주인은 정해져있는 것과 다름없는거 아닌가..?

```cpp
#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	explicit Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	void Print() const { cout << x << ',' << y << endl; }
	void PrintInt(int n) { cout << "테스트 정수 : " << n << endl; }
};

int main()
{
	Point p1(1, 2);
	Point* p2 = new Point(3, 5);

	void(Point:: * pf1) () const;
	pf1 = &Point::Print;            // 🎈🎈얘는 &를 붙여줘야 하네??
	void (Point:: * pf2) (int);
	pf2 = &Point::PrintInt;

	(p1.*pf1)();        // 객체로 멤버 함수 포인터를 이용한 호출
	(p1.*pf2)(10);

	(p2->*pf1)();       // 주소로 멤버 함수 포인터를 이용한 호출
	(p2->*pf2)(20);

	delete p2;

	return 0;
}
```

## 🔥위에서 &를 왜 붙여줘야 하는지에 대해서..
```cpp
pf1 = &Point::Print;
pf1 = &(Point::Print);
```
참고로 위의 두 문장은 동일하다.

✅아래부터는 쳇 GPT의 내용이다. 

C++에서 함수 이름 자체는 해당 함수의 주소를 나타냅니다. 예를 들어, 다음과 같이 함수 포인터를 선언하고 함수의 주소를 할당할 수 있습니다.

```cpp
void someFunction() {
    // 함수의 내용
}

int main() {
    void (*pf)(); // 함수 포인터 선언
    pf = someFunction; // 함수 주소를 할당, &를 사용하지 않아도 됨
    return 0;
}
```
여기서 someFunction은 함수의 이름이며, 이것 자체가 함수의 주소를 의미합니다. 그래서 함수 포인터를 선언할 때 &를 사용하지 않아도 됩니다.

그러나 클래스의 멤버 함수 포인터는 다릅니다. 멤버 함수 포인터는 해당 멤버 함수가 속한 클래스의 인스턴스와 연관이 있습니다. 즉, 멤버 함수 포인터가 특정한 인스턴스에서 호출되어야 하는 함수를 가리키려면 그 인스턴스에 대한 정보가 필요합니다. 따라서 멤버 함수 포인터를 사용하기 위해서는 해당 멤버 함수가 속한 클래스의 인스턴스에 대한 정보와 함께 해당 멤버 함수의 주소를 제공해야 합니다.

그렇기 때문에 멤버 함수 포인터를 선언할 때는 클래스의 인스턴스와 함께 해당 멤버 함수의 주소를 명시해주어야 합니다. 이를 위해 &를 사용하여 해당 멤버 함수의 주소를 명시합니다. 이렇게 하면 클래스의 인스턴스와 멤버 함수의 주소를 모두 가리키는 포인터를 만들 수 있습니다.

요약하면, 함수 이름 자체는 해당 함수의 주소를 의미하며, 일반적인 함수 포인터를 선언할 때는 &를 사용하지 않아도 됩니다. 그러나 멤버 함수 포인터는 클래스의 인스턴스와 함께 해당 멤버 함수의 주소를 가리켜야 하므로 &를 사용하여 해당 멤버 함수의 주소를 명시해야 합니다.

### 위의 내용 잘 읽어보기
결론은 함수 이름 자체는 주소 값을 표현하고 있는 것이 맞다. <br> 
하지만 멤버 함수 포인터가 받아야할 정보는 멤버 함수뿐만 아니라, 해당 클래스의 정보까지 임을 잊으면 안된다. <br>
왜냐하면 멤버 함수 포인터를 호출할 땐 아래와 같이 객체를 활용하여 호출하기 때문이다.
```cpp
(p1.*pf1)();
```
따라서 `&`를 붙여줘야만 하는 이유는 클래스와 멤버 함수의 주소를 명시해줘야 하기 위함이다. <br>
즉, 객체의 정보와 함수의 주소의 정보가 필요하기 때문에 `&`를 붙이는 것이다.
