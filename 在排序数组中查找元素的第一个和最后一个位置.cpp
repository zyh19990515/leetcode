#include<iostream>
#include<vector>

using namespace std;
vector<int> searchRange(vector<int>& nums, int target);
int main() {
	vector<int>nums{ 2,2 };
	int target = 2;
	vector<int>ans = searchRange(nums, target);
	for (auto i : ans) {
		cout << i << endl;
	}

	return 0;
}

vector<int> searchRange(vector<int>& nums, int target) {
	int l = 0;
	int r = nums.size() - 1;
	vector<int>ans(2);
	int temp_l = -1;
	int temp_r = -1;
	if (nums.size() == 0) {
		ans[0] = -1;
		ans[1] = -1;
		return ans;
	}
	else if (target < nums[0]) {
		ans[0] = -1;
		ans[1] = -1;
		return ans;
	}
	else if (target > nums[r]) {
		ans[0] = -1;
		ans[1] = -1;
		return ans;
	}
	else if (nums.size() == 1 && nums[0] == target) {
		ans[0] = 0;
		ans[1] = 0;
		return ans;
	}
	else if (nums.size() == 1 && nums[0] != target) {
		ans[0] = -1;
		ans[1] = -1;
		return ans;
	}
	if (target - nums[0] <= nums[r] - target) {
		int start = 0;
		while (true){
			if (nums[start] == target) {
				if (temp_l == -1) {
					temp_l = start;
				}
				else {
					if (start==nums.size()-1 || nums[start + 1] != target) {
						temp_r = start;
						break;
					}
					else {
						start++;
					}
				}
			}
			else {
				if (nums[start + 1] > target) {
					ans[0] = -1;
					ans[1] = -1;
					return ans;
				}
				else {
					start++;
				}
				
			}

		}
	}
	else {
		int start = nums.size() - 1;
		while (true)
		{
			if (nums[start] == target) {
				if (temp_r == -1) {
					temp_r = start;
				}
				else {
					if (start==0 || nums[start - 1] != target) {
						temp_l = start;
						break;
					}
					else {
						start--;
					}
				}
			}
			else {
				if (nums[start -1] < target) {
					ans[0] = -1;
					ans[1] = -1;
					return ans;
				}
				else {
					start--;
				}
			}
		}
	}
	ans[0] = temp_l;
	ans[1] = temp_r;

	return ans;

}

//以下是二分法

int getRightBorder(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	int rightBorder = -2;
	while (left <= right)
	{
		int mid = left + ((right - left) / 2);
		if (target < nums[mid])
		{
			right = mid - 1;
		}
		else if (target >= nums[mid])
		{
			left = mid + 1;
			rightBorder = left;
		}
	}
	return rightBorder;
}
int getLeftBorder(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	int leftBorder = -2;
	while (left <= right)
	{
		int mid = left + ((right - left) / 2);
		if (target <= nums[mid])
		{
			right = mid - 1;
			leftBorder = right;
		}
		else if (target > nums[mid])
		{
			left = mid + 1;
		}
	}
	return leftBorder;
}

vector<int> searchRange(vector<int>& nums, int target) {
	int rightBorder = getRightBorder(nums, target);
	int leftBorder = getLeftBorder(nums, target);
	if (leftBorder == -2 || rightBorder == -2) return { -1,-1 };
	if (rightBorder - leftBorder > 1) return { leftBorder + 1,rightBorder - 1 };
	return { -1,-1 };
}