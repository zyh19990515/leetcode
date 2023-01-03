#include<iostream>

using namespace std;
string addBinary(string a, string b);
int main() {
	string a = "100000";
	string b = "111";
	string ans = addBinary(a, b);
	cout << ans << endl;

	return 0;
}

string addBinary(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int add = 0;
	int n;
	int m;
	string ans;
	if (a.length() > b.length()) {
		n = b.length();
		m = a.length();
	}
	else {
		n = a.length();
		m = b.length();
	}
	for (int i = 0; i <n; i++) {
		if (add == 0) {
			if (a[i] == '0' && b[i] == '0') {
				ans += '0';
				add = 0;
			}
			else if (a[i] == '0' && b[i] == '1') {
				ans += '1';
				add = 0;
			}
			else if (a[i] == '1' && b[i] == '0') {
				ans += '1';
				add = 0;
			}
			else if (a[i] == '1' && b[i] == '1') {
				ans += '0';
				add = 1;
				if (i == m - 1) {
					ans += '1';
				}
			}
		}
		else {
			if (a[i] == '0' && b[i] == '0') {
				ans += '1';
				add = 0;
			}
			else if (a[i] == '0' && b[i] == '1') {
				ans += '1';
				add = 1;
				if (i == m - 1) {
					ans += '1';
				}
			}
			else if (a[i] == '1' && b[i] == '0') {
				ans += '1';
				add = 1;
				if (i == m - 1) {
					ans += '1';
				}
			}
			else if (a[i] == '1' && b[i] == '1') {
				ans += '0';
				add = 1;
				if (i == m - 1) {
					ans += '1';
				}
			}
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}