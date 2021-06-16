/*
1. ���� ��ġ���� bfs�� ���� ���� ������ �ִ� �մ��� ��ǥ�� �˻�
2. bfs distance�� �̵� �� �ʿ��� ����
3. ���� ���� - �ʿ��� ���� <0�� ��� -1�� ���
4. �մ��� �������� bfs�� �̿��� �˻�
5. bfs distance�� �̵� �� �ʿ��� ����
6. ���� ���� - �ʿ��� ���� <0�� ��� -1�� ���
7. ������ �� 5���� �ʿ��� ���� * 2�� ����
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
		// i��° �մ� = i+1 index
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
		// �ִ� �Ÿ��� �ִ� �մ��� �߰��� ���
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
			// ���ᰡ ������ ���
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
		// �մ��� �¿�� �������� ������ ���
		else if (!canBoard && cx== guests[cur_guest].first && cy == guests[cur_guest].second){
			gas -= dis;
			// ���ᰡ ������ ���
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
			// ���� ����
			gas += dis* 2;
			num++;
			// ��� �մ��� ���� ����� �� ���
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
	// ���� �Ϸ����� ���ϴ� ���
	//printf("not found\n");
	printf("%d\n", -1);
	return;
}

int main() {
	solve();
}