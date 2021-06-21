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
				// here를 아직 방문하지 않았다면 RELAX를 하지 않는다.
				// => INF이상의 값이 주변에 할당될 수도 있고 하지 않아도 무방하기 때문!
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
			// 연결이 되어있지 않은 곳에서 RELAX X
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