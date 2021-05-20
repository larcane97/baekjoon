#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int solve(vector<pair<int,int>>&arr) {
	sort(arr.begin(), arr.end());
	int count = 0;
	int endTime = -1;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].second >= endTime) {
			endTime = arr[i].first;
			count++;
		}
	}
	return count;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>>arr;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back(make_pair(b, a));
	}
	cout << solve(arr) << endl;
}