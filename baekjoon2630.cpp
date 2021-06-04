#include <iostream>
using namespace std;

const int MAX_N = 128;
int board[MAX_N][MAX_N];


int white = 0, blue = 0;
void splitArr(int x,int y,int n) {
	// 나눌 수 없는 경우
	if (n == 0) {
		board[x][y]==0 ? white++ : blue++;
		return;
	}
	int start = board[x][y];
	bool isSplit = false;
	for (int i = x; i < x+n; i++) {
		for (int j = y; j < y+n; j++)
			if (start != board[i][j]) {
				isSplit = true;
				break;
			}
		if (isSplit) break;
	}
	if (!isSplit) {
		start==0 ? white++ : blue++;
		return;
	}
	// 나눌 수 있는 경우
	splitArr(x, y, n / 2);
	splitArr(x + n / 2, y, n / 2);
	splitArr(x, y + n / 2, n / 2);
	splitArr(x + n / 2, y + n / 2, n / 2);
	return;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	splitArr(0, 0, n);
	printf("%d\n%d\n", white, blue);
}





int main() {
	solve();
}