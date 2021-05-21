#include <iostream>
#include <vector>

using namespace std;


int solve(string a, string b) {
	int n = a.size();
	int m = b.size();
	int k = min(n, m);
	vector<vector<int>>mem(n, vector<int>(m, 0));

	mem[0][0] = a[0] == b[0] ? 1 : 0;
	for (int i = 1; i < m; i++) {
		mem[0][i] = mem[0][i - 1];
		if (a[0] == b[i]) mem[0][i] = 1;
	}

	for (int i = 1; i < n; i++) {
		mem[i][0] = mem[i - 1][0];
		if (a[i] == b[0]) mem[i][0] = 1;
	}
		

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <m; j++) {
			if (a[i] == b[j])
				mem[i][j] = mem[i - 1][j - 1] + 1;
			else
				mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);
		}
	}
	return mem[n - 1][m - 1];
}





int mem2[1000][1000];
string a, b;

int solve2(int i,int j) {
	int& ret = mem2[i][j];
	if (ret != -1)return ret;
	if (i==0 && j==0) return ret = (a[0] == b[0])?1:0;
	if (i == 0) return ret = max(solve2(i,j-1),(a[0] == b[j] ? 1 : 0));
	if (j==0) return ret = max(solve2(i-1, j), (a[i] == b[0] ? 1 : 0));

	if (a[i] == b[j])
		return ret = solve2(i - 1, j - 1) + 1;
	else return ret = max(solve2(i, j - 1), solve2(i - 1, j));

	
}

int main() {
	memset(mem2, -1, sizeof(mem2));
	cin >> a >> b;
	cout << solve2(a.size()-1,b.size()-1) << endl;
}