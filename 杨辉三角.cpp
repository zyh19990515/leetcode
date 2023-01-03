#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> generate(int numRows);
int main() {
	int numRows = 5;
	vector<vector<int>>ans = generate(numRows);
	for (auto i : ans) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << "" << endl;
	}

	return 0;
}

vector<vector<int>> generate(int numRows) {
	vector<int>orin{1};
	vector<vector<int>>ans;
	ans.push_back(orin);
	if (numRows == 1) {
		return ans;
	}
	else if (numRows == 2) {
		orin.push_back(1);
		ans.push_back(orin);
		return ans;
	}
	else {
		orin.push_back(1);
		ans.push_back(orin);
		for (int i = 2; i < numRows; i++) {
			vector<int>temp;
			for (int j = 0; j <= i; j++) {
				if (j == 0) {
					temp.push_back(1);
				}
				else if (j == i) {
					temp.push_back(1);
				}
				else {
					temp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
				}
				
			}
			ans.push_back(temp);
		}
	}
	return ans;
}