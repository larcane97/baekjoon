#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, k;
int board[50][50];
bool visit[50][50];
int cur[4][2] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
};

bool inRange(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < m);
}
void count_region(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int dx = x + cur[i][0];
		int dy = y + cur[i][1];
		if (inRange(dx, dy) && board[dx][dy] == 1 && !visit[dx][dy])
			count_region(dx, dy);
	}
}

void solve() {
	int t;
	cin >> t;
	for (int iter = 0; iter < t; iter++) {
		memset(board, 0, sizeof(board));
		memset(visit, 0, sizeof(visit));
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			board[a][b] = 1;
		}

		int ret = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1 && !visit[i][j]) {
					count_region(i, j);
					ret++;
				}
			}
		}
		cout << ret << "\n";
	}
}
int main() {
	solve();
}