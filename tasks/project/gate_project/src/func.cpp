#include"header.h"
int index = 0;
bool clear=true;
map<int, Gate>mp;

void menu()
{
	while (true)
	{
		if(clear)system("clear");
		string command;
		cout << "create" << endl;
		cout << "list" << endl;
		cout << "connect" << endl;
		cout << "print" << endl;
		cout << "setInput" << endl;
		cout << "exec" << endl;
		cout << "exit" << endl;
		cout << "on/off"<<endl;
		cout << "请输入指令：";
		cin >> command;
		if (command == "create")create();
		else if (command == "list")list();
		else if (command == "connect")connect();
		else if (command == "print")print();
		else if (command == "setInput")setInput();
		else if (command == "exec")exec();
		else if (command == "exit")return;
	        else if (command == "on")clear=true;
                else if (command == "off")clear=false;
		else
		{
			cout << "error:没有这个指令，2s后刷新" << endl;
			sleep(2);
		}
	}
}
void create()
{
	if(clear)system("clear");
	bool judge = true;
	string input;
	Gate blank;
	cout << "0、back" << endl;
	cout << "1、与门" << endl;
	cout << "2、或门" << endl;
	cout << "3、非门" << endl;
	cout << "4、异或门" << endl;
	cout << "5、输入端口" << endl;
	while (judge)
	{
		cout << "请输入你要创建的门电路类型：";
		cin >> input;
		if (input == "0") { judge = false; }
		else if (input == "1") { mp.insert(make_pair(index, blank)); mp[index].setType(1); mp[index].setIndex (index); cout << "创建与门成功，编号为：" << index << endl; index++; }
		else if (input == "2") { mp.insert(make_pair(index, blank)); mp[index].setType(2); mp[index].setIndex(index); cout << "创建或门成功，编号为：" << index << endl; index++; }
		else if (input == "3") { mp.insert(make_pair(index, blank)); mp[index].setType(3); mp[index].setIndex(index); cout << "创建非门成功，编号为：" << index << endl; index++; }
		else if (input == "4") { mp.insert(make_pair(index, blank)); mp[index].setType(4); mp[index].setIndex(index); cout << "创建异或门成功，编号为：" << index << endl; index++; }
		else if (input == "5") { mp.insert(make_pair(index, blank)); mp[index].setType(5); mp[index].setIndex(index); cout << "创建输入端口成功，编号为：" << index << endl; index++; }
		else cout << "error:指令错误" << endl;

	}
}
void connect()
{
	if(clear)system("clear");
	int parent1, parent2, child, count = 0;
	for (map<int, Gate>::iterator it = mp.begin(); it != mp.end(); it++)//遍历输出
	{
		cout << "编号" << it->first << it->second.showType();
		it->second.showParents();
		cout << endl;
		count++;//储存已设置的门电路的总数
	}
	while (true)
	{
		cout << "请输入三个你要连接的电路编号(前两个电路的输出端会作为第三个电路的输入端,返回请输入-1 0 0):";
		cin >> parent1 >> parent2 >> child;
		if (parent1 == -1)return;//返回主菜单设置
		//输入错误的情况
		else if (parent1 < -1 || parent2 < 0 || child < 0)cout << "error:请输入正确电路编号！" << endl;
		else if (parent1 >= count || parent2 >= count || child >= count)cout << "error:请输入正确的电路编号！" << endl;
		else if (parent1 == parent2 || parent2 == child || parent1 == child)cout << "error:请连接不同的门电路！" << endl;
		else
		{
			mp[child].setParents(parent1, parent2);
			cout << "连接成功！" << endl;
		}
	}
}
void list()
{
	if(clear)system("clear");
	string input;
	for (map<int, Gate>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		cout << "编号" << it->first << it->second.showType();
		it->second.showParents();
		cout << endl;
	}
	cout << "返回主菜单请输入0：";
	cin >> input;
}
void exec()
{
	string input;
	int i, all = 0,num;
	for (map<int, Gate>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		i = it->second.calculate();
		all += i;
	}
	if (all >= 999)
	{
		num = all / 999;
		cout << "有" << num << "个门电路未设置连接或输入，请问电路是否连接完成？(y/n):";
		cin >> input;
		if (input == "y"|| input=="Y")cout << "执行成功！2s后刷新" << endl;
		else if (input == "n" || input == "N")cout << "执行失败，2s后刷新" << endl;
		else cout<<"error:指令错误，2s后返回菜单"<<endl;
		sleep(2);
	}
	else
	{
		cout << "执行成功! 2s后刷新" << endl;
		sleep(2);
	}
}
void setInput()
{
	if(clear)system("clear");
	int gate, value1, value2;
	cout << "输入格式为：门编号 输入值1 输入值2" << endl;
	cout << "(注：输入端口和非门仅需输入值1，请给输入值2赋0)" << endl;
	cout << "已有的门电路：" << endl;
	for (map<int, Gate>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		cout << "编号" << it->first << it->second.showType();
		it->second.showParents();
		cout << endl;
	}
	while (true)
	{
		cout << "请设置输入(退出请输入-1 0 0)：";
		cin >> gate >> value1 >> value2;
		if (gate == -1)return;//返回主菜单设置
		if (  (value1 != 0 && value1 != 1) || (value2 != 0 && value2 != 1)  )
			cout << "输入值只能为0或1！" << endl;
		else
		{
			mp[gate].setAB(value1, value2);
			cout << "输入成功！" << endl;
		}
	}
}
void print()
{
	if(clear)system("clear");
	int output;
	cout << "已有的门电路：" << endl;
	for (map<int, Gate>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		cout << "编号" << it->first << it->second.showType();
		cout << endl;
	}
	while (true)
	{
		cout << "请输入需要打印结果的门电路编号(退出请输入-1)：";
		cin >> output;
		if (output == -1)return;
		else cout << "编号" << output << " 输出结果为：" << mp[output].showY() << endl;
	}
}
