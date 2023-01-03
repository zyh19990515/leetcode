#include<iostream>
#include<vector>

using namespace std;
int trap(vector<int>& height);
bool back_1(vector<int>&height, int& ans);
int trap_1(vector<int>& height);
int main() {
	vector<int>height{ 4,2,0,3,2,5 };
	int ans = trap(height);
	cout << ans << endl;
	return 0;
}

int trap(vector<int>& height) {
	int size = height.size();
	if (size == 0) {
		return 0;
	}
	vector<int> leftMax(size);
	leftMax[0] = height[0];
	for (int i = 1; i < size; i++) {
		leftMax[i] = max(leftMax[i - 1], height[i]);
	}

	vector<int> rightMax(size);
	rightMax[size - 1] = height[size - 1];
	for (int i = size - 2; i >= 0; i--) {
		rightMax[i] = max(rightMax[i + 1], height[i]);
	}
	for (auto i : leftMax) {
		cout << i;
	}
	cout << "" << endl;
	for (auto i : rightMax) {
		cout << i;
	}
	cout << "" << endl;
	int ans = 0;
	for (int i = 0; i < size; i++) {
		ans += min(leftMax[i], rightMax[i]) - height[i];
	}
	return ans;

}


/*下列程序运行超时*/
int trap_1(vector<int>& height) {
	int ans = 0;
	int end = true;
	
	
	while (end)
	{
		end = back_1(height, ans);
	}


	return ans;
}

bool back_1(vector<int>&height, int &ans) {
	int left = 0;
	int right = 1;

	int start = 0;
	int last = height.size() - 1;

	while (height[0]==0)
	{
		height.erase(height.begin());
		last--;
	}
	while (height[last]==0)
	{
		height.erase(height.begin() + last);
		last--;
	}
	int cnt = 0;
	int cnt_1 = 0;
	for (int i = 0; i <= last;i++) {
		if (height[i] == 0) {
			cnt++;
		}
 		if (height[i] > 0) {
			height[i] -= 1;
			if (height[i] == 0) {
				cnt_1++;
			}
		}
		else if (height[i] == 0) {
			height[i] = 0;
			cnt_1++;
		}
	}
	
	ans += cnt;
	if (cnt_1 == height.size()) {
		return false;
	}
	
	return true;
}