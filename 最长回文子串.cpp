#include<iostream>
#include<vector>
using namespace std;

string longestPalindrome(string s);
bool isPalindrome(string s);
int main() {
	string s = "abcda";
	string ans = longestPalindrome(s);
	cout << ans << endl;

	return 0;
}

string longestPalindrome(string s) {
	int size = s.size();
	bool state;
	string ans;
	vector<string>str;

	int ans_size = 0;
	if (size == 1) {
		return s;
	}
	else if (size == 2) {
		if (s[0] != s[1]) {
			s = s.erase(1);
			return s;
		}
		else {
			return s;
		}
	}
	
	for (int i = 0; i < size; i++) {
		for (int j = size - 1; j > i; j--) {
			if (s[i] == s[j]) {
				string s_t = s.substr(i, j-i+1);
				//cout << s_t << endl;
				state = isPalindrome(s_t);
				if (state == true) {
					if (s_t.size() > ans_size) {
						ans = s_t;
						ans_size = s_t.size();
					}
				}
			}
		}
	}
	if (ans_size == 0) {
		ans = s.substr(0, 1);
	}
	return ans;
}

bool isPalindrome(string s) {
	bool state = true;
	int start = 0;
	int size = s.size();
	int end = size - 1;
	//cout << s << endl;
	while (state){
		if (s.size() % 2 == 0) {
			if (s[start] == s[end]) {
				start++;
				end--;
			}
			else if (s[start] != s[end]) {
				state = false;
			}
			if (start > end) {
				return true;
			}
		}
		else if (s.size() % 2 != 0) {
			if (s[start] == s[end]) {
				start++;
				end--;
			}
			else if (s[start] != s[end]) {
				state = false;
			}
			if (start > end-2) {
				return true;
			}
		}
	}
	return false;
}