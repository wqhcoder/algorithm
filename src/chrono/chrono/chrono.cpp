// chrono.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono; 

int _tmain(int argc, _TCHAR* argv[])
{
	chrono::duration<int, ratio<3>> time(2);
	//thread t(
	//	[&time](void) -> void {
	//		this_thread::sleep_for(time);
	//		cout << time.count() << endl;
	//    }
	//);

	//t.join();

	//chrono::time_point<chrono::system_clock, chrono::duration<int>> tp_seconds(chrono::duration<int>(1));
	//chrono::system_clock::time_point tp(tp_seconds);
	//cout << "1 second since system_clock epoch = ";
	//cout << tp.time_since_epoch().count();
	//cout << ", system_clock periods." << endl;

	//// display time_point
	//time_t tt = chrono::system_clock::to_time_t(tp);
	//cout << "time_point tp is " << ctime(&tt) << endl;

	// 注意:这里的time_point是clock中的，实际上也是chrono::time_point,如下:typedef chrono::time_point<system_clock> time_point;
	steady_clock::time_point begin = chrono::steady_clock::now();
	for (int i = 0, size = 100; i < size; i++)
	{
		cout << "i = " << i << endl;
	}
	steady_clock::time_point end = steady_clock::now();
	int clockRep = (end - begin).count();
	cout << "clockRep = " << clockRep << endl;
	auto timeSecond = chrono::duration_cast<chrono::milliseconds>(end - begin).count(); // 转换为毫秒
	auto timeMillSecond = chrono::duration_cast<duration<int, ratio<1, 1000>>>(end - begin).count(); // 转换为毫秒
	cout << "timeSecond = " << timeSecond << endl;
	cout << "timeMillSecond = " << timeMillSecond << endl;

	//auto time = chrono::duration_cast<ratio<1, 1000>>((end - begin).count());
	
	system("pause");
	return 0;
}

