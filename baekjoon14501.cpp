#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int,int>>schedule;

int reward(int day) {
	if (day > n) return 0;
	// 해당 일을 일하지 않은 경우
	int ret = reward(day + 1);
	// 해당 일을 일한 경우
	if (day + schedule[day].first <= n+1)
		ret = max(ret, reward(day + schedule[day].first) + schedule[day].second);
	return ret;
}

void solve() {
	cin >> n;
	schedule.resize(n+1);
	for (int i = 1; i <= n; i++)
		cin >> schedule[i].first >> schedule[i].second;
	cout << reward(1) << "\n";

}

int main() {
	solve();
}