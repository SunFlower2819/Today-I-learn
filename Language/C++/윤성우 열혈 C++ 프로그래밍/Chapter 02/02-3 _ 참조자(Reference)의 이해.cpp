
  "할당된 하나의 메모리 공간에 둘 이상의 이름을 부여할 수는 없을까?"
    
    int *ptr = &num1;  // 변수 num1의 주소 값을 반환해서 포인터 ptr에 저장해라!
    int &num2 = num1;  // 변수 num1에 대한 참조자 num2를 선언해라!

       위의 문장에서 & 연산자는 우리가 알던 것과 전혀 다른 의미로도 사용된다.
      
  🎈🎈 이미 선언된 변수의 앞에 이 연산자가 오면 '주소 값의 반환'을 명령하는 뜻이 되지만,    
       새로 선언되는 변수의 이름 앞에 등장하면, 이는 '참조자의 선언'을 뜻하는 게 된다.   
         
         
       int num1 = 3;
       int &num2 = num1;

       C++에서는 참조자와 변수를 구분해서 이야기한다. 이미 선언된 변수를 대상으로 만들어진 num2와 같은 것을 가리켜
       변수라 하지 않고, '참조자'라는 별도의 이름을 정의해 놓았다.
         
       
       ✅ "참조자는 자신이 참조하는 변수를 대신할 수 있는 또 하나의 이름인 것이다."
         
            쉽게 말해 "변수에 별명을 하나 붙여주는 것이다."


#include <iostream>
using namespace std;

int main()
{
	int num1 = 10;
	int& num2 = num1;

	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;

	num1 = 50;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;

	num2 = 300;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;

	// 두 값의 주소 값
	cout << "&num1: " << &num1 << endl;             // 🎈🎈 두 변수는 같은 주소를 공유한다. 이것이 포인터와 가장 큰 차이점 같다.
	cout << "&num2: " << &num2 << endl;
  
  //int* p = &num1;
	//cout << "&p: " << &p << endl;       <-- 당연히 포인터 p와 변수 num1의 주소 값은 다르다.

	return 0;
}


/*
  출력결과: num1: 10
            num2: 10
            num1: 50
            num2: 50
            num1: 300
            num2: 300
            &num1: 000000B3A4B8F584
            &num2: 000000B3A4B8F584
*/

         
----------------------------------------------
                              
                          👉👉 참조자의 수에는 제한이 없으며, 참조자를 대상으로 참조자를 선언할 수 있다.
#include <iostream>
using namespace std;

int main()
{
	int num1 = 10;
	int& num2 = num1;
	int& num3 = num2;   // 🎈🎈 코드를 자세히 보면 참조자 num3가 참조자 num2를 참조하고 있다.
	int& num4 = num3;
	int& num5 = num4;

	cout << num1 << endl;           
	cout << num2 << endl;         
	cout << num3 << endl;
	cout << num4 << endl;
	cout << num5 << endl;

	num3 = 300;

	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;
	cout << num4 << endl;
	cout << num5 << endl;

	return 0;
}
         
         

🟢 참조자의 선언 가능 범위

                              

	 오류 ❌  int& num2;   
         
         
	 오류 ❌  int& num2 = 20;      // 참조자는 변수에 대해서만 선언이 가능!!!


	 오류 ❌  int& num2 = NULL;
         
         
         
                           💙💙 "참조자는 무조건 선언과 동시에 변수를 참조하도록 해야 한다." 💙💙
                           
-----------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	int aa[3] = { 5,6,7 };
	int& num1 = aa[0];          // 🎈🎈 배열요소는 변수로 간주되어 참조자의 선언이 가능!!!

	return 0;
}

-----------------------------------------------
  
                       // 겉으로는 복잡해보이는데 전혀 그렇지 않다..!!
  
#include <iostream>
using namespace std;

int main()
{
	int num = 12;
	int* ptr = &num;
	int** dptr = &ptr;

	int& ref = num;                  
	int* (&pref) = ptr;            // 🎈🎈 그저 포인터 ptr의 또다른 이름인 pref를 선언했을 뿐 !!
	int** (&dpref) = dptr;         // 🎈🎈 그저 이중 포인터 dptr의 또다른 이름인 dpref를 선언했을 뿐 !!

	cout << *ptr << endl;
	cout << *pref << endl;
	cout << **dptr << endl;
	cout << **dpref << endl;

	int a = 3;

	pref = &a;
	dpref = &pref;

	cout << *ptr << endl;
	cout << *pref << endl;
	cout << **dptr << endl;
	cout << **dpref << endl;
	
	return 0;
}




