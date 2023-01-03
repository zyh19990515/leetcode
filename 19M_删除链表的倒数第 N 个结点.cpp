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
ListNode* removeNthFromEnd_1(ListNode* head, int n);
ListNode* removeNthFromEnd(ListNode* head, int n);

int main() {
	int nums[] = { 1,2,3,4,5 };
	int n = 2;
	ListNode* head = initList(nums, 5);
	ListNode* ans = removeNthFromEnd(head, n);
	display(ans);

	return 0;
}
//v1.0
ListNode* removeNthFromEnd_1(ListNode* head, int n) {
	int listSize = 0;
	ListNode* node = head;
	while (node != nullptr)
	{
		ListNode* ylx;
		//cout << node->val << endl;
		ylx = node->next;
		node = ylx;
		listSize++;
	}
	//cout << listSize << endl;
	int cnt = 0;
	node = head;
	if (listSize == 1) {
		return nullptr;
	}
	while (node !=nullptr)
	{	ListNode* ylx;
		if (cnt == listSize-n-1 || listSize-n-1==-1) {
			if (listSize-n-1 == -1) {
				node = node->next;
				head = node;
				break;
			}
			ylx = node->next->next;
			node->next = ylx;
			break;
		}
		ylx = node->next;
		node = ylx;
		cnt++;
	}
	return head;
}
//v1.5
ListNode* removeNthFromEnd(ListNode* head, int n) {
	int listSize = 0;
	ListNode* dummy = new ListNode(0, head);
	ListNode* node = dummy;
	int cnt = 0;
	while (node != nullptr)
	{
		ListNode* ylx;
		//cout << node->val << endl;
		ylx = node->next;
		node = ylx;
		listSize++;
	}

	node = dummy;
	while (node != nullptr)
	{
		ListNode* ylx;
		if (cnt == listSize - n - 1) {
			
			ylx = node->next->next;
			node->next = ylx;
			break;
		}
		ylx = node->next;
		node = ylx;
		cnt++;
	}
	return dummy->next;
}

ListNode* initList(int v[], int size) {

	ListNode* node = new ListNode();
	ListNode* head = new ListNode(v[0], node);
	if (size == 1) {
		return new ListNode(v[0]);
	}
	for (int i = 1; i < size; i++) {
		ListNode* tmp = new ListNode();
		/*if (i == 0) {
			head = new ListNode(v[i], node);

		}*/
		if (i == size - 1) {
			node->val = v[i];
			node->next = nullptr;
		}
		else {
			node->val = v[i];
			node->next = tmp;
			node = tmp;
		}
	}
	return head;
}
void display(ListNode* list) {
	ListNode* node = list;
	while (node != nullptr)
	{
		ListNode* ylx;
		cout << node->val << endl;
		ylx = node->next;
		node = ylx;

	}
}