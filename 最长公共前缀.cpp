#include<iostream>
#include<vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs);

int main() {
	//vector<string>strs{ "flower","flow","flight" };
	vector<string>strs{ "," };
	string ans;
	ans = longestCommonPrefix(strs);
	cout << ans << endl;

	return 0;
}

string longestCommonPrefix(vector<string>& strs) {

	if (!strs.size()) {
		return "";
	}
	
	for (int i = 0; i < strs[0].length(); ++i) {
		char c = strs[0][i];
		for (int j = 1; j < strs.size(); ++j) {
			if (i==strs[j].size() || strs[j][i] != c) {
				return strs[0].substr(0, i);
			}
			
		}

	}
	return strs[0];
}