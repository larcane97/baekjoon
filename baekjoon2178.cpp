#include <iostream>
#include <queue>
using namespace std;

int n, m;
string board[100];
bool visit[100][100];
int dir[4][2] = {
	{0,1},
	{1,0},
	{-1,0},
	{0,-1}
};

bool inRange(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < m);
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	queue<pair<pair<int, int>,int>>q;
	q.push(make_pair(make_pair(0, 0), 1));
	while (!q.empty()) {
		int here_x = q.front().first.first;
		int here_y = q.front().first.second;
		int dis = q.front().second;
		if (here_x == n - 1 && here_y == m - 1) {
			cout << dis << "\n";
			break;
		}
		
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = here_x + dir[i][0];
			int dy = here_y + dir[i][1];
			if (inRange(dx, dy) && board[dx][dy] == '1' && !visit[dx][dy]) {
				visit[dx][dy] = true;
				q.push(make_pair(make_pair(dx, dy), dis + 1));
			}
		}
	}
}

int main() {
	solve();
}