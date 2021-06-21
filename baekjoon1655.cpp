#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solve() {
	int n;
	cin >> n;
	priority_queue<int,vector<int>,less<int>>maxq;
	priority_queue<int,vector<int>,greater<int>>minq;
	int cur;
	cin >> cur;
	cout << cur << "\n";
	for (int i = 1; i < n; i++) {
		int a;
		cin >> a;
		if (cur <= a)
			minq.push(a);
		else
			maxq.push(a);
		
		if (maxq.size() - minq.size() == 1){
			minq.push(cur);
			cur = maxq.top();
			maxq.pop();
		}
		if (minq.size() - maxq.size() == 2) {
			maxq.push(cur);
			cur = minq.top();
			minq.pop();
		}
		cout << cur << "\n";
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}