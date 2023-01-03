#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);

int main() {
	//vector<int>nums{ -1, 0, 1, 2, -1,-4 };
	//vector<int>nums{ 0,0,0 };
	//vector<int>nums{ -1,0,1 };
	//nums = numSort(nums);
	vector<int>nums{ 0,0,0,0 };
	for (auto i : nums) {
		cout << i << endl;
	}
	vector<vector<int>>answer = threeSum(nums);
	for (auto i : answer) {
		cout << i[0] << " ";
		cout << i[1] << " ";
		cout << i[2] << endl;
	}
	system("pause");
	return 0;
}

vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>>answer;
	if (nums.size() < 3) {
		return answer;
	}
	for (int i = 0; i < nums.size(); i++) {
		int j = i + 1;
		int k = nums.size() - 1;
		if (nums[i]>0) {
			return answer;
		}
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		while (j<k)
		{
			int sum = nums[i] + nums[j] + nums[k];
			if (sum == 0) {
				answer.push_back({ nums[i],nums[j],nums[k]});
				while (j<k && nums[j]==nums[j+1]){
					j++;
				}
				while (j<k && nums[k]==nums[k-1]){
					k--;
				}
				j++;
				k--;
			}
			else if (sum < 0) {
				j++;
			}
			else if (sum > 0) {
				k--;
			}
		}


	}
	
	return answer;
}
