#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int board[50][50];
bool visit[50][50];
int n, m;
int dir[4][2] = {
	{0,-1},
	{-1,0},
	{0,1},
	{1,0}
};

bool inRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && (board[x][y] != 1);
}

void solve() {
	scanf("%d %d", &n, &m);
	int sx, sy, d;
	scanf("%d %d %d", &sx, &sy, &d);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &board[i][j]);

	queue<pair<int, int>>q;
	q.push({ sx,sy });
	visit[sx][sy] = true;
	int clean = 1;
	while (true) {
		int cx, cy;
		while (!q.empty()) {
			cx = q.front().first;
			cy = q.front().second;
			q.pop();
			int cur_dir = d;
			for (int i = 0; i < 4; i++) {
				// 현재 위치에서 왼쪽방향의 앞 칸
				int nx = cx + dir[cur_dir][0];
				int ny = cy + dir[cur_dir][1];
				if (inRange(nx, ny) && !visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
					clean++;
					d = cur_dir-1;
					if (d < 0) d = 3;
					break;
				}
				cur_dir--;
				if (cur_dir < 0) cur_dir = 3;
			}
		}

		// 네 방향 모두 청소가 되어 있거나 벽인 경우
		int back_dir = d - 1;
		if (back_dir < 0) back_dir = 3;
		int nx = cx + dir[back_dir][0];
		int ny = cy + dir[back_dir][1];
		if (inRange(nx, ny))
			q.push({ nx,ny });
		else
			break;
	}
	printf("%d\n", clean);
}

int main() {
	solve();
}

