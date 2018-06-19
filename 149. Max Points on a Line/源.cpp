#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#include<iostream>
#include<map>
#include<algorithm>
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };
 class hashFunc {
 public:
	 std::size_t operator()(const std::pair<long double, long double> &p) const {
		 return std::hash<long double>()(p.first) ^ std::hash<long double>()(p.second);
	 }
 };
 class isEqual {
 public:
	 bool operator()(const pair<long double, long double>&key1, const pair<long double, long double>&key2) const {
		 return key1.first == key2.first&&key1.second == key2.second;
	 }
 };
 //´íÎó½â·¨¡£
 class Solution {
public:
	int maxPoints(vector<Point>& points) {
		if (points.size() < 3) {
			return points.size();
		}
		unordered_map<pair<long double, long double>, unordered_set<int>,hashFunc,isEqual> kMap;
		for (int i = 0; i < points.size() - 1; i++) {
			for (int j = i + 1; j < points.size(); j++) {
				long double k = points[i].x - points[j].x == 0 ? INT_MAX: (long double)(points[i].y - points[j].y) / (long double)(points[i].x - points[j].x);
				long double c = points[i].x - points[j].x == 0 ? points[i].x : (long double)points[i].y - k * (long double)points[i].x;
				kMap[make_pair(k, c)].insert(i);				
				kMap[make_pair(k, c)].insert(j);
				cout << "i " << i << " j " << j << "  k " <<k<<" c "<< c <<" size " <<kMap[make_pair(k, c)].size() << endl;

			}
		}
		int max = 0;
		for (auto i : kMap) {
			if (i.second.size() > max)
				max = i.second.size();
			if (i.second.size() == 21) {
				for (auto j : i.second) {
					cout << " " << j;
				}
			}
		}
		return max;

		
	}
}; 
 class Solution2 {
public:
	int maxPoints(vector<Point> &points) {

		if (points.size()<2) return points.size();

		int result = 0;

		for (int i = 0; i<points.size(); i++) {

			map<pair<int, int>, int> lines;
			int localmax = 0, overlap = 0, vertical = 0;

			for (int j = i + 1; j<points.size(); j++) {

				if (points[j].x == points[i].x && points[j].y == points[i].y) {

					overlap++;
					continue;
				}
				else if (points[j].x == points[i].x) vertical++;
				else {

					int a = points[j].x - points[i].x, b = points[j].y - points[i].y;
					int gcd = GCD(a, b);

					a /= gcd;
					b /= gcd;

					lines[make_pair(a, b)]++;
					localmax = max(lines[make_pair(a, b)], localmax);
				}

				localmax = max(vertical, localmax);
			}

			result = max(result, localmax + overlap + 1);
		}

		return result;
	}

private:
	int GCD(int a, int b) {

		if (b == 0) return a;
		else return GCD(b, a%b);
	}
 };


 int main() {
	 Solution s;
	 vector<Point> testcase={ { 560,248 },{ 0,16 },{ 30,250 },{ 950,187 },{ 630,277 },{ 950,187 },{ -212,-268 },{ -287,-222 },{ 53,37 },{ -280,-100 },{ -1,-14 },{ -5,4 },{ -35,-387 },{ -95,11 },{ -70,-13 },{ -700,-274 },{ -95,11 },{ -2,-33 },{ 3,62 },{ -4,-47 },{ 106,98 },{ -7,-65 },{ -8,-71 },{ -8,-147 },{ 5,5 },{ -5,-90 },{ -420,-158 },{ -420,-158 },{ -350,-129 },{ -475,-53 },{ -4,-47 },{ -380,-37 },{ 0,-24 },{ 35,299 },{ -8,-71 },{ -2,-6 },{ 8,25 },{ 6,13 },{ -106,-146 },{ 53,37 },{ -7,-128 },{ -5,-1 },{ -318,-390 },{ -15,-191 },{ -665,-85 },{ 318,342 },{ 7,138 },{ -570,-69 },{ -9,-4 },{ 0,-9 },{ 1,-7 },{ -51,23 },{ 4,1 },{ -7,5 },{ -280,-100 },{ 700,306 },{ 0,-23 },{ -7,-4 },{ -246,-184 },{ 350,161 },{ -424,-512 },{ 35,299 },{ 0,-24 },{ -140,-42 },{ -760,-101 },{ -9,-9 },{ 140,74 },{ -285,-21 },{ -350,-129 },{ -6,9 },{ -630,-245 },{ 700,306 },{ 1,-17 },{ 0,16 },{ -70,-13 },{ 1,24 },{ -328,-260 },{ -34,26 },{ 7,-5 },{ -371,-451 },{ -570,-69 },{ 0,27 },{ -7,-65 },{ -9,-166 },{ -475,-53 },{ -68,20 },{ 210,103 },{ 700,306 },{ 7,-6 },{ -3,-52 },{ -106,-146 },{ 560,248 },{ 10,6 },{ 6,119 },{ 0,2 },{ -41,6 },{ 7,19 },{ 30,250 }
	 };
	 auto res = s.maxPoints(testcase);
	 cout << "res is " << res << endl;
	 return 0;

 }