string longestPalindrome(vector<string>& strs)
{
	int tempFlag, myFlag;              //初始化临时原点和原点
	int tempMax = 0;                   //初始化临时半径和半径
	int max = 0;
	string result;                     //用于储存结果


	int lenth = strs[0].size();        //计算字符串长度
	if (lenth == 0 || lenth == 1)      //当输入字符串长度小于等于1无需计算
	{
		return strs[0];           
	}

	//开始判断
	for (int i = 1; i < lenth - 1; i++)                //设置比较原点
	{
		tempMax = 0;                                   //复原临时半径
		for (int j = 1; j <= i&&i+j<lenth; j++)        //从1开始扩大半径
		{
			if (strs[0].at(i - j) == strs[0].at(i + j))//比较原点两边的半径为j的数值是否相同
			{
				tempFlag = i;                                
				tempMax=j;                             //如果相同让临时半径等于j
			}
			else break;                                //不相同直接退出，进行下一个原点的比较
		}
		if (tempMax > max)                             //如果该原点处的半径大于之前原点的半径
		{
			myFlag = tempFlag;                         //把临时原点、半径的值赋给原点、半径
			max = tempMax;
		}
	}


	//返回结果
	if (max == 0)                                      //如果半径为0，即无回文，返回“ ”
	{
		return " ";
	}
	else
	{
		for (int i = myFlag - max; i <= myFlag + max; i++)//存在就通过原点位置和半径返回回文
		{
			result += strs[0].at(i);
		}
		return result;
	}
}
