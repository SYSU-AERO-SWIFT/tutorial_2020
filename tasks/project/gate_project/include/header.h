#pragma once
#pragma once
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<unistd.h>
using namespace std;
void menu();
void create();
void connect();
void list();
void exec();
void setInput();
void print();

class Gate
{
public:
	Gate() //构造函数
	{ A = 3; B = 3; Y = 3; index = -1; parent1 = -1; parent2 = -1; }
	int calculate()//计算门电路的逻辑输出的函数
	{
		switch (type)
		{
		case 1:Y = andCalculate(parent1, parent2); break;
		case 2:Y = orCalculate(parent1, parent2); break;
		case 3:Y = notCalculate(parent1); break;
		case 4:Y = xorCalculate(parent1, parent2); break;
		case 5:Y = inputPort(); break;
		}
		return Y;
	}
	int showY();
	string showType();
	void setType(int);//设置门的类型
	void setIndex(int);//设置该门的编号
	void showParents();
	void setAB(int, int);//设置门电路输入端的值A和B
	void setParents(int, int);//设置门的父母门电路

private:
	int A;
	int B;
	int Y;
	int type;
	int index;
	int parent1;
	int parent2;
	int andCalculate(int parent1, int parent2);
	int orCalculate(int parent1, int parent2);
	int notCalculate(int parent1);
	int xorCalculate(int parent1, int parent2);
	int inputPort();
};



