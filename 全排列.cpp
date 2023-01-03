#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> permute(vector<int>& nums);
void backtrack(vector<vector<int>>& ans, vector<int>& nums, int first, int len);
int main() {
	vector<int>nums{ 1,2,3 };
	vector<vector<int>>ans = permute(nums);
	for (auto i : ans) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << "" << endl;
	}

	return 0;
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>>ans;
	int size = nums.size();
	backtrack(ans, nums, 0, size);
	return ans;
}

void backtrack(vector<vector<int>>&ans, vector<int>&nums, int first, int len) {
	if (first == len) {
		ans.push_back(nums);
		return;
	}
	for (int i = first; i < len; ++i) {
		swap(nums[i], nums[first]);
		backtrack(ans, nums, first + 1, len);
		swap(nums[i], nums[first]);
	}
}