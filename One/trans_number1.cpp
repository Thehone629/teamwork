#include"type.h"
#include<istream>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;



void Number::Trans_Number1() {
	string copy_input = input;
	for (int i = 0; i < 13; i++) {
		int temp = 0;
		if (copy_input.find("��") != string::npos) copy_input = copy_input.replace(copy_input.find("��"), 2, "0");
		if (copy_input.find("Ҽ") != string::npos) copy_input = copy_input.replace(copy_input.find("Ҽ"), 2, "1");
		if (copy_input.find("��") != string::npos) copy_input = copy_input.replace(copy_input.find("��"), 2, "2");
		if (copy_input.find("��") != string::npos) copy_input = copy_input.replace(copy_input.find("��"), 2, "3");
		if (copy_input.find("��") != string::npos) copy_input = copy_input.replace(copy_input.find("��"), 2, "4");
		if (copy_input.find("��") != string::npos) copy_input = copy_input.replace(copy_input.find("��"), 2, "5");
		if (copy_input.find("½") != string::npos) copy_input = copy_input.replace(copy_input.find("½"), 2, "6");
		if (copy_input.find("��") != string::npos) copy_input = copy_input.replace(copy_input.find("��"), 2, "7");
		if (copy_input.find("��") != string::npos) copy_input = copy_input.replace(copy_input.find("��"), 2, "8");
		if (copy_input.find("��") != string::npos) copy_input = copy_input.replace(copy_input.find("��"), 2, "9");
	}
	if (copy_input.find("Ԫ��") != string::npos) copy_input = copy_input.erase(copy_input.find("Ԫ��"), 4);
	if (copy_input.rfind('��') == copy_input.length() - 1) copy_input = copy_input + "00000000";
	if (copy_input.rfind('��') == copy_input.length() - 1) copy_input = copy_input + "0000";
	if (copy_input.rfind('��') == copy_input.length() - 1) copy_input = copy_input + "00";
	if (copy_input.rfind('ʮ') == copy_input.length() - 1) copy_input = copy_input + "0";

	if (copy_input.find("��") != string::npos) copy_input = copy_input.erase(copy_input.find("��"), 2);
	if (copy_input.find("��") != string::npos) copy_input = copy_input.erase(copy_input.find("��"), 2);

	for (int i = 0; i < 5; i++) {
		int temp = 0;
		if (copy_input.find("��") != string::npos) copy_input = copy_input.erase(copy_input.find("��"), 2);
		if (copy_input.find("Ǫ") != string::npos) copy_input = copy_input.erase(copy_input.find("Ǫ"), 2);
		if (copy_input.find("ʰ") != string::npos) copy_input = copy_input.erase(copy_input.find("ʰ"), 2);
	}
	output = copy_input;

}//��дת���� 1

