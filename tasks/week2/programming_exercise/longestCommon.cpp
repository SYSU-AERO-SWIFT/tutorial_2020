string longestCommon(vector<string>& strs)
{
	string result = " ";
	if (strs.empty())                                        //先判断是否有输入,没有就直接返回
		return " No string entered";

	int i = 1;
	while (i < strs[0].size())                                 //从后往前比较
	{
		char temp = strs[0].at(strs[0].size() - i);            //将第一个字符串的第i个字母赋值给temp

		for (int j = 1; j < strs.size(); j++)                   //通过j++来进行与其他两个字符串的第i个字符进行比较
		{
			if (strs[j][strs[j].size() - i] == temp)            //如果第j个字串的第i个字符与temp相等，则判断上一个（j-1）字符串的i个字符
				continue;
			else
				
			{
				reverse(result.begin(), result.end());         // 需要包含<algorithm>头文件     
				return result;
			}
		}
		result += temp;				                          //将每次相等的字符加起来
		i++;
	}                    
	return result;					                           //返回输出结果
}
