#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_N = 10000;
int deq[MAX_N];
int front = 0, back = 0, deq_size = 0;

int calcIndex(int a) {
	return (a + MAX_N) % MAX_N;
}

void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s=="push_front") {
			int a;
			cin >> a;
			deq[front = calcIndex(front-1)] = a;
			deq_size++;
		}
		else if (s == "push_back") {
			int a;
			cin >> a;
			deq[back] = a;
			back = calcIndex(back + 1);
			deq_size++;
		}
		else if (s == "pop_front") {
			if (deq_size == 0)
				cout << -1 << "\n";
			else {
				cout << deq[front] << "\n";
				front = calcIndex(front + 1);
				deq_size--;
			}
		}
		else if (s == "pop_back") {
			if (deq_size == 0) 
				cout << -1 << "\n";
			else {
				cout << deq[back = calcIndex(back - 1)] << "\n";
				deq_size--;
			}
		}
		else if (s == "size") {
			cout << deq_size << "\n";
		}
		else if (s == "empty") {
			cout << (deq_size == 0 ? 1 : 0) << "\n";
		}
		else if (s == "front") {
			cout << (deq_size==0?-1:deq[front]) << "\n";
		}
		else if(s == "back") {
			cout << (deq_size==0? -1 : deq[calcIndex(back - 1)]) << "\n";
		}
		else {
			cout << "wrong commend" << "\n";
			i--;
		}

	}
}

int main() {
	solve();
}