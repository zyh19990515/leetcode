#include<iostream>
#include<vector>
using namespace std;
int searchInsert(vector<int>& nums, int target);
int main() {
	vector<int>nums{ 1,3,5,6 };
	int target = 0;
	int ans = searchInsert(nums, target);
	cout << ans << endl;

}
int searchInsert(vector<int>& nums, int target) {
	
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == target) {
			return i;
		}
		else if (nums[i] > target) {
			return i;
		}
	}
	return nums.size();
}