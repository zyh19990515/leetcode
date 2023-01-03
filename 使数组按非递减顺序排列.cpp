#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int totalSteps(vector<int>& nums);
bool isDcrease_1(vector<int>nums);
int removeNum(vector<int>& nums);
int main() {
	vector<int>nums{ 5,3,4,4,7,3,6,11,8,5,11 };
	//vector<int>nums{ 10,1,2,3,4,5,6,1,2,3 };
	//vector<int>nums{ 7,14,4,14,13,2,6,13 };
	//vector<int>nums{ 4,5,7,7,13 };
	//int ans = totalSteps(nums);
	int ans = removeNum(nums);
	cout << ans << endl;
	return 0;
}

int totalSteps(vector<int>& nums) {
	
	bool judgeNum = isDcrease_1(nums);
	int cnt = 0;
	while (judgeNum)
	{
		removeNum(nums);
		judgeNum = isDcrease_1(nums);
		cnt++;
	}
	
	return cnt;
}
/*_1是原始解法，数据量过大时会超时*/
bool isDcrease_1(vector<int>nums) {
	for (int i = nums.size() - 1; i > 0; i--) {
		if (nums[i] < nums[i - 1]) {
			return true;
		}
	}
	return false;
}

void removeNum_1(vector<int>& nums) {
	vector<int>pos;
	for (int i = nums.size() - 1; i > 0; i--) {
		if (nums[i] < nums[i - 1]) {
			pos.push_back(i);
		}
	}
	for (auto i : pos) {
		nums.erase(nums.begin() + i);
	}
}

//int removeNum(vector<int>& nums) {
//	int max = 0;
//	int cnt = 0;
//	int pos = 0;
//	int j = 0;
//	for (int i = 0; i < nums.size()-1; i++) {
//		if (nums[i-pos] > nums[i + 1]) {
//			if (i != 0 && cnt != 0 && nums[i] > nums[i + 1]) {
//				j++;
//				pos++;
//				continue;
//			}
//			if (i != 0 && cnt != 0 && nums[i - j] > nums[i]) {
//				j++;
//				pos++;
//				continue;
//			}
//			cnt++;
//			pos++;
//			if (max < cnt) {
//				max = cnt;
//			}
//			
//		}
//		else {
//			
//			cnt = 0;
//			pos = 0;
//			
//		}
//	}
//	return max;
// }

int removeNum(vector<int>& nums) {
	int cnt = 0;
	int pos = 0;
	int cnt_main=0;
	int cnt_sub = 0;
	for (int i = 0; i < nums.size() - 1; i++) {
		if (nums[i - pos] > nums[i + 1]) {
			cnt_main++;

			if (nums[i] > nums[i + 1]) {
				cnt_sub++;
			}
			pos++;
		}
		else {
			pos = 0;
		}
	}
	//cout << cnt_main << endl;
	return cnt_main - cnt_sub+1;
}