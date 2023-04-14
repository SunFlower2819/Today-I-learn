
🟢 C언어의 복습을 유도하는 확인학습 문제

[문제 1] : 키워드 const의 의미 

    - const int num = 10;
    - const int * ptr = &val;
    - int * const ptr = &val;
    - const int * const ptr = &val;


[문제 2] : 실행중인 프로그램의 메모리 공간

     - 데이터
     - 스택
     - 힙
     - malloc() 과 free()
  

[문제 3] : Call-by-value 와 Call-by-reference


----------------------------------------------------------------

[문제 1]

    - const int num = 10;     --> 변수 num을 상수화 시킴
                               
    - const int * ptr = &num;  --> *ptr의 값을 변경 불가 !       // *ptr = 3 이렇게 변경 불가 !
      
    - int * const ptr = &num;  --> ptr의 값을 변경 불가 !        // ptr = &val 이렇게 변경 불가 !
      
    - const int * const ptr = &num;  --> *ptr과 ptr의 값 둘다 변경 불가 !
      
int main()
{
	int num1 = 5;
	int num2 = 3;

	const int* p1 = &num1;
	int* const p2 = &num1;
	
	p1 = &num2;
	*p2 = num2;
	
	// *p1 = num2;      <-- 이렇게 하면 오류 발생
	// p2 = &num2;      <-- 이렇게 하면 오류 발생
	
	return 0;
}



[문제 2]

     - 데이터  --> 전역변수 저장
     
     - 스택    --> 지역변수, 매개변수 저장
     
     - 힙      --> malloc()에 의하여 동적으로 할당될 때 저장
     
     - malloc() 과 free()  --> malloc()으로 힙공간에 메모리 할당해주고, free()로 할당한 메모리를 해제시켜줌
       
       
       
       
[문제 3]

     Call-by-value는 값에 의한 호출
     
     Call-by-reference는 참조에 의한 호출
       
       
       
