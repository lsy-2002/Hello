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
//	atomic<int> x = 0;//把x 变成原子的
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
//	printf("%d个线程并行对x++了%d次,x == %d\n", n, N, x);
//	return 0;
//}


//无论是正常执行结果，还是中途返回，还是抛异常
//智能指针lg都会在出了func函数作用域，都会调用自己的析构函数，
//保证一定能解锁
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
			cout << "加锁" << endl;
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
			cout << "解锁" << endl;
		}

		lock_guard(const lock_guard<Lock>& lock) = delete;

	private:
		Lock& _lock;
	};
}

mutex mtx;
void func()
{
	// 无论是正常执行？还是中途返回？还是抛异常？
	// 如何保证这里锁一定解锁了?
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
	char* p = new char[n];  // 抛异常

	// f1();				// 抛异常


	// ...
	//mtx.unlock();
}

mutex mtx;
void func()
{
	// 无论是正常执行？还是中途返回？还是抛异常？
	// 如何保证这里锁一定解锁了?
	//mtx.lock(); 
	// 指向让你保护打开文件这段代码？怎么办
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
	char* p = new char[n];  // 抛异常

	// f1();				// 抛异常


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