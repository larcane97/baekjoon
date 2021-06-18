#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int board[20][20];
int n, m;
vector<int>order;
int dir[5][2] = {
	{0,0},
	{0,1},
	{0,-1},
	{-1,0},
	{1,0}
};
bool inRange(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

vector<int>v1(3,0), v2(4,0);
void move(int d) {
	switch (d) {
	case 1:
		rotate(v1.begin(), v1.begin() +1, v1.end());
		v2[1] = v1[1];
		swap(v2[3], v1[2]);
		break;
	case 2:
		rotate(v1.begin(), v1.end() - 1, v1.end());
		v2[1] = v1[1];
		swap(v2[3], v1[0]);
		break;
	case 3:
		rotate(v2.begin(), v2.begin() + 1, v2.end());
		v1[1] = v2[1];
		break;
	case 4:
		rotate(v2.begin(), v2.end() - 1, v2.end());
		v1[1] = v2[1];
		break;
	}
	return;
}

void solve() {
	int x, y, k;
	scanf("%d %d %d %d %d", &n, &m,&x,&y,&k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &board[i][j]);
	order.resize(k);
	for (int i = 0; i < k; i++)
		scanf("%d", &order[i]);

	
	for (int i = 0; i < k; i++) {
		int d = order[i];
		int dx = x + dir[d][0];
		int dy = y + dir[d][1];
		if (inRange(dx, dy)) {
			move(d);
			if (board[dx][dy] == 0)
				board[dx][dy] = v1[1];
			else {
				v1[1] = v2[1] = board[dx][dy];
				board[dx][dy] = 0;
			}
			printf("%d\n", v2[3]);
			x = dx;
			y = dy;
		}
	}
	return;
}

int main() {
	solve();
}