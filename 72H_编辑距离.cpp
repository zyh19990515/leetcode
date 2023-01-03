#include<iostream>
#include<vector>
#include<time.h>
#include<unordered_map>
using namespace std;
int minDistance(string word1, string word2);
//int dp_1(int i, int j, string word1, string word2);

//unordered_map<int*, int>memo;
int main() {
	string word1 = "dinitrophenylhydrazine";
	string word2 = "benzalphenylhydrazone";
	
	int ans = minDistance(word1, word2);
	cout << ans << endl;
	

	return 0;
}

int minDistance(string word1, string word2) {
	int m = word1.length();
	int n = word2.length();
	vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= m; i++) {
		dp[i][0] = i;
	}
	for (int i = 1; i <= n; i++) {
		dp[0][i] = i;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (word1[i - 1] == word2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1]+1);
			}
		}
	}
	return dp[m][n];


}

/*
int dp_1(int i, int j, string word1, string word2) {
	vector<int>tmp{ i,j };
	
	if (i == -1) return j + 1;
	if (j == -1) return i + 1;
	if (word1[i] == word2[j]) {
		return dp(i - 1, j - 1, word1, word2);
	}
	else
	{
		int Min = min(dp(i, j - 1, word1, word2) + 1, dp(i - 1, j, word1, word2) + 1);
		Min = min(Min, dp(i - 1, j - 1, word1, word2) + 1);
		return Min;
	}
}

int dp_2(int i, int j, string word1, string word2) {
	int* tmp = new int;
	*tmp = i;
	*(tmp + 1) = j;
	if (memo.find(tmp) != memo.end()) {
		return memo[tmp];
	}
	if (i == -1) return j + 1;
	if (j == -1) return i + 1;
	if (word1[i] == word2[j]) {
		//return dp(i - 1, j - 1, word1, word2);
		memo[tmp] = dp(i - 1, j - 1, word1, word2);
	}
	else
	{
		int Min = min(dp(i, j - 1, word1, word2) + 1, dp(i - 1, j, word1, word2) + 1);
		Min = min(Min, dp(i - 1, j - 1, word1, word2) + 1);
		memo[tmp] = Min;
		//return Min;
	}
	return memo[tmp];
}


int minDistance_1(string word1, string word2) {
	return dp(word1.length() - 1, word2.length() - 1, word1, word2);
	

}

*/