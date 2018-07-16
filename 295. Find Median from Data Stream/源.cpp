//Median is the middle value in an ordered integer list.If the size of the list is even, there is no middle value.So the median is the mean of the two middle value.
//
//For example,
//[2, 3, 4], the median is 3
//
//[2, 3], the median is(2 + 3) / 2 = 2.5
//
//Design a data structure that supports the following two operations :
//
//void addNum(int num) - Add a integer number from the data stream to the data structure.
//double findMedian() - Return the median of all elements so far.
//Example :
//
//	addNum(1)
//	addNum(2)
//	findMedian() -> 1.5
//	addNum(3)
//	findMedian() -> 2
#include<vector>
using namespace std;


#include<queue>
//O(logn) insert, O(1) read
class MedianFinder {
	priority_queue<priority_queue<int>, vector<int>, less<int>> left;
	priority_queue<priority_queue<int>, vector<int>, greater<int>> right;//×îÐ¡¶Ñ
public:
	/** initialize your data structure here. */
	MedianFinder(){

	}

	void addNum(int num) {
		if (right.size() == 0 || num >= right.top())
			right.push(num);
		else
			left.push(num);
		if ((int)right.size() - (int)left.size() > 1) {
			int tmp = right.top();
			right.pop();
			left.push(tmp);
		}
		if ((int)left.size() - (int)right.size() > 1) {
			int tmp = left.top();
			left.pop();
			right.push(tmp);
		}
	}

	double findMedian() {
		if (right.size() == left.size())
			return (double)(0.5)*(double)(right.top() + left.top());
		else
			return right.size() > left.size() ? right.top() : left.top();
	}
};

/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder obj = new MedianFinder();
* obj.addNum(num);
* double param_2 = obj.findMedian();
*/

//O(N) add, O(1) read
class MedianFinder {
	vector<int> data;
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		int i = 0;
		while (i < data.size() && data[i] < num)i++;
		data.insert(data.begin() + i, num);
	}

	double findMedian() {
		int n = data.size();
		if (n % 2 == 0)
			return ((double)(data[n / 2] + data[n / 2 - 1])) / 2;
		else
			return data[n / 2];
	}
};

/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder obj = new MedianFinder();
* obj.addNum(num);
* double param_2 = obj.findMedian();
*/