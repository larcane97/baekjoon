#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	vector<int>a, b;
	int n, m;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cin >> m;
	b.resize(m);
	for (int i = 0; i < m; i++)
		cin >> b[i];
	sort(a.begin(), a.end());
	vector<bool>answer(m);
	for (int i = 0; i < m; i++) {
		int left = 0, right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (a[mid] > b[i])
				right = mid - 1;
			else if (a[mid] < b[i])
				left = mid + 1;
			else {
				answer[i] = true;
				break;
			}
		}
	}
	for (int i = 0; i < m; i++)
		cout << answer[i] << " ";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}