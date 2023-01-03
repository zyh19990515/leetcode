#include<iostream>
#include<vector>
using namespace std;
string convertToTitle(int columnNumber);
int main() {
	int columnNumber =52;
	string ans = convertToTitle(columnNumber);
	cout << ans << endl;

	return 0;
}

string convertToTitle(int columnNumber) {
	vector<int>result;
	int ret = 999;
	int d = columnNumber;
	string ans;
	char ch;
	if (columnNumber <= 26) {
		return ans = columnNumber - 1 + 'A';
	}
	while (d>=26){
		ret = d % 26;
		d = d / 26;
		if (ret == 0) {
			d -= 1;
			ret = 26;
		}
		result.push_back(ret);
		if (d <= 26) {
			result.push_back(d);
			break;
		}
		
	}
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << endl;
		
		ch = result[i] - 1 + 'A';
		ans += ch;
	}
	return ans;
}