#include"msg.h"
#include"Urgency.h"

//�鿴�����绰����
void UrgencyMsg::Urgency() {
	ifstream instuf;char x[100][80];string s;int i = 0;
	instuf.open("d:\\AddressBook5.txt", ios::in);//��������绰�ı��ļ�
	//����ַ������ı��ļ�
	while (instuf >> x[i])
	{
		cout << x[i] << endl;
		i += 1;
	}
}