#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int move(int x,int type) {
	switch (type) {
	case 0: 
		return x + 1;
	case 1:
		return x - 1;
	case 2:
		return x * 2;
	}
	return -1;
}

bool inRange(int x) {
	return x >= 0 && x <= 100000;
}


void solve() {
	int n, k;
	cin >> n >> k;
	queue<pair<int, int>>q;
	vector<bool>visit(100001, false);

	q.push(make_pair(n, 0));
	visit[n] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int dis = q.front().second;
		q.pop();

		// 종료 조건
		if (cur == k) {
			cout << dis << "\n";
			return;
		}

	
		for (int i = 0; i < 3; i++) {
			int next = move(cur, i);
			if (inRange(next) && !visit[next]) {
				visit[next]=true;
				q.push(make_pair(next, dis + 1));
			}
		
		}
	}
	
	return;
}

int main() {
	solve();
}