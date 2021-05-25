#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
typedef long long ll;
using namespace std;

vector<ll> arr;
int n;

ll gcd(ll a, ll b) {
	if(a < b) swap(a, b);
	return a % b == 0 ? b : gcd(b, a % b);
}

void solve() {
	vector<ll>ret;
	ll GCD = abs(arr[1] - arr[0]);
	for (int i = 2; i < arr.size(); i++) {
		GCD = gcd(GCD, abs(arr[i] - arr[i - 1]));
	}
	for (int i = 2; i <=sqrt(GCD); i++) {
		if (GCD % i == 0) {
			ret.push_back(i);
			ret.push_back(GCD / i);
		}
	}
	ret.push_back(GCD);
	sort(ret.begin(), ret.end());
	ret.erase(unique(ret.begin(), ret.end()), ret.end());
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
}

void input() {
	cin >> n;
	arr = vector<ll>(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

int main() {
	input();
	solve();

}