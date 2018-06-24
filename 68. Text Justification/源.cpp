//Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully(left and right) justified.
//
//You should pack your words in a greedy approach; that is, pack as many words as you can in each line.Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
//
//Extra spaces between words should be distributed as evenly as possible.If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//
//For the last line of text, it should be left justified and no extra space is inserted between words.
//
//Note:
//
//A word is defined as a character sequence consisting of non - space characters only.
//Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
//The input array words contains at least one word.
//Example 1 :
//
//	Input :
//	words = ["This", "is", "an", "example", "of", "text", "justification."]
//	maxWidth = 16
//	Output :
//	[
//		"This    is    an",
//		"example  of text",
//		"justification.  "
//	]
//Example 2:
//
//Input:
//words = ["What", "must", "be", "acknowledgment", "shall", "be"]
//maxWidth = 16
//Output :
//	[
//		"What   must   be",
//		"acknowledgment  ",
//		"shall be        "
//	]
//Explanation : Note that the last line is "shall be    " instead of "shall     be",
//	because the last line must be left - justified instead of fully - justified.
//	Note that the second line is also left - justified becase it contains only one word.
//	Example 3 :
//
//	Input :
//	words = ["Science", "is", "what", "we", "understand", "well", "enough", "to", "explain",
//	"to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"]
//	maxWidth = 20
//	Output :
//	[
//		"Science  is  what we",
//		"understand      well",
//		"enough to explain to",
//		"a  computer.  Art is",
//		"everything  else  we",
//		"do                  "
//	]
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		if (words.size() == 0)
			return res;
		int left = 0;
		int right = 0;
		while (right < words.size()) {
			string tmp=words[left];
			int currentLength = words[left].length();
			right = ++left;
			while (right < words.size()) {//find out how many words should be in this line
				if (currentLength + words[right].size() + 1 <= maxWidth) {
					currentLength = currentLength + words[right].size() + 1;
					right++;			
				}
				else
					break;
			}
			if (right != words.size() && right>left) {//not last line, fully justify
				int pad = maxWidth - currentLength;
				int padPerWord = pad / (right - left);
				int morePad = pad % (right - left);
				while (left < right) {
					if (morePad != 0) {
						tmp.append(padPerWord + 1 + 1, ' ');//first '1' means morepad and second '1' means the space before every words.
						morePad--;
					}
					else
						tmp.append(padPerWord + 1, ' '); //no morepad, only the space before every words
					tmp.append(words[left]);
					left++;
				}
			}
			else{//last line, left justify
				while (left < right) {
					tmp.append(" ");
					tmp.append(words[left]);
					left++;
				}
			}
			tmp.resize(maxWidth, ' ');
			res.push_back(tmp);
		}
		return res;
	}
};