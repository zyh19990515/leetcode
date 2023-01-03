#include<iostream>

using namespace std;
string generateTheString(int n);
int main() {
	int n = 4;
	string ans = generateTheString(n);
	cout << ans << endl;
	return 0;
}

string generateTheString(int n) {
	if (n % 2 == 1) {
		return string(n, 'a');
	}
	else {
		return string(n - 1, 'a') + 'b';
	}

}