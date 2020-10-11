#include<string>
#include"longestPalindrome.h"
using namespace std;
string longestPalindrome(string& strs)
{
	// Return the longest palindromic substring of input string
	// Or if the string has no palindromic substring, return an empty string: \"\"
	//
	// param strs:
	// 	input string
	// type strs:
	// 	string&
	// type return:
	// 	string

	// left: the left index
	// right: the right index
	int left = 0, right = 0;

	// maxIndex: the maximum index of the input string
	int maxIndex = strs.length() - 1;

	// indexOfMax: the index of the first character of the longest string
	// lengthOfMax: the length of the longest string
	int indexOfMax = 0;
	int lengthOfMax = 0;

	for (int i = 0; i <= maxIndex; i++)
	{
		left = i - 1;
		right = i;
		for(;(right <= maxIndex) && (strs[right] == strs[i]); right++){;}
		for (;
		     (left >= 0) && (right <= maxIndex) &&
		     (strs[left] == strs[right]);
		     left--, right++){;}

		if ((right - left > 2) && (right - left - 1 > lengthOfMax))
		{
			indexOfMax = left + 1;
			lengthOfMax = right - left - 1;
		}
	}
	if (lengthOfMax == 0)
	{
		return "";
	}
	return strs.substr(indexOfMax, lengthOfMax);
}
