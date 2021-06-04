#include <iostream>
using namespace std;

const int MAX_N = 64;
char board[MAX_N][MAX_N];


void quadTree(int x, int y, int n) {
	// 나눌 수 없을 때
	if (n == 0) {
		printf("%c", board[x][y]);
		return;
	}
	char start = board[x][y];
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
		printf("%c", board[x][y]);
		return;
	}
	// 나눌 수 있을 때
	printf("(");
	quadTree(x, y, n / 2);
	quadTree(x, y + n / 2, n / 2);
	quadTree(x + n / 2, y, n / 2);
	quadTree(x + n / 2, y + n / 2, n / 2);
	printf(")");

}


void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	quadTree(0, 0, n);
}

int main() {
	solve();
}