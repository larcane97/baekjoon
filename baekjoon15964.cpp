#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;


int n, k;
double avg;
vector<double>dolls;

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		double pref;
		cin >> pref;
		avg += pref;
		dolls.push_back(pref);
	}
	sort(dolls.begin(), dolls.end());
}

double solve() {
	double min = 987654321;
	for (int i = 0; i <= n - k; i++) {
		double tmp = 0;
		double avg = 0;
		for (int j = i; j < i + k; j++)
			avg += dolls[j];
		avg /= k;

		for (int j = i; j < i + k; j++)
			tmp += (dolls[j]- avg) * (dolls[j]- avg);
		tmp /= k;
		if (tmp < min) min = tmp;
	}
	return sqrt(min);
}

int main() {
	input();
	printf("%.8f\n", solve());

}