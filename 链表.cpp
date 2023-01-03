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
//一下为一些API
ListNode* initList(int v[], int size);
void display(ListNode *list);
ListNode* addNode(ListNode* head, int val, int pos);//添加一个节点

ListNode* swapPairs(ListNode* head);//24M_两两交换链表中的节点

ListNode* mergeKLists(vector<ListNode*>& lists);// 23H_合并K个升序链表
void list2vector(ListNode* head, vector<int>&nums);

ListNode* reverseKGroup(ListNode* head, int k);//25H_K个一组翻转链表
ListNode* swapK(ListNode* &head, int k);

ListNode* rotateRight(ListNode* head, int k);//61M_旋转链表


int main() {
	int l1[] = { 1,2,3 };
	int k = 2000000000;
	ListNode* l_1 = initList(l1, 3);
	//ListNode* l_2 = initList(l2, 3);
	//ListNode* l_3 = initList(l3, 2);
	
	ListNode* ans = rotateRight(l_1, k);
	
	display(ans);
	return 0;
}

ListNode* initList(int v[], int size) {
	if (size == 1) {
		return new ListNode(v[0]);
	}
	ListNode* node = new ListNode();
	ListNode* head = new ListNode(v[0], node);
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

ListNode* addNode(ListNode* head, int val, int pos) {
	ListNode* node = new ListNode(val);
	if (pos == 0) {
		node->next = head;
		return node;
	}
	ListNode* tmp = head;
	int i = 0;
	while (tmp != nullptr){
		ListNode* ylx;
		if (i == pos - 1) {
			node->next = tmp->next;
			tmp->next = node;
			return head;
		}
		ylx = tmp->next;
		tmp = ylx;
		i++;
	}
}
//24M_两两交换链表中的节点
ListNode* swapPairs(ListNode* head) {
	if (head == nullptr) {
		return nullptr;
	}
	if (head->next == nullptr) {
		return head;
	}
	ListNode* node = head;
	head = head->next;
	ListNode* last = head;
	int cnt = 0;
 	while (node != nullptr) {
		ListNode* forward = node->next;
		ListNode* behind = node;
		if (cnt != 0 && node->next != nullptr) {
			last->next = forward;
		}
		else if (cnt != 0 && node->next == nullptr) {
			last->next = behind;
			break;
		}

		/*if (node->next == nullptr) {
			forward = behind;
			forward->next = nullptr;
			break;
		}*/
		if (node->next->next == nullptr) {
			
			behind->next = nullptr;
			forward->next = behind;
			break;
		}
		
		else {
			behind->next = node->next->next;
		}
		
		forward->next = behind;
		last = node;
		node = node->next;
		
		cnt++;
	}
	return head;


}

//23H_合并K个升序链表
ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.size() == 0) {
		return nullptr;
	}
	if (lists.size() == 1 && lists[0] == nullptr) {
		return nullptr;
	}
	vector<int>nums;
	for (int i = 0; i < lists.size(); i++) {
		if (lists[i] == nullptr) {
			continue;
		}
		list2vector(lists[i], nums);
	}
	if (nums.size() == 0) {
		return nullptr;
	}
	sort(nums.begin(), nums.end());
	if (nums.size() == 1) {
		return new ListNode(nums[0]);
	}
	ListNode* node = new ListNode();
	ListNode* head = new ListNode(nums[0], node);
	int size = nums.size();
	for (int i = 1; i < size; i++) {
		ListNode* tmp = new ListNode();
		/*if (i == 0) {
			head = new ListNode(v[i], node);

		}*/
		if (i == size - 1) {
			node->val = nums[i];
			node->next = nullptr;
		}
		else {
			node->val = nums[i];
			node->next = tmp;
			node = tmp;
		}
	}
	return head;
}
void list2vector(ListNode* head, vector<int>&nums) {
	ListNode* node = head;
	while (node != nullptr)
	{
		ListNode* ylx;
		nums.push_back(node->val);
		ylx = node->next;
		node = ylx;

	}
}

//25H_K个一组翻转链表
ListNode* reverseKGroup(ListNode* head, int k) {
	if (head == nullptr) {
		return nullptr;
	}
	else if(head->next==nullptr){
		return head;
	}
	else if (k == 1) {
		return head;
	}
	vector<ListNode*>lists;
	int cnt = 0;
	ListNode* node = head;
	vector<int>nums;
	while (node!=nullptr){
		lists.push_back(node);
		while (node!=nullptr){
			node = node->next;
			if (cnt == k-2) {
				if (node == nullptr) {
					break;
				}
				ListNode* tmp = node->next;
				node->next = nullptr;
				node = tmp;
				nums.push_back(cnt+2);
				cnt = 0;
				break;
			}
			cnt++;
		}
	}
	for (auto i : lists) {
		display(i);
		cout << "*****" << endl;
	}
	ListNode* connect = new ListNode;
	ListNode* ans = new ListNode;
	for (int i = 0; i < nums.size(); i++) {
		ListNode* tmp = swapK(lists[i], k);
		if (i == 0) {
			ans = lists[i];
			connect = tmp;
			continue;
		}
		connect->next = lists[i];
		connect = tmp;

		
	}
	int lists_size = lists.size();
	if (lists_size > nums.size()) {
		connect->next = lists[lists_size - 1];
	}

	return ans;
}
ListNode* swapK(ListNode* &head, int k) {
	ListNode* node = head;
	ListNode* nextone = node->next->next;
	head = head->next;
	head->next = node;
	
	ListNode* forward = head;
	ListNode* behind = head->next;
	
	int cnt = 1;
	while (nextone!=nullptr){
		if (cnt == k - 1) {
			behind->next = nullptr;
			break;
		}
		head = nextone;
		ListNode* next_tmp = nextone->next;
		head->next = forward;
		forward = head;
		nextone = next_tmp;
		cnt++;
	}
	behind->next = nullptr;
	//display(head);
	return behind;
}


//61M_旋转链表
ListNode* rotateRight(ListNode* head, int k) {
	if (head == nullptr || head->next == nullptr ) {
		return head;
	}
	else if (k == 0) {
		return head;
	}
	ListNode* node = head;
	int size = 0;
	while (node!=nullptr){
		node = node->next;
		size++;
	}
	node = head;
	
	ListNode* last = head;
	
	for (int i = 0; i < k; i++) {
		node = last;
		int cnt = 1;
	if (size == 2) {
			ListNode* tmp = head;
			head = head->next;
			head->next = tmp;
			tmp->next = nullptr;
			continue;
		}
		while (node!=nullptr)
		{
			cnt++;
			node = node->next;
			if (cnt == size-1 ) {
				last = node->next;
				node->next = nullptr;
				last->next = head;
				head = last;
				break;
			}
		}
	}


	return head;
}