//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//getMin() --Retrieve the minimum element in the stack.
//Example:
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> Returns - 3.
//minStack.pop();
//minStack.top();      --> Returns 0.
//minStack.getMin();   --> Returns - 2.
#include<stack>
using namespace std;
class MinStack {
	class ListNode {
	public:
		ListNode* next;
		int value;
		ListNode(int x = INT_MIN) :value(x), next(nullptr) {};
	};
	stack<int> rawStack;
	ListNode dummy;

	void insert(int x) {
		ListNode* cur = &dummy;

		while (cur ->next != nullptr && x > cur->next->value) cur = cur->next;
		ListNode* newNode = new ListNode(x);
		newNode->next = cur->next;
		cur->next = newNode;
	}
	void erase(int x) {
		ListNode* cur = &dummy;
		while (cur->next != nullptr && cur->next->value != x) cur = cur->next;
		ListNode* tmp = cur->next;
		cur->next = tmp->next;
		delete(tmp);
	}

public:
	/** initialize your data structure here. */
	MinStack() {
		
	}

	void push(int x) {
		rawStack.push(x);
		insert(x);
	}

	void pop() {
		erase(rawStack.top());
		rawStack.pop();
	}

	int top() {
		return rawStack.top();
	}

	int getMin() {
		return dummy.next->value;
	}
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/