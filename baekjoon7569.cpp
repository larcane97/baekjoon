#include <iostream>
#include <vector>
#include <queue>
using namespace std;

short board[100][100][100];
bool visit[100][100][100];
int dir[6][3] = {
	{0,1,0},
	{1,0,0},
	{-1,0,0},
	{0,-1,0},
	{0,0,1},
	{0,0,-1}
};

int n, m, h;

struct tomato {
	int x, y, z, dis;
	tomato(int _x, int _y, int _z, int _dis) :x(_x),y(_y),z(_z),dis(_dis){}
};

bool inRange(int x, int y, int z) {
	return x >= 0 && x < n&& y >= 0 && y < m && z >= 0 && z < h;
}

void solve() {
	cin >> m >> n >> h;
	queue <tomato>q;
	for (int k = 0; k < h; k++) 
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) {
					q.push(tomato(i, j, k, 0));
					visit[i][j][k] = true;
				}
			}
	
	int ret = -1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		int dis = q.front().dis;
		ret = max(dis, ret);
		q.pop();

		for (int i = 0; i < 6; i++) {
			int dx = x + dir[i][0];
			int dy = y + dir[i][1];
			int dz = z + dir[i][2];
			if (inRange(dx, dy, dz) && !visit[dx][dy][dz] && board[dx][dy][dz] == 0) {
				visit[dx][dy][dz] = true;
				q.push(tomato(dx, dy, dz, dis + 1));
			}
		}
	}
	bool ok = true;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				if (board[i][j][k] == 0 && !visit[i][j][k]) {
					ok = false;
					break;
				}
			if (!ok) break;
		}
		if (!ok) break;
	}
	cout << (ok ? ret : -1) << "\n";

}

int main() {
	solve();
}