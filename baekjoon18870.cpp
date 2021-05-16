#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int,int>> arr(n);
	vector<int>ret(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = make_pair(a, i);
	}
	sort(arr.begin(), arr.end());

	int num = 0;
	ret[arr[0].second] = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i-1].first < arr[i].first)
			num++;
		ret[arr[i].second] = num;
			
	}
	for (int i = 0; i < n; i++)
		cout << ret[i] << " ";

}