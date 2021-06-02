#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void solve() {
	int c;
	cin >> c;
	// totla : O(c * n^2)
	for (int iter = 0; iter < c; iter++) {
		queue<pair<int,int>>q;
		vector<int>costs;
		int n, m;
		cin >> n >> m;
		// for : O(n)
		for (int i = 0; i < n; i++) {
			int cost;
			cin >> cost;
			costs.push_back(cost);
			q.push(make_pair(i, cost));
		}
		// O(nlog(n))
		sort(costs.begin(), costs.end());

		int ret = 0;
		//while : O(n)
		while (!q.empty()) {
			ret++;
			int maxCost = costs[costs.size() - 1];
			// while : O(n)
			while (q.front().second < maxCost) {
				q.push(q.front());
				q.pop();
			}
			if (m == q.front().first) break;

			q.pop();
			costs.pop_back();
		}

		cout << ret << "\n";
	}
}

int main() {
	solve();
}