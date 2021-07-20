#pragma once
#include <iostream>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;
class Date
{
public:
	Date(int year = 2000, int month = 1, int day = 1);
	void Print();
	//�������������졣��ֵ���ء����Բ�д��Ĭ������
	Date& operator+=(int day);
	Date& operator-=(int day);
	Date operator+(int day);
	Date operator-(int day);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator >(const Date&d);
	bool operator <(const Date&d);
	bool operator >=(const Date&d);
	bool operator <=(const Date&d);
	bool operator ==(const Date&d);
	bool operator !=(const Date&d);
	int operator-(const Date&d);
		
private:
	int _year;
	int _month;
	int _day;
};