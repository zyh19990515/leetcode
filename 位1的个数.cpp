#include<iostream>

using namespace std;
int hammingWeight(uint32_t n);
int main() {
	uint32_t n = 00000000000000000000000000001011;
    int ans = hammingWeight(n);
    cout << ans << endl;

	return 0;
}

int hammingWeight(uint32_t n) {
    int ret = 0;
    while (n) {
        n &= n - 1;
        ret++;
    }
    return ret;
}
