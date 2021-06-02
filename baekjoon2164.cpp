#include <iostream>
#include <queue>
using namespace std;

void solve() {
	int n;
	cin >> n;
	queue<int>q;
	for (int i = 0; i < n; i++)
		q.push(i + 1);
	while (q.size() > 1) {
		// 1
		q.pop();
		
		// 2
		q.push(q.front());
		q.pop();
	}
	cout << q.front() << "\n";
}


int main() {
	solve();
}