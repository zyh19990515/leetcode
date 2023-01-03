#include<iostream>
#include<string>

using namespace std;
int myAtoi(string s);
int main() {
	string s = ".1";
	int ans = myAtoi(s);
	cout << ans << endl;
}

int myAtoi(string s) {
	int size = s.size();
	int cnt = 0;
	bool isNeg = false;//·ûºÅ±êÖ¾
	bool sb = false;
	/*while (s[cnt]==' '||s[cnt]>57||s[cnt]<49)
	{
		cnt++;
	}*/

	for (char i : s) {
		if (i == 45) {
			isNeg = true;
		}
		if ((i>=65&&i<=90)||(i>=97&&i<=122)||i==46) {
			sb = true;
		}
		if (i > 58 || i<47 || i==' ') {
			cnt++;
		}
		if (i > 47 && i < 58) {
			break;
		}
	}
	//cout << "cnt:" << cnt << endl;
	s = s.substr(cnt, size - cnt);
	//cout << "ass:" << s << endl;
	if (s[0] == 45) {
		isNeg = true;
		s.erase(0, 1);
	}
	cnt = 0;
	for (char i : s) {
		if (i < 58 && i>47) {
			cnt++;
		}
		else {
			break;
		}
	}
	if (cnt == s.size()&& sb==true) {
		return 0;
	}
	s = s.substr(0, cnt);
	int count_num = s.size()-1;
	long int ans = 0;
	if (s[0] >= 50 && s.size() >= 9) {
		ans = pow(2, 31) - 1;
	}
	for (char i : s) {
		ans += pow(10, count_num) * (i - 48);
		count_num--;
	}
	if (isNeg==true) {
		ans = -ans;
	}
	if (ans > pow(2, 31) - 1) {
		ans = pow(2, 31) - 1;
	}
	if (ans < -pow(2, 31)) {
		ans = -pow(2, 31);
	}

	return ans;
}