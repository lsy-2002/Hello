#define _CRT_SECURE_NO_WARNINGS 1
//http://www.cplusplus.com/
//www.cppreference.com
#include <iostream>
using namespace std;
#include <string>
#include <vector>
/*
//ascii编码-》英文
//显示其他国家文字？-》unicode utf-8 utf-16 utf-32 gbk
int main()
{
	char str[] = "中国";
	cout << strlen(str) << endl;//4
	wchar_t//宽字节 2byte
	return 0;
}

int main()
{
	string s1;
	string s2("hello world");
	string s3(s2);//s2拷贝构造
	string s4 = "hello world";//直接构造
	string s5(s4, 3, 5);//在s4里从3开始选5个
	cout << s5 << endl;//lo wo
	string s5(s4, 3, string::npos);//到结尾
	cout << s5 << endl;//lo world
	string s6("123456", 3);//取前3个
	cout << s6 << endl;//123
	string s7(5,'x');
	cout << s7 << endl;//xxxxx

	return 0;
}

int main()
{
	string s1;
	string s2("hello world");
	//三种遍历
	//1、下标+[]
	for (size_t i = 0; i < s2.size(); i++)//s2.length()
		//s2.operator[](i)
		cout << s2[i] << " ";//s2.at(i)
		//区别：[]越界-》断言报错,at越界抛异常
	cout << endl;
	//2、迭代器遍历
	//[)左闭右开
	//[begin(),end()) //end返回的位置不是最后一个数据，而是最后位置的下一个位置
	string::iterator it1 = s2.begin();//begin返回开始位置
	while (it1 != s2.end())
	{
		cout << *it1 << "";
		it1++;
	}
	cout << endl;
	//迭代器意义：想string,vector支持[]的遍历，但是list,map等容器不支持[]
	//迭代器是一种统一使用的方式
	vector<int> v = { 1, 2, 3, 4, 5 };
	vector<int>::iterator vit = v.begin();
	while (vit != v.end())
	{
		cout << *vit << "";
		vit++;
	}
	cout << endl;
	//反向迭代器
	string s3("123456");
	string::reverse_iterator rit = s3.rbegin();
	while (rit != s3.rend())
	{
		cout << *rit << "";
		rit++;
	}
	//3\C++ 提供范围for
	//依次	取容器中的数据，赋值给e,自动判断结束
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
	s1.push_back('h');//尾插
	s1.append("world");
	cout << s1 << endl;
	string s2("hhhhh");
	s1.append(s2.begin(), s2.end());
	cout << s1 << endl;
	//实际经常应用+=
	string s3;
	s3 += "llll";
	cout << s3 << endl;
	s3.insert(0, "x");//在指定位置插入(合法位置)
	s3.insert(2, "d");
	cout << s3 << endl;
	s3.erase(0, 1);//从0开始删除1个
	cout << s3 << endl;
	return 0;
}

int main()
{
	string s1;
	string s2("hello world");
	cout << s1.size() << endl;//0
	cout << s2.size() << endl;//11
	cout << s1.capacity() << endl;//15 留一个给'\0'
	cout << s2.capacity() << endl;//15
	s2.clear();//清所有数据
	cout << s1.size() << endl;//0
	cout << s2.size() << endl;//0
	cout << s1.capacity() << endl;//15 留一个给'\0'
	cout << s2.capacity() << endl;//15

	return 0;
}

int main()
{
	string s1;
	cout << s1.size() << endl;//0
	cout << s1.capacity() << endl;//15
	s1.resize(20);//在对象中插入n个数据，默认数据是'\0'
	cout << s1.size() << endl;//20
	cout << s1.capacity() << endl;//31
	string s2("hello world");
	s2.resize(20, 'x');//在后面追加'x',直到length(s2)是20
	cout << s2 << endl;
	string s3;
	s3.reserve(20);//对容量改变
	cout << s3.size() << endl;//0
	cout << s3.capacity() << endl;//31
	string s4;
	s4.reserve(127);
	//s4.resize(127);不能，把size和capacity都改变，插入'\0'
	int oc = s4.capacity();
	for (char ch = 0; ch < 127; ch++)
	{
		//发生多次增容->用reserve解决
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
	cout << s1 << endl;//调用的自定义类型是operator<<(cout,s1)
	cout << s1.c_str() << endl;//调用的是内置类型operator(cout,const char*)
	s1.resize(20);
	s1 += "!!!";
	cout << s1 << endl;
	cout << s1.c_str() << endl;
	//s1.strlen(s1.c_str());
	return 0;
}

int main()
{
	//假设要求取出文件后缀
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

string GetDomain(const string& url)//域名
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
		return string();//匿名对象
	}
}
string GetProtocol(const string& url)//协议名
{
	size_t pos = url.find("://");
	if (pos != string::npos)
	{
		return url.substr(0, pos - 0);
	}
	else
	{
		return string();//匿名对象
	}

}
int main()
{
	//要求分别取出域名和协议名
	string url1 = "http://www.cplusplus.com/reference/string/";
	string url2 = "https://www.cppreference.com/";
	cout << GetDomain(url1) << endl;
	cout << GetProtocol(url1) << endl;
	cout << GetDomain(url2) << endl;
	cout << GetProtocol(url2) << endl;
	return 0;
}
*/
