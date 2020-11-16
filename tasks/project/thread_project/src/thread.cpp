#include"header.h"
extern int writer_come;
extern int time_now;
extern vector<bool>judger;
extern vector<bool>wjudger;
int finish = 0;            //表示完成线程的个数
int last_exit_time;        //表示writer前最后一个reader的退出时间或writer的退出时间
int w_exit_time = 0;       //存储写者退出的时间
int r_wait_index = 1;      //表示第一个等待的reader的线程序号，先赋初始值reader线程1号
int r_wait_count = 0;      //表示等待的reader的人数

mutex mt;                  //写者间互斥
mutex mout;                //输出间互斥
mutex m;                   //读者间互斥
condition_variable_any cv;
condition_variable_any condvar;

//读者的线程入口函数
void reader_func(int index, int thread_r, int arrive, int spend)
{
	m.lock();
	int time_in;              //储存该线程开始用洗衣机的时间
	//int Sleep;
	if (writer_come != 0)     //如果前面有writer或者后面有writer到来要插队
	{
		r_wait_count++;       //等待的reader的数量加1
		if (r_wait_count == 1)
		{
			//如果它是第一个等待的读者，则储存线程序号，以便最后一个writer唤醒它
			r_wait_index = thread_r;
		}
		cv.wait(m, [&] { return judger[thread_r - 1]; });  //读者线程阻塞并将锁释放
		r_wait_count--;                                    //唤醒后等待的reader减1
	}
	if (writer_come == 0)      //此时队列中已经没有写者了，有两种可能：写者还没来/写者全洗完了
	{
		if (arrive == time_now)//如果是writer还没来的情况，即读者一进入就可以洗衣服
		{

			cout << "[reader" << thread_r << "]" << arrive << "s: keep for " << spend << "s " << endl;
			m.unlock();        //输出之后释放锁，以便下一个reader线程能运行
			if (arrive + spend > last_exit_time)last_exit_time = arrive + spend; //更新最后退出时间
			usleep(spend * 1000000);
			mout.lock();      //获得输出锁，以便能完整输出
			cout << "[reader" << thread_r << "]" << arrive + spend << "s: exit "<< endl;
			finish++;         //完成线程数加1
			mout.unlock();
		}
		else if (arrive != time_now)      //若读者是经过等待才洗的衣服
		{
			time_in = w_exit_time;        //reader进入的时间是writer退出的时间
			cout << "[reader" << thread_r << "]" << time_in << "s: keep for " << spend << "s " << endl;
			if (time_in + spend > last_exit_time)last_exit_time = time_in + spend;//更新最晚退出时间
			if (r_wait_count >= 1)        //如果不只一个reader在等待
			{
				judger[thread_r] = true;  //则改变下一个线程的bool量以唤醒成功
				cv.notify_all();          //唤醒所有等待线程(但只有下一个等待的reader线程成功唤醒获得锁)
			}
			m.unlock();                   //释放锁
			usleep(spend * 1000000);
			mout.lock();                  //获得输出锁
			cout << "[reader" << thread_r << "]" << time_in + spend << "s: exit " << endl;
			finish++;
			mout.unlock();
		}
	}
}

//写者的线程入口函数
void writer_func(int index2, int thread_w, int arrive, int spend)
{
	m.lock();             //让前面的reader完成输出keep for
	m.unlock();
	bool lock = false;    //lock表示该线程是否获得过锁，等待过的writer都会获得

	if (writer_come != 1) //如果它不是队列中的第一个writer，
	{	                  //或者还有writer在洗衣服，则该线程获得锁并wait
		mt.lock();
		lock = true;      //表示该线程获得过锁
		condvar.wait(mt, [&] {return wjudger[thread_w - 1]; });
	}

	if (last_exit_time < arrive)  //写者到来时没有人在洗衣服
	{

		usleep((index2 + 1) * 6000);  //弥补主函数快的秒数
		mout.lock();
		cout << "[writer" << thread_w << "]" << arrive << "s: keep for " << spend << "s " << endl;
		mout.unlock();
		usleep(spend * 1000000);
		mout.lock();
		cout << "[writer" << thread_w << "]" << arrive + spend << "s: exit " << endl;
		finish++;
		mout.unlock();
		last_exit_time = arrive + spend;   //更新退出时间
		w_exit_time = last_exit_time;      //更新writer退出时间
		writer_come--;                     //writer洗完了，数量减1
		if (lock)mt.unlock();              //若持有锁，则释放
	}
	else if (last_exit_time >= arrive)     //如果前面的reader还没有洗完
	{
		if (!lock)                         //当它是第一个writer
		{
			usleep((index2 + 1) * 6000);      //弥补主函数的秒数
			usleep((last_exit_time - arrive) * 1000000);//等待前面的reader或writer洗完衣服
		}
		cout << "[writer" << thread_w << "]" << last_exit_time << "s: keep for " << spend << "s " << endl;
		usleep(spend * 1000000);
		mout.lock();
		cout << "[writer" << thread_w << "]" << last_exit_time + spend << "s: exit " << endl;
		finish++;
		mout.unlock();
		last_exit_time += spend;         //更新退出时间
		w_exit_time = last_exit_time;    //更新writer退出时间
		writer_come--;                   //writer洗完了，数量减1
		if (lock)mt.unlock();            //若持有锁，则释放
	}
	if (writer_come != 0)                //若该写者洗完后还有其他writer等待
	{
		wjudger[thread_w] = true;        //改变bool值以成功唤醒下一个writer
		condvar.notify_all();            //唤醒
	}
	else if (writer_come == 0)           //由最后一个writer来唤醒第一个等待的reader
	{
		if (r_wait_count != 0)           //如果有reader在等待
		{
			judger[r_wait_index - 1] = true;//将等待的第一个reader的bool值变为true以成功唤醒
			cv.notify_all();             //唤醒
		}
	}
}
