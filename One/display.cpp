#include "type.h"
using namespace std;

void Number::Display()
{
    Number num;
    string s;
    cout << "请输入要转换的数字：";
    cin >> s;
    num.input = s;
    //调试不成功
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
        cout << "转换后： " << num.output << endl;
    }
    else { 
        cout << "输入不合法，请重新输入" << endl;
    }
    
    
    
}