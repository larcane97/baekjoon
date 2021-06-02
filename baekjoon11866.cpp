#include <iostream>
#include <queue>
using namespace std;


void solve() {
	vector<int>ret;
	int n, k;
	cin >> n >> k;
	queue<int>q;
	for (int i = 1; i <= n; i++)
		q.push(i);

	// big-O : O(nk)
	while (!q.empty()) { // while문 : n번 반복
		for (int i = 0; i < k-1; i++) { // 각 반복문마다 k번 반복
			q.push(q.front());
			q.pop();
		}
		ret.push_back(q.front());
		q.pop();
	}
	
	int i;
	printf("<");
	for (i = 0; i < ret.size() - 1; i++)
		printf("%d, ", ret[i]);
	printf("%d>", ret[i]);
}

int main() {
	solve();
}