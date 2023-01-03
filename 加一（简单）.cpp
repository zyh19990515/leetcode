#include<iostream>
#include<vector>

using namespace std;
vector<int> plusOne(vector<int>& digits);
int main() {
	vector<int>digits{ 9 };
	vector<int>ans = plusOne(digits);
	for (auto i : ans) {
		cout << i << " ";
	}
}

vector<int> plusOne(vector<int>& digits) {
	int add=0;
	int size = digits.size();
	/*if (1 == size && digits[0] == 9) {
		digits.clear();
		digits.push_back(1);
		digits.push_back(0);
		return digits;
	}*/
	for (int i = digits.size() - 1; i >= 0; i--) {
		if (i == digits.size() - 1) {
			digits[i] = digits[i] + 1;
			if (digits[i] == 10) {
				digits[i] = 0;
				add = 1;
				if (i == 0 && add == 1) {
					digits.insert(digits.begin(), add);
				}
			}
		}
		else {
			
			digits[i] = digits[i] + add;

			add = 0;
			if (digits[i] == 10) {
				digits[i] = 0;
				add = 1;
				if (i == 0&&add==1) {
				digits.insert(digits.begin(), add);
				}
			}
			
		}
		
	}
	return digits;
}