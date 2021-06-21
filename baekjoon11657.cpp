#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int n, m;
const int INF = 987654321;
vector<pair<int,int>>adj[501];
vector<ll>dist;
bool bellman(int s) {
	dist = vector<ll>(n + 1,INF);
	dist[s] = 0;
	for (int i = 0; i < n-1; i++) {
		for (int here = 1; here <= n; here++) {
			for (int j = 0; j < adj[here].size(); j++) {
				int there = adj[here][j].first;
				int dis = adj[here][j].second;
				// here�� ���� �湮���� �ʾҴٸ� RELAX�� ���� �ʴ´�.
				// => INF�̻��� ���� �ֺ��� �Ҵ�� ���� �ְ� ���� �ʾƵ� �����ϱ� ����!
				if (dist[here] !=INF && dist[here] + dis < dist[there]) {
					dist[there] = dist[here] + dis;
				}

			}
		}
	}

	for (int here = 1; here <= n; here++) {
		for (int j = 0; j < adj[here].size(); j++) {
			int there = adj[here][j].first;
			int dis = adj[here][j].second;
			// ������ �Ǿ����� ���� ������ RELAX X
			if (dist[here] != INF && dist[here] + dis < dist[there])
				return false;
		}
	}
	return true;
}

void solve() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b,&c);
		adj[a].push_back({ b,c });
	}
	if (!bellman(1)) printf("%d\n", -1);
	else {
		for (int i = 2; i <= n; i++)
			printf("%lld\n", (dist[i] != INF ? dist[i] : -1));
	}
	return;
}

int main() {
	solve();
}