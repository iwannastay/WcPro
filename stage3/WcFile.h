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
	static int Line_Size;	//ÿ���ַ�����
	int Line_Num;			//����
	char *File_Line;		//���ַ�
	string Add_Tail;		//β�ַ���
	//char Record[26][28];	//�������
	map<string, int> Word_List;				//��¼��
	vector<pair<string, int>> Rank_List;	//����

	
	string ResultFile_Name;	//����ļ�·��
	fstream File_Stream;	//�ļ���

	string Regex_Name = "[[:alpha:]]+(-[[:alpha:]]+)*";	//������ʽ
	
public:
	string File_Name;	//�����ļ��������ڲ���

};