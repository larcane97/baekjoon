#include <iostream>
#include <cstring>

using namespace std;


int n;
int stairs[301];
int mem[301][3];

int solve(int cur, int num) {
		
	// 계단 범위 초과시
	if (cur > n) return -987654321;
	
	// 연속 3번 이동 시 종료
	if (num >= 3) return -987654321;

	// 동적 계획
	int& ret = mem[cur][num];
	if (ret != -1) return ret;

	// 마지막에 도착했을 시
	if (cur == n)
		return ret = stairs[cur];
	
	return ret =stairs[cur]+max(
		solve(cur + 1, num + 1), solve(cur + 2, 1));
}

int main() {
	cin >> n;
	memset(mem, -1, sizeof(mem));
	stairs[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> stairs[i];
	cout << solve(0, 0);

}