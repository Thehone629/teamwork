
#include "type.h"
#include <string>

using namespace std;

void Number::Valid()
{

    int f = 1;
    //�ж��Ƿ���Сд����
    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= '0' && input[i] <= '9') continue;
        else {
            f = 0;
            break;
        }
    }
    //ȫ��Сд���֣��Ϸ�
    if (f == 1) {
        flag = 1;
        return;
    }
    
    //�ж��ǲ��Ǵ�д�����ַ�
    //��Ҽ��������½��ƾ�ʰ��Ǫ����
    // {"��","Ҽ","��","��","��","��","½","��","��","��","ʰ","��","Ǫ","��","��"} ;
    string temp1 = input;
    f = 1;
    for (int i = 0;i < temp1.size();i = i + 2)
    {
        //�и������ַ�
        char a[3] = "";
        a[0] = temp1[i];
        a[1] = temp1[i + 1];
        a[2] = '\0';
        //�ж��Ƿ������ֻ�λ
        if (!strcmp(a, "��") || a == "Ҽ" || a == "��" || a == "��" || a == "��"
            || a == "��" || a == "½" || a == "��" || a == "��" || a == "��"
            || a == "ʰ" || a == "��" || a == "Ǫ" || a == "��" || a == "��")
        {
            f = 0;
        }
        cout << "a = " << a <<  "    " << strcmp(a, "��") << endl;
        //�Ƿ�
        if (f == 1) {

            flag = 0;
            return;
        }
        f = 1;
    }
    flag = 0;
}
