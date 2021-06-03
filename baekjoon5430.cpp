#include <iostream>
#include <deque>
#include <string>
#include <vector>
using namespace std;




deque<int> input_string2num_to_deque(string arrString);

void solve() {
	int T;
	cin >> T;
	for (int iter = 0; iter < T; iter++) {
		int n;
		string p,arrString;
		cin >> p;
		cin >> n;
		cin >> arrString;
		deque<int>deq = input_string2num_to_deque(arrString);

		// flag==true : front
		// flag==false : back
		bool flag = true;
		bool error = false;
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R')
				flag = !flag;
			else {
				// error
				if (deq.empty()) {
					error = true;
					break;
				}
				// pop
				if (flag)
					deq.pop_front();
				else
					deq.pop_back();
			}
		}

		if (error)
			cout << "error" << "\n";
		else {
			cout << '[';
			if (flag&&!deq.empty()) {
				for (auto i = deq.begin(); i != (deq.end()- 1); i++)
					cout << *i << ',';
				cout << deq.back() << ']' << "\n";
			}
			else if(!flag && !deq.empty()){
				for (auto i = deq.end()-1; i !=deq.begin(); i--)
					cout << *i << ',';
				cout << deq.front() << ']' << "\n";
			}
			else {
				cout << ']' << "\n";
			}
		}
	}
}

int main() {
	solve();
}

deque<int> input_string2num_to_deque(string arrString) {
	deque<int>deq;
	arrString = arrString.substr(1, arrString.size() - 2);
	int num = -1;
	for (int i = 0; i < arrString.size();i++) {
		if (arrString[i] == ',') {
			deq.push_back(num);
			num = -1;
		}
		else {
			if (num == -1)
				num = (arrString[i]) - '0';
			else
				num = num * 10 + (arrString[i] - '0');
		}
	}
	if (num != -1) deq.push_back(num);
	return deq.empty()? deque<int>():deq;
}