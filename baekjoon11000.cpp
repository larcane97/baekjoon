#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>p1, pair<int, int>p2) {
	return p1.second < p2.second;
}

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>>schedule(n);
	for (int i = 0; i < n; i++)
		cin >> schedule[i].first >> schedule[i].second;
	sort(schedule.begin(), schedule.end(),cmp);
	int ret = 0;
	while (schedule.size() > 0) {
		ret++;
		int finished = schedule[0].second;
		schedule.erase(schedule.begin());
		for (int i = 0; i < schedule.size(); i++) {
			if (finished <= schedule[i].first) {
				finished = schedule[i].first;
				schedule.erase(schedule.begin() + i);
				i--;
			}
		}
	}
	cout << ret << "\n";
}

int main() {
	solve();
}