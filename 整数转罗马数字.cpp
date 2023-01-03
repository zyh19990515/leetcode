#include<iostream>

using namespace std;
string intToRoman(int num);
int main() {
	int num = 3;
	string ans = intToRoman(num);
	cout << ans << endl;

	return 0;
}
 
string intToRoman(int num) {
    int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    string symbols[] = { "M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    string roman;
	int cnt = 0;
	while (num!=0){
		if (num >= value[cnt]) {
			roman += symbols[cnt];
			num -= value[cnt];
		}
		else {
			cnt++;
		}
		
	}
    return roman;
}