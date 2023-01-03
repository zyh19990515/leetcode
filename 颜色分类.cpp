#include<iostream>
#include<vector>

using namespace std;
void sortColors_1(vector<int>& nums);
void sortColors_2(vector<int>& nums);
int main() {
	vector<int>nums{ 2,0,2,1,1,0 };
	//sortColors_1(nums);
	sortColors_2(nums);
	for (auto i : nums) {
		cout << i << " ";
	}
}

void sortColors_1(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums.size(); j++) {
			if (nums[i] < nums[j]) {
				int temp;
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
}

void sortColors_2(vector<int>& nums) {
	vector<int>zero;
	vector<int>one;
	vector<int>two;
	
	for (auto i : nums) {
		if (i == 0) {
			zero.push_back(0);
		}
		else if (i == 1) {
			one.push_back(1);
		}
		else {
			two.push_back(2);
		}
	}
	nums.clear();
	for (int i = 0; i < zero.size(); i++) {
		nums.push_back(zero[i]);
	}
	for (int i = 0; i < one.size(); i++) {
		nums.push_back(one[i]);
	}
	for (int i = 0; i < two.size(); i++) {
		nums.push_back(two[i]);
	}

}