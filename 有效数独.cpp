#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board);
int main() {
	vector<vector<char>>board = { {'5', '3', '3', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'} ,
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'} ,
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'} ,
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'} ,
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'} ,
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'} ,
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'} ,
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'} ,
	};
	bool ans = isValidSudoku(board);
	cout << ans << endl;

	return 0;

}

bool isValidSudoku(vector<vector<char>>& board) {
	for (int i = 0; i < 9; i++) {
		vector<int>row;
		vector<int>col;
		for (int j = 0; j < 9; j++) {
			//首先遍历行[i][j]
			/*
			if (board[i][j] == '.') {
				continue;
			}
			*/
			if (board[i][j] != '.') {
				row.push_back(board[i][j] - '0');
			}
			if (board[j][i] != '.') {
				col.push_back(board[j][i] - '0');
			}
			sort(row.begin(), row.end());
			sort(col.begin(), col.end());
			for (int i = 1; i < row.size(); i++) {
				if (row[i] == row[i - 1]) {
					return false;
				}
			}
			for (int i = 1; i < col.size(); i++) {
				if (col[i] == col[i - 1]) {
					return false;
				}
			}
			

		}

	}
	for (int i = 0; i < 3 ; i++) {
		for (int j = 0; j < 3; j++) {
			vector<int>block;
			for (int k = i * 3; k < i * 3 + 3; k++) {
				for (int l = j * 3; l < j * 3 + 3; l++) {
					if (board[k][l] != '.') {
						block.push_back(board[k][l] - '0');
					}
				}
			}
			sort(block.begin(), block.end());
			for (int n = 1; n < block.size(); n++) {
				if (block[n] == block[n - 1]) {
					return false;
				}
			}
		}
	}

	return true;
}