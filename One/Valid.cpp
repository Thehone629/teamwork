
#include "type.h"
#include <string>

using namespace std;

void Number::Valid()
{

    int f = 1;
    //ÅĞ¶ÏÊÇ·ñÊÇĞ¡Ğ´Êı×Ö
    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= '0' && input[i] <= '9') continue;
        else {
            f = 0;
            break;
        }
    }
    //È«ÊÇĞ¡Ğ´Êı×Ö£¬ºÏ·¨
    if (f == 1) {
        flag = 1;
        return;
    }
    
    //ÅĞ¶ÏÊÇ²»ÊÇ´óĞ´Êı×Ö×Ö·û
    //ÁãÒ¼·¡ÈşËÁÎéÂ½Æâ°Æ¾ÁÊ°°ÛÇªÍòÒÚ
    // {"Áã","Ò¼","·¡","Èş","ËÁ","Îé","Â½","Æâ","°Æ","¾Á","Ê°","°Û","Çª","Íò","ÒÚ"} ;
    string temp1 = input;
    f = 1;
    for (int i = 0;i < temp1.size();i = i + 2)
    {
        //ÇĞ¸îÖĞÎÄ×Ö·û
        char a[3] = "";
        a[0] = temp1[i];
        a[1] = temp1[i + 1];
        a[2] = '\0';
        //ÅĞ¶ÏÊÇ·ñÊÇÊı×Ö»òµ¥Î»
        if (!strcmp(a, "Áã") || a == "Ò¼" || a == "·¡" || a == "Èş" || a == "ËÁ"
            || a == "Îé" || a == "Â½" || a == "Æâ" || a == "°Æ" || a == "¾Á"
            || a == "Ê°" || a == "°Û" || a == "Çª" || a == "Íò" || a == "ÒÚ")
        {
            f = 0;
        }
        cout << "a = " << a <<  "    " << strcmp(a, "Áã") << endl;
        //·Ç·¨
        if (f == 1) {

            flag = 0;
            return;
        }
        f = 1;
    }
    flag = 0;
}
