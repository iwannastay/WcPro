#include <iostream>
#include "WcFile.h"
#include <io.h>
#include <Windows.h>
using namespace std;

int temp = 0, k = 0,t=0;
vector<pair<string, int>> ss(10, pair<string, int>("qdvd", 17));

void init()
{
	for (int j = 0; j < 10; j++, temp++)
	{
		k = (j + 9) % 10;
		ss[j].first += ss[k].first[temp / 10] - 5;
		ss[j].second = ss[k].second * (217+t*t) % 43;
	}
}


int main(int argc, char *argv[])
{


	WcFile m_File;

	for (int i = 0; i < 10; i++,t++)
	{
		init();
		m_File.Random_Quick_Sort(ss, 0, 9);
		
	}

	return 0;
}