#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


char map[25][25];
bool visit[25][25] = { false };
int n;
vector<pair<int, int>> directions = {
	make_pair(1,0),
	make_pair(-1,0),
	make_pair(0,1),
	make_pair(0,-1)
};

bool rangeCheck(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}

int move(int x,int y) {
	visit[x][y] = true;
	int ret = 1;
	for (int i = 0; i < directions.size(); i++) {
		// 인접한 곳 방문
		x += directions[i].first;
		y += directions[i].second;
		// 범위 내에 있고, 아직 방문하지 않은 곳이면서 집이 존재하는 경우, 이동
		if ( rangeCheck(x,y) && !visit[x][y] && map[x][y]=='1')
			ret += move(x, y);
		x -= directions[i].first;
		y -= directions[i].second;
	}
	return ret;
}

void solve(){
	vector<int> regions;

	int count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			if (!visit[i][j] && map[i][j]=='1') {
				regions.push_back(move(i, j));
				count++;
			};
				
	cout << count << endl;
	sort(regions.begin(), regions.end());
	for (int i = 0; i < regions.size(); i++)
		cout << regions[i] << endl;
}




void input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
}

int main() {
	input();
	solve();
}