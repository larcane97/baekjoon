#include <iostream>
using namespace std;
typedef long long ll;
ll cache[91][2];

ll dp(int digit) {
	cache[1][0] = 0;
	cache[1][1] = 1;
	for (int i = 2; i <= digit; i++) {
		cache[i][0] = cache[i - 1][0] + cache[i - 1][1];
		cache[i][1] = cache[i - 1][0];
	}
	return cache[digit][0] + cache[digit][1];
}

void solve() {
	int n;
	scanf("%d", &n);
	printf("%lld\n", dp(n));
}

int main() {
	solve();
}