#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals);

int main() {
	vector<vector<int>>intervals{ {1,3},{2,6},{8,10},{15,18} };
	vector<vector<int>>ans = merge(intervals);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < 2; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "" << endl;
	}

	return 0;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	
	vector<vector<int>>ans;
	for (int i = 0; i < intervals.size(); i++) {
		for (int j = i+1; j < intervals.size(); j++) {
			if (intervals[i][1] > intervals[j][0]) {
				intervals[j][0] = intervals[i][0];
				if (intervals[j][1] < intervals[i][1]) {
					intervals[j][1] = intervals[i][1];
				}
				ans.push_back(intervals[j]);
			}
			else {
				
			}
			
		}
				ans.push_back(intervals[i]);
	}
	return ans;
}