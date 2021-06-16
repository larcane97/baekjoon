#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int board[500][500];
int n, m;
int t1[2][4][2] = {
	{
	{0,0},
	{0,1},
	{0,2},
	{0,3}
	},
	{{0,0},
	{1,0},
	{2,0},
	{3,0} }
};
int t2[1][4][2] = {
	{
	{0,0},
	{0,1},
	{1,0},
	{1,1} }
};
int t3[8][4][2] = {
	{
	{0,0},
	{0,1},
	{0,2},
	{1,0}
	},
	{{0,0},
	{0,1},
	{0,2},
	{1,2} },

	{{0,0},
	{1,0},
	{2,0},
	{0,1} },

	{{0,0},
	{0,1},
	{1,1},
	{2,1} },

	{{0,0},
	{1,0},
	{1,1},
	{1,2} },

	{{0,0},
	{1,0},
	{1,-1},
	{1,-2} },

	{{0,0},
	{1,0},
	{2,0},
	{2,1} },
	{
	{0,0},
	{1,0},
	{2,0},
	{2,-1}
	}
};
int t4[4][4][2] = {
	{
	{0,0},
	{1,0},
	{1,1},
	{2,1}
	},
	{{0,0},
	{0,1},
	{1,1},
	{1,2} },
	{
	{0,0},
	{1,0},
	{0,1},
	{1,-1}
	},
	{
	{0,0},
	{1,0},
	{1,-1},
	{2,-1}
	}
};
int t5[4][4][2] = {
	{
	{0,0},
	{0,1},
	{1,1},
	{0,2}
	},
	{{0,0},
	{1,0},
	{2,0},
	{1,1} },
	{
	{0,0},
	{1,0},
	{1,1},
	{1,-1}
	},
	{
	{0,0},
	{1,0},
	{1,-1},
	{2,0}
	}
};

bool inRange(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

int get_value(int x, int y) {
	int ret = -1;
	for (int i = 0; i < 2; i++) {
		int tmp = 0;
		for (int j = 0; j < 4; j++) {
			int dx = x+t1[i][j][0];
			int dy = y+t1[i][j][1];
			if (inRange(dx, dy))
				tmp += board[dx][dy];
			else {
				tmp = -1;
				break;
			}
		}
		ret = max(ret, tmp);
	}

	for (int i = 0; i < 1; i++) {
		int tmp = 0;
		for (int j = 0; j < 4; j++) {
			int dx = x+t2[i][j][0];
			int dy = y+t2[i][j][1];
			if (inRange(dx, dy))
				tmp += board[dx][dy];
			else {
				tmp = -1;
				break;
			}
		}
		ret = max(ret, tmp);
	}

	for (int i = 0; i < 8; i++) {
		int tmp = 0;
		for (int j = 0; j < 4; j++) {
			int dx = x+t3[i][j][0];
			int dy = y+t3[i][j][1];
			if (inRange(dx, dy))
				tmp += board[dx][dy];
			else {
				tmp = -1;
				break;
			}
		}
		ret = max(ret, tmp);
	}

	for (int i = 0; i < 4; i++) {
		int tmp = 0;
		for (int j = 0; j < 4; j++) {
			int dx = x +t4[i][j][0];
			int dy = y+ t4[i][j][1];
			if (inRange(dx, dy))
				tmp += board[dx][dy];
			else {
				tmp = -1;
				break;
			}
		}
		ret = max(ret, tmp);
	}

	for (int i = 0; i < 4; i++) {
		int tmp = 0;
		for (int j = 0; j < 4; j++) {
			int dx = x+ t5[i][j][0];
			int dy = y+ t5[i][j][1];
			if (inRange(dx, dy))
				tmp += board[dx][dy];
			else {
				tmp = -1;
				break;
			}
		}
		ret = max(ret, tmp);
	}

	return ret;
}

void solve() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &board[i][j]);
	int ret = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ret = max(ret, get_value(i, j));
	printf("%d\n", ret);
}

int main() {
		solve();
}
