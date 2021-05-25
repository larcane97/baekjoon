#include <iostream>
#include <vector>
#include <string>
using namespace std;





string input() {
	string s;
	cin >> s;
	return s;
}

vector<int> string2arr(string s){
	vector<int> arr;
	int digit = 1;
	int num = 0;
	bool minus = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-' || s[i] == '+') {
			if (minus) num *= -1;
			arr.push_back(num);
			digit = 1;
			num = 0;
			if (s[i] == '-') minus = true;
			else minus = false;
		}
		else {
			if (s[i] == '0' && digit == 1)continue;
			num = (num*digit) + (s[i] - '0');
			digit *= 10;
		}
	}
	arr.push_back(num);
	return arr;
}

int solve(vector<int>arr) {
	int ret = 0;
	// 마이너스가 나오기 전까지 결과값에 그대로 더하기
	// 마이너스가 나올 경우, 다음 마이너스가 나오기 전까지 계속 빼기
	int i = 0;
	while(i<arr.size()){
		if (arr[i] < 0) {
			int tmp = -arr[i];
			while (true) {
				i++;
				if (i < arr.size() && arr[i] >= 0)
					tmp += arr[i];
				else break;
			}
			ret -= tmp;
		}
		else {
			ret += arr[i];
			i++;
		}
		
	}
	return ret;
}


int main() {
	string s = input();
	vector<int> arr = string2arr(s);
	cout << solve(arr) << endl;

}