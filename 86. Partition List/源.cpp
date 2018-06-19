//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes in each of the two partitions.
//
//Example:
//
//Input: head = 1->4->3->2->5->2, x = 3
//	Output : 1->2->2->4->3->5
#include<vector>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
	ListNode * partition(ListNode* head, int x) {
		ListNode* lessStart = nullptr,*lessCurrent=nullptr;
		ListNode* biggerStart = nullptr,*biggerCurrent=nullptr;

		ListNode* current = head;
		while (current!=nullptr) {
			if (current->val < x&&lessStart == nullptr)
				lessCurrent = lessStart = current;
			if (current->val >= x && biggerStart == nullptr)
				biggerCurrent = biggerStart = current;

			if (current->val < x && lessStart != nullptr) {
				lessCurrent->next = current;
				lessCurrent = lessCurrent->next;
			}
			if (current->val >= x && biggerStart != nullptr) {
				biggerCurrent->next = current;
				biggerCurrent = biggerCurrent->next;
			}
			current = current->next;
		}
		if(lessCurrent!=nullptr)
			lessCurrent->next = biggerStart;
		if(biggerCurrent!=nullptr)
			biggerCurrent->next = nullptr;
		return lessStart==nullptr?biggerStart:lessStart;

	}
};