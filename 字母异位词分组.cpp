#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs);
void backtrck(int ptr, vector<string>& strs, vector<vector<string>>& ans, unordered_set<string>& all_strs, unordered_set<int>& num_i);
int main() {
	vector<string>strs{ "eat", "tea", "tan", "ate", "nat", "bat" };

	vector<vector<string>>ans = groupAnagrams(strs);
	for (auto i : ans) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << "" << endl;
		
	}



	return 0;
}


vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>>ans;
	unordered_set<int>num_i;
	
	for (int i = 0; i < strs.size(); i++) {
		vector<string>temp;
		if (num_i.find(i) == num_i.end()) {
			temp.push_back(strs[i]);
		}
		int ori[26] = { 0 };
		for (int j = 0; j < strs[i].size(); j++) {
			ori[strs[i][j] - 'a']++;
		}
		for (int j = i+1; j < strs.size(); j++) {
			int cnt = 0;
			if (num_i.find(i) != num_i.end()) {
				break;
			}
			int judge[26]={0};
			for (int k = 0; k < strs[j].size(); k++) {
				judge[strs[j][k] - 'a']++;
			}
			for (int k = 0; k < 26; k++) {
				if (ori[k] == judge[k]) {
					cnt++;
				}
			}
			if (cnt == 26) {
				temp.push_back(strs[j]);
				num_i.insert(j);
			}
		}
		if (!temp.empty()) {
			ans.push_back(temp);
		}
		
	}

	return ans;
}


vector<vector<string>> groupAnagrams_1(vector<string>& strs) {
	//int ptr = 0;
	vector<vector<string>>ans;
	vector<string>temp;
	unordered_set<string>all_strs;
	unordered_set<int>num_i;
	if (strs.size() <= 1) {
		ans.push_back(strs);
		return ans;
	}
	for (int i = 0; i < strs.size(); i++) {
		if (strs[i].size() == 0) {
			temp.push_back(strs[i]);
		}
		if (num_i.find(i)!=num_i.end()) {
			continue;
		}
		backtrck(i, strs, ans, all_strs, num_i);

	}
	if (temp.size() != 0) {
		ans.push_back(temp);
	}
	
	return ans;
}

void backtrck(int ptr, vector<string>& strs, vector<vector<string>>& ans, unordered_set<string>& all_strs, unordered_set<int>& num_i) {
	string tem = strs[ptr];
	vector<string>temp;
	unordered_set<char>charmap;

	for (auto i : tem) {
		if (charmap.find(i) == charmap.end()) {
			charmap.insert(i);
		}
		
	}
	
	for (int i = ptr; i < strs.size(); i++) {
		
		if (tem.size() != strs[i].size()) {
			continue;
		}
		
		int cnt = 0;
		for (int j = 0; j < strs[i].size();j++) {
			
			if (charmap.find(strs[i][j]) == charmap.end()) {
				break;
			}
			cnt++;
			if (cnt == tem.size() ) {
				temp.push_back(strs[i]);
				all_strs.insert(strs[i]);
				num_i.insert(i);
			}
		}
		
		
		
	}
	if (!temp.empty()) {
		ans.push_back(temp);
	}
	

}