#include<iostream>
#include<vector>

using namespace std;
int removeElement(vector<int>& nums, int val);
int main() {
	vector<int>nums{ 0,1,2,2,3,0,4,2 };
	int val = 2;
	int size = removeElement(nums, val);
	for (auto i : nums) {
		cout << i << " ";
	}
	return 0;
}

int removeElement(vector<int>& nums, int val) {
	int cnt = 0;
	for (auto i : nums) {
		if (i != val) {
			nums[cnt] = i;
			cnt++;
			//cout << i << endl;
		}
	}
	/*cout << cnt << endl;
	for (int i = 0; i < nums.size()-cnt+2; i++) {
		nums.pop_back();
	}*/
	//return nums.size();
	return cnt;
}