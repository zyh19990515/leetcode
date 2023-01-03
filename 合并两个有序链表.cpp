#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
void disPlay(ListNode l1);

int main() {
	ListNode l1_four = ListNode(4);
	ListNode l1_two = ListNode(2, &l1_four);
	ListNode l1 = ListNode(1, &l1_two);
	/*ListNode head1 = ListNode();
	head1.next = &l1;*/

	ListNode l2_four = ListNode(4);
	ListNode l2_three = ListNode(3, &l1_four);
	ListNode l2 = ListNode(1, &l2_three);
	/*ListNode head2 = ListNode();
	head2.next = &l2;*/
	//disPlay(head1);
	ListNode* ans = mergeTwoLists(&l1, &l2);
	disPlay(*ans);

	return 0;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	vector<int>num;
	ListNode *temp = list1;
	ListNode* temp1 = list2;
	
	while (true){
		num.push_back(temp->val);
		
		if (temp->next == nullptr) {
			break;
		}
		temp = temp->next;
	}
	while (true)
	{
		num.push_back(temp1->val);

		if (temp1->next == nullptr) {
			break;
		}
		temp1 = temp1->next;
	}
	
	sort(num.begin(), num.end());
	for (auto i : num) {
		cout << i;
	}
	ListNode* ans = new ListNode;
	ListNode* head = ans;
	for (int i = 0; i < num.size(); i++) {
		ListNode* t = new ListNode;
		head->val = num[i];
		if (i == num.size() - 1) {
			head->next == nullptr;
			break;
		}
		head->next = t;
		head = t;
		
	}

	return ans;
}

void disPlay(ListNode l1) {
	ListNode* head = &l1;
	while (head->next!=nullptr){
		head = head->next;
		cout << head->val << endl;
	}
}