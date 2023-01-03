#include<iostream>
#include<vector>

using namespace std;
int coinChange(vector<int>& coins, int amount);
int main() {
	vector<int>coins{ 2 };
	int amount = 3;
	int ans = coinChange(coins, amount);
	cout << ans << endl;
	return 0;
}

int coinChange(vector<int>& coins, int amount) {
	vector<int>dp(amount + 1, amount + 1);
	dp[0] = 0;

	for (int i = 0; i < dp.size(); i++) {
		for (int coin : coins) {
			if (i - coin < 0) {
				continue;
			}
			dp[i] = min(dp[i], 1 + dp[i - coin]);
		}
	}
	if (dp[amount] == amount + 1) {
		return -1;
	}
	return dp[amount];
}