//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
//Return a deep copy of the list.


#include<unordered_map>
using namespace std;
 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
	RandomListNode * copyRandomList(RandomListNode *head) {
		unordered_map<RandomListNode*, RandomListNode*> map;
		map[nullptr] = nullptr;
		RandomListNode* cur = head;
		while (cur != nullptr) { 
			map[cur] = new RandomListNode(cur->label);
			cur = cur->next;
		}
		cur = head;
		while (cur != nullptr) {
			map[cur]->next = map[cur->next];
			map[cur]->random =  map[cur->random];
			cur = cur->next;
		}
		return map[head];

	}
};