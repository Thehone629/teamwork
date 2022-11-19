#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> mypair;
string transform(long long i)
{
	//����mapӳ��
	map<int, string> mymap1;
	map<int, string> mymap2;
	mymap1.insert(mypair(0, "��"));
	mymap1.insert(mypair(1, "Ҽ"));
	mymap1.insert(mypair(2, "��"));
	mymap1.insert(mypair(3, "��"));
	mymap1.insert(mypair(4, "��"));
	mymap1.insert(mypair(5, "��"));
	mymap1.insert(mypair(6, "½"));
	mymap1.insert(mypair(7, "��"));
	mymap1.insert(mypair(8, "��"));
	mymap1.insert(mypair(9, "��"));

	mymap2.insert(mypair(1, "ʰ"));
	mymap2.insert(mypair(2, "��"));
	mymap2.insert(mypair(3, "Ǫ"));
	mymap2.insert(mypair(4, "��"));
	mymap2.insert(mypair(8, "��"));
	int count = -1, j = 0, k = 0;//count��¼λ��
	int yi = 100000000;
	int wan = 10000;
	string result;
	stack<int> stak;//��ջʵ�ָ�λ����
	//�ж���λ����
	if (i > yi)
	{
		j = i / yi;
		while (j)
		{
			stak.push(j % 10);
			++count;
			j /= 10;
		}
		while (!stak.empty())
		{
			k = stak.top();
			stak.pop();

			while (k == 0 && !stak.empty() && stak.top() == 0)//������ظ�ֻ����һ��
			{
				--count;
				stak.pop();
			}
			if (k == 0 && stak.empty()) break;//���һ���㲻���
			result += mymap1[k];
			if (count > 0 && k != 0)
			{
				result += mymap2[count];
				--count;
			}
			else
				--count;
		}
		count = -1;
		result += mymap2[8];//�����ϡ��ڡ�λ��ʶ��
	}

	//��λ
	if (i > wan)
	{
		j = i % yi;
		j = j / wan;
		while (j)
		{
			stak.push(j % 10);
			++count;
			j /= 10;
		}
		while (!stak.empty())
		{
			k = stak.top();
			stak.pop();

			while (k == 0 && !stak.empty() && stak.top() == 0)
			{
				--count;
				stak.pop();
			}
			if (k == 0 && stak.empty()) break;
			result += mymap1[k];
			if (count > 0 && k != 0)
			{
				result += mymap2[count];
				--count;
			}
			else --count;
		}
		count = -1;
		if (i % yi)
			result += mymap2[4];
	}
	//��λ����	
	if (i > 0)
	{
		j = i % wan;
		while (j)
		{
			stak.push(j % 10);
			++count;
			j /= 10;
		}
		while (!stak.empty())
		{
			k = stak.top();
			stak.pop();

			while (k == 0 && stak.empty() && stak.top() == 0)
			{
				--count;
				stak.pop();
			}
			if (k == 0 && !stak.empty()) break;
			result += mymap1[k];
			if (count > 0 && k != 0)
			{
				result += mymap2[count];
				--count;
			}
			else --count;
		}
	}
	result += "Ԫ��";
	return result;
}

class Number {
private:
	string input;	//����
	string output;	//ת����Ĵ�д����
	string letter;	//1-10��д const
	string allChNum[15];
	int length;
	bool flag;
	int temp;//����
public:
	void Init_Number();	//���� letter��ʼ�� ��������input��
	bool Valid();	//�ж��Ƿ�Ϸ�  T/F->flag
	void Judge();//temp
	void Trans_Number0();//����ת��д 0
	void Trans_Number1();//��дת���� 1
	void Display0();
	void Display1();
};

void Number::Init_Number()
{
	cout << "��������:";
	cin << input;
	letter = "��Ҽ��������½��ƾ�ʰ"; 
	return;
}

bool Number::Valid()
{
	
	return flag;
}

// string allChNum[] = {"��","Ҽ","��","��","��","��","½","��","��","��","ʰ","��","Ǫ","��","��"} ;
// string bignumber[]={"��","Ҽ","��","��","��","��","½","��","��","��"} ;
// string digital_units[] ={"ʰ","��","Ǫ","��","��"};
// const int bigl = 15;
void Number::Judge()
{
	int len = strlen(a), sum = 0, f = 1;
	for (int i = 0; i < len; i++) {
		if (input[i] >= '0' && input[i] <= '9') sum++;
		else {
			f = 0;
			break;
		}
	}
	if (f == 1)flag = 0;
	else {
		flag = 1;
		return;
	}
	//��Ҽ��������½��ƾ�ʰ��Ǫ����
	// {"��","Ҽ","��","��","��","��","½","��","��","��","ʰ","��","Ǫ","��","��"} ;
	string temp1 = input;
	int f = 1;//�жϱ�ʶ�������ж��Ƿ�ȫΪ���ֻ�λ��ȫΪ����Ϊ0������Ϊ1

	for (int i = 0; i < temp1.size(); i = i + 2)
	{
		//�и������ַ�
		string a = "";
		a = a + temp1[i] + temp1[i + 1];
		//�ж��Ƿ������ֻ�λ
		for (int i = 0; i < 15; i++)
		{
			if (a == allChNum[i])
			{
				f = 0;
				break;
			}

		}
		if (f == 1) {

			flag = 1;
			return;
		}
		f = 1;
		// cout<<a;//��ӡ��ǰ�����ַ�
	//  ch.push_back(a);
	}
	//������Խ�������
	// if(tf == 1){
	//     cout<<"error";
	// }else{
	//     cout<<"OK";
	// }
	// 
	// for(int i = 0;i<14;i++)
	// {
	//     cout<<bignumber[i];
	// }
	// cout<<"dd";
	// string temp = "";
	// for (auto iter = ch.cbegin(); iter != ch.cend(); iter++) {
	//         string temp = (*iter);
	//         // cout << (*iter) << endl;

	//     }

	flag = 0;
}
void Number::Judge()
{
	if (isdigit(input[0])) temp = 1;
	else temp = 0;
}

void Number::Trans_Number0()
{
	if (!flag) return;
	long long ll = atoll(input.c_str());
	output = transform(ll);
}

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
}

void Number::Display0()
{
	if (flag) cout << output << endl;
	else cout << "�������";
}

void Number::Display1()
{
	if (flag) cout << output << endl;
	else cout << "�������";
}
int main(int argc, const char** argv)
{
	Number n;
	n.Init_Number();
	if (n.Valid() == true) {
		if (n.Judge()) {
			n.Trans_Number1();
			n.Display1();
		}
		else {
			n.Trans_Number0();
			n.Display0();
		}
	}
	else n.Display0();
	return 0;
}
