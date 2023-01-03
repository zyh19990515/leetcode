#include<iostream>
using namespace std;
int divide(int dividend, int divisor);
int diva(long a, long b);
int main() {
    int dividend = -2147483648;
    int divisor = -1;
    int ans = divide(dividend, divisor);
    
	cout << ans << endl;
}
int divide(int dividend, int divisor) {
    if (dividend == 0) {
        return 0;
    }
    if (divisor == 1) {
        return dividend;
    }
    if (divisor == -1) {
        if (dividend > INT_MIN) {
            return -dividend;
        }
        return INT_MIN;
    }
    long a = dividend;
    long b = divisor;
    int sign = 1;
    if ((a > 0 && b < 0) || (a < 0 && b>0)) {
        sign = -1;
    }
    a = a > 0 ? a : -a;
    b = b > 0 ? b : -b;
    /*
    if (a == 0) {
        a = a;
    }
    else{
        a = -a;
    }
    */
    long res = diva(a, b);
    if (sign == 1) {
        return res > INT_MAX ? INT_MAX : res;
    }
    else {
        return -res;
    }

}

int diva(long a, long b) {
    if (a < b) {
        return 0;
    }
    long count = 1;
    long tb = b;
    while ((tb+tb)<=a){
        count += count;
        tb = tb + tb;
    }
    return count + diva(a - tb, b);
}