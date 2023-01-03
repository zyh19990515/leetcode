#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix);
int main() {
	vector<vector<int>>matrix{ {1,2,3},{4,5,6},{7,8,9} };
	vector<int>ans = spiralOrder(matrix);
	for (auto i : ans) {
		cout << i << " ";
	}


	return 0;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	int x_size = matrix[0].size();
	int y_size = matrix.size();
	int all_num = x_size * y_size;
	x_size -= 1;
	y_size -= 1;
	vector<int>ans;
	int i = 0, j = 0, cnt = 0;
	int flag_i = 1, flag_j = 0;
	while (true)
	{
		if (j == x_size) {
			ans.push_back(matrix[i][j]);
			flag_i = 0;
	}
		if(i==)
		if (flag_i == 1 && j != x_size) {
			ans.push_back(matrix[i][j]);
			j++;
		}
		
	}

}