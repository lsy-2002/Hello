#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
/*
struct Student
{
	string _name = "peter";
	int _age = 18;
};

int main()
{
	/*cout << "�������" << endl;
	cerr << "�������" << endl;
	clog << "��־���" << endl;*/
	//Student s;
	//cin >> s._name >> s._age;
	//cout << "����:" << s._name << "����:" << s._age << endl;

	//scanf("%s%d", s._name.c_str(), &s._age);
	//printf("���֣�%s,����:%d\n", s._name.c_str(), s._age);
	////����ڶ������볤�ȴ��ڵ�һ������Խ�磬�ϸ���˵�ͱ���
	////����VS��string���������⴦����С��16��浽Bufָ����

	//Student s;
	//cin >> s._name >> s._age;//���ݴ��豸(�ն�)���������(�ڴ�)
	//cout << "����:" << s._name << "����:" << s._age << endl;//���ݴӶ���(�ڴ�)�����豸(�ն�)

	////s._name.resize(100);//��ǰ���ÿռ�Ͳ������
	//scanf("%s%d", s._name.c_str(), &s._age);
	//cout << "����:" << s._name << "����:" << s._age << endl;
	////printf("���֣�%s,����:%d\n", s._name.c_str(), s._age);
	////���飺1.C++������cin/cout
	////2.��cout��cin ������ĵط���scanf��printf
//	string line;
//	/*
//	cin >> line;
//	cout << line << endl;*/
//	getline(cin, line);//��ȡ�ַ����Ի��н�����
//	cout << line << endl;
//	//�������Ϳ���֧������������Զ������Ͳ���
//	//�Զ���������Ҫcout��cin�����������Ҫ�Լ����� << >>�����
//	return 0;
//}
//*/
//int main()
//{
//	string str;
//	//�������� ctrl+c����
//	//operator >>(cin,str)->return cin ����
//	//cin �������߼��жϣ� operator void*()const -istream�������ת���ɿ�ָ��
//	//���� operator bool() const;->�������
//	//�Զ������Ͷ������ֱ���������߼��ж�
//	//��������operator void*()��operator bool
//	while (cin >> str)
//	{
//		cout << str << endl;
//	}
//
//	return 0;
//}
//void Readfile()
//{
//	ifstream ifs("main.cpp");
//	char ch;
//	/*while ((ch = ifs.get()) != EOF)
//	{
//		cout << ch;
//	}*/
//	/*while (ifs.get(ch))
//	{
//		cout << ch;
//	}*/
//	while (ifs)
//	{
//		cout << (char)ifs.get();//�������Σ�ǿתΪ�ַ���
//	}
//}
//void Writefile()
//{
//	ofstream ofs("write.txt");
//	ofs.put('x');
//	ofs.write("hello world",10);
//}
//struct ServerInfo
//{
//	char _ip[20];
//	int _port;
//};
//struct ConfigManager
//{
//public:
//	ConfigManager(const char* filename)
//		:_filename(filename)
//	{}
//	void ReadBin(ServerInfo& info)
//	{
//		ifstream ifs(_filename);
//		ifs.read((char*)&info, sizeof(info));
//	}
//	void WriteBin(const ServerInfo& info)
//	{
//		ofstream ofs(_filename);
//		ofs.write((char*)&info, sizeof(info));
//	}
//	void Readtxt(ServerInfo& info)
//	{
//		/*ifstream ifs(_filename);
//		ifs.getline(info._ip, 20);
//		char portbuff[20];
//		ifs.getline(portbuff, 20);
//		info._port = stoi(portbuff);*/
//		//C++����
//		ifstream ifs(_filename);
//		ifs >> info._ip >> info._port;
//	}
//	void Writetxt(const ServerInfo& info)
//	{
//		/*ofstream ofs(_filename);
//		ofs.write(info._ip, strlen(info._ip));
//		ofs.put('\n');
//		string poststr = to_string(info._port);
//		ofs.write(poststr.c_str(), poststr.size());*/
//		//C++����
//		ofstream ofs(_filename);
//		ofs << info._ip << '\n'<< info._port;
//	}
//private:
//	string _filename;
//};
//int main()
//{
//	/*Readfile();
//	Writefile();*/
//	ServerInfo winfo = { "191.0.0.4", 80 };//д
//	ServerInfo rinfo;//��
//	//��д -- ������ ��д�򵥣���Ч���
//	//ȱ�㣺���ַ����ַ��������ڴ�д���ļ�����������
//	/*ConfigManager cfbin("config.bin");
//	cfbin.ReadBin(winfo);
//	cfbin.WriteBin(rinfo);*/
//	//��д -- �ı�
//	ConfigManager cfbin("config.txt");
//	cfbin.Readtxt(rinfo);
//	cfbin.Writetxt(winfo);
//
//	return 0;
//}
struct ServerInfo
{
	char _ip[20];
	int _port;
};
int main()
{
	ServerInfo info = { "191.0.0.4", 800 };
	//char buff[128];
	////��Ϣ-���ַ��� ��Ϊ���л�
	//sprintf(buff, "%s%d", info._ip, info._port);//ת���Ը����ŵ�buff��
	//ServerInfo rinfo;
	////�����л� ���ַ�����ԭ�ɽṹ��
	//sscanf(buff, "%s%d", rinfo._ip, &rinfo._port);
	/*stringstream ssm;
	ssm << info._ip << " " << info._port;
	string buff = ssm.str();*/

	stringstream ssm;
	ssm.str("121.0.0.1 90");
	//stringstream ssm("121.0.0.1 90");
	ServerInfo rinfo;
	ssm >> rinfo._ip >> rinfo._port;
	
	return 0;
}