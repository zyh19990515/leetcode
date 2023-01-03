#include<iostream>
#include<vector>

using namespace std;
int search(vector<int>& nums, int target);
int main() {
	vector<int>nums{ 1,3 };
	int target = 2;
	int ans = search(nums, target);
	cout << ans << endl;

	return 0;
}

int search(vector<int>& nums, int target) {
	if (nums.size() == 1) {
		if (nums[0] != target) {
			return -1;
		}
		else{
			return 0;
		}
	}
	int last = nums.size() - 1;
	if (target < nums[0]) {
		for (int i = last; i > 0; i--) {
			int last_2 = i - 1;
			if (target > nums[i]) {
				return -1;
			}
			if (target == nums[i]) {
				return i;
			}
			else if ((nums[last_2] > nums[i])){
				return -1;
			}
			
		}
	}
	else if (target == nums[0]) {
		return 0;
	}
	else if (target > nums[0]) {
		for (int i = 0; i <= last-1; i++) {
			int next = i + 1;
			if (target == nums[i]) {
				return i;
			}
			if (nums[i] > nums[next]) {
				return -1;
			}
		}
	}
	return -1;
}