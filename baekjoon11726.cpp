#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int cache[1001];
int n;
const int DIV = 10007;

int dp(int x) {
	if (x > n) return 0;
	int& ret = cache[x];
	if (ret != -1) return ret;
	if (x == n) return ret = 1;
	ret = ( (dp(x + 1)%DIV) + (dp(x + 2)%DIV) )%DIV;
	return ret;
}

void solve() {
	memset(cache, -1, sizeof(cache));
	cin >> n;
	cout << dp(0) << "\n";

}

int main() {
	solve();
}