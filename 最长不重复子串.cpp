#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int lengthOfLongestSubstring(string s);
int main() {
	string s = "pwwkew";
	int ans = lengthOfLongestSubstring(s);
	cout << ans << endl;
	return 0;
}

string findString(string s, int left, int right) {
	unordered_set<char>tmp;
	tmp.insert(s[left]);
	string tmp_s;
	tmp_s += s[left];
	while (right<=s.length()-1)
	{	
		if (tmp.find(s[right]) == tmp.end()) {
			tmp.insert(s[right]);
			tmp_s += s[right];
		}
		else
		{
			break;
		}
		right++;
	}
	return tmp_s;
}

int lengthOfLongestSubstring(string s) {
	int ans = 1;
	int left = 0;
	int right = 1;
	while (left<s.length()-1)
	{
		if (s[left] == s[right]) {
			left++;
			right = left + 1;
			continue;
		}
		string tmp = findString(s, left, right);
		cout << tmp << endl;
		if (tmp.length() > ans) {
			ans = tmp.length();
			//left = right;
			//right = left + 1;
			
		}
		left++;
		right = left + 1;
	}

	return ans;
}