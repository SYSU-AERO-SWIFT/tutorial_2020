#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;

int cot;
vector<string>In(1);
string compare1(vector<string>ou);
int main()
{

	cout << "输入字符串的个数" << endl;
	cin >> cot;
	for(int i=0;i<cot;i++ )
	{
		string a;
		cin>>a;
		In.push_back(a);
	}
	cout << compare1(In) << endl;

	system("pause");
	return 0;
}
string compare1(vector<string>ou)
{
	int count = ou.size();               //字符串个数
	vector<string>fz(count,"");

	for (int i = 0; i < count; i++)                //反转
	{
		int n = ou[i].size();
		for (int j = 0; j < n; j++)
		{
			fz[i] = fz[i] + ou[i][n - 1 - j];
		}
	}

	for (int k = 0; k < fz[1].size(); k++)                //寻找前缀
	{
		for (int m = 2; m < count; m++)
		{
			if (fz[m][k] != fz[1][k])
			{
				string final=fz[1].substr(0,k);
				reverse(final.begin(),final.end());
				return final;
			}
			else;
		}
	}
}
