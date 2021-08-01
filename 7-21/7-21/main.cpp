#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

//namespace S
//{
//	//�����ַ��������飬������ɾ���
//	//�ַ�������Ľ�β��"\0"
//	class string
//	{
//	public:
//		string(const char* str = "")
//			:_str(new char[strlen(str) + 1])
//		{
//			strcpy(_str, str);
//		}
//		//��ͳд��
//		/*string(const string& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}
//		string operator=(const string&s)
//		{
//			if (this != &s)
//			{
//				delete[]_str;
//				_str = new char[strlen(s._str) + 1];
//				strcpy(_str, s._str);
//			}
//			return *this;
//		}*/
//		//�ִ�д��
//		string (const string& s)
//			:_str(nullptr)
//		{
//			string tmp(s._str);//����
//			swap(_str, tmp._str);
//		}
//		string& operator= (string s)
//		{
//			swap(_str, s._str);
//			return *this;
//		}
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//		const char* c_str()
//		{
//			return _str;
//		}
//	private:
//		char* _str;
//	};
//	void test_string1()
//	{
//		string s1("hello world");
//		string s2(s1);
//		cout << s1.c_str() << endl;
//		cout << s2.c_str() << endl;
//		string s3("hello lsy");
//		s1 = s3;
//		cout << s1.c_str() << endl;
//		cout << s3.c_str() << endl;
//	}
//}
//
//int main()
//{
//	S::test_string1();
//	return 0;
//}

namespace S
{
	//֧����ɾ���
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		const_iterator begin() const
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		string(const char* str = "")
		{
			_size = strlen(str);//_size���һλ����\0
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);//����
		/*	swap(_str, tmp._str);
			swap(_size, tmp._size);
			swap(_capacity, tmp._capacity);*/
			//this->swap(tmp)
			swap(tmp);
		}
		string& operator= (string s)
		{
			/*swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);*/
			swap(s);
			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}
		//����
		//at ���ú�operator[]����,Խ�����쳣
		
		const char& operator[](size_t i) const// ��
		{
			assert(i < _size);

			return _str[i];
		}
		char& operator[](size_t i)//�ɶ���д
		{
			assert(i < _size);
			return _str[i];
		}
		void reserve(size_t n)//���ռ䣬��չcapacity
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void resize(size_t n,char val = '\0')//���ռ�+��ʼ������չcapacity,�ҳ�ʼ���ռ�
		{
			//n < size
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				//n > capacity
				if (n > _capacity)
				{
					reserve(n);
				}
				// size < n < capacity
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = val;
					
				}
				_str[n] = '\0';
				_size = n;
			}
			
			
		}
		void push_back(char ch)
		{
			/*if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			_str[_size + 1] = '\0';
			_size++;*/
			insert(_size, ch);
		}
		void append(const char* str)
		{
			/*size_t len = _size + strlen(str);
			if (len > _capacity)
			{
				reserve(len);
			}
			strcpy(_str + _size, str);
			_size = len;*/
			insert(_size, str);
		}
		string& operator += (char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator += (const char *_str)
		{
			append(_str);
			return *this;
		}
		//posλ��֮ǰ����
		string& insert(size_t pos, const char *str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			//Ų������
			char* end = _str + _size;
			while (end >= _str + pos)
			{
				*(end + len) = *end;
				end--;
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size = _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			//���Ƽ�
			/*int end = _size;
			while (end > (int)pos)
			{
				_str[end - 1] = _str[end];
				end--;
			}*/
			/*size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}*/
			//��������ָ��
			char* end = _str + _size;
			while (end >= _str + pos)
			{
				*(end + 1) = *end;
				end--;
			}
			_str[pos] = ch;
			_size++;
			return *this;
		}
		string& erase(size_t pos, size_t len = npos)//npos = -1
		{
			assert(pos < _size);
			size_t leftlen = _size - pos;
			//ʣ����ַ�����С��Ҫɾ�ĳ���
			if (len >= leftlen)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else//ʣ����ַ����ȴ���Ҫɾ�ĳ���
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}
		size_t find(char ch, size_t pos = 0)
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);
			const char* ret = strstr(_str + pos, str);
			if (ret)
			{
				return ret - _str;
			}
			else
			{
				return npos;
			}
		}
		size_t size() const 
		{
			return _size;
		}
		const char* c_str() const 
		{
			return _str;
		}
		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const size_t npos;
	};
	const size_t string::npos = -1;
	inline bool operator <(const string& s1, const string s2)
	{
		return strcmp(s1.c_str(),s2.c_str()) < 0;
	}
	inline bool operator ==(const string& s1, const string s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}
	inline bool operator <=(const string& s1, const string s2)
	{
		return s1 < s2 || s1 == s2;
	}
	inline bool operator >(const string& s1, const string s2)
	{
		return !(s1 <= s2);
	}
	
	inline bool operator >=(const string& s1, const string s2)
	{
		return !(s1 < s2);
	}
	
	inline bool operator !=(const string& s1, const string s2)
	{
		return !(s1 == s2);
	}

	ostream& operator <<(ostream& out, const string&s)
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}
	istream& operator >>(istream&in, string& s)
	{
		s.clear();
		char ch;
		ch = in.get();
		while (ch != ' '&& ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}
	istream& getline(istream& in, string& s)
	{
		s.clear();
		char ch;
		ch = in.get();
		while (ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}
	void test1()
	{
		string s1("hello world");
		string s3("hello lsy");
		//������C++98,C++11��������ֵ���õ��ƶ����壬�Ż���swap����ģ��
		swap(s1, s3);//Ч�ʵ�
		s1.swap(s3);//Ч�ʸߣ��Ƽ�ʹ��

	}
	void f(const string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			
			cout << s[i] << endl;
		}
		cout << endl;
	}
	void func(const string& s)
	{
		string s1("hello world");
		string::const_iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	void test2()
	{
		string s1("hello world");
		s1[1] = 'm';
		cout << s1[1] << endl;
		cout << s1.c_str() << endl;
		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << endl;
		}
		cout << endl;
		f(s1);
	}
	void test3()
	{
		string s1("hello world");
		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			*it += 1;//�޸�
			cout << *it << " ";
		}
		cout << endl;
		string s;
	}
}
int main()
{
	S::test3();
	return 0;
}