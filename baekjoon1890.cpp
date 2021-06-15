#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int board[100][100];
ll cache[100][100];
int n;
bool inRange(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}

ll dp(int x, int y) {
	if (x == n - 1 && y == n - 1) return 1;
	ll& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = 0;
	if (inRange(x + board[x][y], y))
		ret += dp(x + board[x][y], y);
	if(inRange(x,y+board[x][y]))
		ret += dp(x, y + board[x][y]);
	return ret;
}

void solve() {
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	cout << dp(0, 0) << "\n";
}

int main() {
	solve();
}