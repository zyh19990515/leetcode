#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int countRestrictedPaths(int n, vector<vector<int>>& edges);
vector<vector<int>> findRoad(vector<vector<int>>graph, int n);
int main() {
	int n = 5;
	vector<vector<int>>edges{ {1,2,3},{1,3,3},{2,3,1},{1,4,2},{5,2,2},{3,5,1},{5,4,10} };
	int ans = countRestrictedPaths(n, edges);
	//cout << ans << endl;

	return 0;
}
 
int countRestrictedPaths(int n, vector<vector<int>>& edges) {
	vector<vector<int>>graph(n, vector<int>(n,0));


	for (int i = 0; i < edges.size(); i++) {
		if (edges[i][0] > edges[i][1]) {
			int temp = edges[i][0];
			edges[i][0] = edges[i][1];
			edges[i][1] = temp;
		}
		graph[edges[i][0]-1][edges[i][1]-1] = edges[i][2];
		//graph[edges[i][1] - 1][edges[i][0] - 1] = edges[i][2];
	}
	for (auto i : graph) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << "" << endl;
	}
	findRoad(graph, n);

	return 0;
}

vector<vector<int>> findRoad(vector<vector<int>>graph, int n) {
	vector<vector<int>>road;
	vector<vector<int>>road_pre;
	unordered_map<int, vector<int>>road_map;
	for (int i = n-1; i >=1; i--) {
		vector<int>temp;
		for (int j = 0; j <=i-1 ; j++) {
			if (graph[j][i] != 0) {
				temp.push_back(j+1);

			}
		}
		road_map[i+1] = temp;
		road_pre.push_back(temp);
	}
	/*for (auto i:road_pre){
		for (auto j : i) {
			cout << j << " ";
		}
		cout << "" << endl;
	}*/
	for (auto i : road_map[2]) {
		cout << i << "";
	}

	return road;
}