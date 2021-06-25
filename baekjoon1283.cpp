#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void solve() {
	int n;
	vector<vector<string>>words;
	vector<bool>used(26, false);
	cin >> n;
	words.resize(n);
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		stringstream ss(s);
		string token;
		while (getline(ss, token, ' ')) {
			words[i].push_back(token);
		}

		bool ok = false;
		for (int j = 0; j < words[i].size(); j++) {
			int index = toupper(words[i][j][0]) - 'A';
			if (used[index]) continue;
			words[i][j] =  "[" +words[i][j].substr(0,1)+"]"+words[i][j].substr(1);
			used[index] = true;
			ok = true;
			break;
		}
		if (!ok) {
			for (int j = 0; j < words[i].size(); j++) {
				for (int k = 1; k < words[i][j].size(); k++) {
					int index = toupper(words[i][j][k]) - 'A';
					if (used[index]) continue;
					words[i][j] = words[i][j].substr(0, k) + '[' + words[i][j][k] + ']' + words[i][j].substr(k + 1);
					used[index] = true;
					ok = true;
					break;
				}
				if (ok) break;
			}

		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < words[i].size(); j++)
			cout << words[i][j] << " ";
		cout << "\n";
	}

}
int main() {
	solve();
}