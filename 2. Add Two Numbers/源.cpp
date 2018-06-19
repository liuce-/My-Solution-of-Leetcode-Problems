/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
	
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* i = l1;
		ListNode* j = l2;
		ListNode* result = new ListNode(0);
		ListNode* k = result;
		while (i != nullptr) {
			if (j != nullptr) {
				k->val += i->val + j->val;
				
				if (k->val > 9) {
					k->next = new ListNode(1);
					k->val -= 10;
				}
				else if (i->next != nullptr||j->next != nullptr) {
					k->next = new ListNode(0);
				}
				j = j->next;
			}
			else {
				k->val += i->val;
				
				if (k->val > 9) {
					k->next = new ListNode(1);
					k->val -= 10;
				}
				else if (i->next != nullptr) {
					k->next = new ListNode(0);
				}
			}
			k = k->next;
			i = i->next;
		}
		if (j != nullptr) {
			while (j != nullptr) {
				k->val += j->val;
				if (k->val > 9) {
					k->next = new ListNode(1);
					k->val -= 10;
				}else if(j->next!=nullptr){
					k->next = new ListNode(0);
				}
				j = j->next;
				k = k->next;
			}
		}
		return result;
	}//58 ms	
};