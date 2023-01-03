#include<iostream>
#include<vector>


using namespace std;
int maxArea(vector<int>& height);
int	MaxArea(vector<int>& height);
int main() {
	vector<int>height{ 59,15,23,55,30,47,61,74,86,25,42,40,21,0,87,79,45,42,0,47,61,93,69,1,42,93,2,92,15,97,38,26,64,14,33,95,61,94,21,48,20,15,88,41,67,28,72,12,22,7 };
	int ans;
	//ans = maxArea(height);
	ans = MaxArea(height);
	cout << ans << endl;

	return 0;

}
//以下是第一次解题，在输入较少时有效，但输入数量非常大时，运算时间非常慢
int maxArea(vector<int>& height) {
	int maxLen = height.size();
	int ans = 0;
	vector<int>allAns;
	for (int i = 0; i < maxLen; i++) {
		for (int j = i + 1; j < maxLen; j++) {
			if (height[i] < height[j]) {
				int a = height[i] * (j - i);
				allAns.push_back(a);
			}
			else {
				int a = height[j] * (j - i);
				allAns.push_back(a);
			}
		}
	}
	int Ans_size = allAns.size();
	for (int i = 0; i < Ans_size; i++) {
		for (int j = 0; j < Ans_size - 1; j++) {
			if (allAns[j] < allAns[j + 1]) {
				int temp = allAns[j+1];
				allAns[j + 1] = allAns[j];
				allAns[j] = temp;
			}
		}
	}

	return allAns[0];
}
/*
以下是看过题解之后
使用两个指针，一头一尾，计算容积，直到指针相遇
判断那边指针移动的依据是，此时指针值的大小，小的先移动
*/
int	MaxArea(vector<int>& height) {
	int cnt = height.size()-1;
	int ans = 0;
	int i = 0;
	int area;
	while (i<cnt)
	{
		area = min(height[i], height[cnt]) * (cnt - i);
		ans = max(ans, area);
		if (height[i] > height[cnt]) {
			cnt--;
		}
		else {
			i++;
		}
	}
	return ans;
}