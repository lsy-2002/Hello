#define _CRT_SECURE_NO_WARNINGS 1
//http://www.cplusplus.com/
//www.cppreference.com
#include <iostream>
using namespace std;
#include <string>
#include <vector>
/*
//ascii����-��Ӣ��
//��ʾ�����������֣�-��unicode utf-8 utf-16 utf-32 gbk
int main()
{
	char str[] = "�й�";
	cout << strlen(str) << endl;//4
	wchar_t//���ֽ� 2byte
	return 0;
}

int main()
{
	string s1;
	string s2("hello world");
	string s3(s2);//s2��������
	string s4 = "hello world";//ֱ�ӹ���
	string s5(s4, 3, 5);//��s4���3��ʼѡ5��
	cout << s5 << endl;//lo wo
	string s5(s4, 3, string::npos);//����β
	cout << s5 << endl;//lo world
	string s6("123456", 3);//ȡǰ3��
	cout << s6 << endl;//123
	string s7(5,'x');
	cout << s7 << endl;//xxxxx

	return 0;
}

int main()
{
	string s1;
	string s2("hello world");
	//���ֱ���
	//1���±�+[]
	for (size_t i = 0; i < s2.size(); i++)//s2.length()
		//s2.operator[](i)
		cout << s2[i] << " ";//s2.at(i)
		//����[]Խ��-�����Ա���,atԽ�����쳣
	cout << endl;
	//2������������
	//[)����ҿ�
	//[begin(),end()) //end���ص�λ�ò������һ�����ݣ��������λ�õ���һ��λ��
	string::iterator it1 = s2.begin();//begin���ؿ�ʼλ��
	while (it1 != s2.end())
	{
		cout << *it1 << "";
		it1++;
	}
	cout << endl;
	//���������壺��string,vector֧��[]�ı���������list,map��������֧��[]
	//��������һ��ͳһʹ�õķ�ʽ
	vector<int> v = { 1, 2, 3, 4, 5 };
	vector<int>::iterator vit = v.begin();
	while (vit != v.end())
	{
		cout << *vit << "";
		vit++;
	}
	cout << endl;
	//���������
	string s3("123456");
	string::reverse_iterator rit = s3.rbegin();
	while (rit != s3.rend())
	{
		cout << *rit << "";
		rit++;
	}
	//3\C++ �ṩ��Χfor
	//����	ȡ�����е����ݣ���ֵ��e,�Զ��жϽ���
	for (auto e : s3)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}

int main()
{
	string s1;
	s1.push_back('h');//β��
	s1.append("world");
	cout << s1 << endl;
	string s2("hhhhh");
	s1.append(s2.begin(), s2.end());
	cout << s1 << endl;
	//ʵ�ʾ���Ӧ��+=
	string s3;
	s3 += "llll";
	cout << s3 << endl;
	s3.insert(0, "x");//��ָ��λ�ò���(�Ϸ�λ��)
	s3.insert(2, "d");
	cout << s3 << endl;
	s3.erase(0, 1);//��0��ʼɾ��1��
	cout << s3 << endl;
	return 0;
}

int main()
{
	string s1;
	string s2("hello world");
	cout << s1.size() << endl;//0
	cout << s2.size() << endl;//11
	cout << s1.capacity() << endl;//15 ��һ����'\0'
	cout << s2.capacity() << endl;//15
	s2.clear();//����������
	cout << s1.size() << endl;//0
	cout << s2.size() << endl;//0
	cout << s1.capacity() << endl;//15 ��һ����'\0'
	cout << s2.capacity() << endl;//15

	return 0;
}

int main()
{
	string s1;
	cout << s1.size() << endl;//0
	cout << s1.capacity() << endl;//15
	s1.resize(20);//�ڶ����в���n�����ݣ�Ĭ��������'\0'
	cout << s1.size() << endl;//20
	cout << s1.capacity() << endl;//31
	string s2("hello world");
	s2.resize(20, 'x');//�ں���׷��'x',ֱ��length(s2)��20
	cout << s2 << endl;
	string s3;
	s3.reserve(20);//�������ı�
	cout << s3.size() << endl;//0
	cout << s3.capacity() << endl;//31
	string s4;
	s4.reserve(127);
	//s4.resize(127);���ܣ���size��capacity���ı䣬����'\0'
	int oc = s4.capacity();
	for (char ch = 0; ch < 127; ch++)
	{
		//�����������->��reserve���
		s4 += ch;
		if (oc != s4.capacity())
		{
			cout << oc << "->" << s4.capacity() << endl;
			oc = s4.capacity();
		}
	}
	cout << s4 << endl;
	return 0;
}

int main()
{
	string s1("hello world");
	cout << s1 << endl;//���õ��Զ���������operator<<(cout,s1)
	cout << s1.c_str() << endl;//���õ�����������operator(cout,const char*)
	s1.resize(20);
	s1 += "!!!";
	cout << s1 << endl;
	cout << s1.c_str() << endl;
	//s1.strlen(s1.c_str());
	return 0;
}

int main()
{
	//����Ҫ��ȡ���ļ���׺
	string filename = "text.cpp";
	size_t pos = filename.find('.');
	if (pos != string::npos)
	{
		//string suff(filename, pos, filename.size() - pos);
		//string suff(filename, pos);
		//string suff = filename.substr(pos, filename.size() - pos);
		string suff = filename.substr(pos);
		cout << suff << endl;
	}
	return 0;
}

int main()
{
	string filename = "text.cpp.zip";
	size_t pos = filename.rfind('.');
	if (pos != string::npos)
	{
		//string suff(filename, pos, filename.size() - pos);
		//string suff(filename, pos);
		//string suff = filename.substr(pos, filename.size() - pos);
		string suff = filename.substr(pos);
		cout << suff << endl;
	}
	return 0;
}

string GetDomain(const string& url)//����
{
	size_t pos = url.find("://");
	if (pos != string::npos)
	{
		size_t sta = pos + 3;
		size_t end = url.find("/", sta);
		if (end != string::npos)
		{
			return url.substr(sta, end - sta);
		}
	}
	else
	{
		return string();//��������
	}
}
string GetProtocol(const string& url)//Э����
{
	size_t pos = url.find("://");
	if (pos != string::npos)
	{
		return url.substr(0, pos - 0);
	}
	else
	{
		return string();//��������
	}

}
int main()
{
	//Ҫ��ֱ�ȡ��������Э����
	string url1 = "http://www.cplusplus.com/reference/string/";
	string url2 = "https://www.cppreference.com/";
	cout << GetDomain(url1) << endl;
	cout << GetProtocol(url1) << endl;
	cout << GetDomain(url2) << endl;
	cout << GetProtocol(url2) << endl;
	return 0;
}
*/
