//Given a singly linked list L : L0¡úL1¡ú¡­¡úLn - 1¡úLn,
//reorder it to : L0¡úLn¡úL1¡úLn - 1¡úL2¡úLn - 2¡ú¡­
//
//You may not modify the values in the list's nodes, only nodes itself may be changed.
//
//Example 1 :
//
//	Given 1->2->3->4, reorder it to 1->4->2->3.
//	Example 2 :
//
//	Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

#include<vector>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
	vector<ListNode*> v;
public:
	void reorderList(ListNode* head) {
		while (head != nullptr) {
			v.push_back(head);
			head = head->next;
		}
		ListNode dummy(0);
		ListNode* cur = &dummy;
		int size = v.size();
		for (int i = 0; i < size / 2; i++) {
			cur->next = v[i];
			cur = cur->next;
			cur->next = v[size - i - 1];
			cur = cur->next;
		}
		if (size % 2 != 0) {
			cur->next = v[size / 2];
			cur = cur->next;
		}
		cur->next = nullptr;
	}
};

ListNode* construct(const int* a, int size) {
	ListNode dummy(0);
	ListNode* cur = &dummy;
	for (int i = 0; i < size; i++) {
		cur->next = new ListNode(a[i]);
		cur = cur->next;
	}
	return dummy.next;
}

int main() {
	Solution s;
	int a[] = { 1,2,3,4,5,6,7,8 };
	ListNode* testCase = construct(a, 8);
	s.reorderList(testCase);
	return 0;
	
}