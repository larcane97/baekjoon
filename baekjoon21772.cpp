#include <iostream>
#include <vector>
using namespace std;

int h, w, t;
string room[101];
int dir[4][2] = {
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};

bool inRange(int x, int y) {
	return (x >= 0 && x < h&& y >= 0 && y < w);
}

int search(int x, int y,int time,int get) {
	if (time == t)
		return get;

	int ret = 0;

	for (int i = 0; i < 4; i++) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (inRange(tx, ty) && room[tx][ty] != '#') {
			if (room[tx][ty] == 'S') {
				room[tx][ty] = '.';
				ret = max(ret, search(tx, ty, time + 1, get+1));
				room[tx][ty] = 'S';
			}
			else
				ret = max(ret, search(tx, ty, time + 1, get));
		}
	}
	return ret;
}

void solve() {
	cin >> h >> w >> t;
	int start_x = -1;
	int start_y = -1;
	for (int i = 0; i < h; i++) {
		cin >> room[i];
		if (start_y == -1) {
			start_y = room[i].find('G');
			start_x = i;
		}
	}
	int ret = search(start_x, start_y,0,0);
	cout << ret << "\n";

}

int main() {
	solve();
}