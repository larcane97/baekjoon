#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>arr;

vector<int> combination(int cur, vector<int>& ret) {
	if (ret.size() == 7) {
		int heights = 0;
		for (int i = 0; i < ret.size(); i++)
			heights += ret[i];
		if (heights == 100)
			return ret;
		else return vector<int>();
	}
	for (int i = cur; i < 9; i++) {
		ret.push_back(arr[i]);
		combination(i + 1, ret);
		ret.pop_back();
	}
	return ret;
}

void solve() {
	arr.resize(9);
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	vector<int>ret;
	ret = combination(0,ret);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << "\n";
}

int main() {
	solve();
}