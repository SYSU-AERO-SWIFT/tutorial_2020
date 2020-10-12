#include"opencv.h"
int main(int agrc, char** argv)
{
	cout << "*********************" << endl;
	cout << "选择难度1和难度2请输入1" << endl;
	cout << "选择难度3请输入3" << endl;
	
	int num;
	cin >> num;
	if (num == 1)
	{
		get();
		Read_to_Binary();
	}
	else if (num = 3)
	{
		get3();
		Read_to_Bianry3();
	}
	else
	{
		cout << "ERROR" << endl;
		return -1;

	}

	get_Rectangle();
	position();
	realise();

	cout << endl;
	cv::waitKey(0);
	return 0;

}
