#include<stdlib.h>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include "type.h"
using namespace std;

typedef pair<int,string> mypair;
string transform(long long i)
{
        //����mapӳ��
	map<int,string> mymap1;
	map<int,string> mymap2;
	mymap1.insert(mypair(0,"��"));
	mymap1.insert(mypair(1,"Ҽ"));
	mymap1.insert(mypair(2,"��"));
	mymap1.insert(mypair(3,"��"));
	mymap1.insert(mypair(4,"��"));
	mymap1.insert(mypair(5,"��"));
	mymap1.insert(mypair(6,"½"));
	mymap1.insert(mypair(7,"��"));
	mymap1.insert(mypair(8,"��"));
	mymap1.insert(mypair(9,"��"));
 
	mymap2.insert(mypair(1,"ʰ"));
	mymap2.insert(mypair(2,"��"));
	mymap2.insert(mypair(3,"Ǫ"));
	mymap2.insert(mypair(4,"��"));
	mymap2.insert(mypair(8,"��"));
	int count=-1,j=0,k=0;//count��¼λ��
	int yi=100000000;
	int wan=10000;
	string result;
	stack<int> stak;//��ջʵ�ָ�λ����
        //�ж���λ����
	if(i>yi)
	{
		j=i/yi;
		while(j)
		{
			stak.push(j%10);
			++count;
			j/=10;
		}
		while(!stak.empty())
		{
			k=stak.top();
			stak.pop();
				
			while(k==0&&!stak.empty()&&stak.top()==0)//������ظ�ֻ����һ��
			{
				--count;
				stak.pop();
			}
			if(k==0&&stak.empty()) break;//���һ���㲻���
			result+=mymap1[k];
			if(count>0&&k!=0)
			{
				result+=mymap2[count];
				--count;
			}
			else
				--count;
		}
		count=-1;
		result+=mymap2[8];//�����ϡ��ڡ�λ��ʶ��
	}
 
        //��λ
	if(i>wan)
	{
		j=i%yi;
		j=j/wan;
		while(j)
		{
			stak.push(j%10);
			++count;
			j/=10;
		}
		while(!stak.empty())
		{
			k=stak.top();
			stak.pop();
			
			while(k==0&&!stak.empty()&&stak.top()==0)
			{
				--count;
				stak.pop();
			}
			if(k==0&&stak.empty()) break;
			result+=mymap1[k];
			if(count>0&&k!=0)
			{
				result+=mymap2[count];
				--count;
			}
			else --count;
		}
		count=-1;
		if(i%yi)
			result+=mymap2[4];
	}
        //��λ����	
	if(i>0)
	{	
		j=i%wan;
		while(j)
		{
			stak.push(j%10);
			++count;
			j/=10;
		}
		while(!stak.empty())
		{
			k=stak.top();
			stak.pop();
			
			while(k==0&&stak.empty()&&stak.top()==0)
			{
				--count;
				stak.pop();
			}
			if(k==0&&!stak.empty()) break;
			result+=mymap1[k];
			if(count>0&&k!=0)
			{
				result+=mymap2[count];
				--count;
			}
			else --count;
		}
	}	
	result+="Ԫ��";
	return result;
}

//����ת��д 0
void Number::Trans_Number0()
{
	long long ll = atoll(input.c_str());
	output = transform(ll);
}
