#include<iostream>

using namespace std;
int strStr(string haystack, string needle);
int main() {
	/*string haystack = "hello";
	string needle = "ll";*/
	string haystack = "abc";
	string needle = "c";
	int ans = strStr(haystack, needle);
	cout << ans << endl;
	return 0;
}

int strStr(string haystack, string needle) {
	char n = needle[0];
	int len = needle.length();
	if (haystack == needle) {
		return 0;
	}
	for (int i = 0; i < haystack.length();i++) {
		if (haystack[i] == n) {
			if (haystack.substr(i, len) == needle) {
				return i;
			}
			else
			{
				continue;
			}
		}
	}
	return -1;
}