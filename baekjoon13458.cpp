#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

vector<int>room;
void solve() {
	int n;
	scanf("%d", &n);
	room.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &room[i]);
	int b, c;
	scanf("%d %d", &b, &c);
	ll ret = n;
	for (int i = 0; i < n; i++) {
		room[i] = room[i] - b < 0 ? 0 : room[i] - b;
		ret +=ceil((double)room[i] / c);
	}
	printf("%lld\n", ret);
}

int main() {
	solve();
}
