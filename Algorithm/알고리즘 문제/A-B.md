당연히 기초적인 문제이기 만만하게 보았다. 하지만 큰 코를 다쳤다.
문제는 간단하다. 두 정수 A와 B를 입력받은 다음, A/B를 출력하는 코드를 짜면 된다. 

하지만 이 문제는 "실제 정답과 출력값의 절대오차 또는 상대오차가 $$10^{-9}$$ 이하면 정답이다."   
라는 조건이 있다. 이 조건의 뜻은 다음과 같다. 

프로그램이 출력한 값 Y, 정답 X가 있다고 가정했을 때,   
절대오차: |Y-X| <= $$10^{-9}$$ 이거나   
상대오차: |(Y-X)/X| <= $$10^{-9}$$이어야 한다.

🎈🎈결국 최소한 출력한 값이 $$10^{-9}$$ 까지는 실제 정답과 반드시 일치해야 한다는 뜻이다.

즉, "절대오차 또는 상대오차가 $$10^{-9}$$ 이하"라는 조건은 최소한 출력값이 실제 정답과 소수점 8번째 자릿수까지는 반드시 일치해야 하고,   
그러나 소수점 9번째 자리에서 차이가 있더라도 그 차이가 $$10^{-9}$$ 이하라면 정답으로 인정된다는 뜻이다.


```cpp 
#include <iostream>
using namespace std;

int main()
{
	int A, B;

	cin >> A >> B;
	cout << A / (float)B << endl;

	return 0;
}
```
처음에 짠 코드다. 당연히 절대오차와 상대오차를 생각하지 않았기에 다음과 같이 코딩했다. 

위의 코드는 다음과 같은 반례가 존재한다.

```
입력
1 3

출력
0.3  

정답
0.3333333333333

비고
절대오차 = 0.03333333.. > 0.000000001
상대오차 = 0.1 > 0.000000001
```
절대오차가 $$10^{-9}$$보다 크고, 상대오차 또한 $$10^{-9}$$보다 크다. 즉, 실제 정답과 출력값의 절대오차 또는 상대오차가 $$10^{-9}$$ 보다 더 큰 것이다.

🎈🎈백준의 채점기는 오직 출력되는것만 보고 채점하기 때문에, 여기서 출력된 값, `0.3`은 `0.300000`으로 인식된다.   
`0.300000`과 `0.3333333333333`은 다른 수이다.   

따라서 우리는 `cout`가 출력해주는 범위를 수정해줄 필요가 있다. 그래야지 확실히 오차범위를 줄여줄 수 있다.

여기에서 사용되는 함수가 있는데, 바로 `std::ios_base::precision` 함수이다.


---


## `cout.precision(n)`

***`cout.precision(n)`은 출력되는 숫자의 유효 숫자 자리 수를 최대 `n`자리까지 설정해주는 함수이다.***   
유효숫자라는 말에 주의해야 한다. 검색해보면 좋다.

아래의 코드를 보자.
```cpp
std::cout.precision(5);
std::cout << 123.456789 << std::endl;


std::cout << std::fixed; // 🎈🎈fixed를 사용하면 소수점 기준으로 동작
std::cout << 123.456789 << std::endl;
```

```
출력
123.46    // 5자리만 출력하고 반올림 123.456이 반올림된 값
123.45679 // 소수점 이하를 5자리로 고정
```

따라서 코드를 수정하면 다음과 같다.
```cpp
#include <iostream>
using namespace std;

int main()
{
	int A, B;

	cin >> A >> B;
	cout.precision(10);
	cout << A / (double)B << endl;  // double이 float보다 더 정밀하기 때문에 double을 사용해줘야 한다.

	return 0;
}
```


