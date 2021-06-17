#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll n, k;
// num보다 작거나 같은 수를 반환
ll count(ll num) {
	ll sum = 0;
	for (int i = 1; i <= n; i++)
		sum += min(num / i, n);
	return sum;
}

void solve() {
	cin >> n >> k;
	ll left = 0;
	ll right = n * n;
	while (left <= right) {
		ll mid = (left + right) / 2;
		// count(mid)==k인 mid값 중 최솟값을 반환해야 한다.
		if (count(mid) >= k)
			right = mid - 1;
		else
			left = mid + 1;
	}
	cout << left << "\n";
}

int main() {
	solve();
}