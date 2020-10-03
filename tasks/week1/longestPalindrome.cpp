#include"header.h"
string longestPalindrome(string a)
{
      int len, i, j, k, n = 0, longest,q=0;
      string str1, str2;
      vector <string>strs;
      vector<string>c;
            
      len = a.length();
      for (i = 0; i < len; i++)//将字符串的每个字符分开存储
	strs.push_back(a.substr(i, 1));


      for (i = 0; i < len; i++)//从第一个字符开始将每一个字符与其后的所有字符进行比较
      {
	for (j = i + 1; j < len; j++)//循环其后面的所有字符
	{
	         if (strs[i] == strs[j])//判断两个字符是否相等
	         {
		       str1 = "";
		       str2 = "";
		       for (k = i; k <= j; k++)//相等时，顺序连接两个字符间的所有字符，得到正序字符串
		                 str1 = str1 + strs[k];
		       for (k = j; k >= i; k--)//将字符反序连接，得到反序字符串
		                 str2 = str2 + strs[k];
		       if (str1 == str2)//正序与反序比较，判断截取的字符串是否是回文字符串
		       {
			c.push_back(str1);//储存回文字符串
			n++;//记录回文字符串的个数
		       }
	         }
	}
      }
	

       if (n == 0)//判断是否存在回文字符串
	return "";
       else
      {
	longest = c[0].length();
	for (i = 0; i < n; i++)//通过循环比较得出最长回文字符串
	        if (c[i].length() > longest)
	         {
		longest = c[i].length();
		q = i;//记下最长回文字符串的下标
	         }
                 return c[q];
      }
}
