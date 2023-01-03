#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int singleNumber(vector<int>& nums);
int singleNumber_1(vector<int>& nums);
int main() {
	vector<int>nums{ 3,3,6,5,7,6,7 };
	int ans = singleNumber_1(nums);
	cout << ans << endl;

	return 0;
}

int singleNumber(vector<int>& nums) {
	int ans = 0;
	sort(nums.begin(), nums.end());
	if (nums.size() == 1) {
		return nums[0];
	}
	for (int i = 1; i < nums.size() - 1; i++) {
		if (nums[i - 1] != nums[i] && nums[i + 1] != nums[i]) {
			return nums[i];
		}
		else if (i + 1 == nums.size() - 1 && nums[i + 1] != nums[i]) {
			return nums[i + 1];
		}
		else if (i - 1 == 0 && nums[i - 1] != nums[i]) {
			return nums[0];
		}
	}

	return ans;
}

int singleNumber_1(vector<int>& nums) {
	int ret = 0;
	for (auto e : nums) {
		ret = ret ^ e;
	}
	return ret;
}
