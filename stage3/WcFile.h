#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <regex>  

using namespace std;

class WcFile
{
public:
	WcFile() :WcFile("empty path") {}
	WcFile(const char*);
	~WcFile();

	bool LoadFile(const char*);
	void SaveResult();
	
	void LineProcess();
	void RankProcess();
	void MainProcess();

	void Insert(string&);

	int Partition(vector<pair<string, int>>& A, int p, int q);

	int Random_Partition(vector<pair<string, int>>& A, int p, int q);

	void Random_Quick_Sort(vector<pair<string, int>>& A, int p, int q);

	void Swap(pair<string, int>& m, pair<string, int>& n);

	bool ComparePriority(pair<string, int>& m, pair<string, int>& n);


private:
	static int Line_Size;	//每行字符上限
	int Line_Num;			//行数
	char *File_Line;		//行字符
	string Add_Tail;		//尾字符串
	//char Record[26][28];	//标记数组
	map<string, int> Word_List;				//记录集
	vector<pair<string, int>> Rank_List;	//排序集

	
	string ResultFile_Name;	//输出文件路径
	fstream File_Stream;	//文件流

	string Regex_Name = "[[:alpha:]]+(-[[:alpha:]]+)*";	//正则表达式
	
public:
	string File_Name;	//输入文件名，便于测试

};