set은 컨테이너에 원서(key)를 저장(삽입)하는 유일한 멤버 함수 `insert()`를 제공합니다. 연관 컨테이너 정렬 기준이 있으므로 `insert()`에 의해 삽입된 원소는
자동 정렬됩니다.

set에서 원소(10,30,40,50,70,80,90)를 key라 하며 이 키를 비교하여 내부 원소를 정렬합니다.

set은 그림처럼 모든원소(key)가 유일합니다. 원소의 중복을 허용한다면 ***multiset***을 사용해야 합니다.

![image](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/6093007f-71cc-48f2-9cd4-5a7f31a2ad80)

***연관 컨테이너는 특정 정렬 기준(조건자)에 따라 원소를 자동 정렬하는 컨테이너 입니다.***

정렬 기준은 템플릿 매개변수에 지정할 수 있으며, 기본 정렬 기준은 less 조건자입니다.

연관 컨테이너는 균형 이진 트리를 사용하므로찾기 연산 <`find()`, `lower_bound()`, `upper_bound()`, `equal_range()`, `count()`>에 뛰어난 성능(로그 시간)을
보이며 `insert()` 멤버 함수를 이용한 삽입도 로그 시간 복잡도를 보인다.

---

## 🔥insert()

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	s.insert(50); // 중복 원소(key) 삽입 실패!!
	s.insert(50);

	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	return 0;
}
```
