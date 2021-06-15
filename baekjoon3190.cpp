#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

map<int, char>dirs;
int board[101][101];
int n, k, l;
int dir[4][2] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};

bool check(int x, int y) {
	return (x > 0 && x <= n&& y > 0 && y <= n)&& board[x][y] !=1;
}
// board[i][j] = 0 : blank
// board[i][j] = 1 : snake
// board[i][j] = 2 : apple
void solve() {
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		board[a][b] = 2;
	}
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		int a;
		char b;
		scanf("%d %c", &a, &b);
		dirs[a] = b;
	}
	queue<pair<int, int>>q;
	int time = 0;
	int x = 1, y = 1;
	int idx = 0;
	board[x][y] = 1;
	q.push({ x,y });
	while (true) {
		time++;
		x += dir[idx][0];
		y +=dir[idx][1];
		if (check(x, y)) {
			q.push({ x,y });
			if (!(board[x][y] == 2)) {
				board[q.front().first][q.front().second] = 0;
				q.pop();
			}
			board[x][y] = 1;
		}
		else break;
		// 방향 조정
		if (dirs.count(time) > 0) {
			char d = dirs[time];
			if (d == 'D') {
				idx++;
				if (idx == 4) idx = 0;
			}
			else {
				idx--;
				if (idx == -1) idx = 3;
			}
		}
	}
	printf("%d\n", time);
}

int main() {
	solve();
}
