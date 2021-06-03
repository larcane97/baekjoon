#include <iostream>
#include <vector>
using namespace std;



const int n = 19;
int board[n+2][n+2];

void solve() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	bool win = false;
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (board[i][j] == 0)
				continue;
			//°¡·Î Å½»ö
			int k;
			for (k = 1; k < 5; k++) {
				int x = k + i;
				if (x>=n || board[x][j] != board[i][j])
					break;
			}
			if (k == 5 && 
				(i - 1 < 0 || board[i - 1][j] != board[i][j]) &&
				(k + i >= n || board[k+i][j] != board[i][j])
				) {
				win = true;
				break;
			}

			//¼¼·Î Å½»ö
			for (k = 1; k < 5; k++) {
				int y = k + j;
				if ( y >= n|| board[i][y] != board[i][j])
					break;
			}
			if (k == 5 &&
				(j - 1 < 0 || board[i][j-1] != board[i][j]) && 
				(k + j >= n || board[i][k+j] != board[i][j])) {
				win = true;
				break;
			}

			//´ë°¢¼± Å½»ö
			for (k = 1; k < 5; k++) {
				int x = k + i;
				int y = k + j;
				if ( y >= n || x>=n || board[x][y] != board[i][j] )
					break;
			}
			if (k == 5 
				&& 
				( k + i >= n || k+j >= n || board[i+k][j+k] != board[i][j])
				&&
				( i-1 <0 || j-1<0 || board[i-1][j-1] != board[i][j])
				) {
				win = true;
				break;
			}

			for (k = 1; k < 5; k++) {
				int x = k + i;
				int y = j - k;
				if (y <0 || x >= n || board[x][y] != board[i][j])
					break;
			}
			if (k == 5
				&&
				(k + i >= n || j-k < 0 || board[i + k][j-k] != board[i][j])
				&&
				(i - 1 < 0 || j + 1 >=n || board[i - 1][j + 1] != board[i][j])
				) {
				i = i + (k - 1);
				j=j - (k - 1);
				win = true;
				break;
			}

		}
		if (win)break;
	}


	win? printf("%d\n%d %d\n", board[i][j], i + 1, j + 1):
		printf("%d\n", 0);
}


int main() {
	solve();
}
