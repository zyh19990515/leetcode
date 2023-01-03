#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;
bool isValid(string s);
int main() {
	string s = "()[]{)";
	bool ans = isValid(s);
	cout << ans << endl;
	return 0;
}

bool isValid(string s) {
	int n = s.length();
	if (n % 2 == 1) {
		return false;
	}
	unordered_map<char, char>pairs = {
		{')','('},
		{']','['},
		{'}','{'}
	};
	stack<int>stk;
	for (char ch : s) {
		if (pairs.count(ch)) {
			if (stk.empty() || stk.top() != pairs[ch]) {
				return false;
			}
			stk.pop();
		}
		else{
			stk.push(ch);
		}
	}
	return stk.empty();
}