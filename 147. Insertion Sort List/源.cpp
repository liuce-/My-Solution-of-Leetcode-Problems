//Sort a linked list using insertion sort.
//
//
//A graphical example of insertion sort.The partial sorted list(black) initially contains only the first element in the list.
//With each iteration one element(red) is removed from the input data and inserted in - place into the sorted list
//
//
//Algorithm of Insertion Sort :
//
//Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
//At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
//It repeats until no input elements remain.
//
//Example 1:
//
//Input: 4->2->1->3
//	Output : 1->2->3->4
//	Example 2 :
//
//	Input : -1->5->3->4->0
//	Output : -1->0->3->4->5


#include <algorithm>    

using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
	ListNode* headPtr;
	void sortList(ListNode* nodeToInsert) {
		ListNode* nextNodeToSort = nodeToInsert->next;		
		ListNode* cur = headPtr;
		while (cur != nodeToInsert && cur->val < nodeToInsert->val)
			cur = cur->next;
	
		if (cur != nodeToInsert) {
			int prevVal = nodeToInsert->val;
			while (cur != nodeToInsert->next) {
				swap(prevVal, cur->val);
				cur = cur->next;}}

		if(nextNodeToSort!=nullptr)
			sortList(nextNodeToSort);		
	}
public:
	ListNode * insertionSortList(ListNode* head) {
		if (head == nullptr|| head->next==nullptr)
			return head;

		headPtr = head;
		sortList(head->next);
		return headPtr;
	}
};
class Solution2 {
public:
	ListNode * insertionSortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode dummyHead(0);
		dummyHead.next = head;

		ListNode* curNodeToInsert = head->next;
		ListNode* prev = head;

		while (curNodeToInsert != nullptr) {

			ListNode* cur = dummyHead.next;
			ListNode* prevofCur = &dummyHead;
			if (prev->val > curNodeToInsert->val) {
				while (cur != curNodeToInsert && cur->val <= curNodeToInsert->val) {
					prevofCur = cur;
					cur = cur->next;
				}
				if (cur != curNodeToInsert) {
					prev->next = curNodeToInsert->next;
					prevofCur->next = curNodeToInsert;
					curNodeToInsert->next = cur;
					curNodeToInsert = prev->next;
				}
			}
			else {
				prev = curNodeToInsert;
				curNodeToInsert = curNodeToInsert->next;
			}			

		}		
		return dummyHead.next;
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
	int a[] = { 4,2,1,3 };
	ListNode* head = construct(a, 4);
	Solution2 s;
	s.insertionSortList(head);
	return 0;

}