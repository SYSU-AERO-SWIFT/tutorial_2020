#include<vector>
#include<string>
#include<iostream>
using namespace std;

string longestPalindrome(string str)
{
	int len = str.length();
	string max;
	vector<vector<int> > dp(len, vector<int>(len, 0));  //创建一个len*len的矩阵dp
	for (int l = 1; l <= len; l++)         //l为最长回文子串的长度
	{
		for (int i = 0; i + l - 1 < len; i++)
		{
			int j = l - 1;
			if (l == 1)              //每一个单独的字符也可以视为回文串
			{
				dp[i][i] = 1;
			}          //对角线置1
			else if (l == 2)         //回文串构成为2个相同的字符
			{
				if (str[i] == str[i + j]) {
					dp[i][i + j] = 2;
				}
				else dp[i][i + j] = 0;
			}
			else                  //回文串长度大于2的情况
			{
				if (str[i] == str[i + j] && dp[i + 1][i + j - 1] != 0) {
					dp[i][i + j] = dp[i + 1][i + j - 1] + 2;
				}
				else dp[i][i + j] = 0;
			}
			if (l >= max.length() && dp[i][i + j]) {
				max = str.substr(i, l);
			}
		}
	}
	if (max.length() <= 1)
	{
		max = " ";
	}
	return max;
}

int main()
{
	string str;
	cin >> str;
	cout << longestPalindrome(str);
	system("pause");
	
	return 0;
}
