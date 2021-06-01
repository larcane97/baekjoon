#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
vector<int> arr;
vector<char>ret;

bool solve() {
	stack<int> st;

	int i, cur;
	for (i = 1, cur = 0; i <= arr.size() || cur < arr.size();) {
		if (i <= arr.size() && (st.empty() || st.top() < arr[cur])) {
			st.push(i);
			ret.push_back('+');
			i++;
		}
		else if (cur < arr.size() && st.top() == arr[cur]) {
			st.pop();
			ret.push_back('-');
			cur++;
		}
		else return false;
	}
	return i == cur + 1 ? true : false;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

}

int main() {
	input();
	if (solve())
		for (int i = 0; i < ret.size(); i++)
			cout << ret[i] << "\n";
	else
		cout << "NO" << "\n";
}