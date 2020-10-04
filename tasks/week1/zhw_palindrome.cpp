//空队考核
//寻找字符串中的最长回文子串

//written by ：郑皓文

//data started ： 2020年10月2日
//version ： 


#include<iostream>
#include<string.h>

using namespace std;

//function:寻找最长回文子串
//input: 任意字符串
//output：输入的字符串中最长的回文字串
//written by : 郑皓文 @SEIT
//data complted : 2020年10月2日
string longestPalindrome(const string/*in*/); 

int main()
{
	string str = "ccbabdc";
	cout << longestPalindrome(str);
	return 0;
}

//function:寻找最长回文子串
//input: 任意字符串
//output：输入的字符串中最长的回文字串
//written by : 郑皓文 @SEIT
//data complted : 2020年10月2日
string longestPalindrome(const string str/*in*/)
{

	int index_max = 0; //最长回文字串的索引
	int count_max = 0; //最长回文子串长度

	//遍历字符串
	for (int i = 2; i < str.length(); i++)

		//当一个字符与两个以前的字符相同时，判断为回文字串
		if (str[i] == str[i - 2]) 
		{
			int start = i - 2; //考察子串的第一个字符
			int end = i;      //考查子串的最后一个字符

			int index = start;  //记录当前回文字串的索引
			int count = 1;    //记录当前回文字符数（一侧）

			//**迭代求当前回文子串的长度**//
			while ((--start) >= 0 && (end++) < str.length() && str[start] == str[end]) //延长子串
			{
				index = start; //索引更新
				count++;       //长度更新
			};

			//判断该回文子串是否为最长
			if (count > count_max)
			{
				index_max = index;
				count_max = count;
			}
		}

	//返回最长子串
	return str.substr(index_max, 2 * count_max + 1);
}