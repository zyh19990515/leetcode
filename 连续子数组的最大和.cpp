#include<iostream>
#include<vector>

using namespace std;
int maxSubArray(vector<int>& nums);
int main() {
	vector<int>nums{ -1, -2 };
	int ans = maxSubArray(nums);
	cout << ans << endl;
}

//v1.0
int maxSubArray_1(vector<int>& nums) {
	int size = nums.size();
	if (size == 0) return 0;
	if (size == 1) return (nums[0]);
	vector<int>dp(size, INT16_MIN);
	dp[0] = nums[0];
	for (int i = 1; i < size; i++) {
		dp[i] = max(nums[i], nums[i] + dp[i - 1]);
	}
	int res = INT16_MIN;
	for (int i = 0; i < size; i++) {
		res = max(res, dp[i]);
	}
	return res;
}

int maxSubArray(vector<int>& nums) {
	int size = nums.size();
	int dp_0 = nums[0];
	int dp_1 = 0;
	int res = dp_0;
	if (size == 0) return 0;
	if (size == 1) return dp_0;
	for (int i = 1; i < size; i++) {
		dp_1 = max(nums[i], nums[i] + dp_0);
		dp_0 = dp_1;
		res = max(res, dp_1);
	}

	return res;
}