#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ret = 987654321;
int n, m;
int dir[4][2] = {
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};

bool inRange(int x, int y,int arr[8][8]) {
	return x >= 0 && x < n&& y >= 0 && y < m && (arr[x][y] != 6);
}

void f(int x,int y,int arr[8][8],int c) {
	if (c==0) {
		int r = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (arr[i][j]==0)r++;
		ret = min(ret, r);
		return;
	}

	if (y >= m) {
		y = 0;
		x++;
	}
	int tmp[8][8];
	bool ok = false;
	for (int i = x; i < n; i++) {
		for (int j = y; j < m; j++) {
			if (arr[i][j] >= 1 && arr[i][j] <= 5) {
				// 1번
				if(arr[i][j]==1)
					for (int k = 0; k < 4; k++) {
						copy(&arr[0][0], &arr[0][0] + 64, &tmp[0][0]);
						int dx = i + dir[k][0];
						int dy = j + dir[k][1];
						while (inRange(dx, dy, arr)) {
							tmp[dx][dy] = (tmp[dx][dy] == 0 ? -1 : tmp[dx][dy]);
							dx += dir[k][0];
							dy += dir[k][1];
						}
						f(i, j + 1, tmp,c-1);
					}

				// 2번
				else if (arr[i][j] == 2)
					for (int k = 0; k < 4; k+=2) {
					copy(&arr[0][0], &arr[0][0] + 64, &tmp[0][0]);
					int ldx = i + dir[k][0];
					int ldy = j + dir[k][1];
					int rdx = i + dir[k+1][0];
					int rdy = j + dir[k+1][1];
					while (inRange(ldx, ldy, arr)) {
						tmp[ldx][ldy] = (tmp[ldx][ldy] == 0 ? -1 : tmp[ldx][ldy]);
						ldx += dir[k][0];
						ldy += dir[k][1];
					}
					while (inRange(rdx, rdy, arr)) {
						tmp[rdx][rdy] = (tmp[rdx][rdy] == 0 ? -1 : tmp[rdx][rdy]);
						rdx += dir[k+1][0];
						rdy += dir[k+1][1];
					}
					f(i, j + 1, tmp,c-1);
				
				}

				// 3번
				else if (arr[i][j] == 3)
					for (int k = 0; k <= 1; k++) {
						for (int w = 2; w <= 3; w++) {
							copy(&arr[0][0], &arr[0][0] + 64, &tmp[0][0]);
							int dx1 = i + dir[k][0];
							int dy1 = j + dir[k][1];
							int dx2 = i + dir[w][0];
							int dy2 = j + dir[w][1];

							while (inRange(dx1, dy1, arr)) {
								tmp[dx1][dy1] = (tmp[dx1][dy1] == 0 ? -1 : tmp[dx1][dy1]);
								dx1 += dir[k][0];
								dy1 += dir[k][1];
							}
							while (inRange(dx2, dy2, arr)) {
								tmp[dx2][dy2] = (tmp[dx2][dy2] == 0 ? -1 : tmp[dx2][dy2]);
								dx2 += dir[w][0];
								dy2 += dir[w][1];
							}
							f(i, j + 1, tmp,c-1);
						}
					}

				// 4번
				else if (arr[i][j] == 4)
					for (int k = 0; k < 4; k++) {
						for (int w = k + 1; w < 4; w++) {
							for (int z = w + 1; z < 4; z++) {
								copy(&arr[0][0], &arr[0][0] + 64, &tmp[0][0]);
								int dx1 = i + dir[k][0];
								int dy1 = j + dir[k][1];
								int dx2 = i + dir[w][0];
								int dy2 = j + dir[w][1];
								int dx3 = i + dir[z][0];
								int dy3 = j + dir[z][1];

								while (inRange(dx1, dy1, arr)) {
									tmp[dx1][dy1] = (tmp[dx1][dy1] == 0 ? -1 : tmp[dx1][dy1]);
									dx1 += dir[k][0];
									dy1 += dir[k][1];
								}
								while (inRange(dx2, dy2, arr)) {
									tmp[dx2][dy2] = tmp[dx2][dy2] == 0 ? -1 : tmp[dx2][dy2];
									dx2 += dir[w][0];
									dy2 += dir[w][1];
								}
								while (inRange(dx3, dy3, arr)) {
									tmp[dx3][dy3] = tmp[dx3][dy3] == 0 ? -1 : tmp[dx3][dy3];
									dx3 += dir[z][0];
									dy3 += dir[z][1];
								}
								f(i, j + 1, tmp,c-1);
							}
						}
					}

				// 5번
				else {
					copy(&arr[0][0], &arr[0][0] + 64, &tmp[0][0]);
					for (int k = 0; k < 4; k++) {
						int dx = i + dir[k][0];
						int dy = j + dir[k][1];
						while (inRange(dx, dy, arr)) {
							tmp[dx][dy] = tmp[dx][dy] == 0 ? -1 : tmp[dx][dy];
							dx += dir[k][0];
							dy += dir[k][1];
						}
					}
					f(i, j + 1, tmp,c-1);
				}
				
				ok = true;
				break;
			}
		}
		if (ok) break;
		y = 0;
	}

	return;
}

void solve() {
	int board[8][8];
	int c = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] >= 1 && board[i][j] <= 5)
				c++;
		}
	f(0, 0, board,c);
	cout << ret << "\n";

}

int main() {
	solve();
}