#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll n, k;
// num���� �۰ų� ���� ���� ��ȯ
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
		// count(mid)==k�� mid�� �� �ּڰ��� ��ȯ�ؾ� �Ѵ�.
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