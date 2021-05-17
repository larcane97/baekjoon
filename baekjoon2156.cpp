#include <iostream>
#include <cstring>

using namespace std;
int n;

int arr[10001];
int mem[10001][4];


// mem[cur][count] : ���� ��ġ���� count��°�� ��� �ִ밪�� ��ȯ
int solve(int cur,int count) {	
	if (count >= 3) return -987654321;
	
	int& ret = mem[cur][count];
	if (ret != -1) return ret;

	// ����
	if (cur == n) 
		return ret = (count < 2 ? arr[cur] :0);

	// 1. ���� ��ġ�� ���� ��� : arr[cur]��ŭ ���� & count����
	// �� ���� ��� : count �ʱ�ȭ
	// 2. ���� ��ġ�� �̵�
	return ret = (count < 2) ? max(solve(cur + 1, count + 1) + arr[cur], solve(cur + 1, 0))
		: solve(cur + 1, 0);
}


int main() {
	cin >> n;
	memset(mem, -1, sizeof(mem));
	arr[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cout << solve(1,0) << endl;

}