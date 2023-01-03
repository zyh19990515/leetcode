#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<vector<int>> permuteUnique(vector<int>& nums);
void backtrack(vector<vector<int>>& ans, vector<int>& nums, int first, int len, unordered_set<vector<int>>R);
int main() {
	vector<int>nums{ 1,1,2 };
	vector<vector<int>>ans = permuteUnique(nums);


	return 0;
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>>ans;
	int size = nums.size();
	unordered_set<vector<int>>R;
	backtrack(ans, nums, 0, size, R);
	return ans;
}

void backtrack(vector<vector<int>>& ans, vector<int>& nums, int first, int len, unordered_set<vector<int>>R) {
	if (first == len) {
		if (R.find(nums)==R.end()) {
			ans.push_back(nums);
			R.insert(nums);
		}
		
		return;
	}
	for (int i = first; i < len; ++i) {
		swap(nums[i], nums[first]);
		backtrack(ans, nums, first + 1, len, R);
		swap(nums[i], nums[first]);
	}
}