#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int board[20][20];
int n;
int dir[4][2] = {
	{0,1},
	{1,0},
	{-1,0},
	{0,-1}
};

void move_board(int index) {
	if (index == 0) {
		// 오른쪽으로 이동 : x:0 ~ -> y:n-1 ~
		for (int j = n - 1; j >= 0; j--) {
			for (int i = 0; i < n; i++) {
				// 해당 행 모두 이동
				int y = j;
				// 옮길 아이템을 찾는다.
				while (board[i][y] == 0 && y > 0)
					y--;
				if (y != j) {
					board[i][j] = board[i][y];
					board[i][y] = 0;
				}
			}
		}
		// 아이템 합치기
		for (int j = n - 1; j > 0; j--) {
			for (int i = 0; i < n; i++) {
				if (board[i][j] == board[i][j - 1]) {
					board[i][j] *= 2;
					int k = j - 1;
					while (k > 0 && board[i][k] != 0) {
						board[i][k] = board[i][k - 1];
						k--;
					}
					board[i][k] = 0;
				}
			}
		}

	}
	else if (index == 1) {
		// 아래로 이동 : y:0 ~ & x:n-1
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				int x = i;
				while (board[x][j] == 0 && x > 0)
					x--;
				if (x != i) {
					board[i][j] = board[x][j];
					board[x][j] = 0;
				}
			}
		
		}
		// 아이템 합치기
		for (int i = n - 1; i > 0; i--) {
			for (int j = 0; j < n; j++) {

				if (board[i][j] == board[i - 1][j]) {
					board[i][j] *= 2;
					int k = i - 1;
					while (k > 0 && board[k][j] != 0) {
						board[k][j] = board[k - 1][j];
						k--;
					}
					board[k][j] = 0;
				}
			}
		
		}

	}
	else if (index == 2) {
		// 위로 이동 : y:0~ & x:0~
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				int x = i;
				while (board[x][j] == 0 && x < n - 1)
					x++;
				if (x != i) {
					board[i][j] = board[x][j];
					board[x][j] = 0;
				}
			}
		}
		// 아이템 합치기
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n; j++) {

				if (board[i][j] == board[i + 1][j]) {
					board[i][j] *= 2;
					int k = i + 1;
					while (k < n - 1 && board[k][j] != 0) {
						board[k][j] = board[k + 1][j];
						k++;
					}
					board[k][j] = 0;
				}
			}
		}

	}
	else if (index == 3) {
		// 왼쪽으로 이동 : y:0~ & x:0~
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {
				int y = j;
				while (board[i][y] == 0 && y < n-1)
					y++;
				if (y != j) {
					board[i][j] = board[i][y];
					board[i][y] = 0;
				}
			}
		}
		// 아이템 합치기
		for (int j = 0; j < n-1; j++) {
			for (int i = 0; i < n; i++) {
				if (board[i][j] == board[i][j+1]) {
					board[i][j] *= 2;
					int k = j + 1;
					while (k < n-1 && board[i][k] != 0) {
						board[i][k] = board[i][k+1];
						k++;
					}
					board[i][k] = 0;
				}
			}
		}

	}
}

int dfs(int v) {
	if (v == 5) {
		int ret = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ret = max(ret, board[i][j]);
		return ret;
	}

	int tmp[20][20];
	copy(&board[0][0], &board[0][0]+ 400, &tmp[0][0]);
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		move_board(i);
		ret = max(ret, dfs(v + 1));
		copy(&tmp[0][0], &tmp[0][0] + 400, &board[0][0]);
	}
	return ret;
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &board[i][j]);
	int ret = dfs(0);
	printf("%d\n", ret);
}

int main() {
	solve();
	
}