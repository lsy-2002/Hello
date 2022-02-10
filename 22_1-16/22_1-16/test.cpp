#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <mutex>


//�ڶ������һ����,ֻ�ܴ���
class HeapOnly
{
public:
	static HeapOnly* CreateObj()//����
	{
		return new HeapOnly;
	}
	static HeapOnly* CopyObj(const HeapOnly& h)//����
	{
		return new HeapOnly(h);
	}
private:
	HeapOnly()
	{}
	//��������˽�У�ֻ������ʵ��
	//������
	//C++98
	HeapOnly(const HeapOnly&);
	////C++11
	//public:
	//	HeapOnly(const HeapOnly&) = delete;
};
//��ջ�����һ����,
class StackOnly
{
public:
	StackOnly(){}//ȱ�ݣ����ܽ����ھ�̬���Ķ���
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};

//���һ���࣬���ܱ�����



//���һ���࣬ȫ��(һ��������)ֻ��һ��Ψһʵ������
//1�����캯��˽�ж��塣���쿽���͸�ֵ��������
//����ģʽ -- ����ʼmainִ��֮ǰ�ʹ�����������
//�ṩһ����ָ̬��������ĳ�Աָ�룬��ʼ��ʱnewһ������
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

//����ģʽ
//���赥���๹�캯���У�Ҫ���ܶ����ó�ʼ�������������Ͳ�����-�����³���������
class Singletion
{
public:
	static Singletion* GetInstance()
	{
		//������һ����Ҫ���������涼����Ҫ�����ĳ���������ʹ��˫������
		//�ص㣺��һ�μ��������治�����������̰߳�ȫ�����Ч��
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
	//ʵ��һ����Ƕ����������
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
	//����һ����̬��Ա�������������ʱ��ϵͳ�Զ������������������Ӷ��ͷŵ�������
	static CGarbo Garbo;
	void Print()
	{
		std::cout << "Print()" << _a << std::endl;
	}
private:
	Singletion()
		:_a(0)
	{
		//���赥���๹�캯���У�Ҫ���ܶ����ó�ʼ�������������Ͳ�����-�����³���������
	}
	~Singletion()
	{
		//�������ʱ�账���־û���������..
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