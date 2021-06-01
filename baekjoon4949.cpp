#include <stack>
#include <iostream>
#include <string>

using namespace std;


string solve(string s) {
	stack<char> st;
	
	for (string::iterator it = s.begin(); it != s.end(); it++) {
		if ( *it == '(' || *it == '[')
			st.push(*it);
		else if (*it == ')') {
			if (st.empty() || st.top() != '(') return "no";
			st.pop();
		}
		else if (*it == ']') {
			if (st.empty() || st.top() != '[') return "no";
			st.pop();
		}

	}
	return st.empty() ? "yes" : "no";
}



int main() {
	while (true) {
		string ch;
		getline(cin, ch);
		if (ch.size()==1 && ch[0]=='.') break;
		cout << solve(ch) << endl;
	}
}