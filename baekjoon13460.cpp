#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char board[15][15];
const int INF = 987654321;
int dir[4][2] = {
	{1,0},
	{0,1},
	{-1,0},
	{0,-1}
};
int n, m;
struct state {
	int rx, ry;
	int bx, by;
	state(int _rx, int _ry, int _bx, int _by) :rx(_rx), ry(_ry), bx(_bx), by(_by) {}
};

bool inRange(int x, int y) {
	return (x >= 1 && x <= n - 2 && y >= 1 && y <= m - 2)
		&& (board[x][y]!='#');
}

void solve() {
	cin >> n >> m;
	int red_x, red_y;
	int blue_x, blue_y;
	int dest_x, dest_y;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				red_x = i;
				red_y = j;
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				blue_x = i;
				blue_y = j;
				board[i][j] = '.';
			}
			else if (board[i][j] == 'O') {
				dest_x = i;
				dest_y = j;
			}
		}

	int ret = INF;
	state init(red_x, red_y, blue_x, blue_y);
	queue<pair<state,int>>q;
	q.push(make_pair(init,0));
	int find = false;
	while (!q.empty()&& !find) {
		state cur = q.front().first;
		int dis = q.front().second;
		q.pop();
		if (dis >= 10) continue;

		for (int i = 0; i < 4; i++) {
			int rdx = cur.rx + dir[i][0];
			int rdy = cur.ry + dir[i][1];
 			int bdx = cur.bx + dir[i][0];
			int bdy = cur.by + dir[i][1];

			while (true) {
				if (!inRange(rdx, rdy) && !inRange(bdx, bdy)) {
					rdx -= dir[i][0];
					rdy -= dir[i][1];
					bdx -= dir[i][0];
					bdy -= dir[i][1];
					break;
				}
				if (!inRange(rdx, rdy)) {
					rdx -= dir[i][0];
					rdy -= dir[i][1];
					if (rdx == bdx && rdy == bdy) {
						bdx -= dir[i][0];
						bdy -= dir[i][1];
						break;
					}
				}
				if (!inRange(bdx, bdy)) {
					bdx -= dir[i][0];
					bdy -= dir[i][1];
					if (rdx == bdx && rdy == bdy) {
						rdx -= dir[i][0];
						rdy -= dir[i][1];
						break;
					}
				}
				if (bdx == dest_x && bdy == dest_y) {
					bdx = -1, bdy = -1;
					break;
				}
					
				if (rdx == dest_x && rdy == dest_y) {
					find = true;
					while (inRange(bdx, bdy)) {
						if (bdx == dest_x && bdy == dest_y) {
							find = false;
							break;
						}
						bdx += dir[i][0];
						bdy += dir[i][1];
					}
					if (find) ret = dis + 1;
					else bdx = -1, bdy = -1;
					break;
				}
				rdx += dir[i][0];
				rdy += dir[i][1];
				bdx += dir[i][0];
				bdy += dir[i][1];
			}
			if (find) break;
			if(inRange(rdx,rdy) && inRange(bdx,bdy) && !( rdx==cur.rx && rdy ==cur.ry && bdx ==cur.bx && bdy ==cur.by) )
				q.push(make_pair(state(rdx, rdy, bdx, bdy), dis + 1));
		}

	}
	cout << (ret == INF ? -1 : ret) << "\n";
	return;
}

int main() {
	solve();
}