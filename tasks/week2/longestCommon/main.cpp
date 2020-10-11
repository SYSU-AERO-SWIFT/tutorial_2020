#include<iostream>
#include<string>
#include<vector>
#include"longestCommon.h"
using namespace std;
int main(int argc, char** argv)
{
	vector<string> temp(3);
	temp[0] = "ppp";
	temp[1] = "pplpp";
	temp[2] = "lpp";
	cout << longestCommon(temp) << endl;
	return 0;
}
