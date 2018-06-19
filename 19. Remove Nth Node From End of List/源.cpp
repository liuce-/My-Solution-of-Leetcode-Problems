//Given a linked list, remove the n - th node from the end of list and return its head.
//
//Example:
//
//Given linked list : 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note :
//
//	Given n will always be valid.
//
//	Follow up :
//
//Could you do this in one pass ?
//


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		ListNode dummy(0);
		dummy.next = head;
		ListNode* cur = &dummy;
		ListNode* end = head;
		for (int i = 0; i < n; i++) {
			end = end->next;
		}
		while (end != nullptr) {
			cur = cur->next;
			end = end->next;
		}
		cur->next = cur->next->next;
		return dummy.next;

	}
};