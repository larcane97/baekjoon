#include <iostream>
#include <cstring>

using namespace std;

long long arr[101];

long long solve(int n) {
	long long& ret = arr[n];
	if (ret != -1) return ret;
	
	if (n == 1) return ret = 1;
	if (n == 2) return ret = 1;
	if (n == 3) return ret = 1;
	if (n == 4) return ret = 2;
	if (n == 5) return ret = 2;

	return ret = solve(n - 1) + solve(n - 5);
}

int main() {
	int t;
	cin >> t;
	int n;
	memset(arr, -1, sizeof(arr));
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << solve(n) << endl;
	}

}