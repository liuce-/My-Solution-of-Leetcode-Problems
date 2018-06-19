//
//Given a linked list, rotate the list to the right by k places, where k is non - negative.
//
//Example 1:
//
//Input: 1->2->3->4->5->NULL, k = 2
//	Output : 4->5->1->2->3->NULL
//	Explanation :
//	   rotate 1 steps to the right : 5->1->2->3->4->NULL
//		   rotate 2 steps to the right : 4->5->1->2->3->NULL
//		   Example 2 :
//
//		   Input : 0->1->2->NULL, k = 4
//		   Output : 2->0->1->NULL
//		   Explanation :
//	   rotate 1 steps to the right : 2->0->1->NULL
//		   rotate 2 steps to the right : 1->2->0->NULL
//		   rotate 3 steps to the right : 0->1->2->NULL
//		   rotate 4 steps to the right : 2->0->1->NULL

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

 //solution one : time limited exceeded
class Solution {
public:
	ListNode * rotateRight(ListNode* head, int k) {
		if(head==nullptr)
			return nullptr;
		ListNode* newHead = nullptr;
		ListNode* newEnd = head;
		ListNode* cur = head;
		for (int i = 0; i < k+1; i++) {
			if (cur->next == nullptr)//build the circle
				cur->next = head;
			cur = cur->next;
		}
		while (cur != head) {
			if (cur->next == nullptr)//build the circle
				cur->next = head;
			if (newEnd->next == nullptr)//build the circle
				newEnd->next = head;
			cur = cur->next;
			newEnd = newEnd->next;
		}
		//break the circle
		newHead = newEnd->next;
		newEnd->next = nullptr;
		return newHead;
	}
};


class Solution {
public:
	ListNode * rotateRight(ListNode* head, int k) {
		if (head == nullptr)
			return nullptr;
		int size = 1;
		ListNode* temp = head;
		while (temp ->next != nullptr) {
			temp = temp->next;
			size++;
		}
		//build a circle
		temp->next = head;

		k = k % size;
		ListNode* newHead = nullptr;
		ListNode* newEnd = head;
		ListNode* cur = head;
		for (int i = 0; i < k + 1; i++) {
			cur = cur->next;
		}
		while (cur != head) {
			cur = cur->next;
			newEnd = newEnd->next;
		}
		//break the circle
		newHead = newEnd->next;
		newEnd->next = nullptr;
		return newHead;
	}
};


class Solution {
public:
	ListNode * rotateRight(ListNode* head, int k) {
		if (head == nullptr)
			return nullptr;
		int size = 1;
		ListNode* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
			size++;
		}
		//build a circle
		temp->next = head;

		k = size - k % size -1 ;
		ListNode* newEnd = head;
		ListNode* newHead = nullptr;
		for (int i = 0; i < k; i++)
			newEnd = newEnd->next;
		//break the circle
		newHead = newEnd->next;
		newEnd->next = nullptr;

		return newHead;
	}
};