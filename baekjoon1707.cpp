#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

const int MAX_V = 20000;
vector<short>adj[MAX_V+1];
void solve() {
	int k;
	cin >> k;
	for (int iter = 0; iter < k; iter++) {
		int v, e;
		cin >> v >> e;

		for (int j = 0; j < e; j++) {
			short a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		map<int, bool>m;
		queue<int>q;
		vector<bool>visit(v + 1, false);

		bool ok = true;
		for (int j = 1; j <= v; j++) {
			if (!ok) break;
			if (visit[j]) continue;

			q.push(j);
			visit[j] = true;
			m[j] = true;
			while (!q.empty()) {
				int here = q.front();
				q.pop();
				for (int i = 0; i < adj[here].size(); i++) {
					int there = adj[here][i];
					if (!visit[there]) {
						visit[there] = true;
						m[there] = !m[here];
						q.push(there);
					}
					else if (m[there] == m[here]) {
						ok = false;
						break;
					}
				}
				if (!ok) break;
			}
		}

		cout << (ok? "YES" : "NO") << "\n";

		for (int i = 0; i <=v; i++)
			adj[i].clear();
	}
}

int main() {
	solve();
}