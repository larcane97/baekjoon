#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_V = 100;
vector<int>adj[MAX_V + 1];
int n, m;


int dfs(int here, vector<bool>& visited) {
	static int ret = 0;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (visited[there]) continue;		
		ret++;
		visited[there] = true;
		dfs(there, visited);
	}
	return ret;
}

void solve_by_dfs() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	vector<bool>visited(n + 1, false);
	visited[1] = true;
	int ret = dfs(1, visited);
	cout << ret << "\n";
}





void solve_by_bfs() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int ret = 0;
	vector<bool>visited(n+1, false);
	queue<int>q;
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		ret++;
		int here = q.front();
		q.pop();
		//if (visited[here]) continue;
		//visited[here] = true;
		for (int i = 0; i< adj[here].size(); i++) {
			int there = adj[here][i];
			if (visited[there])continue;
			visited[there] = true;
			q.push(there);
		}
	}
	cout << ret-1 << "\n";
}

int main() {
	solve_by_dfs();
}