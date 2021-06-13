#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;
const int MAX_N = 2000;
vector<pair<int, int>>adj[MAX_N+1];
int n;

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
			if (cost + adj[here][i].second < ret[there]) {
				ret[there] = cost + adj[here][i].second;
				pq.push(make_pair(-ret[there], there));
			}
		}
	}
	return ret;
}

void solve() {
	int T;
	cin >> T;
	for (int iter = 0; iter < T; iter++) {
		int m, t;
		int s, g, h;
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		vector<int>dest_set(t);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}
		for (int i = 0; i < t; i++)
			cin >> dest_set[i];

		vector<int>S = dijkstra(s);
		vector<int>G = dijkstra(g);
		vector<int>H = dijkstra(h);
		
		sort(dest_set.begin(), dest_set.end());
		for(int i=0;i<dest_set.size();i++){
			if ((S[dest_set[i]] == (S[g] + G[h] + H[dest_set[i]]))
				|| (S[dest_set[i]] == (S[h] + H[g] + G[dest_set[i]])))
				cout << dest_set[i] << " ";
		}
		cout << "\n";

		for (int i = 1; i <= n; i++)
			adj[i].clear();
	}
}

int main() {
	solve();
}