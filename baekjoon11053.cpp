#include <iostream>
#include <cstring>

using namespace std;

int n;
int mem[1001];
int arr[1001];
int solve(int cur) {
	if (cur == n) return 1;

	int& ret = mem[cur];
	if (ret != -1)return ret;

	for (int i = cur + 1; i <= n; i++)
		if(arr[cur] < arr[i])
			ret = max(ret, 1+solve(i));
	return ret = max(ret,1);
}


int main() {
	cin >> n;
	memset(arr, 0, sizeof(arr));
	memset(mem, -1, sizeof(mem));

	arr[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cout << solve(0)-1 << endl;
}