#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// ���� �������� �־��� �� �ּҺ���� ��ȯ
// 1.���� ��� ��ġ�ų� 2.��ġ�� �ʰų�
int mem[501][501];
int sum[501];
int arr[501];
int dp(int start, int end) {
	int& ret = mem[start][end];
	if (ret != -1) return ret;
	if (start == end) return ret = 0;
	ret = 987654321;
	for (int i = start; i <= end; i++) {
		ret = min(ret,dp(start, i) + dp(i + 1, end)+sum[end]-sum[start-1]);
	}

	return ret;
}

void solve() {
	int T;
	cin >> T;
	for (int iter = 0; iter < T; iter++) {
		memset(mem, -1, sizeof(mem));
		int k;
		cin >> k;
		sum[0] = 0;
		for (int i = 1; i <= k; i++) {
			cin >> arr[i];
			sum[i] = arr[i] + sum[i - 1];
		}
		cout << dp(1, k) << "\n";
	}
}

int main() {
	solve();
}