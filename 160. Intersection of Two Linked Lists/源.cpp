//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
//For example, the following two linked lists :
//
//A:          a1 ¡ú a2
//	¨K
//	c1 ¡ú c2 ¡ú c3
//	¨J
//	B : b1 ¡ú b2 ¡ú b3
//	begin to intersect at node c1.
//
//
//	Notes :
//
//	If the two linked lists have no intersection at all, return null.
//	The linked lists must retain their original structure after the function returns.
//	You may assume there are no cycles anywhere in the entire linked structure.
//	Your code should preferably run in O(n) time and use only O(1) memory.


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


/**********************************************************************
The solution is based on question 142142. Linked List Cycle II.
The Basic idea is make the first list(headA) a circle by link the end to the beginning.If there is a intersection, then there must be a circle in listB.The start pointer of the circle is the intersection pointer.Therefore, this question becomes 142. Linked List Cycle II.All you need to do is to find the start pointer of the circle.
Don't forget to break the circle when the algorithm are finished.
*********************************************************************/


class Solution {
public:
	ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr)
			return nullptr;
		//1. make a circle
		ListNode* end = headA;
		while (end->next != nullptr) end = end->next;
		end->next = headA;

		//2. Then copy the code from Question 142: Linked List Cycle II
		ListNode* res = yourSolutionOfQuestion142(headB);
		//3. Break the circle.
		end->next = nullptr;
		return res;

	}
};


class Solution {
public:
	ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr)
			return nullptr;
		//1. make a circle
		ListNode* end = headA;
		while (end->next != nullptr) end = end->next;
		end->next = headA;

		//2. Then copy the code from Question 142: Linked List Cycle II
		ListNode* fast = headB;
		ListNode* slow = headB;

		while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				break;
		}

		if (fast == nullptr || fast->next ==nullptr) {//no circle means no intersection
			end->next = nullptr;//3. Break the circle
			return nullptr;
		}
		else {//Having circle means having intersection.
			ListNode* slow2 = headB;
			while (slow != slow2) {
				slow = slow->next;
				slow2 = slow2->next;
			}
			end->next = nullptr;//3. Break the circle
			return slow;
		}

	}
};

//Best Solution, Find it on https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!
//I found most solutions here preprocess linkedlists to get the difference in len.
//Actually we don't care about the "value" of difference, 
//we just want to make sure two pointers reach the intersection node at the same time.

//We can use two iterations to do that.
//In the first iteration, we will reset the pointer of one linkedlist to the head of another linkedlist after it reaches the tail node.
//In the second iteration, we will move two pointers until they points to the same node.Our operations in first iteration will help us counteract the difference.So if two linkedlist intersects, the meeting point in second iteration must be the intersection point.If the two linked lists have no intersection at all, then the meeting pointer in second iteration must be the tail node of both lists, which is null


class Solution {

public:
	ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) return nullptr;
		ListNode *pa = headA, *pb = headB;
		while (pa != pb)
		{
			pa = (!pa->next) ? headB : (pa->next);
			pb = (!pb->next) ? headA : (pb->next);
		}

		return pa;

	}
}; 
