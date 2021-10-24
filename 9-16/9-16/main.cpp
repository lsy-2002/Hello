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
	/*cout << "正常输出" << endl;
	cerr << "错误输出" << endl;
	clog << "日志输出" << endl;*/
	//Student s;
	//cin >> s._name >> s._age;
	//cout << "名字:" << s._name << "年龄:" << s._age << endl;

	//scanf("%s%d", s._name.c_str(), &s._age);
	//printf("名字：%s,年龄:%d\n", s._name.c_str(), s._age);
	////如果第二个输入长度大于第一个，会越界，严格来说就崩了
	////但是VS下string进行了特殊处理，当小于16会存到Buf指针中

	//Student s;
	//cin >> s._name >> s._age;//数据从设备(终端)流向对象中(内存)
	//cout << "名字:" << s._name << "年龄:" << s._age << endl;//数据从对象(内存)流向设备(终端)

	////s._name.resize(100);//提前开好空间就不会出错
	//scanf("%s%d", s._name.c_str(), &s._age);
	//cout << "名字:" << s._name << "年龄:" << s._age << endl;
	////printf("名字：%s,年龄:%d\n", s._name.c_str(), s._age);
	////建议：1.C++尽量用cin/cout
	////2.用cout和cin 不方便的地方用scanf和printf
//	string line;
//	/*
//	cin >> line;
//	cout << line << endl;*/
//	getline(cin, line);//获取字符串以换行结束的
//	cout << line << endl;
//	//内置类型可以支持输入输出，自定义类型不能
//	//自定义类型想要cout和cin输入输出，需要自己重载 << >>运算符
//	return 0;
//}
//*/
//int main()
//{
//	string str;
//	//多行输入 ctrl+c结束
//	//operator >>(cin,str)->return cin 对象，
//	//cin 可以做逻辑判断： operator void*()const -istream对象可以转化成空指针
//	//调用 operator bool() const;->返回真假
//	//自定义类型对象可以直接做条件逻辑判断
//	//可以重载operator void*()或operator bool
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
//		cout << (char)ifs.get();//返回整形，强转为字符型
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
//		//C++独有
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
//		//C++独有
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
//	ServerInfo winfo = { "191.0.0.4", 80 };//写
//	ServerInfo rinfo;//读
//	//读写 -- 二进制 读写简单，高效快捷
//	//缺点：除字符和字符串，从内存写到文件，都是乱码
//	/*ConfigManager cfbin("config.bin");
//	cfbin.ReadBin(winfo);
//	cfbin.WriteBin(rinfo);*/
//	//读写 -- 文本
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
	////信息-》字符串 称为序列化
	//sprintf(buff, "%s%d", info._ip, info._port);//转成自负串放到buff里
	//ServerInfo rinfo;
	////反序列化 把字符串还原成结构体
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