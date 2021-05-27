#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int mem[31][31];

int calc(int a,int b) {
	int& ret = mem[a][b];
	if (ret != -1)return ret;
	if (a == 1) return ret = b;
	ret = 0;
	for (int i = b - 1; i >= a - 1; i--)
		ret += calc(a - 1, i);
	return ret;
}


void solve() {
	memset(mem, -1, sizeof(mem));
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;
		cout << calc(a,b) << endl;
	}
}


int main() {
	solve();
}