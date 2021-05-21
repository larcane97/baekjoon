#include <iostream>
#include <vector>

using namespace std;

struct stack {
	int arr[100001];
	int pointer;
	stack(){
		pointer = 0;
		arr[0] = -1;
	};

	void push(int x) {
		arr[++pointer] = x;
	}
	int pop() {
		int ret=arr[pointer];
		pointer = max(pointer - 1, 0);
		return ret;
	}
	int size() {
		return pointer;
	}
	int empty() {
		return pointer==0?1:0;
	}
	int top() {
		return arr[pointer];
	}

};

int main() {
	int n;
	cin >> n;
	stack s;
	for (int i = 0; i < n; i++) {
		string commend;
		int x;
		cin >> commend;
		if (commend == "push") {
			cin >> x;
			s.push(x);
		}
		else if (commend == "pop")
			cout << s.pop() << endl;
		else if (commend == "size")
			cout << s.size() << endl;
		else if (commend == "empty")
			cout << s.empty() << endl;
		else if (commend == "top")
			cout << s.top() << endl;
		else
			cout << "wrong commend !!" << endl;
	}
}