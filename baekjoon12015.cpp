#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int arr[1000000];
int n;

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	vector<int>ret;
	ret.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (ret.back() < arr[i])
			ret.push_back(arr[i]);
		else {
			int left = 0;
			int right = ret.size()-1;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (ret[mid] > arr[i])
					right = mid - 1;
				else if (ret[mid] < arr[i])
					left = mid + 1;
				else {
					left = mid;
					break;
				}
			}
			ret[left] = arr[i];
		}
	}
	cout << ret.size() << "\n";
}

int main() {
	solve();
}