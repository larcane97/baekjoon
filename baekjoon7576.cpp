#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

const int MAX_SIZE = 1000;
char board[MAX_SIZE][MAX_SIZE];
int n, m;
int dir[4][2] = {
	{1,0},
	{-1,0},
	{0,-1},
	{0,1}
};

bool inRange(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}
void solve() {
	scanf("%d %d", &m, &n);

	queue<pair<pair<int, int>,int>>q;
	int zero = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 1)
				q.push(make_pair(make_pair(i, j), 0));
			else if (board[i][j] == 0)zero++;
		}

	int days = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int day = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + dir[i][0];
			int dy = y + dir[i][1];
			if (inRange(dx, dy) && board[dx][dy] == 0) {
				q.push(make_pair(make_pair(dx, dy), day + 1));
				board[dx][dy] = 1;
				zero--;
				days = max(days, day + 1);
			}
		}
	}
	printf("%d\n", (zero==0)?days:-1);
}

int main() {
	solve();
}