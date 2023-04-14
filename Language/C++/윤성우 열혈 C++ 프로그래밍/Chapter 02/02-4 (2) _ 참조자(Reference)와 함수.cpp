
C언어 에서는 

int num = 24;
HappyFunc(num);
printf("%d", num);       이런 코드만 봐도 출력결과가 24라는 것을 알 수 있었다.
  
하지만 C++은 얼마가 출력될지 알 수 없다.
  
  void HappyFunc(int num);      함수의 원형이 이렇다면 24가 출력된다는 것을 알 수 있지만,
 
  void HappyFunc(int& num);     함수의 원형이 이렇다면 참조자를 통해 num의 값을 바꿀 수 있기에, 분명히 확인이 필요할 것이다.
    
    
   🎈🎈 따라서 C++에서는 함수의 호출문장만을 보고서 값이 변경되는지 안되는지 알 수가 없다.
    
    
    
    하지만 이를 극복하는 방법이 있다..     바로 'const' 키워드를 사용하는 것이다..!!
    
    
    void HappyFunc(const int& num);     <--  "함수 HappyFunc 내에서 참조자 num을 이용한 값의 변경은 하지 않겠다!"
    
    "함수 내에서, 참조자를 통한 값의 변경을 진행하지 않을 경우, 참조자를 const로 선언해서, 함수의 원형만 봐도 값의 변경이 이뤄지지 않음을 알 수 있게 한다."
    
    
---------------------------------------------------------
    
#include <iostream>
using namespace std;

int& RefRetFuncOne(int& ref)
{
	ref++;
	return ref;             // RefRetFuncOne 함수 종료와 동시에 참조자 ref는 소멸
}

int main()
{
	int num1 = 1;
	int& num2 = RefRetFuncOne(num1);

	cout << "num1: " << num1 << endl;      // 2 출력
	cout << "num2: " << num2 << endl;      // 2 출력

	num1++;

	cout << "num1: " << num1 << endl;      // 3 출력
	cout << "num2: " << num2 << endl;      // 3 출력

	num2 += 5;

	cout << "num1: " << num1 << endl;      // 8 출력
	cout << "num2: " << num2 << endl;      // 8 출력

	return 0;
}

---------------------------------------------------------
                                 책 p.87 함 보기 (그냥 쉬운 내용이긴함)
#include <iostream>
using namespace std;

int& Func(int& ref)
{
	ref++;
	return ref;
}

int main()
{
	int num1 = 1;
	int num2 = Func(num1);
	//int& num2 = Func(num1);   이렇게 하면 당연히 같은 것을 참조하니까 같이 변함

	num1++;
	num2 += 100;

	cout << num1 << endl;      // 3 출력
	cout << num2 << endl;      // 102 출력

	return 0;
}

---------------------------------------------------------
  
#include <iostream>
using namespace std;

int Func(int& ref)      // 반환값이 int형 정수
{                       
	ref++;
	return ref;           // ref 반환
}

int main()
{
	int num1 = 1;
	int num2 = Func(num1);     

	num1++;
	num2 += 100;

	cout << num1 << endl;      // 3 출력
	cout << num2 << endl;      // 102 출력

	return 0;
}

---------------------------------------------------------
  
🟢 잘못된 참조의 반환
  
#include <iostream>
using namespace std;

int& Func(int n)              // 🎈🎈 코드를 자세히 보면 참조자 num2가 참조하는 값이 Func()의 num인데 num은 Func()함수의 종료와 동시에 소멸되므로
{                             //       num2는 올바르지 않은 참조를 하고 있게 된다.
	int& num = n;
	num++;

	return num;
}

int main()
{
	int num1 = 1;
	int& num2 = Func(num1);

	cout << num2 << endl;

	return 0;
}



🟢 const 참조자의 또 다른 특징


	const int a = 3;     <-- 오류 발생 ❌    상수화가 되었다면 어떠한 경로를 통하더라도 값의 변경이 허용되지 않아야하기 때문 !!
	int& ref = a;


	const int a = 3;     <-- 허용 ⭕         참조자 ref를 통해서도 값을 변경이 불가하므로 허용 !!
	const int& ref = a;



 
           👉👉👉   const int& ref = 50;   <-- 허용 ⭕ 
           
             아니 어떻게 const 참조자는 상수도 참조가 가능한 것일까???????
             
             
             int num = 20 + 30;   이 문장에서 20과 30은 다음 행으로 넘어가면 존재하지 않는 상수가 된다.
               
             하지만
             
             const int &ref = 50;    C++에서는 이 문장이 성립하도록, const 참조자를 이용해서 상수를 참조할 때 '임시 변수'라는 것을 만든다.
                                     그리고 이 장소에 상수 50을 저장한 뒤, 참조자가 이를 참조하게끔 한다.

                
             
              이를 활용한 코드 하나를 봐보자.
               
             
#include <iostream>
using namespace std;

int Add(const int& a, const int& b)   // 🎈🎈 이렇게 정의된 함수에 인자의 전달을 목적으로 변수를 선언하는 것은 매우 번거롭다.
{                                     //      그러나 임시변수의 생성을 통해 const 참조자의 상수참조를 허용하여, 이 함수를 매우 간단히 호출할 수 있다.
	return a + b;
}

int main()
{
	cout << Add(5, 3) << endl;
	
	return 0;
}


------------------------------------------------------
  
🟠 문제 1
  
#include <iostream>
using namespace std;

int main()
{
	const int num = 12;

	const int* ptr = &num;

	const int* (&ref) = ptr;

	cout << "ptr: " << ptr << endl;                        // 걍 다 같음  ref는 ptr의 별명일 뿐
	cout << "ref: " << ref << endl;

	cout << "*ptr: " << *ptr << endl;
	cout << "*ref: " << *ref << endl;

	cout << "&ptr: " << &ptr << endl;
	cout << "&ref: " << &ref << endl;

	return 0;
}


