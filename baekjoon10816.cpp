#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


void solve() {
	int n, m;
	cin >> n;
	vector<int> arr = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> m;
	vector<int>cards = vector<int>(m);
	for (int i = 0; i < m; i++)
		cin >> cards[i];

	sort(arr.begin(), arr.end());

	map<int, int>cards_num;
	for (int i = 0; i < n;) {
		int j = i + 1;
		int num_count = 1;
		while (j < n && arr[i] == arr[j]) {
			num_count++;
			j++;
		}
		cards_num[arr[i]] = num_count;
		i = j;
	}

	//중복 제거
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	vector<int>ret(m, 0);
	for (int i = 0; i <m; i++) {
		int left = 0, right = arr.size()-1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (cards[i]==arr[mid]){
				ret[i] = cards_num[arr[mid]];
				break;
			}

			if (arr[mid] < cards[i])
				left = mid+1;
			else
				right = mid-1;
		}
	}
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
	
}
// 각 숫자 별 개수 파악
// 중복제거
// 해당 숫자가 있을 경우 개수대로 저장
// 없을 경우 0

int main() {
	solve();
}