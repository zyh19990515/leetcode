#include<iostream>
#include<vector>
using namespace std;
int findKthLargest(vector<int>& nums, int k);
int findKthLargest_2(vector<int>& nums, int k);
int main() {
	vector<int>nums{ 3,2,1,5,6,4 };
	int k = 2;
	int ans = findKthLargest(nums, k);
	cout << ans << endl;
}

int findKthLargest_1(vector<int>& nums, int k) {
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums.size(); j++) {
			if (nums[i] > nums[j]) {
				int temp;
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
	return nums[k-1];
}

