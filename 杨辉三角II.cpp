#include<iostream>
#include<vector>

using namespace std;
vector<int> getRow(int rowIndex);
int main() {
	int rowIndex = 6;
	vector<int>ans = getRow(rowIndex);
	for (auto i : ans) {
		cout << i << " ";
	}

	return 0;
}

vector<int> getRow(int rowIndex) {
	int numRows = rowIndex + 1;
	vector<int>orin{ 1 };
	vector<vector<int>>ans;
	ans.push_back(orin);
	if (numRows == 1) {

		return orin;
	}
	else if (numRows == 2) {
		orin.push_back(1);
		return orin;
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
			if (i == numRows - 1) {
				return temp;
			}
		}
	}
}