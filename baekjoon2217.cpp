#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}

void solve() {
	int n;
	cin >> n;
	vector<int>lope(n);
	for (int i = 0; i < n; i++)
		cin >> lope[i];
	sort(lope.begin(), lope.end(), cmp);
	int ret = lope[0];
	for (int i = 1; i < n; i++)
		ret = max(ret, (i + 1) * lope[i]);
	cout << ret << "\n";
}

int main() {
	solve();
}