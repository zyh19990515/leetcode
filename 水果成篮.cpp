#include<iostream>
#include<vector>

using namespace std;
int totalFruit(vector<int>& fruits);
int main() {
	vector<int>nums{ 3,3,3,1,2,1,1,2,3,3,4 };
	int ans = totalFruit(nums);
	cout << ans << endl;

	return 0;
}

int totalFruit(vector<int>& fruits) {
	if (fruits.size() <= 2) {
		return fruits.size();
	}
	int first = 0, second = 1, pos = 0, cnt = 0;
	int ans = 0;
	while (true){
		if (second == fruits.size() -1 || first == fruits.size()) {
			if (second - pos + 1 > ans) {
				ans = second - pos + 1;
			}
			break;
		}
		if (fruits[second] == fruits[first]) {
			first++;
			second++;
		}
		else if (fruits[second] != fruits[first] && fruits[second]==fruits[second+1]) {
			second++;
		}
		else if (fruits[second] != fruits[first] && (fruits[second] != fruits[second + 1] && fruits[second + 1] == fruits[first])) {
			first = second;
			second++;
		}
		else
		{
			if (second - pos + 1 > ans) {
				ans = second - pos + 1;
		}
			
			first++;
			second = first + 1;
			pos = first;
			if (fruits.size() - second < ans) {
				break;
			}
		}
	}
	return ans;
}