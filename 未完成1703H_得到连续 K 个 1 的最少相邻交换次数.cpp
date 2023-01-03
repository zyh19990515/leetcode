#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minMoves(vector<int>& nums, int k);

int main() {
	vector<int>nums{ 0,1,0,0,1,1,0,1,0,1,1,1,1,0,1,0 };
	int k = 7;
	int ans = minMoves(nums, k);
	cout << ans << endl;

	return 0;
}

int minMoves(vector<int>& nums, int k) {
	vector<int>pos;
	vector<int>div_pos;
	int ans = 0;
	int last = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 1) {
			pos.push_back(i);
			if (pos.size() != 1) {
				div_pos.push_back(i - last-1);
			}
			last = i;
		}
		
	}
	if (div_pos.size() == 0) {
		return 0;
	}
	//sort(div_pos.begin(), div_pos.end());
	for (auto i : div_pos) {
		cout << i << " ";
	}
	cout << endl;
	/*
	ans = div_pos[0];
	for (int i = 1; i < k-1; i++) {
		if (div_pos[0] != 0) {
			ans += div_pos[i];
		}
		else {
			ans += div_pos[i] + div_pos[i-1];
		}
		
	}
	*/
	return ans;
}