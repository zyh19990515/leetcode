#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;
int threeSumClosest_1(vector<int>& nums, int target);
int threeSumClosest(vector<int>& nums, int target);
int main() {
	//vector<int>nums{ -1,2,1,-4 };
	//vector<int>nums{ -1,2,1,-4 };
	clock_t start, end;
	vector<int>nums{ 616,330,-854,919,-247,841,842,-310,-47,547,-839,565,-551,-127,264,725,17,865,-2,-578,-318,-288,-913,-662,452,700,-397,-645,-790,-682,-522,769,-115,-437,-465,419,421,151,-345,-471,128,303,-399,-901,463,610,788,-591,407,768,509,54,572,-469,449,223,-661,801,456,-832,-175,398,51,-123,479,-240,487,-686,457,523,-867,277,-554,-311,-385,294,638,458,942,-831,-46,892,-226,-221,47,496,-999,531,576,312,100,-282,774,620,-329,-623,-778,519,-619,590,847,846,563,-751,-589,-330,-861,436,-261,782,-161,-38,-558,-254,-27,256,885,570,-294,684,484,-528,-302,783,365,685,-935,-654,-149,-150,-782,-794,-814,-227,-164,196,103,834,656,701,62,-140,307,385,-436,824,-51,575,800,735,-678,248,-32,991,-816,-995,-950,120,87,-613,716,-884,-580,-371,-322,920,-574,766,-332,-877,527,-597,-134,605,559,707,-709,-988,585,214,-205,-404,-568,-973,511,161,-539,-411,-210,-255,43,676,-875,-364,-201,417,-485,-342,-502,-88,-335,280,850,660,101,193,36,534,-562,-187,-197,-657,-827,-923,211,-998,-438,938,-733,477,-755,-80,459,-945,558,-918,792,-803,267,-354,235,-789,-155,75,878,-874,-427,992,602,-148,-626,629,-142,-12,-864,359,-229,229,704,794,-102,349,-712,744,-405,-272,250,501,239,968,986,403,-728,-370,-484,633,-944,453,-826,224,971,-339,65,-154,190,-828,853,-933,115,7,-640,-883,-264,-767,569,873,-211,-535,24,-184,-777,-216,209,-739,-691,-248,-896,-937,-278,-163,-31,-225,907,-324,42,450,46,-445,879,789,943,-693,-35,-681,-573,-62,757,-199,-665,-383,-560,-1,460,-5,-348,-379,550,826,-73,-401,-705,929,921,-505,808,-463,849,124,375,-529,627,-283,-433,639,692,63,993,-942,356,157,451,-194,383,514,-299,150,191,960,-813,-74,-872,584,881,-387,-807,556,804,189,346,-749,742,775,-394,-143,898,-275,110,-598,173,-780,-658,895,95,-907,-969,592,-334,-801 };
	int target = 7262;
	start = clock();
	int ans = threeSumClosest(nums, target);
	end = clock();
	cout << end - start << "ms" << endl;
	cout << ans << endl;
	system("pause");
}
//暴力法时间超时
int threeSumClosest_1(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int ans = 0;
	vector<int>sum;
	for (int i = 0; i < nums.size(); i++) {
		int j = i + 1;
		
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		for (int j = i + 1; j < nums.size(); j++) {
			int k = nums.size() - 1;
			while (j<k){
				int s = nums[i] + nums[j] + nums[k];
				sum.push_back(s);
				while (j<k&&nums[k]==nums[k-1]){
					k--;
			}
				k--;
		}
		}
		
	}
	int min;
	int sub;
	for (int i = 0; i < sum.size(); i++) {
		
		if (i == 0) {
			min = sum[i];
			sub = abs(sum[i] - target);
		}
		else {
			if (sub > abs(sum[i] - target)) {
				min = sum[i];
				sub = abs(sum[i] - target);
			}
		}
		
	}
	return min;

}

int threeSumClosest_3(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int ans = 0;
	//vector<int>sum;
	int min;
	int sub;
	for (int i = 0; i < nums.size(); i++) {
		int j = i + 1;

		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		for (int j = i + 1; j < nums.size(); j++) {
			int k = nums.size() - 1;
			while (j < k) {
				int s = nums[i] + nums[j] + nums[k];
				//sum.push_back(s);
				if (i == 0 && j == 1 && k == nums.size() - 1) {
					min = s;
					sub = abs(s - target);
				}
				else {
					if (abs(s - target) < sub) {
						min = s;
						sub = abs(s - target);
					}
				}
				while (j < k && nums[k] == nums[k - 1]) {
					k--;
				}
				k--;
			}
		}

	}
	return min;
}

//题解
int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int n = nums.size();
	int best = 1e7;

	// 根据差值的绝对值来更新答案
	auto update = [&](int cur) {
		if (abs(cur - target) < abs(best - target)) {
			best = cur;
		}
	};

	// 枚举 a
	for (int i = 0; i < n; ++i) {
		// 保证和上一次枚举的元素不相等
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		// 使用双指针枚举 b 和 c
		int j = i + 1, k = n - 1;
		while (j < k) {
			int sum = nums[i] + nums[j] + nums[k];
			// 如果和为 target 直接返回答案
			if (sum == target) {
				return target;
			}
			update(sum);
			if (sum > target) {
				// 如果和大于 target，移动 c 对应的指针
				int k0 = k - 1;
				// 移动到下一个不相等的元素
				while (j < k0 && nums[k0] == nums[k]) {
					--k0;
				}
				k = k0;
			}
			else {
				// 如果和小于 target，移动 b 对应的指针
				int j0 = j + 1;
				// 移动到下一个不相等的元素
				while (j0 < k && nums[j0] == nums[j]) {
					++j0;
				}
				j = j0;
			}
		}
	}
	return best;
}