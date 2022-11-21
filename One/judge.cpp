#include "type.h"



int is_digit(char ch)
{
	if (ch >= '0' && ch <= '9') {
		return 1;
	}
	else {
		return 0;
	}
}

//temp = 0 大写->小写
//temp = 1 小写->大写 
void Number::Judge()
{
	if (is_digit(input[0])) {
		temp = 1;
	}
	else {
		temp = 0;
	}
}