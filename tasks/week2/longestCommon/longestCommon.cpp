#include<string>
#include<vector>
#include"longestCommon.h"
using namespace std;

string longestCommon(vector<string>& strs)
{
	if (strs.empty())
	{
		return "";
	}
	bool not_equal = false;
	int count = 0;
	for (int i = strs[0].size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < strs.size(); j++)
		{
			if (strs[j][strs[j].size() - 1 - count] != strs[0][i])
			{
				not_equal = true;
				break;
			}
		}
		if (not_equal)
		{
			break;
		}
		count++;
	}
	return strs[0].substr(strs[0].size() - 1 - count, count);
}
