#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int majorityElement(vector<int>& nums);
int main() {
	vector<int>nums{ 2,2,1,1,1,2,2 };
	int ans = majorityElement(nums);
	cout << ans << endl;

	return 0;
}

int majorityElement(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int ans = 0;
	int pos = 0;
	int cnt = 0;
	if (nums.size() == 1) {
		return nums[0];
	}
	for (int i = 0; i < nums.size(); i++) {
		if (i == 0) {
			ans = nums[i];
		}
		else if (i == nums.size() - 1) {
			if (nums[i] == nums[i - 1]) {
				if (i - pos + 1 > cnt) {
					ans = nums[i];
					cnt = i - pos + 1;
				}
			}
			else {
				break;
			}
		}
		else {
			if (nums[i] != nums[i + 1]) {
				if (i + 1 - pos > cnt) {
					
					cnt = i + 1 - pos;
					ans = nums[i];
					
				}
					pos = i + 1;
			}
		}
	}
	return ans;
}