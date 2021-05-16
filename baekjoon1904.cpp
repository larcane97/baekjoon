#include <iostream>
#include <cstring>
using namespace std;



int solve(int n,int* arr) {
	int&ret =arr[n];
	if (ret != 0) return ret;

	if (n == 1) return ret = 1;
	if (n == 2) return ret = 2;
	return ret = (solve(n - 1,arr) + solve(n - 2,arr)) % 15746;
}

int main() {
	int* arr = new int[1000001]{};
	int n;
	cin >> n;
	cout << solve(n,arr)  << endl;
	delete[] arr;
}