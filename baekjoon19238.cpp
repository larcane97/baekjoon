/*
1. 현재 위치에서 bfs를 통해 가장 가까이 있는 손님의 좌표를 검색
2. bfs distance은 이동 중 필요한 연료
3. 현재 연료 - 필요한 연료 <0인 경우 -1을 출력
4. 손님의 목적지를 bfs를 이용해 검색
5. bfs distance은 이동 중 필요한 연료
6. 현재 연료 - 필요한 연료 <0인 경우 -1을 출력
7. 도착한 후 5에서 필요한 연료 * 2를 충전
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

struct state {
	int x, y, dis;
	state(int _x, int _y, int _dis) :x(_x), y(_y), dis(_dis)
	{}
};

map<int, pair<int, int>>guests;
int board[21][21];
bool visit[21][21];
int dir[4][2] = {
	{-1,0},
	{0,-1},
	{0,1},
	{1,0}
};
int n, m, gas;

bool inRange(int x,int y){
	return x > 0 && x <= n && y > 0 && y <= n && (board[x][y] != 1);
}

void solve() {
	scanf("%d %d %d", &n, &m, &gas);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &board[i][j]);
	int sx, sy;
	scanf("%d %d", &sx, &sy);
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c,&d);
		// i번째 손님 = i+1 index
		board[a][b] = i + 2;
		guests[i + 2] = { c,d };
	}

	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++)
	//		printf("%d\t", board[i][j]);
	//	printf("\n");
	//}

	queue<state>q;
	q.push(state(sx,sy,0));
	visit[sx][sy] = true;
	int num = 0;
	int cur_guest = -1;
	bool canBoard = true;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int dis = q.front().dis;
		q.pop();
		// 최단 거리에 있는 손님을 발견한 경우
		if (canBoard && board[cx][cy] > 1) {
			while (!q.empty()) {
				int tx = q.front().x;
				int ty = q.front().y;
				int tdis = q.front().dis;
				q.pop();
				if (tdis < dis)
					for (int i = 0; i < 4; i++) {
						int dx = tx + dir[i][0];
						int dy = ty + dir[i][1];
						if (inRange(dx, dy) && !visit[dx][dy]) {
							visit[dx][dy] = true;
							q.push(state(dx, dy, tdis + 1));
						}
					}
				else if(tdis==dis){
					if (board[tx][ty] > 1) {
						if (tx < cx) {
							cx = tx;
							cy = ty;
						}
						else if (tx == cx && ty < cy) {
							cx = tx;
							cy = ty;
						}
					}
				}
			}
			gas -= dis;
			// 연료가 부족한 경우
			if (gas < 0) {
				//printf("gas is 0.");
				printf("%d\n", -1);
				return;
			}
			q.push({ cx,cy,0 });
			cur_guest = board[cx][cy];
			canBoard = false;
			memset(visit, 0, sizeof(visit));
			visit[cx][cy] = true;
			board[cx][cy] = 0;
			//printf("found guest : %d %d, remain gas : %d\n", cx, cy,gas);
			continue;
		}
		// 손님을 태우고 목적지에 도착한 경우
		else if (!canBoard && cx== guests[cur_guest].first && cy == guests[cur_guest].second){
			gas -= dis;
			// 연료가 부족한 경우
			if (gas < 0) {
				//printf("gas is 0.");
				printf("%d\n", -1);
				return;
			}
			queue<state>empty;
			swap(q, empty);
			q.push({ cx,cy,0 });
			cur_guest = -1;
			canBoard = true;
			// 연료 충전
			gas += dis* 2;
			num++;
			// 모든 손님을 전부 대려다 준 경우
			if (num == m) {
				printf("%d\n", gas);
				return;
			}
			memset(visit, 0, sizeof(visit));
			visit[cx][cy] = true;
			//printf("finish guest : %d %d, remain gas: %d\n", cx, cy,gas);
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int dx = cx + dir[i][0];
			int dy = cy + dir[i][1];
			if (inRange(dx, dy) && !visit[dx][dy]) {
				visit[dx][dy] = true;
				q.push(state(dx, dy, dis + 1));
			}
		}
	}
	// 전부 완료하지 못하는 경우
	//printf("not found\n");
	printf("%d\n", -1);
	return;
}

int main() {
	solve();
}