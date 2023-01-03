#include<iostream>

using namespace std;
int mySqrt(int x);
int main() {
	int x = 8;
	double ans = mySqrt(2147395599);
	printf("%f", ans);

	return 0;
}

int mySqrt(int x) {
	float l = 0;
	float r = x;
	double mid=0;
	double cnt = (long long)mid * mid;
	int n = 0;
	if (x == 1) {
		return 1;
	}
	while (abs(cnt-x)>0.01)
	{
		mid = l + (r - l) / 2;
		cnt = mid * mid;
		if (cnt < x) {
			l = mid;
			cout << "l:" << l << endl;
			
		}
		else {
			r = mid;
			cout << "r:" << r << endl;
		}
		cout << "mid " << mid << endl;
		n++;
		if (n > 500) {
			break;
		}
	}
	
	return mid;
}

int mySqrt_1(int x) {
	int l = 0, r = x, ans = -1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if ((long long)mid * mid <= x) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return ans;
}