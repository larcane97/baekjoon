#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int arr[100001];
int mem[100001];
int n;

// 현재 위치에서 연속된 값 중 최대값 반환
int solve(int cur) {
	int& ret = mem[cur];
	if (ret != -1001) return ret;

	if (cur == n) return ret = arr[n];
	return ret = max(arr[cur], solve(cur + 1) + arr[cur]);
}

int getAnswer() {
	int ans = -1001;
	for (int i = 1; i <= n; i++)
		ans = max(solve(i), ans);
	return ans;
}


int main() {
	cin >> n;
	arr[0] = -1001;
	for (int i = 0; i <= 100000; i++)
		mem[i] = -1001;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cout << getAnswer() << endl;

}


