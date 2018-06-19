//Reverse a linked list from position m to n.Do it in one - pass.
//
//Note: 1 ¡Ü m ¡Ü n ¡Ü length of list.
//
//	Example :
//
//	Input : 1->2->3->4->5->NULL, m = 2, n = 4
//	Output : 1->4->3->2->5->NULL



 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

 class Solution {
 public:
	 ListNode * reverseBetween(ListNode* head, int m, int n) {
		 if (head == nullptr)
			 return nullptr;

		 ListNode* partOnestart = nullptr;
		 ListNode* partOneEnd = nullptr;
		 ListNode* partTwoStart = nullptr;
		 ListNode* partTwoEnd = nullptr;
		 ListNode* partThreeStart = nullptr;
		 //part one
		 if (m > 1) {
			 partOnestart = head;
		 }
		 for (int i = 1; i < m; i++) {
			 partOneEnd = head;
			 head = head->next;
		 }
		 partTwoEnd = head;
		 //part two
		 ListNode* next = nullptr;
		 for (int i = 0; i < n - m + 1; i++) {
			 ListNode* temp = head;
			 head = head->next;
			 temp->next = next;
			 next = temp;
		 }
		 partTwoStart = next;
		 //part three
		 partThreeStart = head;

		 //combine three part
		 if (partOnestart != nullptr) {
			 partOneEnd->next = partTwoStart;
		 }
		 partTwoEnd->next = partThreeStart;

		 return partOnestart == nullptr ? partTwoStart : partOnestart;
	 }
 };