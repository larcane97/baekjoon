#include <iostream>
using namespace std;

int gcd, lcm;
int ea(int a, int b) {
	if (a < b) swap(a, b);
	int t = a % b;
	if (t == 0) return b;
	else return ea(b, t);
}
void solve(int a,int b) {
	gcd = ea(a, b);
	lcm = a * b / gcd;
	return;
}
int main() {
	int a, b;
	cin >> a >> b;
	solve(a, b);
	cout << gcd << endl;
	cout << lcm << endl;

}