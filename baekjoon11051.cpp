#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int mem[1001][1001];


int solve(int n,int k) {
	int& ret = mem[n][k];
	if ( (n == 0 || k == 0)|| n==k) return ret =1;
	if (ret != -1) return ret;
	return ret = (solve(n - 1, k - 1) + solve(n - 1, k)) %10007;

}

void input(int& n,int& k) {
	memset(mem, -1, sizeof(mem));
	cin >> n >> k;
}

int main() {
	int n, k;
	input(n,k);
	cout << solve(n, k) << endl;
}