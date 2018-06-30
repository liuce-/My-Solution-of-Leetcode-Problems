//Given a linked list, determine if it has a cycle in it.
//
//Follow up :
//Can you solve it without using extra space ?
//


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
 //O(n) time O(1) space
class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode* singleBegin = head;
		ListNode* doubleBegin = head;
		while (singleBegin && singleBegin->next && doubleBegin->next && doubleBegin->next->next) {
			singleBegin = singleBegin->next;
			doubleBegin = doubleBegin->next->next;
			if (singleBegin == doubleBegin)
				return true;
		}
		return false;
	}
};