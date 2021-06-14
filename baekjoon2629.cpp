#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int weights[30];
int beads[7];
int mem[31][500 * 30 + 1];
int n, m;
void dp(int total_num, int total_weight) {
	if (total_num > n) return;
	int& ret = mem[total_num][total_weight];
	if (ret != -1) return;
	ret = 1;
	int weight = weights[total_num];
	dp(total_num + 1, total_weight + weight);
	dp(total_num + 1, abs(total_weight - weight));
	dp(total_num + 1, total_weight);
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> weights[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> beads[i];
	memset(mem, -1, sizeof(mem));
	dp(0, 0);

	for (int i = 0; i < m; i++) {
		if (beads[i] > 15000)
			cout << "N ";
		else if (mem[n][beads[i]] == 1)
			cout << "Y ";
		else
			cout << "N ";
	}


}

int main() {
	solve();
}