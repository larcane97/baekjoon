#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char board[20][20];
bool visited[20][20];
bool used[26];
int r, c;
int dir[4][2] = {
	{0,1},
	{1,0},
	{-1,0},
	{0,-1}
};

bool inRange(int x, int y) {
	return x >= 0 && x < r&& y >= 0 && y < c;
}
int ret = 0;
void DFS(int x, int y, int dis) {
	ret = max(ret, dis);
	for (int i = 0; i < 4; i++) {
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		if (inRange(dx, dy) && !visited[dx][dy] && !used[board[dx][dy] - 'A']) {
			visited[dx][dy] = true;
			used[board[dx][dy] - 'A'] = true;
			DFS(dx, dy, dis + 1);
			visited[dx][dy] = false;
			used[board[dx][dy] - 'A'] = false;
		}
	}
}

void solve() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> board[i][j];
	visited[0][0] = true;
	used[board[0][0] - 'A'] = true;
	DFS(0, 0, 1);
	cout << ret << "\n";
}

int main() {
	solve();
}