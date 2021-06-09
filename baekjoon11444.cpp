#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll c = 1000000007;

ll fibo_arr[2][2] = {
	{1,1},
	{1,0}
};


void calc_square() {
	ll tmp[2][2];
	copy(&fibo_arr[0][0], &fibo_arr[0][0] + 4, &tmp[0][0]);
	fibo_arr[0][0] =
		( ( (tmp[0][0] % c) * (tmp[0][0] % c ) % c )
		+ ( (tmp[1][0] % c) * (tmp[0][1] % c) ) % c)%c;

	fibo_arr[0][1] =
		(((tmp[0][0] % c) * (tmp[0][1] % c) % c)
		+ ((tmp[0][1] % c) * (tmp[1][1] % c)) % c)%c;

	fibo_arr[1][0] =
		(((tmp[0][0] % c) * (tmp[1][0] % c) % c)
		+ ((tmp[1][0] % c) * (tmp[1][1] % c)) % c)%c;

	fibo_arr[1][1] =
		(((tmp[0][1] % c) * (tmp[1][0] % c) % c)
		+ ((tmp[1][1] % c) * (tmp[1][1] % c)) % c)%c;

}

void mul_one() {
	ll tmp[2][2];
	copy(&fibo_arr[0][0], &fibo_arr[0][0] + 4, &tmp[0][0]);
	fibo_arr[0][0] =
		((tmp[0][0] % c) + (tmp[0][1] % c)) % c;

	fibo_arr[0][1] = tmp[0][0];

	fibo_arr[1][0] =
		((tmp[1][0] % c) + (tmp[1][1] % c)) % c;

	fibo_arr[1][1] = tmp[1][0];
}

void fibonacci(ll n) {
	if (n <= 1) return;
	fibonacci(n / 2);
	calc_square();
	if (n % 2 == 1)
		mul_one();
}

void solve() {
	ll n;
	scanf("%lld", &n);
	fibonacci(n-1);
	printf("%lld\n", fibo_arr[0][0]);
	return;
}

int main() {
	solve();
}