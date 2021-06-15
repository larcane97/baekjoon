#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<int, int>>coords;
bool cmpx(pair<int, int> p1, pair<int, int>p2) {
	return p1.first < p2.first;
}
bool cmpy(pair<int, int> p1, pair<int, int>p2) {
	return p1.second < p2.second;
}

const int INF = 987654321;
int dis(pair<int, int>p1, pair<int, int>p2) {
	return int(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}
int f(int start, int end) {
	int n = end - start + 1;
	int ret = INF;
	if (n <= 3) {
		for (int i = start; i < end ; i++)
			for (int j = i + 1; j <= end; j++) 
				ret = min(ret, dis(coords[i], coords[j]));
	}
	else {
		int mid = (start + end) / 2;
		ret = min(ret, f(start, mid));
		ret = min(ret, f(mid + 1, end));
		vector<pair<int, int>>cand;
		cand.push_back(coords[mid]);
		for (int i = mid-1; i >= start; i--)
			if ((int)pow(coords[i].first - coords[mid].first, 2) >= ret) break;
			else cand.push_back(coords[i]);
		for (int i = mid + 1; i <= end; i++)
			if ((int)pow(coords[i].first - coords[mid].first, 2) >= ret) break;
			else cand.push_back(coords[i]);

		sort(cand.begin(), cand.end(), cmpy);
		for (int i = 0; i < cand.size() - 1; i++)
			for (int j = i + 1; j < cand.size(); j++)
				if (pow(cand[i].second - cand[j].second, 2) >= ret) break;
				else ret = min(ret, dis(cand[i], cand[j]));
	}
	return ret;
}

void solve() {
	int n;
	scanf("%d", &n);
	coords.resize(n);
	for (int i = 0; i < n; i++) 
		scanf("%d %d", &coords[i].first, &coords[i].second);

	sort(coords.begin(), coords.end(),cmpx);
	printf("%d\n", f(0, n - 1));
}

int main() {
	solve();
}