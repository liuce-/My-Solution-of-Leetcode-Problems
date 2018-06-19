//You are given two non - empty linked lists representing two non - negative integers.The most significant digit comes first and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Follow up :
//What if you cannot modify the input lists ? In other words, reversing the lists is not allowed.
//
//Example :
//
//	Input : (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//	Output : 7 -> 8 -> 0 -> 7

#include<stack>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

//错误，不能处理大数据
class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		long long int a = 0;
		long long int b = 0;
		while (l1 != nullptr) {
			a = a * 10 + l1->val;
			l1 = l1->next;
		}
		while (l2 != nullptr) {
			b = b * 10 + l2->val;
			l2 = l2->next;
		}
		long long int c = a + b;
		stack<int> s;
		while (1) {
			s.push(c % 10);
			c = c / 10;
			if (c == 0)
				break;
		}
		ListNode* start = new ListNode(s.top());
		ListNode* cur = start;
		s.pop();
		while (s.size() != 0) {
			cur->next = new ListNode(s.top());
			s.pop();
			cur = cur->next;
		}
		return start;

	}
};
///**

class Solution {
	ListNode* reverseList(ListNode* l) {
		ListNode* end = nullptr;
		while (l != nullptr) {
			ListNode* temp = l;
			l = l->next;
			temp->next = end;
			end = temp;
		}
		return end;
	}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* rl1 = reverseList(l1);
		ListNode* rl2 = reverseList(l2);
		ListNode* result = new ListNode(0);
		ListNode* current = result;
		while (rl1 != nullptr || rl2 != nullptr) {
			int a = rl1 == nullptr ? 0 : rl1->val;
			int b = rl2 == nullptr ? 0 : rl2->val;
			current->next = new ListNode(a + b);
			current = current->next;
			rl1 = rl1->next;
			rl2 = rl2->next;
		}
		current = result;
		while (current != nullptr) {
			if (current->val > 9) {
				current->val -= 10;
				if(current->next!=nullptr)
					current->next->val += 1;
				else {
					current->next = new ListNode(1);
				}				
			}
			current = current->next;
		}
		return result->next;
    }
};