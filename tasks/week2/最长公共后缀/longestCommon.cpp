#include "header.h"
string longestCommon(vector<string>&strs)
{
	int num,min=strs[0].length(),i,j;
	vector<int>len;
	bool judge=true;
	string answer="";
	num = strs.size();//储存字符串个数

	//该循环是为了储存每个字符串的长度，并用变量min记下最短长度
	for (i = 0; i < num; i++)
	{
		if (strs[i].length() < min) min = strs[i].length();
		len.push_back(strs[i].length()); 
	}

	/*这两层循环目的是以第一个字符串strs[0]为标准，
	依次与剩余的字符串从后往前比较末尾的min个字符*/
	for (i = 1; i <= min; i++)//所有字符串倒数第i个字符的比较
	{
		for (j = 1; j <= num - 1; j++)//用strs[0]与剩余（num-1）个字符串比较
		{
			//string[i]会显示该字符串第（i+1)个字符，
			//若strs[0]和某个字符串的倒数第i个字符不相等
			if(strs[0][len[0]-1]!=strs[j][len[j]-1])
			{judge = false; break;}//改变bool量以结束外层循环，并用break退出内层循环
			else len[j] = len[j] - 1;//若相等，则将取出strs[j]的字符前移一位	
		}
		if(judge)//若strs[0]与所有字符串的倒数第i个字符都相等，即judge仍然为true
		{
			answer = strs[0][len[0] - 1] + answer;//将相等的倒数第i个字符储存
			len[0] = len[0] - 1;//将取出的strs[0]的字符前移一位
		}
		else break;//当布尔变量judge变为false时，退出外层循环
	}

	return answer;
}
