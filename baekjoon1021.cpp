#include <deque>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int ret = 0;
	int n, m;
	cin >> n>>m;
	deque<int>deq(n);
	vector<int>selected(m);
	for (int i = 0; i < m; i++)
		cin >> selected[i];
	for (int i = 0; i < n; i++)
		deq[i] = i + 1;
	
	for (int i = 0; i < m; i++) {
		int forward = 0;
		int backward = 1;
		for (int j = 0; j < deq.size(); j++) {
			if (selected[i] == deq[j]) break;
			forward++;
		}
		for (int j = deq.size()-1; j >=0; j--) {
			if (selected[i] == deq[j]) break;
			backward++;
		}

		
		if (forward < backward) {
			for (int j = 0; j < forward; j++) {
				deq.push_back(deq.front());
				deq.pop_front();
			}
			deq.pop_front();
			ret += forward;
		}
		else {
			for (int j = 0; j < backward; j++) {
				deq.push_front(deq.back());
				deq.pop_back();
			}
			deq.pop_front();
			ret += backward;
		}
	}

	cout << ret << "\n";
}

int main() {
	solve();
}