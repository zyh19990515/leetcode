#include<iostream>
#include<string>

using namespace std;
int titleToNumber(string columnTitle);
int main() {
	string columnTitle = "ZY";
	int ans = titleToNumber(columnTitle);
	cout << ans << endl;


	return 0;
}

int titleToNumber(string columnTitle) {
	int ans = 0;
	int cnt = 0;
	for (int i = columnTitle.length()-1; i >= 0; i--) {
		int temp = columnTitle[i] - 'A' + 1;
		ans += pow(26, cnt) * temp;
		cnt++;
	}
	return ans;
}