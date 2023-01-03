#include<iostream>

using namespace std;
int lengthOfLastWord(string s);
int main() {
	//string s = "Hello World";
	string s = "day";
	int ans = lengthOfLastWord(s);
	cout << ans << endl;
	return 0;
}

int lengthOfLastWord(string s) {
	int n;
	int cnt=0;
	for (int i = s.length() - 1; i > 0; i--) {
		if (s[i] == ' ') {
			s = s.substr(0,s.length()-1);
		}
		else {
			break;
		}
	}
	if (s.length() == 1) {
		return 1;
	}
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			n = i;
			cnt++;
		}
	}
	if (cnt == 0) {
		return s.length();
	}
	return s.length()-1-n;
}
