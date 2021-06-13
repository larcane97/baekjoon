#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;
const int MAX_N = 2000;
const int MAX_T = 100;
vector<pair<int, int>>adj[MAX_N+1];
int n;

vector<pair<int,int>> dijkstra(int start) {
	vector<pair<int,int>>ret(n+1, make_pair(INF,-1));
	priority_queue<pair<int, int>>pq;
	ret[start] = make_pair(0,start);
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (ret[here].first < cost) continue;
		
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			if (cost + adj[here][i].second < ret[there].first) {
				ret[there].first = cost + adj[here][i].second;
				ret[there].second = here;
				pq.push(make_pair(-ret[there].first, there));
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

		vector<pair<int,int>>ret = dijkstra(s);
		vector<int>ret_v;
		for (int i = 0; i < dest_set.size(); i++) {
			if (ret[dest_set[i]].first == INF) continue;
			for (int here = ret[dest_set[i]].second; here != ret[here].second ; here = ret[here].second) {
				int parent = ret[here].second;
				if ((here == g && parent == h) || (here == h && parent == g)) {
					ret_v.push_back(dest_set[i]);
					break;
				}
			}
		}
		sort(ret_v.begin(), ret_v.end());
		for (int i = 0; i < ret_v.size(); i++)
			cout << ret_v[i] << " ";
		cout << "\n";

		for (int i = 0; i < n; i++)
			adj[i].clear();
	}
}

int main() {
	solve();
}