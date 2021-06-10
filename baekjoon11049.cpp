#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
const int MAX_N = 500;
int mem[MAX_N][MAX_N];
vector<pair<int, int>>arr(MAX_N);

int dp(int start, int end) {
	int& ret = mem[start][end];
	if (ret != -1)return ret;
	if (start == end) return ret = 0;
	ret = INF;
	for (int i = start; i < end; i++)
		ret = min(ret, dp(start, i) + dp(i + 1, end)
			+ arr[start].first * arr[i].second * arr[end].second);
	return ret;
}


void solve() {
	memset(mem, -1, sizeof(mem));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = make_pair(a, b);
	}
	cout << dp(0, n - 1) << "\n";

}

int main() {
	solve();
}
