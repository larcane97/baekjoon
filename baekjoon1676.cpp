#include <iostream>
#include <vector>
using namespace std;


// 각 숫자마다 2와 5의 개수 저장
const int MAX_N = 500;
vector<pair<int, int>>arr(MAX_N);


// n을 소인수분해 했을 때, 2와 5의 개수
pair<int,int> count_2and5(int n) {
	int two = 0, five = 0;
	while (true) {
		if (n % 2 == 0) {
			two++;
			n /= 2;
		}
		else if (n % 5 == 0) {
			five++;
			n /= 5;
		}
		else {
			return make_pair(two, five);
		
		}
	}
}

// factorial의 2와 5의 개수 계산
pair<int,int> calcFact_2and5(int n) {
	if (n == 0 || n == 1) return make_pair(0, 0);
	pair<int, int>&ret = arr[n];
	if (ret.first != 0) return ret;

	pair<int, int>prev = calcFact_2and5(n - 1);
	pair<int, int> cur = count_2and5(n);
	return ret = make_pair(prev.first + cur.first, prev.second + cur.second);
}


int solve() {
	int n;
	cin >> n;
	pair<int, int> ret = calcFact_2and5(n);
	return min(ret.first, ret.second);
}


int main() {
	cout << solve() << endl;
}