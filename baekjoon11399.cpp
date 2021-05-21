#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> P;
int n;
int solve() {
	int ret = 0;
	int wait = 0;
	sort(P.begin(), P.end());
	
	for (int i = 0; i < n; i++) {
		ret += (wait + P[i]);
		wait += P[i];
	}
	return ret;
}

int main() {
	cin >> n;
	P = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> P[i];
	cout << solve() << endl;
}