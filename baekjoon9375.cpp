#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int T, n;
map<string, int>clothes;
void input() {
	clothes.clear();
	cin >> n;
	for (int i = 0; i < n; i++) {
		string type, item;
		cin >> item >> type;
		if (clothes.find(type) != clothes.end())
			clothes[type]++;
		else clothes[type] = 2;
	}
}



void solve() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		input();
		int ret = 1;
		for(auto it = clothes.begin();it!=clothes.end();it++)
			ret *= it->second;
		cout << ret - 1 << endl;
	}
}



int main() {
	solve();
}