#include<iostream>
#include<vector>

using namespace std;
int removeDuplicates(vector<int>& nums);
int main() {
	vector<int>nums{ 1,1,1,2,2,3 };
	int size = removeDuplicates(nums);
	for (auto i : nums) {
		cout << i << " ";
	}
	return 0;
}

int removeDuplicates(vector<int>& nums) {
	int cnt = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (cnt < 2 || nums[i] != nums[cnt - 2]) {
			nums[cnt++] = nums[i];
		}
	}
	return cnt;
}