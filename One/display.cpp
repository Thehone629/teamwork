#include "type.h"
using namespace std;

void Number::Display()
{
    Number num;
    string s;
    cout << "������Ҫת�������֣�";
    cin >> s;
    num.input = s;
    //���Բ��ɹ�
    //num.Valid();
    num.flag = 1;
    cout << "input = " << num.input << endl;
    num.Judge();
    
    
    if (num.flag) {
        if (num.temp) {
            num.Trans_Number0();
        }
        else {
            num.Trans_Number1();
        }
        cout << "ת���� " << num.output << endl;
    }
    else { 
        cout << "���벻�Ϸ�������������" << endl;
    }
    
    
    
}