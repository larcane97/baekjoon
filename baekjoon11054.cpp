#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int arr[1001];
int mem[1001][2];
int n;

// flag 0 : cur에서 최대 bitonic값 
// flag 1 : cur에서 내려갈 수 있는 최대값

int solve(int cur, int flag) {
	if (cur == n) return 1;
	int& ret = mem[cur][flag];
	if (ret != -1 ) return ret;

	ret = 1;
	// arr[cur] < arr[next]:
	// 현재 값 = next의 최대 bitonic 값 + 1
	// arr[cur] > arr[next]:
	// 현재 값 = next의 최대 내려가는 값 + 1
 	for (int i = cur + 1; i <= n; i++)
		// flag 0일 때는 bitonic값 갱신
		if (arr[cur] < arr[i] && flag == 0)
			ret = max(ret, solve(i, 0)+1);
		// flag 1일 때는 내려가는 값 갱신
		else if (arr[cur] > arr[i])
			ret = max(ret, solve(i, 1) + 1);

	if (cur == 0) ret--;
	return ret;


}


int main() {
	cin >> n;
	arr[0] = 0;
	memset(mem, -1, sizeof(mem));

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cout << solve(0, 0)<< endl;
}
