#include <iostream>
#include <math.h>
using namespace std;

const int MAX_N = 2187;
int board[MAX_N][MAX_N];
int minus_one = 0, one = 0, zero = 0;

void countNum(int num) {
	switch (num) {
	case -1:
		minus_one++;
		return;
	case 0:
		zero++;
		return;
	case 1:
		one++;
		return;
	}
}

void nineTree(int x, int y, int n) {
	if (n == 0) {
		countNum(board[x][y]);
		return;
	}
	int start = board[x][y];
	bool isSplit = false;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (start != board[i][j]) {
				isSplit = true;
				break;
			}
		}
		if (isSplit) break;
	}
	if (!isSplit) {
		countNum(start);
		return;
	}

	nineTree(x, y, n / 3);
	nineTree(x, y+n/3, n / 3);
	nineTree(x, y+n*2/3, n / 3);
	nineTree(x + n / 3, y, n / 3);
	nineTree(x + n / 3, y+n/3, n / 3);
	nineTree(x + n / 3, y+n*2/3, n / 3);
	nineTree(x + n * 2 / 3, y, n / 3);
	nineTree(x + n * 2 / 3, y+n/3, n / 3);
	nineTree(x + n * 2 / 3, y+n*2/3, n / 3);

}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	nineTree(0, 0, n);
	printf("%d\n%d\n%d\n", minus_one, zero, one);
}
int main() {
	solve();
}