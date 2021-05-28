#include <iostream>
using namespace std;



int contest1(int a){
	if (a == 0) return 0;
	if (a == 1) return 5000000;
	else if (a <= 3) return 3000000;
	else if (a <= 6) return 2000000;
	else if (a <= 10) return 500000;
	else if (a <= 15) return 300000;
	else if (a <= 21) return 100000;
	return 0;
}

int contest2(int a){
	if (a == 0) return 0;
	if (a == 1) return 5120000;
	else if (a <= 3) return 2560000;
	else if (a <= 7) return 1280000;
	else if (a <= 15) return 640000;
	else if (a <= 31) return 320000;
	return 0;

}



int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;
		int ret = contest1(a) + contest2(b);
		cout << ret << endl;
	}
}