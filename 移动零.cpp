#include<iostream>
#include<vector>

using namespace std;
void moveZeroes_1(vector<int>& nums);
void moveZeroes_2(vector<int>& nums);
int main() {
	vector<int>nums{ 0,1,0,3,12 };
	//moveZeroes_1(nums);
	moveZeroes_2(nums);
	for (auto i : nums) {
		cout << i << " ";
	}

	return 0;
}
//判断0元素的位置，使用erase操作删除
void moveZeroes_1(vector<int>& nums) {
	vector<int>pos;
	int cnt = 0;
	for (int i = nums.size()-1; i >=0; i--) {
		if (nums[i] == 0) {
			pos.push_back(i);
			cnt++;
		}
	}
	for (auto i : pos) {
		nums.erase(nums.begin() + i);
	}
	for (int i = 0; i < cnt; i++) {
		nums.push_back(0);
	}
}

//将不是0的元素排在前面，后面补0
void moveZeroes_2(vector<int>& nums) {
	int cnt = 0;
	for (auto i : nums) {
		if (i) {
			nums[cnt] = i;
			cnt++;
		}
	}
	for (int i = cnt; i < nums.size(); i++) {
		nums[i] = 0;
	}
}