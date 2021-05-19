#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int A[501] = {0};
int B[501] = {0};
int n;
vector<pair<int, int>> crossNum;

int countCross() {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		int cur_count = 0;;
		int cur =A[i];
		for (int j = cur - 1; j > 0; j--)
			if (B[j] && B[j] > i) cur_count++;
		crossNum.push_back(make_pair(cur_count, i));
		count += cur_count;
	}
	
	return count;
}

int solve() {
	int num = 0;
	int count = countCross();
	if (count == 0) return num;

	sort(crossNum.begin(), crossNum.end(), greater<pair<int,int>>());
	for (int i = 0; i < crossNum.size(); i++) {
		B[A[crossNum[i].second]] = 0;
		A[crossNum[i].second] = 0;
		num++;
		count = countCross();
		if (count == 0) break;
	}
	return num;
}




int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		A[a] = b, B[b] = a;
	}
	cout << solve() << endl;

}


