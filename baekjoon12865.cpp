#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int mem[101][100001];
vector<pair<int, int>>bags;
int n, k;

// cur 위치에서 remain만큼 배낭이 남아있을 경우,
// 최대값 반환
int solve(int cur, int remain) {
	if (remain < 0) return -987654321;
	int& ret = mem[cur][remain];
	if (ret != -1) return ret;
	if (cur == n - 1) {
		if (remain >= bags[cur].second)
			return ret = bags[cur].first;
		return ret = 0;
	}
	for (int next = cur+1; next < n; next++) {
		// 현재 값을 넣지 않는 경우
		ret = max(ret, solve(next, remain));
		// 현재 값을 넣을 경우
		ret = max(ret, solve(next, remain - bags[cur].second) + bags[cur].first);
	}
	return ret;
}

int output() {
	memset(mem, -1, sizeof(mem));
	int ret = -1;
	for (int i = 0; i < n; i++)
		ret = max(ret, solve(i, k));
	return ret;
}

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int v, w;
		cin >> w >> v;
		bags.push_back(make_pair(v, w));
	}
}

int main() {
	input();
	cout << output() << endl;

}