#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int n, l;
int board[100][100];

void solve() {
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &board[i][j]);
	vector<bool>row_check(n, false);
	vector<bool>col_check(n, false);
	int ret = 0;
	//1
	for (int i = 0; i < n; i++) {
		bool ok = true;
		int canClimb = 0;
		for (int j = 1; j < n; j++) {
			canClimb++;
			if (canClimb >= 0) canClimb = 0;
			if (board[i][j-1] == board[i][j]) continue;
			else if (abs(board[i][j-1]-board[i][j])==1) {
				if (canClimb != 0) {
					ok = false;
					break;
				}
				int c = 1;
				int k = j + 1;
				while (k< n && (board[i][j]==board[i][k])&&c<l) {
					c++;
					k++;
				}
				if (c == l) {
					canClimb -= l+1;
					j = k;
				}
				else {
					ok = false;
					break;
				}
			}
			else {
				ok = false;
				break;
			}
		}
		if (ok) col_check[i] = true;
	}

	//2
	for (int i = 0; i < n; i++) {
		int canClimb = 0;
		bool ok = true;
		for (int j = n-2; j >= 0; j--) {
			canClimb++;
			if (canClimb >= 0) canClimb = 0;
			if (board[i][j+1] == board[i][j]) continue;
			else if (abs(board[i][j+1] -board[i][j])==1) {
				if (canClimb != 0) {
					ok = false;
					break;
				}
				int c = 1;
				int k = j - 1;
				while (k >= 0 && (board[i][j]==board[i][k])&&c<l) {
					c++;
					k--;
				}
				if (c == l) {
					j = k;
					canClimb -= l+1;
				}
				else {
					ok = false;
					break;
				}
			}
			else {
				ok = false;
				break;
			}
		}
		if (ok) col_check[i] = true;
	}

	//3
	for (int j = 0; j < n; j++) {
		int canClimb = 0;
		bool ok = true;
		for (int i = 1; i < n; i++) {
			canClimb++;
			if (canClimb >= 0) canClimb = 0;
			if (board[i-1][j] == board[i][j]) continue;
			else if (abs(board[i-1][j]-board[i][j])==1) {
				if (canClimb != 0) {
					ok = false;
					break;
				}
				int c = 1;
				int k = i + 1;
				while (k < n && (board[i][j]==board[k][j])&& c<l) {
					c++;
					k++;
				}
				if (c == l) {
					canClimb -= l+1;
					i = k;
				}
				else {
					ok = false;
					break;
				}
			}
			else {
				ok = false;
				break;
			}
		}
		if (ok) row_check[j] = true;
	}

	//4
	for (int j = n-1; j >= 0; j--) {
		int canClimb = 0;
		bool ok = true;
		for (int i = n-2; i >= 0; i--) {
			canClimb++;
			if (canClimb > 0) canClimb = 0;
			if (board[i+1][j] == board[i][j]) continue;
			else if (abs(board[i+1][j]-board[i][j])==1) {
				if (canClimb != 0) {
					ok = false;
					break;
				}
				int c = 1;
				int k = i - 1;
				while (k >=0 && (board[i][j]==board[k][j])&&c<l) {
					c++;
					k--;
				}
				if (c >= l) {
					canClimb -= l+1;
					i = k;
				}
				else {
					ok = false;
					break;
				}
			}
			else {
				ok = false;
				break;
			}
		}
		if (ok) row_check[j] = true;
	}
	
	for (int i = 0; i < n; i++)
		ret += (int)row_check[i] + (int)col_check[i];
	printf("%d\n",ret);
}

int main() {
	solve();
}