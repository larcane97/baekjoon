#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<long long> dis;
vector<long long> oil;

long long solve() {
	long long ret = 0;
	int cur = 0;
	while (cur < n-1) {
		ret += oil[cur] * dis[cur];
		int next = cur + 1;
		while (next < n-1 && oil[cur] < oil[next]) {
			ret += oil[cur] * dis[next];
			next++;
		}
		cur = next;
	}
	return ret;
}


int main() {
	cin >> n;
	dis = vector<long long>(n - 1);
	oil = vector<long long>(n);
	for (int i = 0; i < n - 1; i++)
		cin >> dis[i];
	for (int i = 0; i < n; i++)
		cin >> oil[i];
	cout << solve() << endl;
}
