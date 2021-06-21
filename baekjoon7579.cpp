#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int>memory;
vector<int>cost;
int cache[10001][100];
int n, m;


/// <summary>
/// cur위치에서 cur_cost를 가지고 얻을 수 있는 최대 메모리를 반환
/// </summary>
/// <param name="cur_cost">현재 남은 cost</param>
/// <param name="cur">현재 위치</param>
/// <returns>최대 메모리</returns>
int dp(int cur_cost, int cur) {
	// M만큼 메모리를 확보한 경우
	if (cur_cost < 0) return -987654321;
	if (cur==n) return 0;
	int& ret = cache[cur_cost][cur];
	if (ret != -1)return ret;
	ret = 0;
	return ret = max(
		dp(cur_cost - cost[cur], cur + 1)+memory[cur], dp(cur_cost, cur + 1)
	);
}

void solve() {
	memset(cache, -1, sizeof(cache));
	int total_cost = 0;
	cin >> n >> m;
	memory.resize(n);
	cost.resize(n);
	for (int i = 0; i < n; i++)
		cin >> memory[i];
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
		total_cost += cost[i];
	}
	for(int i=0;i<=total_cost;i++)
		if (dp(i, 0) >= m) {
			cout << i << "\n";
			break;
		}
}

int main() {
	solve();
}