#include <iostream>
using namespace std;


long long mul(long long a, long long b, long long c) {
	if (b == 0) return 1;
	long long ret = mul(a, b / 2, c);
	ret = (ret * ret) % c;
	if (b % 2 == 0)
		return ret;
	else
		return (ret * a) % c;
}


void solve() {
	long long a, b, c;
	cin >> a >> b >> c;
	cout << mul(a, b, c) << "\n";
	return;
}





int main() {
	solve();
}