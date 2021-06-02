#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 2000000;
int q[MAX_N];
int front = 0;
int back = 0;

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if(s=="push")
			cin >> q[back++%MAX_N];
		else if (s == "pop") {
			int a = -1;
			if(front-back!=0)
				a = q[front++%MAX_N];
			cout << a << "\n";
		}
		else if (s == "size")
			cout << abs(front-back) << "\n";
		
		else if (s == "empty") 
			cout << ( front-back==0 ? 1 : 0) << "\n";
		
		else if (s == "front") 
			cout << ( front-back==0? -1:q[front]) << "\n";

		else if (s == "back") 
			cout << ( front-back==0? -1:q[back-1]) << "\n";

		else 
			cout << "Error" << "\n";
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}