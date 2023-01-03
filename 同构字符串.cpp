#include<iostream>
#include<unordered_map>

using namespace std;
bool isIsomorphic(string s, string t);
int main() {
	string s = "egg";
	string t = "add";
	bool ans = isIsomorphic(s, t);
	cout << ans << endl;
}

bool isIsomorphic(string s, string t) {
	unordered_map<char, char>s2t;
	unordered_map<char, char>t2s;
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		char x = s[i];
		char y = t[i];
		if ((s2t.count(x) && s2t[x] != y) || t2s.count(y) && t2s[y] != x) {
			return false;
		}
		s2t[x] = y;
		t2s[y] = x;
	}
	return true;
}