//A binary watch has 4 LEDs on the top which represent the hours(0 - 11), and the 6 LEDs on the bottom represent the minutes(0 - 59).
//
//Each LED represents a zero or one, with the least significant bit on the right.
//
//
//For example, the above binary watch reads "3:25".
//
//Given a non - negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
//
//Example:
//
//Input: n = 1
//	Return : ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
//	Note :
//	The order of output does not matter.
//	The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
//	The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
#include<vector>
#include<string>
using namespace std;
class Solution {
	const vector<int> hour = { 8,4,2,1 };//4
	const vector<int> minute = { 32,16,8,4,2,1 };//6
	vector<string> result;
	vector<vector<int>> test;
	void findLight(int count, int start, vector<int> prev) {
		if (count == 0) {
			int hours = 0;
			int minutes = 0;
			for (int i = 0; i < prev.size(); i++) {
				if (prev[i] < 4) 
					hours += hour[prev[i]];
				else
					minutes += minute[prev[i]-4];
			}
			if (hours < 12 && minutes < 60) {
				string hoursStr = to_string(hours);
				string minutesStr;
				if (minutes <= 9) {
					minutesStr = "0" + to_string(minutes);
				}
				else {
					minutesStr = to_string(minutes);
				}
				result.push_back(hoursStr + ":" + minutesStr);

			}

		}
		else if (count > 0 && start < 10) {
			for (int i = start; i < 10; i++) {
				prev.push_back(i);
				findLight(count - 1, i+1, prev);
				prev.pop_back();
			}
		}

	}
public:
	vector<string> readBinaryWatch(int num) {
		vector<int> prev;
		findLight(num, 0, prev);
		return result;
	}
};