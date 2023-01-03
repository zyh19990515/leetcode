#include<iostream>
#include<vector>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main() {
	double ans;
	vector<int>nums1{ 3,1 };
	vector<int>nums2{ 2 };
	ans = findMedianSortedArrays(nums1, nums2);
	cout << ans << endl;

	return 0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int n_1 = nums1.size();
	int n_2 = nums2.size();
	double a = 0.0;
	vector<int>ans;
	for (int i = 0; i < n_1; i++) {
		ans.push_back(nums1[i]);
	}
	for (int i = 0; i < n_2; i++) {
		ans.push_back(nums2[i]);
	}
	
	int ans_len = ans.size();
	for (int i = 0; i < ans_len; ++i) {
		for (int j = 0; j < ans_len - 1; ++j) {
			if (ans[j] > ans[j + 1]) {
				int temp = ans[j];
				ans[j] = ans[j + 1];
				ans[j + 1] = temp;
			}
		}
	}
	/*for (auto i : ans) {
		cout << i << endl;
	}*/
	
	if (ans_len % 2 == 0) {
		int num = (ans_len / 2) - 1;
		a = ((float)ans[num] + (float)ans[num+1]) / 2;
	}
	else {
		int num = (ans_len + 1) / 2;
		a = ans[num-1];
		cout << a << endl;
	}
	


	return a;
}