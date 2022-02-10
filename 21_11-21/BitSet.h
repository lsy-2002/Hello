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
//		//������
//	}
//	else
//	{
//		assert(false);
//	}
//
//}
namespace hs
{
	
	template<size_t N>//N�Ƕ�󣬾Ϳ�����λͼ
	class BitSet
	{
	public:
		BitSet()
		{
			_bs.resize(N / 32 + 1, 0);
		}
		//��Xӳ���λ��ǳ�1
		void Set(size_t x)
		{
			//���Xӳ���λ�ڵ�i������
			//���Xӳ���λ����������ĵ�j��λ
			size_t i = x / 32;
			size_t j = x % 32;
			//��bs[i]�ĵ�jλ��ǳ�1�����Ҳ�Ӱ������λ
			_bs[i] |= (1 << j);

		}
		void RSet(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			//��bs[i]�ĵ�jλ��ǳ�0�����Ҳ�Ӱ������λ
			_bs[i] &= (~(i << j));
		}
		bool Test(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			//�����jλ��1������Ƿ�0����0Ϊ��
			//�����jλ��1�������0��0Ϊ��
			return _bs[i] & (i << j);
		}
		
	private:
		vector<int> _bs;
	};
}