#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int cache[12];

int dp(int x) {
	if (x < 0) return 0;
	if (x == 0) return 1;
	int& ret = cache[x];
	if (ret != -1) return ret;
	ret = dp(x - 1) + dp(x - 2) + dp(x - 3);
	return ret;
}

void solve() {
	int T;
	cin >> T;
	for (int iter = 0; iter < T; iter++) {
		memset(cache, -1, sizeof(cache));
		int n;
		cin >> n;
		cout << dp(n) << "\n";
	}
}

int main() {
	solve();
}
