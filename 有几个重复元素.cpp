#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int majorityElement(vector<int>& nums);
int main() {
	vector<int>nums{ 4,4,5,3,3,3,6,7,8,1,1,1,2,2,2 };
	int ans = majorityElement(nums);
	cout << ans << endl;

	return 0;
}

int majorityElement(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	if (nums.size() == 1) {
		return 1;
	}
	int cnt = 0;
	int pos = 0;
	for (int i = 0; i < nums.size() - 1; i++) {
		if (nums[i] != nums[i + 1] && i != pos) {
			pos = i + 1;
			cnt++;
		}
		else if (nums[i] ==nums[i+1] && i == nums.size() - 2 && pos != i) {
			cnt++;
		}
		else if (nums[i] != nums[i+1]) {
			pos = i+1;
		}
	}
	return cnt;
}