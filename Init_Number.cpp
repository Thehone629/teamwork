#include <iostream>
#include <string.h>
#include "type.h"
using namespace std;    
	void Number::Init_Number()
	{
		cout<<"����������:"; 
		cin>>input;
		if( input[0] >= '0' && input[0] <= '9' )
		{
			letter = "��Ҽ��������½��ƾ�";
		} 
		else letter = "0123456789";
		length = input.length();
		return;
	}
	

