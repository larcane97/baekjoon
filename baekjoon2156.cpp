#include <iostream>
#include <cstring>

using namespace std;
int n;

int arr[10001];
int mem[10001][4];


// mem[cur][count] : 현재 위치에서 count번째일 경우 최대값을 반환
int solve(int cur,int count) {	
	if (count >= 3) return -987654321;
	
	int& ret = mem[cur][count];
	if (ret != -1) return ret;

	// 종료
	if (cur == n) 
		return ret = (count < 2 ? arr[cur] :0);

	// 1. 현재 위치를 마실 경우 : arr[cur]만큼 증가 & count증가
	// 안 마실 경우 : count 초기화
	// 2. 다음 위치로 이동
	return ret = (count < 2) ? max(solve(cur + 1, count + 1) + arr[cur], solve(cur + 1, 0))
		: solve(cur + 1, 0);
}


int main() {
	cin >> n;
	memset(mem, -1, sizeof(mem));
	arr[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cout << solve(1,0) << endl;

}