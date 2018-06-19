//Sort a linked list in O(n log n) time using constant space complexity.
//
//Example 1:
//
//Input: 4->2->1->3
//	Output : 1->2->3->4
//	Example 2 :
//
//	Input : -1->5->3->4->0
//	Output : -1->0->3->4->5


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
	//end is not included
	ListNode* mergeSort(ListNode* start, ListNode* end) {
		if (start == nullptr || start->next == end) {
			if(start!=nullptr) start->next = nullptr;
			return start;
		}
		
		//find the mid 
		ListNode* cur = start;
		ListNode* doubleCur = start;
		while (cur != end && doubleCur != end && doubleCur->next != end) {
			cur = cur->next;
			doubleCur = doubleCur->next->next;
		}
		//sort substr
		ListNode* first = mergeSort(start, cur);
		ListNode* second = mergeSort(cur, end);
		//merge
		ListNode dummy(0);
		ListNode* resCur = &dummy;
		ListNode* cur1 = first;
		ListNode* cur2 = second;
		while (cur1!=nullptr || cur2!=nullptr){
			if (cur1 == nullptr) {
				resCur->next = cur2;
				cur2 = cur2->next;
			}
			else if (cur2 == nullptr) {
				resCur->next = cur1;
				cur1 = cur1->next;
			}
			else {
				ListNode* max = nullptr;
				if (cur1->val < cur2->val) {
					max = cur1;
					cur1 = cur1->next;
				}
				else {
					max = cur2;
					cur2 = cur2->next;
				}
				resCur->next = max;
			}
			resCur = resCur->next;				
		}
		resCur->next = nullptr;
		return dummy.next;

	}
public:
	ListNode * sortList(ListNode* head) {
		if (head == nullptr)
			return nullptr;

		return mergeSort(head, nullptr);

	}
};