#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int cache[10001];
int coin[100];
int n, k;


void solve() {
	memset(cache, 0, sizeof(cache));
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> coin[i];

	cache[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++)
			// j���� ���� �� �ִ� ����� �� : ������ ����� �� + (j�� - ���� ���� ����)�� ���� �� �ִ� ����� ��
			// j�� -���� ���� ������ ���� �� ������ ���� ���� ������ �ٷ� ���ؼ� j���� ���� �� �ִ�.
			// �� �������� ������ ���س����鼭 ������ ���� �� �ִ� ����� ���� �߰��Ѵ�.
			cache[j] = cache[j] + cache[j - coin[i]];
	}
	cout << cache[k] << "\n";

}

int main() {
	solve();
}