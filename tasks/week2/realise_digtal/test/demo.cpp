#include"opencv.h"
int main(int agrc, char** argv)
{

	cout << "是否选择难度三输入Y/N？" << endl;
	char get;
	cin >> get;
	if (get == 'N' || get == 'n')
		Read_to_Binary();
	else if (get == 'Y' || get == 'y')
		Read_to_Bianry3();
	else
	{cout << "选项字母不匹配" << endl;
	return -1;}

	draw_Rectangle();
	position();
	realise();

cout<<endl;
		cv::waitKey(0);
		return 0;

}
