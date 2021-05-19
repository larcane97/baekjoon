#include <iostream>
#include <string>

using namespace std;


string solve(int a, int b) {
	if (b % a == 0) return "factor";
	if (a % b == 0) return "multiple";
	else return "neither";
}


int main() {
	int a, b;
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		cout << solve(a, b) << endl;
	}

}