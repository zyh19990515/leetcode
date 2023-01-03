#include<iostream>
#include<vector>

using namespace std;
int candy(vector<int>& ratings);
int main() {
	vector<int>ratings{ 1,3,2,2,1 };
	int ans = candy(ratings);

	cout << ans << endl;
	return 0;
}

int candy(vector<int>& ratings) {
	//int* candyArr = new int;
	//*candyArr = 1;
	vector<int>candyArr(ratings.size());
	candyArr[0] = 1;
	for (int i = 1; i < ratings.size(); i++) {
		//*(candyArr + i) = ratings[i] > ratings[i - 1] ? *(candyArr + i - 1) + 1 : 1;
		if (ratings[i] > ratings[i - 1]) {
			candyArr[i] = candyArr[i - 1] + 1;
		}
		else {
			candyArr[i] = 1;
		}
	}

	int right = 0, ans = 0;
	for (int i = ratings.size() - 1; i >= 0; i--) {
		if (i<ratings.size()-1 && ratings[i]>ratings[i + 1]){
			right++;
			}
		else {
			right = 1;
		}
		ans += max(candyArr[i], right);
	}
	return ans;
	
}