#include<iostream>
#include<vector>

using namespace std;
int longestCommonSubsequence(string text1, string text2);
int main() {
	string s1 = "abcde";
	string s2 = "ace";
	int ans = longestCommonSubsequence(s1, s2);
	cout << ans << endl;

	return 0;
}

int longestCommonSubsequence(string text1, string text2) {
	int m = text1.length();
	int n = text2.length();

	vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i < m+1; i++) {
		for (int j = 1; j < n+1; j++) {
			if (text1[i-1] == text2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				int Max = max(dp[i - 1][j], dp[i][j - 1]);
				Max = max(Max, dp[i - 1][j - 1]);

				dp[i][j] = Max;
			}
		}
	}
	return dp[m][n];

}