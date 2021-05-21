#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>>lines;

vector<pair<int,int>> countCross() {
	int n = lines.size();
	int totalCount = 0;
	vector<pair<int, int>>crossNum;
	for (int i = 0; i < n ; i++) {
		int count = 0;
		for (int j = 0; j < n; j++)
			if ((lines[i].first < lines[j].first && lines[i].second > lines[j].second)
				|| (lines[i].first > lines[j].first && lines[i].second < lines[j].second))
				count++;
		totalCount += count;
		crossNum.push_back(make_pair(count, i));
	}

	if (totalCount > 0) {
		sort(crossNum.begin(), crossNum.end(), greater<pair<int, int>>());
		return crossNum;
	}
	else return vector<pair<int, int>>();
}


int solve() {
	int count = 0;
	while (true) {
		vector<pair<int, int>>crossNum = countCross();
		if (crossNum.empty()) break;
		count++;
		lines[crossNum[0].second] = make_pair(0, 0);
	}
	return count;
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		lines.push_back(make_pair(a, b));
	}
	cout << solve() << endl;



}