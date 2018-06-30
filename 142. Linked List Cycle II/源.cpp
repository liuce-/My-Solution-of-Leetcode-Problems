//Given a linked list, return the node where the cycle begins.If there is no cycle, return null.
//
//Note: Do not modify the linked list.
//
//	Follow up :
//Can you solve it without using extra space ?
//

//
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
	ListNode * detectCycle(ListNode *head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (slow && slow->next && fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast) {
				ListNode* cyclebegin = head;
				while (cyclebegin != slow) {
					slow = slow->next;
					cyclebegin = cyclebegin->next;
				}
				return cyclebegin;

			}
		}
		return nullptr;
	}
};