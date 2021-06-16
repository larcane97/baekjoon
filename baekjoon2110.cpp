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
	// ������ �ּ� �� �ִ�
	int left = 1;
	int right = coords[n - 1];
	int ret = -1;
	while (left <= right) {
		// ��ġ�� ���� : �̺�Ž��
		int mid = (left + right) / 2;
		int num = 1;
		int prev = coords[0];
		for (int i = 1; i < n; i++) 
			if (coords[i] - prev>= mid) {
				num++;
				prev = coords[i];
			}
	
		// ������ ���� ���
		if (num >= c)	
			left = mid + 1;
		// ������ ���� ���
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

