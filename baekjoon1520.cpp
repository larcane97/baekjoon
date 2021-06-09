#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//mem[x][y] : 현재 위치에서 마지막까지 갈 수 있는 경로의 수
int mem[500][500];
int board[500][500];
int n, m;
int dir[4][2] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
};
bool inRange(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

int dynamic(int x, int y) {
	int& ret = mem[x][y];
	if (ret != -1)return ret;
	if (x == n - 1 && y == m - 1) return ret = 1;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		if (inRange(dx, dy) && board[x][y] > board[dx][dy])
			ret += dynamic(dx, dy);
	}
	return ret;
}

void solve() {
	memset(mem, -1, sizeof(mem));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &board[i][j]);
	int ret = dynamic(0, 0);
	printf("%d\n", ret);
}

int main() {
	solve();
}