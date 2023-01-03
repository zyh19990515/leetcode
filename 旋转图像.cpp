#include<iostream>
#include<vector>

using namespace std;
void rotate(vector<vector<int>>& matrix);
int main() {
	vector<vector<int>>matrix{ 
		{1,2,3 }, { 4,5,6 }, { 7,8,9 }
		};
	rotate(matrix);
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++) {
			cout << matrix[i][j];
		}
		cout << "" << endl;
	}

	return 0;
}

void rotate(vector<vector<int>>& matrix) {
	int size = matrix.size();
	auto matrix_new = matrix;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[j][size - 1 - i] = matrix_new[i][j];
		}
	}
	
}