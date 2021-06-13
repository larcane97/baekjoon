#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

bool visit[300][300];
int l;
int dir[8][2] = {
	{-2,1},
	{-1,2},
	{1,2},
	{2,1},
	{2,-1},
	{1,-2},
	{-1,-2},
	{-2,-1}
};

bool inRange(int x, int y) {
	return x >= 0 && x < l&& y >= 0 && y < l;
}

void solve() {
	int T;
	cin >> T;
	for (int iter = 0; iter < T; iter++) {
		memset(visit, 0, sizeof(visit));
		cin >> l;
		int sx, sy, dx, dy;
		cin >> sx >> sy;
		cin >> dx >> dy;

		visit[sx][sy] = true;
		queue<pair<pair<int, int>,int>>q;
		q.push(make_pair(make_pair(sx, sy), 0));
		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int dis = q.front().second;
			q.pop();
			if (x == dx && y == dy) {
				cout << dis << "\n";
				break;
			}
			for (int i = 0; i < 8; i++) {
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (inRange(nx, ny) && !visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push(make_pair(make_pair(nx, ny), dis + 1));
				}
			}
		}
	}
	return;
}

int main() {
	solve();
}