#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll c = 1000000007;
ll pow_f(ll a,ll p) {
	if (a == 1) return a%c;
	if (p == 0) return 1;
	ll ret = pow_f(a, p / 2)%c;
	ret = (ret * ret) % c;
	if (p % 2 == 0)
		return ret;
	else
		return (ret * (a % c)) % c;

}

ll factorial_f(int a) {
	ll ret = 1;
	for (int i = 1; i <= a; i++)
		ret = (ret * (i % c)) % c;
	return ret;
}

void solve() {
	int n, k;
	cin >> n >> k;
	cout << (factorial_f(n) * pow_f( (factorial_f(k) * factorial_f(n - k))%c, c - 2) ) % c;
}

int main() {
	solve();
}