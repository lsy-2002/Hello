#pragma once
#include "HashTable.h"
//void set(size_t x)
//{
//	//00->01
//	if (!_bs1.Test(x) && !_bs[2].Test(x))
//	{
//		_bs1.Set(x);
//	}
//	//01->10
//	else if (!_bs1.Test(x) && _bs2.Test(x))
//	{
//		_bs1.Set(x);
//		_bs2.RSet(x);
//	}
//	//10->10
//	else if (_bs1.Test(x) && !_bs2.Test(x))
//	{
//		//不处理
//	}
//	else
//	{
//		assert(false);
//	}
//
//}
namespace hs
{
	
	template<size_t N>//N是多大，就开多大的位图
	class BitSet
	{
	public:
		BitSet()
		{
			_bs.resize(N / 32 + 1, 0);
		}
		//把X映射的位标记成1
		void Set(size_t x)
		{
			//算出X映射的位在第i个整数
			//算出X映射的位在这个整数的第j个位
			size_t i = x / 32;
			size_t j = x % 32;
			//把bs[i]的第j位标记成1，并且不影响其他位
			_bs[i] |= (1 << j);

		}
		void RSet(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			//把bs[i]的第j位标记成0，并且不影响其他位
			_bs[i] &= (~(i << j));
		}
		bool Test(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			//如果第j位是1，结果是非0，非0为真
			//如果第j位是1，结果是0，0为假
			return _bs[i] & (i << j);
		}
		
	private:
		vector<int> _bs;
	};
}