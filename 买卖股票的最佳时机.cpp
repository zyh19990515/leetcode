#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int maxProfit(vector<int>& prices);

int main() {
	vector<int>prices{ 2,1,2,0,1 };
	int ans = maxProfit(prices);
	cout << ans << endl;

	return 0;
}

int maxProfit(vector<int>& prices) {
	int max = 0;
	int minp = 1e9;
	for (int i = 0; i < prices.size(); i++) {
		if (prices[i] < minp) {
			minp = prices[i];
		}
		else if (prices[i] - minp > max) {
			max = prices[i] - minp;
		}
	}
	return max;
}

