#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target);
int main() {
	///vector<int>nums{ 1,0,-1,0,-2,2 };
	//vector<int>nums{2,2,2,2,2};
	//vector<int>nums{ 0,0,0,0 };
	//vector<int>nums{ -3,-1,0,2,4,5};
	vector<int>nums{ 100000000,100000000,100000000,100000000 };
	int target =0;
	vector<vector<int>>ans;
	ans = fourSum(nums, target);
	for (auto i : ans) {
		cout << i[0] << " " << i[1] << " " << i[2] << " " << i[3] << endl;
	}
	system("pause");
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	
	vector<vector<int>>ans;
	if (nums.size() < 4) {
		return ans;
	}
	for(int left=0;left<nums.size();left++)
	{	
		int right = nums.size() - 1;
		if (left > 0 && nums[left] == nums[left - 1]) {
				continue;
			}
		if (left > right) {
			return ans;
		}	
		while (left < right) {
			int i = left + 1;
			int j = right - 1;
			
			if (right < nums.size() - 1 && nums[right] == nums[right + 1]) {
				right--;
				continue;
			}
			while (i < j)
			{
				//double sum = nums[left] + nums[right] + nums[i] + nums[j];
				if ((long)nums[left] + nums[right] + nums[i] + nums[j] == target) {
					ans.push_back({ nums[left],nums[i],nums[j],nums[right] });
					while (i < j && nums[i] == nums[i + 1]) {
						i++;
					}
					while (i < j && nums[j] == nums[j - 1])
					{
						j--;
					}
					i++;
					j--;
				}
				else if ((long)nums[left] + nums[right] + nums[i] + nums[j] <= target) {
					i++;
				}
				else if ((long)nums[left] + nums[right] + nums[i] + nums[j] > target) {
					j--;
				}
			}
			right--;
		}
	}
	return ans;
}