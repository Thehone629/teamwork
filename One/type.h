#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Number {
	
public:
	string input;	//����
	string output;	//ת����Ĵ�д����
	int length;
	bool flag;
	int temp;//����

	//void Init_Number();	//���� letter��ʼ�� ��������input��
	void Valid();	//�ж��Ƿ�Ϸ�  T/F->flag
	void Judge();//temp
	void Trans_Number0();//����ת��д 0
	void Trans_Number1();//��дת���� 1
	void Display();
};
