#include <stack>
#include <iostream>

using namespace std;


string solve(char s[]) {
	stack<char> st;
	int i = 0;
	while(s[i] !='\0'){
		if (s[i] == '(' || s[i] == '[')
			st.push(s[i]);
		else if (s[i] == ')') {
			if (st.empty() || st.top() != '(') return "NO";
			st.pop();
		}
		else if(s[i] == ']'){
			if (st.empty() || st.top() != '[') return "NO";
			st.pop();
		}
		i++;
	}
	return st.empty() ? "YES" : "NO";
}



int main() {
	while (true) {
		char ch[102];
		cin.getline(ch, 102, '.');
		if (ch[0] == '\0') break;
		cout << solve(ch) << endl;
	}
}