#include <iostream>
#include <cstring>

using namespace std;

int arr[1000][3];
int mem[1000][3];

int n;
int ret = 987654321;
int solve(int cur,int prev) {
	
	if (prev == -1) {
		ret =min(
			solve(cur + 1, 0) + arr[cur][0],
			solve(cur + 1, 1) + arr[cur][1]);
		ret =min(ret, solve(cur + 1, 2) + arr[cur][2]);
	}


	int& chk = mem[cur][prev];
	if (chk != -1) return chk;

	if (cur == n - 1) {
		switch (prev) {
		case 0:
			return  chk = min( arr[cur][1],arr[cur][2]);
		case 1:
			return  chk = min( arr[cur][0], arr[cur][2]);
		case 2:
			return  chk = min(arr[cur][1], arr[cur][0]);
		}

	}
	switch (prev) {
	case 0:
		return  chk =  min(solve(cur + 1, 1) + arr[cur][1], solve(cur + 1, 2) + arr[cur][2]);
	case 1:
		return  chk =  min(solve(cur + 1, 0) + arr[cur][0], solve(cur + 1, 2) + arr[cur][2]);
	case 2:
		return  chk =  min(solve(cur + 1, 1) + arr[cur][1], solve(cur + 1, 0) + arr[cur][0]);
	}

	return 987654321;
}

int main() {
	memset(mem, -1, sizeof(mem));
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	solve(0,-1);
	cout << ret << endl;

}