#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
bool containsDuplicate(vector<int>& nums);
bool containsDuplicate_1(vector<int>& nums);
int main() {
	vector<int>nums{ 1,2,1,3 };
	bool ans = containsDuplicate_1(nums);
	cout << ans << endl;

	return 0;
}

bool containsDuplicate(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size()-1; i++) {
		if (nums[i] == nums[i + 1]) {
			return true;
		}
	}
	return false;
}

bool containsDuplicate_1(vector<int>& nums) {
	unordered_set<int>s;
	for (int x : nums) {
		if (s.find(x) != s.end()) {
			return true;
		}
		
		s.insert(x);
	}
	return false;
}