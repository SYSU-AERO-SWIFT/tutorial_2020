#include<iostream>
#include<string>
#pragma warning(disable:4786)
#include<vector>
using namespace std;

string longestCommon(vector<string>& strs)
{
	if (strs.size()==0)
	{
		return "";
	}
	for (int i=strs[1].size()-1;i>=0;i--) //将第一个字符串作为比较对象
	{
		for (int j=2;j<strs.size();j++) //组数增加
		{
			if (strs[j][(strs[j].size()-strs[1].size()+i)]!=strs[1][i])
			{
				return strs[1].substr(i+1,(strs[1].size()-1));//返回后缀
			}
		}
	}
	return strs[1];
}

int main()
{
	vector<string>strs(1);
	int number;
	cout<<"请输入字符串个数"<<endl;//提示信息
	cin>>number;
	for(int i=0;i<number;i++)
	{
		string s;
		cin>>s;
		strs.push_back(s);//输入字符串
	}
	cout<<longestCommon(strs)<<endl;//调用函数
	return 0;
}
