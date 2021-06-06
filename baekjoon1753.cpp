#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_V = 20000;
const int INF = 987654321;
vector<pair<int,int>>adj[MAX_V+1];
int V, E;
vector<int> dijkstra(int start);
void solve() {
	cin >> V >> E;
	int start;
	cin >> start;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
	}
	vector<int> ret = dijkstra(start);
	for (int i = 1; i < ret.size(); i++)
		if (ret[i] != INF)
			cout << ret[i] << "\n";
		else
			cout << "INF" << "\n";
}

vector<int> dijkstra(int start) {
	vector<int>ret(V+1, INF);
	priority_queue<pair<int, int>>pq;
	ret[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (cost > ret[here]) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			if (ret[there] > cost + adj[here][i].second) {
				ret[there] = cost + adj[here][i].second;
				pq.push(make_pair(-ret[there], there));
			}
		}
	}
	return ret;
}

int main() {
	solve();
}
