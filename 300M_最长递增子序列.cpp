#include<iostream>
#include<vector>

using namespace std;
int lengthOfLIS(vector<int>& nums);
int main() {
	
	vector<int>nums{ 10,9,2,5,3,7,101,18 };
	int ans = lengthOfLIS(nums);
	cout << ans << endl;

	return 0;
}

int lengthOfLIS(vector<int>& nums) {
	int ans = 1;
	vector<int>dp(nums.size(), 1);
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	for (int i = 0; i < nums.size(); i++) {
		ans = max(ans, dp[i]);
	}

	return ans;
}