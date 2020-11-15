#include"header.h"
extern map<int, Gate>mp;

void Gate::setParents(int parent1, int parent2)//设置与该门电路相连的两个门电路的编号
{
	if (Gate::type == 3 || Gate::type == 5)Gate::parent1 = parent1;
	else
	{
		Gate::parent1 = parent1;
		Gate::parent2 = parent2;
	}
}
void Gate::setIndex(int index)//储存该门电路的编号
{
	Gate::index = index;
}
void Gate::setAB(int a, int b)//设置该门电路两个输入端的值
{
	Gate::A = a;
	Gate::B = b;
}
int Gate::showY()//返回该门电路的输出结果
{
	return Gate::Y;
}
void Gate::setType(int type)//设置该门电路的类型，type=1,2,3,4,5分别表示不同门
{
	Gate::type = type;
}
int Gate::andCalculate(int parent1, int parent2)//与门函数
{    if (parent1 != -1 && parent2 != -1)//如果设置了父母电路
	 {
		Gate::A = mp[parent1].calculate();//计算然后赋值
		Gate::B = mp[parent2].calculate();
	  }
	else if (parent1 == -1 && parent2 == -1 && Gate::A == 3 && Gate::B == 3)//没有设置输入也没有父母电路，报错
	{
		return 999;//返回一个较大的数
	}
	

	if (Gate::A == 0 || Gate::B == 0)return 0;//与门电路的逻辑判断
	else return 1;
}
int Gate::orCalculate(int parent1, int parent2)//或门函数
{
    if (parent1 != -1 && parent2 != -1)//如果设置了父母电路
	{
		Gate::A = mp[parent1].calculate();//计算然后赋值
		Gate::B = mp[parent2].calculate();
	}
	else if (parent1 == -1 && parent2 == -1 && Gate::A == 3 && Gate::B == 3)//没有设置输入也没有父母电路，报错
	{
		return 999;//返回一个较大的数
	}
	
	if (Gate::A == 1 || Gate::B == 1)return 1;//或门的逻辑判断
	else return 0;
}
int Gate::notCalculate(int parent1)//非门函数
{

    if (parent1 != -1) Gate::A = mp[parent1].calculate();//如果设置了父母电路，计算然后赋值
	else if (parent1 == -1 && Gate::A == 3)//没有设置输入也没有父母电路，报错
	{
		return 999;//返回一个较大的数
	}
	

	if (Gate::A == 0)return 1;
	else return 0;
}
int Gate::xorCalculate(int parent1, int parent2)//异或门函数
{
    if (parent1 != -1 && parent2 != -1)//如果设置了父母电路，计算然后赋值
	{
		Gate::A = mp[parent1].calculate();
		Gate::B = mp[parent2].calculate();
	}
	else if (parent1 == -1 && parent2 == -1 && Gate::A == 3 && Gate::B == 3)//没有设置输入也没有父母电路，报错
	{
		return 999;//返回一个较大的数
	}
	

	if (Gate::A == Gate::B)return 0;
	else return 1;
}
int Gate::inputPort()//输入端口函数
{
	if(Gate::A !=3)return Gate::A;//设置了输入，则返回输入值
	else if (Gate::A == 3 && parent1 == -1 )//没有设置输入也没有父母电路，报错
	{
		return 999;//返回一个较大的数
	}
	else return Gate::A;
}
string Gate::showType()//返回门电路的类型信息
{
	switch (Gate::type)
	{
	case 1:return "、与门     ";
	case 2:return "、或门     ";
	case 3:return "、非门     ";
	case 4:return "、异或门   ";
	case 5:return "、输入端口 ";
	default:return"、error    ";
	}
}
void Gate::showParents()//返回与该门电路连接的父母门电路的信息
{
	if (Gate::parent1 != -1)cout << "parent1: " << Gate::parent1 << "    ";
	else cout << "parent1: NULL ";
	if (Gate::parent2 != -1)cout << "parent2: " << Gate::parent2;
	else cout << "parent2: NULL ";
}
