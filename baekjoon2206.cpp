#define _CRT_SECURE_NO_WARNINGS
#include <queue>
#include <iostream>
#include <vector>
using namespace std;


const int INF = 987654321;
char board[1000][1000];
bool visit[1000][1000][2];
int n, m;
int dir[4][2] = {
	{0,1},
	{1,0},
	{-1,0},
	{0,-1}
};

bool inRange(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}


void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for(int j=0;j<m;j++)
			cin >> board[i][j];
	
	visit[0][0][true] = true;
	queue<pair<pair<int, int>,pair<int,bool>>>q;
	q.push(make_pair(make_pair(0, 0),make_pair(1,true)));

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dis = q.front().second.first;
		bool canJump = q.front().second.second;
		q.pop();

		if (x == n - 1 && y == m - 1) {
			cout << dis << "\n";
			return;
		}

		for (int i = 0; i < 4; i++) {
			int dx = x + dir[i][0];
			int dy = y + dir[i][1];
			if (inRange(dx, dy) && !visit[dx][dy][canJump]) {
				if (board[dx][dy] == '0') {
					visit[dx][dy][canJump] = true;
					q.push(make_pair(make_pair(dx, dy), make_pair(dis + 1, canJump)));
				}
				else if (canJump) {
					visit[dx][dy][false] = true;
					q.push(make_pair(make_pair(dx, dy), make_pair(dis + 1, false)));
				}
			}
		}
	}
	cout << -1 << "\n";
	return;
}

int main() {
	solve();
}