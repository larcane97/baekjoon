#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


void solve() {
	int n, m;
	scanf("%d", &n);
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr.begin(), arr.end());
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		bool find = false;
		int left = 0, right = arr.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (arr[mid] == a) {
				find = true;
				break;
			}
			if (arr[mid] < a)
				left = mid+1;
			else
				right = mid-1;
		}
		printf("%d\n", find ? 1 : 0);
	}
}

int main() {
	solve();
}