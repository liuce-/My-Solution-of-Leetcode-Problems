//Given a singly linked list, group all odd nodes together followed by the even nodes.Please note here we are talking about the node number and not the value in the nodes.
//
//You should try to do it in place.The program should run in O(1) space complexity and O(nodes) time complexity.
//
//Example 1:
//
//Input: 1->2->3->4->5->NULL
//	Output : 1->3->5->2->4->NULL
//	Example 2 :
//
//	Input : 2->1->3->5->6->4->7->NULL
//	Output : 2->3->6->7->1->5->4->NULL
//	Note :
//
//	   The relative order inside both the even and odd groups should remain as it was in the input.
//		   The first node is considered odd, the second node even and so on ...


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
	ListNode * oddEvenList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)//Do Not switch order!
			return head;
		ListNode* oddCurrent = head;
		ListNode* evenCurrent = head->next;
		ListNode* evenStart = evenCurrent;
		ListNode* current = head->next->next;
		int i = 3;
		while (current != nullptr) {
			if (i % 2 == 1) {
				oddCurrent->next = current;
				oddCurrent = oddCurrent->next;
			}
			else {
				evenCurrent->next = current;
				evenCurrent = evenCurrent->next;
			}
			current = current->next;
			i++;
		}
		oddCurrent->next = evenStart;
		evenCurrent->next = nullptr;
		return head;

	}
};