

    int num = 3; 
    int num(3);     이 두가지의 초기화 방식은 결과적으로 동일하다.
      
----------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

class Number
{
private:
	int a;
	int b;
public:
	Number(int a, int b) : a(a), b(b) {}
  
	void AddNum()
	{
		a++;
		b++;
	}

	void ShowNum()
	{
		cout << a << ', ' << b << endl;
	}
};

int main()
{
	//Number num;   <-- 오류발생 : 객체에 맞는 생성자가 정의되어 있지 않음.
  
	Number num1(3, 5);
  
	//Number num2 = num1;
	Number num2(num1);        // 🎈🎈 객체 num1과 num2간의 멤버 대 멤버 복사가 일어난다.
                            //      num1의 멤버변수의 값이 num2의 멤버변수에 복사가 된다.

	num2.AddNum();    
	num2.ShowNum();     // 4, 6 출력                  

	num1.ShowNum();     // 3, 5 출력

	return 0;                              ✅ Q.의문점이 든다. Number num2(num1); 이렇게 객체 num2를 생성했을 경우
}                                              Number 클래스에 num2를 만족시키는 생성자가 없는데 어떻게 오류가 발생하지 않는걸까?
  
                                             --> 아래에 이유가 나옴.
  
----------------------------------------------------------------------------------------  

   SoSimple sim2(sim1);  는 다음과 같은 뜻을 지닌다.

   - SoSimple형 객체를 생성해라.
   - 객체의 이름은 sim2로 정한다.
   - sim1을 인자로 받을 수 있는 생성자의 호출을 통해서 객체생성을 완료한다.
  
  그리고 
  
    SoSimple sim2 = sim1;  과 같은 문장은 
    
    SoSimple sim2(sim1);   와 같은 형태로 결국 묵시적 변환(자동으로 변환)되어서 객체가 생성되는 것이다.
  
  
      
      
#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2) : num1(n1), num2(n2)
	{

	}
  
	SoSimple(SoSimple& copy) : num1(copy.num1), num2(copy.num2)  // 🎈🎈 복사 생성자
	{
		cout << "Called SoSimple(SoSimple &copy)" << endl;
	}
                                           // ✅ 만약 복사 생성자를 정의하지 않으면, 멤버 대 멤버의 복사를 진행하는 디폴트 복사 생성자가 자동으로 삽입된다.
	void ShowSimpleData()                    //     그래서 위에서 만족하는 생성자가 존재하지 않아도 오류가 발생하지 않았던 것이다.
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main()
{
	SoSimple sim1(15, 30);
	cout << "생성 및 초기화 직전" << endl;
	SoSimple sim2 = sim1;
	cout << "생성 및 초기화 직후" << endl;
	sim2.ShowSimpleData();

	return 0;
}


----------------------------------------------------------------------------
  
🟢 explicit 키워드 ! 변환에 의한 초기화를 막을 수 있다!
  
  
	explicit SoSimple(SoSimple& copy) : num1(copy.num1), num2(copy.num2)   // 복사 생성자 앞에 explicit 키워드를 붙인다면,,
	{
		cout << "Called SoSimple(SoSimple &copy)" << endl;
	}


	//SoSimple sim2 = sim1;     이러한 묵시적으로 변환되어서 복사 생성자가 묵시적으로 호출 되는 것을 막을 수 있다.
	SoSimple sim2(sim1);



----------------------------------------------------------------------------

        ✔ 다음 내용 살짝 예습
	
      🎈🎈  SimpleClass num1 = num2;
            SimpleClass num1(num2);   와 같은 문장에서 멤버 대 멤버로 복사된다는 것이 매우 중요한 핵심이다... !

		    
      지금 객체를 생성시 객체를 복사하는 경우에 대해 익히고 있는 중이다..
  
      객체를 이미 생성된 객체의 값으로 복사하고자 할 때는 따로 복사 생성자를 만들어 놓지 않아도,
      디폴트 복사 생성자로 인해, 멤버 대 멤버가 복사가 된다.
        
      그러나 예외가 있다. 복사 생성자를 따로 만들어놔야할 경우가 있는데
      그건 멤버 대 멤버의 복사가 참조형일 경우이다.
        
      멤버변수 char* p와 같은 경우 주소 값을 가리키고 있다. (동적으로 힙에 할당을 해주겠지? class 내부에선?)
      이러한 경우 객체 간의 멤버 대 멤버 복사가 일어나면, 포인터 p는 각각의 객체가 서로 같은 공간의 주소를
      참조하는 상황이 발생한다.
        
      (값이 복사되니까 p의 값은 주소값일테니까 당연히 그러겠지?)
        
      따라서 delete를 해주는 경우 하나의 객체는 해제를 시켜주지만, 나머지 객체의 p는 이미 자신이 가리키고 있는
      공간이 해제가 되었으므로, 오류를 발생하게 된다.

----------------------------------------------------------------------------------------------------------------------------------------------	 
	      
      ✅ 복사 생성자든 일반 생성자든 솔직히 생성자는 함수이고 객체를 생성할 때 알아서 호출되는 함수인거잖아.
          그리고 생성자 또한 함수이기 때문에 오버로드가 가능하잖아..
	      
          이 말이 무슨 말이야?? 어?? 
      
          SimpleC num1;
          SimpleC num2 = num1;  이런 식으로 호출은 결곡 SimpleC num2(num1);으로 묵시적 변환으로 객체가 생성되잖아..
	 
          그니까 결국 num2 객체를 생성할 때 num1을 매개변수로 받을 수 있는 생성자가 필요하다는 거 아니야 !!! 어??
          그래서 복사생성자라는 이름을 가진 생성자를 배운거고..
       
          쉽잖아..
	     
