#include<vector>
#include<utility>
#include<unordered_map>
using namespace std;
class Solution {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int result = 0;
		if (points.size() <=2 )
			return 0;
		vector<vector<int>> distanceData(points.size(),vector<int>(points.size(),0));
		for (int i = 0; i < points.size() - 1; i++) {
			for (int j = i + 1; j < points.size(); j++) {
				int distance = (points[i].first - points[j].first)*(points[i].first - points[j].first) + (points[i].second - points[j].second)*(points[i].second - points[j].second);
				distanceData[i][j] = distance;
				distanceData[j][i] = distance;
			}
		}
		for (int i = 0; i < points.size(); i++) {
			unordered_map<int, int> distanceMap;
			for (int j = 0; j < points.size(); j++) {
				if (j != i) {
					distanceMap[distanceData[i][j]]++;
				}
			}
			for (auto itr : distanceMap) {
				if (itr.second > 1) {
					result += itr.second*(itr.second - 1);
				}
			}
		}
		return result;
	}
};