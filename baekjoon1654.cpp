#include <iostream>
#include <vector>
using namespace std;

long long lines[10000];

// big-O : k
long long cutLines(long long cut,long long k) {
	long long ret = 0;
	for (int i = 0; i < k; i++)
		ret += lines[i] / cut;
	return ret;
}

// big-O : k
long long getRemain(long long cut, long long k) {
	long long ret = 0;
	for (int i = 0; i < k; i++)
		ret += lines[i] % cut;
	return ret;
}


void solve() {
	int n, k;
	cin >> k >> n;

	long long maxlen= 0;
	for (int i = 0; i < k; i++) {
		cin >> lines[i];
		maxlen+= lines[i];
	}
	maxlen /= n;

	// binary search
	// log(n)* (2*k)
	long long remain = 9876543210;
	long long ret = -1;
	long long minlen = 1;
	long long mid = 0;
	while (minlen <= maxlen) {
		mid = (maxlen + minlen) / 2;
		long long cutLine = cutLines(mid, k);
		if (cutLine >= n) {
			if (ret < mid)
				ret = mid;
			minlen = mid+1;
		}
		else//(cutLine < n)
			maxlen = mid - 1;
		
	}
	cout << ret << "\n";

}

 int main() {
	solve();
}