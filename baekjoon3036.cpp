#include <iostream>
#include <vector>
using namespace std;


vector<int> radiuses;
int n;
int gcd(int a, int b) {
	if (a < b) swap(a, b);
	return (a % b == 0) ? b : gcd(b, a % b);
}

void solve() {
	int first = radiuses[0];
	for (int i = 1; i < n; i++) {
		int GCD = gcd(first, radiuses[i]);
		cout << first / GCD << '/' << radiuses[i] / GCD << endl;
	}

}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		radiuses.push_back(a);
	}

}

int main(){
	input();
	solve();
}