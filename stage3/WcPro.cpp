#include <iostream>
#include "WcFile.h"
#include <io.h>
#include <Windows.h>
using namespace std;


//�������
void InputAnalysis(int argc, char *argv[], string& _str)
{
	if (argc == 1) //�Ƿ�����
	{
		cout << "Invalid order:" << endl;
		system("exit");
	}
	else if (argc == 2 && !strcmp(argv[1], "-x")) //ͼ�ν���
		WinExec("WcProUI.exe", SW_NORMAL);
	else { //��ȡ�ļ�·��
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
	WcFile m_File(str.c_str()); //��ʼ��WcFile��

	m_File.MainProcess(); //��⣬����������

	m_File.SaveResult(); //������

	return 0;
}
