#include <iostream>
using namespace std;


int* mem = new int[1000001]{ 0 };
int n;

int solve(int num,int calc) {
	if (num == 1) return 0;

	int& ret = mem[num];
	if (ret != 0) return ret;

	int tmp = 987654321;
	if (num % 3 == 0)
		tmp = min(tmp,1+ solve(num/ 3, calc + 1));
	if (num % 2 == 0)
		tmp = min(tmp, 1+solve(num / 2, calc + 1));

	return ret =min(tmp, 1+solve(num - 1, calc + 1));
}

int main() {
	cin >> n;
	cout << solve(n, 0) << endl;

	delete[] mem;
	return 0;

}
