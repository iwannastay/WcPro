#include "WcFile.h"

#define ADD_L 50

int WcFile::Line_Size = 2000;

WcFile::WcFile(const char * _filename)
{
	Line_Num = 0;
	File_Line = (char*)malloc((Line_Size + ADD_L) * sizeof(char));
	memset(File_Line, '\0', (Line_Size + ADD_L) * sizeof(char));
	Rank_List.reserve(100);
	//Record[0][0] = 0;
	ResultFile_Name = "result.txt";

	Regex_Name = "[[:alpha:]]+(-[[:alpha:]]+)*";

	LoadFile(_filename);
}

WcFile::~WcFile()
{
	free(File_Line);
	File_Line = nullptr;

}

//导入文件
bool WcFile::LoadFile(const char *_filename)
{
	File_Name = _filename;
	File_Stream.open(File_Name);
	if (!File_Stream)
	{
		cout << "Fail to open the source file:" << File_Name << endl;
		system("exit");
	}
	return true;
}

//保存结果
void WcFile::SaveResult()
{
	File_Stream.close();
	File_Stream.open(ResultFile_Name);
	if (!File_Stream)
	{
		cout << "Fail to open the result file." << endl;
		system("exit");
	}

	for (int i = 0; i < 100 && i < Rank_List.size(); i++)
		File_Stream << Rank_List[i].first << "\t" << Rank_List[i].second << endl;
	File_Stream.close();
}

//文件行处理
void WcFile::LineProcess()
{
	regex r(Regex_Name);
	string test_str = File_Line;
	for (sregex_iterator it(test_str.begin(), test_str.end(), r), end_it; it != end_it; it++)
	{
		string str = it->str();
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		Insert(str);
	}
}

//词频排序
void WcFile::RankProcess()
{
	int count = 0, size = Word_List.size();
	map<string, int>::iterator iter = Word_List.begin();
	while (iter != Word_List.end())
	{
		Rank_List.push_back(*iter);
		iter++;
	}
	//随机快排
	Random_Quick_Sort(Rank_List, 0, Rank_List.size() - 1);
}

//文件处理框架
void WcFile::MainProcess()
{

	int Add_Length;
	while (!File_Stream.eof())
	{
		File_Stream.read(File_Line, Line_Size);
		File_Stream >> Add_Tail;
		Add_Length = Add_Tail.length();
		_ASSERT(Add_Length < ADD_L);
		memcpy_s(File_Line + Line_Size, Add_Length, Add_Tail.c_str(), Add_Length);
		File_Line[Line_Size + Add_Length + 1] = '\0';

		LineProcess();
	}

	RankProcess();
}

//插入单词记录集
void WcFile::Insert(string& _str)
{
	auto iter = Word_List.find(_str);
	if (iter != Word_List.end())
		iter->second++;
	else
		Word_List.insert(pair<string, int>(_str, 1));

	/*if (!Record[_str[0] - 97][_str[1] - 97])
	{
		Word_List.insert(pair<string, int>(_str, 1));
		Record[_str[0] - 97][_str[1] - 97]++;
	}
	else
	{
		auto iter = Word_List.find(_str);
		if (iter != Word_List.end())
			iter->second++;
		else
		{
			Word_List.insert(pair<string, int>(_str, 1));
			Record[_str[0] - 97][_str[1] - 97]++;
		}
	}*/
}


//快速排序分划程序
int WcFile::Partition(vector<pair<string, int>> &A, int p, int q)
{
	auto x = A[p];
	int i = p;
	for (int j = p + 1; j <= q; j++)
	{
		if (ComparePriority(A[j], x))
		{
			i = i + 1;
			Swap(A[i], A[j]);
		}
	}
	Swap(A[p], A[i]);
	return i;
}

//随机化快速排序分划程序
int WcFile::Random_Partition(vector<pair<string, int>> &A, int p, int q)
{
	int i = rand() % (q - p) + p;
	Swap(A[i], A[p]);
	return Partition(A, p, q);
}

//随机化快速排序
void WcFile::Random_Quick_Sort(vector<pair<string, int>> &A, int p, int q)
{
	if (p < q)
	{
		int i = Random_Partition(A, p, q);
		Random_Quick_Sort(A, p, i - 1);
		Random_Quick_Sort(A, i + 1, q);
	}
}

//交换元素
void WcFile::Swap(pair<string, int> &m, pair<string, int> &n)
{
	pair<string, int> tmp;
	tmp = m;
	m = n;
	n = tmp;
}

//首字母排序
bool WcFile::ComparePriority(pair<string, int> &m, pair<string, int> &n)
{
	if (m.second != n.second)
		return m.second > n.second ? true : false;
	else
		return m.first < n.first ? true : false;
}
