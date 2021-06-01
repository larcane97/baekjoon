#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> arr;
int n;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
}

void solve() {
	vector<int> ret(n);
	stack<int>st;
	for (int i = arr.size() - 1; i >= 0; i--) {
		while (true) {
			if (st.empty()) {
				ret[i] = -1;
				st.push(arr[i]);
				break;
			}
			if (st.top() > arr[i]) {
				ret[i] = st.top();
				st.push(arr[i]);
				break;
			}
			else
				st.pop();
		}
	}

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
	cout << "\n";

}

int main() {
	input();
	solve();
}

