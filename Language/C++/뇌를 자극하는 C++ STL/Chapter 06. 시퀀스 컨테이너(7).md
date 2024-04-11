![image](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/04c6828a-e129-4a8b-b18b-79bbdb339edb)

list는 시퀀스 컨테이너이므로 원소의 저장 위치(순서)가 정해지며 노드 기반 컨테이너이므로 원소가 각각의 노드에 저장됩니다.
각 노드는 앞쪽, 뒤쪽 노드와 연결된 형태로 ***이중 연결 리스트***입니다.

list는 노드 기반 컨테이너로 `at()`과 `[]`연산자가 없으며 임의 접근 반복자가 아닌 양방향 반복자를 제공합니다.
그래서 모든 원소를 탐색하려면 양방향 반복자의 연산인 `++`,`--`를 사용합니다.

---

## 🔥list의 원소 추가와 반복자
```cpp
#include <iostream>
#include <list> 
using namespace std;

int main()
{
	list<int> lt;

	lt.push_back(10); // 뒤쪽에 추가
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);
	lt.push_back(50);

	list<int>::iterator iter;
	for (iter = lt.begin(); iter != lt.end(); iter++) // 10 20 30 40 50 출력
		cout << *iter << " ";
	cout << endl;

	lt.push_front(100); // 앞쪽에 추가
	lt.push_front(200);

	for (iter = lt.begin(); iter != lt.end(); iter++) // 200 100 10 20 30 40 50 출력
		cout << *iter << " ";
	
	return 0;
}
```
---

## 🔥list의 `insert()`와 `erase()`
***list의 가장 큰 특징 중 하나는 순차열 중간에 원소를 삽입(insert), 제거(erase)하더라도 상수 시간 복잡도의 수행 성능을 보인다는 점입니다.
배열 기반 컨테이너 vector나 deque처럼 원소를 밀어내지 않고 노드를 서로 연결하기만 하면 되기 때문입니다.***

```
또한, 노드 기반 컨테이너 삽입(insert)과 제거(erase) 동작은 반복자를 무효화시키지 않습니다.
반복자가 가리키는 원소 자체가 제거되지 않는 한 반복자가 가리키는 원소는 그대로 존재합니다.
하지만 배열 기반 컨테이너(vector, deque)의 반복자는 원소의 삽입과 제거 동작이 발생하면
메모리가 재할당되거나 원소가 이동할 수 있으므로 반복자가 무효화됩니다.

-> 위의 문단이 이해가 안됐다. 근데 그냥 쉽게 말하면 list는 노드 기반 컨테이너이기 때문에
   원소를 삽입하거나 제거하는 과정에서 메모리의 재할당이 필요없지만,
   vector 같이 배열 기반 컨테이너는 원소를 삽입하거나 제거하는 과정에서
   메모리 재할당이 일어난다는 의미이다.

   아래에 코드와 그림으로 보자.
```

```cpp
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
	list<int> lt;
	vector<int> v;

	lt.push_back(10); 
	lt.push_back(20);
	lt.push_back(30);

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	list<int>::iterator Liter = lt.begin();
	vector<int>::iterator Viter = v.begin();

	Liter++; // 원소 20을 가리킴
	Viter++; // 원소 20을 가리킴

	Liter = lt.insert(Liter, 999);
	Viter = v.insert(Viter, 999);

	cout << *Liter << endl; // 999 출력 
	cout << *Viter << endl; // 999 출력

	for (Liter = lt.begin(); Liter != lt.end(); Liter++)  // 10 999 20 30 출력
		cout << *Liter << " ";
	cout << endl;

	for (Viter = v.begin(); Viter != v.end(); Viter++)   // 10 999 20 30 출력
		cout << *Viter << " ";

	return 0;
}
```

아래의 그림처럼 `v`에 999를 삽입하면 다음 원소부터 모두 뒤로 밀려나며 할당된 메모리 공간이 부족하면 메모리 재할당이 발생한다.
하지만, `lt`는 원소(노드) 하나만을 삽입하므로 속도가 빠르며 반복자들이 무효화되지 않는다. 

또한, `erase()`함수의 동작도 '삽입'동작과 같은 특징을 보인다.

![image](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/1b4cccea-f54e-4371-a456-111ed616d5c0)

