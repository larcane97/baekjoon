#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n,k;
vector<int> vals;
int solve() {
	sort(vals.begin(), vals.end(),greater<int>());
	int count = 0;
	int cur = 0;
	while (true) {
		if (cur >= n) break;

		if (k >= vals[cur]) {
			int nums = k / vals[cur];
			count += nums;
			k -= vals[cur] * nums;
		}
		cur++;
	}
	return count;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		vals.push_back(tmp);
	}
	cout << solve() << endl;
	
}