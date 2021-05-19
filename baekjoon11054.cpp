#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int arr[1001];
int mem[1001][2];
int n;

// flag 0 : cur���� �ִ� bitonic�� 
// flag 1 : cur���� ������ �� �ִ� �ִ밪

int solve(int cur, int flag) {
	if (cur == n) return 1;
	int& ret = mem[cur][flag];
	if (ret != -1 ) return ret;

	ret = 1;
	// arr[cur] < arr[next]:
	// ���� �� = next�� �ִ� bitonic �� + 1
	// arr[cur] > arr[next]:
	// ���� �� = next�� �ִ� �������� �� + 1
 	for (int i = cur + 1; i <= n; i++)
		// flag 0�� ���� bitonic�� ����
		if (arr[cur] < arr[i] && flag == 0)
			ret = max(ret, solve(i, 0)+1);
		// flag 1�� ���� �������� �� ����
		else if (arr[cur] > arr[i])
			ret = max(ret, solve(i, 1) + 1);

	if (cur == 0) ret--;
	return ret;


}


int main() {
	cin >> n;
	arr[0] = 0;
	memset(mem, -1, sizeof(mem));

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cout << solve(0, 0)<< endl;
}
