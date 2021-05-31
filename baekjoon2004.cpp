#include <iostream>
#include <vector>
using namespace std;



pair<int,int> factorial_2and5(long long n) {
	int two = 0, five = 0;
	for (long long i = 2; i <= n; i *= 2)
		two += n / i;
	for (long long i = 5; i <= n; i *= 5)
		five += n / i;
	return make_pair(two, five);
}


int solve() {
	long long n, m;
	cin >> n >> m;
	pair<int, int> a, b, c;
	a = factorial_2and5(n);
	b = factorial_2and5(m);
	c = factorial_2and5(n - m);

	pair<int, int> ret = make_pair(a.first - (b.first + c.first), a.second - (b.second + c.second));
	return min(ret.first, ret.second);
}

int main() {
	cout << solve() << endl;
}