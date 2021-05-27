#include <iostream>
#include <vector>
using namespace std;

int n, k;
int ret;

void search(int cur, int num, vector<bool>& visit) {
	if (num == k)
		ret++;
	else 
		for (int i = cur; i < n; i++)
			if (!visit[i]) {
				visit[i] = true;
				search(i + 1, num + 1, visit);
				visit[i] = false;
			}
}

void solve() {
	ret = 0;
	vector<bool>visit(n, false);
	search(0, 0, visit);
	cout << ret << endl;
}



void input() {
	cin >> n >> k;
}

int main() {
	input();
	solve();
}