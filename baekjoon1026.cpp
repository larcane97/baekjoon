#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int>a(n);
	vector<int>b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret += a[i] * b[n - i - 1];
	}
	cout << ret << "\n";
}

int main() {
	solve();
}