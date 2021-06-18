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
			// j원을 만들 수 있는 경우의 수 : 기존의 경우의 수 + (j원 - 현재 동전 가격)를 만들 수 있는 경우의 수
			// j원 -현재 동전 가격을 만들 수 있으면 현재 동전 가격을 바로 더해서 j원을 만들 수 있다.
			// 각 동전별로 가격을 더해나가면서 동전이 만들 수 있는 경우의 수를 추가한다.
			cache[j] = cache[j] + cache[j - coin[i]];
	}
	cout << cache[k] << "\n";

}

int main() {
	solve();
}