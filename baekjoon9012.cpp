#include <iostream>
using namespace std;

string solve(string s) {
	int counter = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') counter++;
		else {
			if (counter == 0) return "NO";
			counter--;
		}
	}
	return counter == 0 ? "YES" : "NO";
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		cout << solve(s) << endl;
	}

}