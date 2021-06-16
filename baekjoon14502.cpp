#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int board[8][8];
int n, m;
vector<pair<int, int>>virus;
bool inRange(int x, int y,int b[8][8]=board) {
	return x >= 0 && x < n&& y >= 0 && y < m && (b[x][y]==0);
}

int dir[4][2] = {
	{0,1},
	{1,0},
	{-1,0},
	{0,-1}
};;
int ret = -1;
void block_board(int x, int y,int num) {
	if (num == 3) {
		int tmp[8][8];
		copy(&board[0][0], &board[0][0] + 64, &tmp[0][0]);
		queue<pair<int, int>>q;
		for (int i = 0; i < virus.size(); i++)
			q.push(virus[i]);
		while (!q.empty()) {
			int nx = q.front().first;
			int ny = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int dx = nx + dir[i][0];
				int dy = ny + dir[i][1];
				if (inRange(dx, dy,tmp)) {
					tmp[dx][dy] = 2;
					q.push({ dx,dy });
				}
			}
		}

		int safe = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (tmp[i][j] == 0) safe++;
		ret = max(safe, ret);
	}
	else {
		if (y >= m) {
			x++;
			y = 0;
		}
		for (int i = x; i < n; i++) {
			for (int j = y; j < m; j++)
				if (inRange(i, j)) {
					board[i][j] = 1;
					block_board(i, j + 1, num + 1);
					board[i][j] = 0;
				}
			y = 0;
		}
	}
}

void solve() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 2)
				virus.push_back({ i,j });
		}

	block_board(0, 0, 0);
	printf("%d\n", ret);
}

int main() {
	solve();
}
