#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int x, int y) {
	return x < y;
}
vector<int>coords;
void solve() {
	int n, c;
	cin >> n >> c;
	coords.resize(n);
	for (int i = 0; i < n; i++)
		cin >> coords[i];

	sort(coords.begin(), coords.end(),cmp);
	// 간격의 최소 및 최대
	int left = 1;
	int right = coords[n - 1];
	int ret = -1;
	while (left <= right) {
		// 설치할 간격 : 이분탐색
		int mid = (left + right) / 2;
		int num = 1;
		int prev = coords[0];
		for (int i = 1; i < n; i++) 
			if (coords[i] - prev>= mid) {
				num++;
				prev = coords[i];
			}
	
		// 간격이 좁은 경우
		if (num >= c)	
			left = mid + 1;
		// 간격이 넓은 경우
		else 
			right = mid - 1;

		if (mid > ret && num >= c)
			ret = mid;
	}
	cout << ret << "\n";
}

int main() {
	solve();
}

