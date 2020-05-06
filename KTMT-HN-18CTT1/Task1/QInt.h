#pragma once
#include "Header.h"
#include "Bit.h"

using namespace System;
using namespace System::Windows::Forms;

class QInt {
	unsigned int data[4];
public:
	enum class mode { binary, decimal, hexadecimal };
	mode md;//MODE ma User dang thao tac -> moi ket qua se hien theo he cua mode
	QInt();
	~QInt();

	unsigned int MulAdd(const unsigned int& mul, const unsigned int add);// xu li du lieu vao cho data[]
	//-----------------HELPER-----------------

	//-----------------CONVERT----------------
	void setMode();//chon mode theo enum class
	void setMode(int mode);
	void input(); //xu li input theo mode => lay data
	void print();//xu li output => in data theo mode ma user da chon
	void clear() { data[0] = data[1] = data[2] = data[3] = 0; };//Khoi tao
	void func_InToOut()
	{
		std::cout << "[>INPUT<]" << std::endl;
		input();
		std::cout << "[>OUTPUT<]" << std::endl;
		print();
	};// function chuyen doi cac he co so voi nhau



	//----------MATH-OPERATOR---------
	unsigned int operator[](int i)
	{
		return data[i];
	}

	QInt operator+(QInt);
	QInt operator-(QInt);
	QInt operator*(QInt);
	QInt operator/(QInt);
	void func_MathOperator()
	{
		//nhap operator
		QInt param1, param2;
		param1.input();
		param2.input();
		(param1 - param2).print();

	};



	//---------------COMPARERATIVE-OPERATOR-----------
	bool operator<(QInt);
	bool operator>(QInt);
	bool operator==(QInt);
	bool operator<=(QInt);
	bool operator>=(QInt);
	void func_CompareOperator()
	{
		//nhap operator
		QInt param1, param2;
		param1.input();
		param2.input();
		std::cout << (param1 >= param2);
	};


	void operator=(QInt param)
	{
		for (int i = 0; i < 4; i++)
		{
			data[i] = param.data[i];
		}
	}
	//-----------------BIT-OPERATOR----------------
	QInt operator&(QInt);
	QInt operator|(QInt);
	QInt operator^(QInt);
	QInt operator~();

	QInt operator>>(QInt);
	QInt operator<<(QInt);
	QInt rol();
	QInt ror();
	void func_BitOperator()
	{
		//nhap operator
		QInt param1, param2;
		param1.input();
		param2.input();
		QInt res = param1 & param2;
		res.print();
	};
	//--------------EXE-FUNCTION---------------
};