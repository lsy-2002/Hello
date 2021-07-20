#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"
inline int GetMonthDay(int year, int month)//频繁调用
{
	//数组存储平年每个月的天数
	int DayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = DayArray[month];
	if ((year % 4 == 0 && year % 400 != 0) || year % 400 == 0 && month == 2)
	{
		day = 29;
	}
	return day;
}
Date::Date(int year, int month, int day)
{
	//检查日期的合法性
	if (year >= 0
		&&(month >0 && month < 13)
		&& day <= GetMonthDay(year,month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "非法日期" << endl;
		assert(false);
	}
}
void Date::Print()
{
	cout << _year << "年" << _month << "月" << _day << "天" << endl;

}
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= -day;
	}
	else
	{
		_day += day;
		//天数不合法，不断进位
		while (_day >= GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month > 12)
			{
				++_year;
				_month = 1;
			}
		}
	}
	
	return*this;

}
Date Date::operator+(int day)//复用
{
	Date tmp(*this);
	//复用operator+=
	tmp += day;//tmp.operator+=(day)
	return tmp;
}
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		_day += -day;
	}
	else
	{
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
	}
	
	return *this;
}
Date Date::operator-(int day)
{
	Date tmp = *this;
	//Date tmp(*this);
	tmp -= day;//tmp.operator-=(&tmp.day)
	return tmp;
}
Date& Date::operator++()
{
	*this += 1;
	return *this;
	//++d->d.operator++(&d)
}
Date Date::operator++(int)
{
	//d++->d.operator++(&d,0)
	//int参数不需要给实参，没用，它的作用是为了跟前置++构成函数重载
	Date tmp(*this);
	*this += 1;
	return tmp;
}
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int )
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
//d1>d2->d1.operator>(&d1,d2)
bool Date::operator >(const Date&d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month = d._month)
		{
			if (_day > d._day)
				return true;
		}
	}
	return false;
}
bool Date::operator ==(const Date&d)
{
	return _year == d._year
		&&_month == d._month
		&&_day == d._day;
}
//复用
bool Date::operator <(const Date&d)
{
	return !(*this >= d);
}
bool Date::operator >=(const Date&d)
{
	return *this > d || *this == d;
}
bool Date::operator <=(const Date&d)
{
	return !(*this > d);
}

bool Date::operator !=(const Date&d)
{
	return !(*this == d);
}
int Date::operator-(const Date&d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;

	}
	return n * flag;
}
