//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
//Example 1:
//
//Input: 1->2->3->3->4->4->5
//	Output : 1->2->5
//	Example 2 :
//
//	Input : 1->1->1->2->3
//	Output : 2->3


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
	ListNode * deleteDuplicates(ListNode* head) {
		if (head == nullptr)
			return nullptr;

		ListNode dummy(0);
		dummy.next = head;
		ListNode* current = head;
		ListNode* prev = &dummy;
		ListNode* suc = current;
		while (current != nullptr) {
			while (suc != nullptr) {
				if (suc->val == current->val) {
					suc = suc->next;
				}
				else
					break;
			}
			if (suc != current->next) {
				prev->next = suc;
				current = suc;
			}
			else {
				prev = current;
				current = current->next;
				suc = current;
			}

		}
		return dummy.next;
	}
};