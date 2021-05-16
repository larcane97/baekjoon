#include <iostream>
#include <vector>


using namespace std;

const int MAX = 987654321;
int n;
int S[20][20];
bool isCheck[20];
vector<int> t1, t2;



int calc() {
	int first = 0, second = 0;
	for (int i = 0; i < (int)t1.size(); i++) {
		for (int j = 0; j < (int)t1.size(); j++) {
			if (t1[i] != t1[j])
				first += S[t1[i]][t1[j]];
			if (t2[i] != t2[j])
				second += S[t2[i]][t2[j]];
		}
	}
	return abs(first - second);
}



int ret = MAX;
int solve(int prev) {
	// base
	if ((int)t1.size() == n / 2) {
		t2.clear();
		for (int j = 0; j < n; j++)
			if (!isCheck[j]) t2.push_back(j);
		return ret = min(ret, calc());
	}
	
	for (int i = prev; i < n; i++) {
		if (isCheck[i] == true)
			continue;
		
		isCheck[i] = true;
		t1.push_back(i);
		solve(i+1);
		isCheck[i] = false;
		t1.pop_back();
	}

	return ret;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> S[i][j];
	solve(0);
	cout << ret;

	return 0;

}