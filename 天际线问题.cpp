#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings);
int main() {
	vector<vector<int>>buildings{ {2,9,10},{3,7,15}, {5,12,12}, {15,20,10}, {19,24,8} };
	vector<vector<int>>answer = getSkyline(buildings);
}

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

}