//Design and implement a data structure for Least Recently Used(LRU) cache.It should support the following operations : get and put.
//
//get(key) - Get the value(will always be positive) of the key if the key exists in the cache, otherwise return -1.
//put(key, value) - Set or insert the value if the key is not already present.When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//
//Follow up :
//Could you do both operations in O(1) time complexity ?
//
//Example :
//
//	LRUCache cache = new LRUCache(2 /* capacity */);
//
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // returns 1
//cache.put(3, 3);    // evicts key 2
//cache.get(2);       // returns -1 (not found)
//cache.put(4, 4);    // evicts key 1
//cache.get(1);       // returns -1 (not found)
//cache.get(3);       // returns 3
//cache.get(4);       // returns 4


#include<unordered_map>
using namespace std;

//O(1) for all operation
class LRUCache {
	struct ListNode {
		int key;
		int value;
		ListNode*next;
		ListNode(int x, int v) :key(x), value(v),next(nullptr) {};
	};

	unordered_map<int, ListNode*> cache;
	ListNode* dummyHead;
	ListNode* end;
	size_t capacity;
	void update(int key) {
		auto i = cache.find(key);
		ListNode* predeccessor = i->second;
		ListNode* node = predeccessor->next;
		if (node == end)
			return;
		//remove from the list
		predeccessor->next = node->next;
		//change i's predeccessor
		i->second = end;
		//change node->next predeccessor
		if (predeccessor->next) {
			cache[predeccessor->next->key] = predeccessor;
		}
		//add i to the end
		end->next = node;
		end = node;
		node->next = nullptr;
		
	}
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
		dummyHead = new ListNode(0,0);
		end = dummyHead;
	}

	int get(int key) {
		auto i = cache.find(key);
		if (i == cache.end())
			return -1;
		else {
			update(key);
			return i->second->next->value;						
		}
	}

	void put(int key, int value) {
		auto i = cache.find(key);
		if (i != cache.end()) {
			i->second->next->value = value;
			update(key);
		}
		else {
			ListNode* node = new ListNode(key, value);
			cache.insert(make_pair(key, end));
			end->next = node;
			end = node;
			if (cache.size() > capacity) {
				ListNode* old = dummyHead->next;
				cache.erase(old->key);
				dummyHead->next = old->next;
				if (end == old)
					end = dummyHead;
				else 
					cache[dummyHead->next->key] = dummyHead;
				
				delete old;
			}
		}
	}
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache obj = new LRUCache(capacity);
* int param_1 = obj.get(key);
* obj.put(key,value);
*/
int main() {
	LRUCache cache(1);
	cache.put(2, 1);
	cache.get(2);
	return 0;
}