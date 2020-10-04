#include<string>
#include<vector>

using namespace std;

//输入多个字符串，分别求出最长回文子串并按顺序输出
vector<string> longestPalindrome(vector<string>& strs)
{
	//用于存储最长回文文子串
	vector<string> lpd;
	//对输入的字符串逐个进行处理
	vector<string>::iterator p = strs.begin();
	for(; p != strs.end(); p++)
	{
		//用于存储回文子串
		vector<string> palindrome;
		//进行逐个字符查找
		for(int i = 0; i < (*p).length(); i++)
		{
			//长度为偶数的回文子串
			if(i + 1 < (*p).length() && (*p)[i] == (*p)[i + 1])
			{
				int j = 1;
				while(i - j >= 0 && (*p)[i - j] == (*p)[i + j + 1])
					j++;
				palindrome.push_back((*p).substr(i - j + 1, 2*j));
			}
			//长度为奇数的回文子串
			if(i + 2 < (*p).length() && (*p)[i] == (*p)[i + 2])
			{
				int j = 1;
				while(i - j >= 0 && (*p)[i - j] == (*p)[i + j + 2])
					j++;
				palindrome.push_back((*p).substr(i - j + 1, 2*j + 1));
			}
		}
		//如果字符串中存在回文子串，找出最长的第一个
		if(palindrome.size() > 0)
		{
			vector<string>::iterator q = palindrome.begin();
                	int j = 1;
                	int max = 0;
                	while(j < palindrome.size())
                	{
                		if((*(q + j)).length() > (*(q + max)).length())
                        		max = j;
                        	j++;
                	}
                	lpd.push_back((*(q + max)));
		}
		//如果不存在回文子串，输出None
		else
			lpd.push_back("None");
	}
	//返回一个存储结果的vector
	return lpd;
}
