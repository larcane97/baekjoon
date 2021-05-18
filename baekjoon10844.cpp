#include <iostream>
#include <cstring>

using namespace std;

long long mem[101];

long long numCount[101][10];

void setNumCount(int n) {
	numCount[1][0] = 0;
	for (int i = 1; i < 10; i++)
		numCount[1][i] = 1;

	for (int i = 2; i <= n; i++) 
		for (int j = 0; j < 10; j++)
			if(j==0)
				numCount[i][j] = numCount[i - 1][1];
			else if(j==9)
				numCount[i][j] = numCount[i - 1][8];
			else
				numCount[i][j] = (numCount[i - 1][j - 1] + numCount[i - 1][j + 1]) % 1000000000;
	return;
}



long long solve(int n) {
	long long& ret = mem[n];
	if (ret != 0) return ret;

	if (n == 1) return ret = 9;

	for (int i = 0; i < 10; i++)
		ret += numCount[n][i];
	return ret % 1000000000;
}


int main() {
	int n;
	cin >> n;
	memset(mem, 0, sizeof(mem));
	memset(numCount, 0, sizeof(numCount));
	setNumCount(n);
	cout << solve(n) << endl;


}