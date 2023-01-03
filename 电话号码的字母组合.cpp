#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<string> letterCombinations(string digits);
vector<string> combineLetters(vector<string>temp, string s);
int main() {
	string digits = "23";
	vector<string>ans = letterCombinations(digits);
	for (auto i : ans) {
		cout << i << endl;
	}

	return 0;
}

vector<string> letterCombinations(string digits) {
	vector<string>ans;
	unordered_map<string, string>numToletter{
		{"2", "abc"},
		{"3", "def"},
		{"4", "ghi"},
		{"5", "jkl"},
		{"6", "mno"},
		{"7", "pqrs"},
		{"8", "tuv"},
		{"9", "wxyz"},
	};
	if (digits.length() == 0) {
		return ans;
	}
	if (digits.length() == 1) {
		string temp = numToletter[digits];
		for (int i = 0; i < temp.length();i++) {
			string t(1, temp[i]);
			ans.push_back(t);
		}
		return ans;
	}
	int ptr = 0;
	vector<string>temp;
	while (ptr<digits.length()){
		
		string s(1, digits[ptr]);
		string str = numToletter[s];
		temp = combineLetters(temp, str);
		ptr++;
	}

	
	
	return temp;
}

vector<string> combineLetters(vector<string>temp, string s) {
	vector<string>t;
	if (temp.empty()) {
		for (char i : s) {
			string temp(1, i);
			t.push_back(temp);
		}
		return t;
	}
	for (auto i : temp) {
		string str_i = i;
		int s_size = str_i.length();
		for (auto j : s) {
			string str_j(1, j);
			string ans = str_i + str_j;
			t.push_back(ans);
		}
	}


	return t;
}