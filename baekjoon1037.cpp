#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int>& divisors) {
	sort(divisors.begin(), divisors.end());
	return divisors[0] * divisors[divisors.size() - 1];
}

int main() {
	int n;
	cin >> n;
	vector<int>divisors(n);
	for (int i = 0; i < n; i++)
		cin >> divisors[i];
	cout << solve(divisors) << endl;

}