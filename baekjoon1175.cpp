#include <queue>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
const char MAX_SIZE = 50;
char board[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE][5][2][2];
int dir[4][2] = {
	{1,0},
	{0,1},
	{-1,0},
	{0,-1}
};

bool inRange(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

void solve() {
	cin >> n >> m;
	int start_x,start_y;
	bool next = false;
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'S') {
				start_x = i;
				start_y = j;
			}
			else if (board[i][j] == 'C') {
				if (next)
					board[i][j] = 'D';
				else next = true;
			}
		}

	queue<pair<
		pair
		<pair<short, short>, pair<short,short>>,
		pair<bool,bool>
		>>q;
	q.push(
		make_pair(
			make_pair(make_pair(start_x, start_y),make_pair(-1,0)),make_pair(false,false))
	);

	visit[start_x][start_y][4][false][false] = true;

	while (!q.empty()) {
		short x = q.front().first.first.first;
		short y = q.front().first.first.second;
		short prev = q.front().first.second.first;
		short dis = q.front().first.second.second;
		bool first_item = q.front().second.first;
		bool second_item = q.front().second.second;
		q.pop();

		if (first_item && second_item) {
			cout << dis << "\n";
			return;
		}
		
		for (short i = 0; i < 4; i++) {
			if (prev != i) {
				short dx = x + dir[i][0];
				short dy = y + dir[i][1];
				bool first = first_item;
				bool second = second_item;
				if (inRange(dx, dy) && !visit[dx][dy][i][first_item][second_item] && board[dx][dy]!='#') {
					if (board[dx][dy] == 'C') first = true;
					else if (board[dx][dy] == 'D') second = true;
					visit[dx][dy][i][first][second] = true;
					q.push(make_pair(make_pair(make_pair(dx, dy), make_pair(i,dis+1)),make_pair(first,second)));
				}
			}
		}
	}
	cout << -1 << "\n";
	return;
}

int main() {
	solve();
}