#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <mutex>


//在堆上设计一个类,只能创建
class HeapOnly
{
public:
	static HeapOnly* CreateObj()//创建
	{
		return new HeapOnly;
	}
	static HeapOnly* CopyObj(const HeapOnly& h)//拷贝
	{
		return new HeapOnly(h);
	}
private:
	HeapOnly()
	{}
	//拷贝构造私有，只声明不实现
	//防拷贝
	//C++98
	HeapOnly(const HeapOnly&);
	////C++11
	//public:
	//	HeapOnly(const HeapOnly&) = delete;
};
//在栈上设计一个类,
class StackOnly
{
public:
	StackOnly(){}//缺陷：不能禁掉在静态区的对象
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};

//设计一个类，不能被拷贝



//设计一个类，全局(一个进程中)只有一个唯一实例对象
//1、构造函数私有定义。构造拷贝和赋值拷贝禁掉
//饿汉模式 -- 程序开始main执行之前就创建单例对象
//提供一个静态指向单例对象的成员指针，初始化时new一个对象
class Singletion
{
public:
	static Singletion* GetInstance()
	{
		return _inst;
	}
	void Print()
	{
		std::cout << "Print()" << _a << std::endl;
	}
private:
	Singletion()
		:_a(0)
	{}
	Singletion(const Singletion&) = delete;
	Singletion& operator=(const Singletion&) = delete;
	static Singletion* _inst;
	int _a;
};

Singletion* Singletion::_inst = new Singletion;

//懒汉模式
//假设单例类构造函数中，要做很多配置初始化工作，饿汉就不合适-》导致程序启动慢
class Singletion
{
public:
	static Singletion* GetInstance()
	{
		//保护第一次需要加锁，后面都不需要加锁的场景，可以使用双检查加锁
		//特点：第一次加锁，后面不加锁，保护线程安全，提高效率
		if (_inst == nullptr)
		{
			_mtx.lock();
			if (_inst == nullptr)
			{

				_inst = new Singletion;
			}
			_mtx.unlock();
		}
		
		return _inst;
	}
	//实现一个内嵌垃圾回收类
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (Singletion::_inst)
			{
				delete Singletion::_inst;
			}
		}
	};
	//定义一个静态成员变量，程序结束时，系统自动调用它的析构函数从而释放单例对象
	static CGarbo Garbo;
	void Print()
	{
		std::cout << "Print()" << _a << std::endl;
	}
private:
	Singletion()
		:_a(0)
	{
		//假设单例类构造函数中，要做很多配置初始化工作，饿汉就不合适-》导致程序启动慢
	}
	~Singletion()
	{
		//程序结束时需处理，持久化保存数据..
	}
	Singletion(const Singletion&) = delete;
	Singletion& operator=(const Singletion&) = delete;
	static Singletion* _inst;
	static std::mutex _mtx;
	int _a;
};

Singletion* Singletion::_inst = nullptr;
std::mutex Singletion:: _mtx;
Singletion::CGarbo Garbo;




int main()
{
	return 0;
}