string longestPalindrome(vector<string> strs)
{
	int n = strs[0].size();
	int* length = new int[n];          // 记录长度
	int location;                       // 记录最大位置
	for (int i = 0; i < n-1; i++)
	{
		for(int j = 0;;)
		{
			if (i - j < 0 || i + j > n || strs[0][i - j] != strs[0][i + j])
			{
				length[i] = 2 * j - 1;                           //最长记录
				break;
			}
			else {
				j++;
			}
		}
	}
	location = max_element(length, length + n)-length;        //  使用<algorithm>库中函数，返回数组最大值对应的角标
	int max = length[location];              //最大长度
	delete [] length;
	string ans = "";
	if (max != 1)
		for (int m = 0; m < max; m++)                      //取出最长的回文字符串
		{
			int first = location - (max - 1) / 2;              //回文序列第一个字符的位置
			ans += strs[0][first + m];
		}
	else;

	return ans;
}

