#include"msg.h"
#include"Urgency.h"

//查看紧急电话函数
void UrgencyMsg::Urgency() {
	ifstream instuf;char x[100][80];string s;int i = 0;
	instuf.open("d:\\AddressBook5.txt", ios::in);//读入紧急电话文本文件
	//逐个字符读入文本文件
	while (instuf >> x[i])
	{
		cout << x[i] << endl;
		i += 1;
	}
}