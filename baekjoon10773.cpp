#include <stack>
#include <iostream>

using namespace std;

int main() {
	stack<int>s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 0) s.pop();
		else s.push(a);
	}
	
	int ret = 0;
	while (!s.empty()) {
		ret += s.top();
		s.pop();
	}
	cout << ret << endl;
	
}