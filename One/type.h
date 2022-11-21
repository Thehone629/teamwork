#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Number {
	
public:
	string input;	//输入
	string output;	//转换后的大写数字
	int length;
	bool flag;
	int temp;//类型

	//void Init_Number();	//输入 letter初始化 输入数据input流
	void Valid();	//判断是否合法  T/F->flag
	void Judge();//temp
	void Trans_Number0();//数字转大写 0
	void Trans_Number1();//大写转数字 1
	void Display();
};
