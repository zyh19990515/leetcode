#include<iostream>
#include<vector>

using namespace std;
int climbStairs(int n);
int main() {
	int n = 3;
	int ans = climbStairs(n);
	cout << ans << endl;

	return 0;
}

int climbStairs(int n) {
	if (n <= 1) {
		return n;
	}
	vector<int>ans(n+1);

	ans[1] = 1;
	ans[2] = 2;
	for (int i = 3; i <= n; i++) {
		ans[i] = ans[i - 1] + ans[i - 2];
	}
	return ans[n];
}