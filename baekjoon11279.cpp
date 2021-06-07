#define _CRT_SECURE_NO_WARNINGS
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
void solve() {
	int n;
	scanf("%d", &n);
	priority_queue<ll>pq;
	for (int iter = 0; iter < n; iter++) {
		ll a;
		scanf("%lld", &a);
		if (a == 0) {
			if (pq.empty())
				printf("%d\n", 0);
			else {
				printf("%lld\n", pq.top());
				pq.pop();
			}
		}
		else
			pq.push(a);
	}
}
int main() {
	solve();
}