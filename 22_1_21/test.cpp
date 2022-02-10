#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>
using namespace std;
//mutex mtx;
//
//void f(int N)
//{
//	mtx.lock();
//	for (int i = 0; i < N; ++i)
//	{
//		cout <<this_thread::get_id()<<":" <<i << endl;
//	}
//	mtx.unlock();
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	vector<thread> vthreads;
//	vthreads.resize(n);
//	for (auto& td : vthreads)
//	{
//		td = thread(f, 100);
//		//cout << td.get_id() << endl;
//	}
//	for (auto& td : vthreads)
//	{
//		td.join();
//	}
//	return 0;
//}



//int main()
//{
//	int n;
//	cin >> n;
//	mutex mtx;
//	vector<thread> vthreads;
//	vthreads.resize(n);;
//	int N = 100;
//	atomic<int> x = 0;//��x ���ԭ�ӵ�
//	for (auto& td : vthreads)
//	{
//		td = thread([&mtx, &N,&x]
//
//		{
//			mtx.lock();
//			for (int i = 0; i < N; i++)
//			{
//				++x;
//			}
//			mtx.unlock();
//		}
//			);
//		//cout << td.get_id() << endl;
//	}
//	for (auto& td : vthreads)
//	{
//		td.join();
//	}
//	printf("%d���̲߳��ж�x++��%d��,x == %d\n", n, N, x);
//	return 0;
//}


//����������ִ�н����������;���أ��������쳣
//����ָ��lg�����ڳ���func���������򣬶�������Լ�������������
//��֤һ���ܽ���
// RAII
namespace RAII
{
	template<class Lock>
	class lock_guard
	{
	public:
		lock_guard(Lock& lock)
			:_lock(lock)
		{
			_lock.lock();
			cout << "����" << endl;
		}

		/*void lock()
		{
		_lock.lock();
		}

		void unlock()
		{
		_lock.unlock();
		}*/

		~lock_guard()
		{
			_lock.unlock();
			cout << "����" << endl;
		}

		lock_guard(const lock_guard<Lock>& lock) = delete;

	private:
		Lock& _lock;
	};
}

mutex mtx;
void func()
{
	// ����������ִ�У�������;���أ��������쳣��
	// ��α�֤������һ��������?
	//mtx.lock(); 
	RAII::lock_guard<mutex> lg(mtx);
	// ...

	FILE* fout = fopen("test.txt", "r");
	if (fout == nullptr)
	{
		// ....
		//mtx.unlock();
		return;
	}

	int n;
	cin >> n;
	char* p = new char[n];  // ���쳣

	// f1();				// ���쳣


	// ...
	//mtx.unlock();
}

mutex mtx;
void func()
{
	// ����������ִ�У�������;���أ��������쳣��
	// ��α�֤������һ��������?
	//mtx.lock(); 
	// ָ�����㱣�����ļ���δ��룿��ô��
	{
		RAII::lock_guard<mutex> lg(mtx);

		FILE* fout = fopen("test.txt", "r");
		if (fout == nullptr)
		{
			// ....
			//mtx.unlock();
			//return;
		}
	}

	int n;
	cin >> n;
	char* p = new char[n];  // ���쳣

	// f1();				// ���쳣


	// ...
	//mtx.unlock();
}

int main()
{
	try{
		func();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}