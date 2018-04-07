#include <iostream>
#include "WcFile.h"
#include <io.h>
#include <Windows.h>
using namespace std;


//输入控制
void InputAnalysis(int argc, char *argv[], string& _str)
{
	if (argc == 1) //非法输入
	{
		cout << "Invalid order:" << endl;
		system("exit");
	}
	else if (argc == 2 && !strcmp(argv[1], "-x")) //图形界面
		WinExec("WcProUI.exe", SW_NORMAL);
	else { //获取文件路径
		string str;
		for (int u = 1; u < argc; u++)
		{
			str += argv[u];
			str += " ";
		}
		_str = str;
	}
}

int main(int argc, char *argv[])
{
	
	string str;
	InputAnalysis(argc, argv, str);

	//str = "test.txt";
	WcFile m_File(str.c_str()); //初始化WcFile类

	m_File.MainProcess(); //检测，计数，排序

	m_File.SaveResult(); //输出结果

	return 0;
}
