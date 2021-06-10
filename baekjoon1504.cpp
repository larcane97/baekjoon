#include <queue>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 800;
const int INF = 987654321;
vector<pair<int,int>>adj[MAX_N+1];
int n, e;
vector<int> dijkstra(int start) {
	vector<int>ret(n+1, INF);
	priority_queue<pair<int, int>>pq;
	ret[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (ret[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int dis = adj[here][i].second;
			if (cost + dis < ret[there]) {
				ret[there] = cost + dis;
				pq.push(make_pair(-ret[there], there));
			}
		}
	}
	return ret;
}

void solve() {
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	int v1, v2;
	cin >> v1 >> v2;
	vector<int>ret1 = dijkstra(v1);
	vector<int>ret2 = dijkstra(v2);
	if (ret1[v2] == INF || ret2[v1]==INF) {
		cout << -1 << "\n";
		return;
	}	
	int ret = min(
		ret1[1] + ret1[v2] + ret2[n],
		ret2[1] + ret2[v1] + ret1[n]);
	cout << ret << "\n";

}

int main() {
	solve();
}


