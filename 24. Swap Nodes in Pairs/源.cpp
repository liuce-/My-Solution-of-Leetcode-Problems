
//Given a linked list, swap every two adjacent nodes and return its head.
//
//Example:
//
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//Note :
//
//	Your algorithm should use only constant extra space.
//	You may not modify the values in the list's nodes, only nodes itself may be changed.

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
	ListNode * swapPairs(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* l = head->next;
		head->next = swapPairs(l->next);
		l->next = head;
		return l;
	}
};

class Solution {
public:
	ListNode * swapPairs(ListNode* head) {
		if (head == nullptr || head->next == nullptr)//exit point
			return head;
		//node1 is the first one in two nodes, node 2 is the second one.
		ListNode* node1 = head;
		ListNode* node2 = head->next;
		node1->next = swapPairs(node2->next);
		node2->next = head;
		return node2;
	}
};

class Solution {
public:
	ListNode * swapPairs(ListNode* head) {
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode*p = dummyHead;
		while (p->next&&p->next->next) {
			ListNode* node1 = p->next;
			auto node2 = node1->next;
			auto next = node2->next;
			node2->next = node1;
			node1->next = next;
			p->next = node2;
			p = node1;
		}
		return dummyHead->next;
	}
};