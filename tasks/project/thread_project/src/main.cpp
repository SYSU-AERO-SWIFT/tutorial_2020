#include"header.h"
#include<fstream>          //ifstream
#include<sstream>
extern int finish;        //储存运行完毕的线程个数
int time_now = 0;         //表示主线程的时间
int writer_come = 0;      //表示到来的写者的个数
vector<bool>judger;       //给每一个reader线程设置一个bool值，目的是notify的时候可以依次唤醒线程
vector<bool>wjudger;      //给所有writer线程设置一个bool，前一个writer控制下一个writer的bool值，
						  //目的是满足writer与writer间互斥
int main(int argc,char**argv)
{
   if(argc!=2)
	{
	cout<<"[main] fail to exec"<<endl;
	return -1;
	}
   else
   {
	vector<thread>reader;
	vector<thread>writer;
	vector<char>type;     //表示到来洗衣服的人的类型
	vector<int>arrive;    //表示它的到来时间
	vector<int>spend;     //它洗衣服耗费的时间

	string line;
	int count = 0;        //储存读者与写者的总数
	int time_all = 0;     //一个人接一个人来洗衣服所需要的最长时间

   //临时存储数据的变量
	int num, arrive_time, spend_time;
	char type2;
	cout << "[main] start" << endl;
	cout << "[main] try open "<<argv[1] << endl;

	//确认文件输入正确
	ifstream file(argv[1]);
	if (!file)
	{
		cout << "[main] fail to open "<<argv[1]<< endl;
		return -1;
	}
	else cout << "[main] open "<<argv[1] <<" success" << endl;

	//逐行读取数据并储存
	while (getline(file, line))
	{
		istringstream line2(line);
		line2 >> num >> type2 >> arrive_time >> spend_time;
		time_all += spend_time;
		type.push_back(type2);
		arrive.push_back(arrive_time);
		spend.push_back(spend_time);
		count++;
	}
	//加上第一个人到来的时间，使time_all表示了所有人洗完衣服所需要的最大时间
	time_all += arrive[0];

	//主线程模拟时间流逝
	int index = 0;                      //表示洗衣服的人的索引
	int thread_r = 1, thread_w = 1;     //表示reader线程与writer线程的序号
	for (int i = 0; i < time_all; i++)
	{
		usleep(999000);                     //挂起999ms表示时间流去1秒钟
		time_now++;                     //主线程时间加1s
		if (i + 1 == arrive[index])     //若这个时间有人到来
		{
			if (type[index] == 'R')
			{
				judger.push_back(false);
				reader.push_back(thread(reader_func, index, thread_r, arrive[index], spend[index]));
				thread_r++;             //reader线程序号+1
			}
			else if (type[index] == 'W')
			{
				wjudger.push_back(false);
				writer_come++;
				writer.push_back(thread(writer_func, index, thread_w, arrive[index], spend[index]));
				thread_w++;
			}
			if (index < count - 1)index++;//如果index不是最后一个人的索引，则index加1
		}
		if (finish == count)break;       //所有人都洗完了，则退出循环
	}
	if (thread_r != 1)
	{
		for (auto &thr : reader)
			thr.join();
	}
	if (thread_w != 1)
	{
		for (auto & thr : writer)
			thr.join();
	}
	cout << "[main] end" << endl;
	return 0;
 }
}
