#include <iostream>
using namespace std;


int ea(int a, int b) {
	if (a < b) swap(a, b);
	int c = a % b;
	if (c == 0)return b;
	else return ea(b, c);
}


int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		cout << a*b/ea(a, b) << endl;
	}
}