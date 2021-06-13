#include <iostream>
using namespace std;

typedef long long ll;
int tree[1000000];

ll calc(int n,int k) {
	ll ret = 0;
	for (int i = 0; i < n; i++) {
		ret += (tree[i] >= k ? tree[i] - k : 0);
	}
	return ret;
}

void solve() {
	int n, m;
	cin >> n >> m;

	int left = 0, right = -1;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
		right = max(right, tree[i]);
	}

	int ret = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		ll cut = calc(n, mid);
		if (cut >= m) {
			ret = max(ret, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << ret << "\n";
}

int main() {
	solve();
}