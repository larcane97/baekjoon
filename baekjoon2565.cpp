#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<int, int>>lines;

int mem[101];
int n;
// 현재 위치에서 최대 LIS
int LIS(int cur) {
	int& ret = mem[cur];
	if (ret != -1)return ret;
	if (cur == n - 1) return ret = 1;

	ret = 1;
	for (int next = cur + 1; next < n; next++) {
		if (lines[cur].second < lines[next].second)
			ret = max(ret, LIS(next) + 1);
	}
	return ret;
}


int solve() {
	sort(lines.begin(), lines.end());
	int lis = -1;
	memset(mem, -1, sizeof(mem));
	for (int i = 0; i < n; i++)
		lis = max(lis, LIS(i));
	return n - lis;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		lines.push_back(make_pair(a, b));
	}
}


int main() {
	input();
	cout << solve() << endl;
}