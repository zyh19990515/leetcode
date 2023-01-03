#include<iostream>
#include<vector>

using namespace std;
bool canJump(vector<int>& nums);
int main() {
	vector<int>nums{ 2,3,1,1,4 };
	bool ans = canJump(nums);
	cout << ans << endl;

	return 0;
}

bool canJump(vector<int>& nums) {
	int ptr = 0;
	int goal = nums.size() - 1;
	for (int i = 0; i <= goal; i++) {
		if (i <= ptr) {
			ptr = max(ptr, i + nums[i]);
		}
		if (ptr >= goal) {
			return true;
		}
	}
	return false;
}