#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve() {
	int answer = 0;
	int n;
	vector<string>start;
	string s;
	cin >> n;
	map<string, bool>isPass;
	start.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> start[i];
		isPass[start[i]] = false;
	}

	int front = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (start[front] != s) {
			answer++;
			isPass[s] = true;
		}
		else {
			front++;
			while (front<n && isPass[start[front]])
				front++;
		}
	}
	cout << answer<<"\n";
}

int main() {
	solve();
}