#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool isHappy(int n);
vector<int> numSplit(int n);
int main() {
	int n = 2;
	bool ans = isHappy(n);
	cout << ans << endl;

	return 0;
}

bool isHappy(int n) {
	int cnt = 0;
	int count = 0;
	int nn = n;
	while (cnt != 1) {
		cnt = 0;
		vector<int>num = numSplit(nn);
		for (auto i : num) {
			cnt += i * i;

		}
		
		nn = cnt;
		
		count++;
		if (count > 50) {
			return false;
		}
	}

	return true;
}

vector<int> numSplit(int n) {
	string n_str = to_string(n);
	vector<int>num;
	for (int i = 0; i < n_str.length(); i++) {
		int temp = n_str[i] - '0';
		num.push_back(temp);
	}
	
	
	return num;
}