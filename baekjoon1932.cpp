#include <iostream>
#include <cstring>

using namespace std;


int n;
int arr[500][500];
int mem[500][500];

int solve(int raw, int col) {
	int& ret = mem[raw][col];
	if (ret != -1) return ret;

	if (raw == n-1) return ret = arr[raw][col];

	return ret = arr[raw][col] + max(solve(raw+1, col), solve(raw+ 1, col+ 1));


}

int main() {
	memset(mem, -1, sizeof(mem));
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> arr[i][j];
	cout << solve(0, 0) << endl;




}

