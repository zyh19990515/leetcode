#include<iostream>
#include<vector>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};

ListNode* initList(int v[], int size);
void display(ListNode* list);


int main() {


	return 0;
}