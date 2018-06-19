//Merge k sorted linked lists and return it as one sorted list.Analyze and describe its complexity.
//
//Example:
//
//Input:
//[
//	1->4->5,
//	1->3->4,
//	2->6
//]
//Output : 1->1->2->3->4->4->5->6

#include<vector>
#include<queue>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
	ListNode * mergeKLists(vector<ListNode*>& lists) {
		int listCount = lists.size();
		if (listCount == 0)
			return nullptr;
		ListNode* start = nullptr;
		ListNode* current = nullptr;
		priority_queue<pair<int, ListNode*>,vector<pair<int, ListNode*>>,greater<pair<int, ListNode*>>> q;
		for (int i = 0; i<listCount; i++) {
			if(lists[i]!=nullptr)
				q.push(make_pair(lists[i]->val, lists[i]));
		}
		if (q.size() == 0)
			return nullptr;

		start = new ListNode(q.top().first);
		current = start;
		auto next = q.top().second->next;
		q.pop();
		if (next != nullptr)
			q.push(make_pair(next->val, next));

		while (q.size() != 0) {
			int val = q.top().first;
			ListNode* next = q.top().second->next;
			q.pop();
			current->next = new ListNode(val);
			current = current->next;

			if (next != nullptr) {
				q.push(make_pair(next->val, next));
			}

		}
		return start;
	}
};