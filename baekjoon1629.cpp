#include <iostream>
using namespace std;


long long mul(long long a, long long b, long long c) {
	if (b == 1) return a % c;
	if (b % 2 == 0)
		return (mul(a, b / 2, c) * mul(a, b / 2, c)) % c;
	else
		return (mul(a, b / 2, c) * mul(a, b / 2, c) * mul(a, 1, c)) % c;
}


void solve() {
	long long a, b, c;
	cin >> a >> b >> c;
	cout << mul(a, b, c) % c << "\n";
	return;
}





int main() {
	solve();
}