#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int n, m, s;
const int MAX_V = 1000;
vector<int>adj[MAX_V + 1];

vector<int>ret_bfs, ret_dfs;


void dfs(int here,vector<bool>&visited) {
	ret_dfs.push_back(here);
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (visited[there])continue;
		visited[there] = true;
		dfs(there,visited);
	}
}

void dfs_search() {
	vector<bool>visited(n+1, false);
	visited[s] = true;
	dfs(s, visited);
}

void bfs_search() {
	queue<int>q;
	vector<bool>visited(n+1, false);
	visited[s] = true;
	q.push(s);
	while (!q.empty()) {
		int here = q.front();
		ret_bfs.push_back(here);
		q.pop();
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i];
			if (visited[there])continue;
			visited[there] = true;
			q.push(there);
		}
	}

}

void solve() {
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());
	
	dfs_search();
	for (int i = 0; i < ret_dfs.size(); i++)
		printf("%d ", ret_dfs[i]);
	printf("\n");
	bfs_search();
	
	for (int i = 0; i < ret_bfs.size(); i++)
		printf("%d ", ret_bfs[i]);

}

int main() {
	solve();
}