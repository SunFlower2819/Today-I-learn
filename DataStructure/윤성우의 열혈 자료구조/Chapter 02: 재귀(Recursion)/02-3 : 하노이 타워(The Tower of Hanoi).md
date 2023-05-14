```c
#include <stdio.h>

// 하노이 함수
void HanoiTowerMove(int num, char from, char by, char to)
{
	if (num == 1)  // 이동할 원반의 수가 1개라면
	{
		printf("원반1을 %c에서 %c로 이동 \n", from, to); 
		return;
	}
	HanoiTowerMove(num - 1, from, to, by);
	printf("원반%d을(를) %c에서 %c로 이동 \n", num, from, to);
	HanoiTowerMove(num - 1, by, from, to);
}

int main()
{
	HanoiTowerMove(3, 'A', 'B', 'C');
	return 0;
}
```
