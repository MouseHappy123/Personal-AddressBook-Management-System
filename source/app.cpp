#include"AddMsg.h"
#include"DeleteMsg.h"
#include"Urgency.h"
#include"InitialMsg.h"
#include"InquireMsg.h"
#include"ModifyMsg.h"
#include"SortMsg.h"
#include"app.h"

int app::showMenu() {
	char choice;
	while (1) {
		cout << "********** ����ͨѶ¼����ϵͳ **********\n���������ѡ��\n"
			<< "0: ��ʼ��\t" << "1: ¼��\t" << "2: �޸�\t" << "3: ��ѯ\t" << "4: ɾ��\t" << "5.����\t"
			<< "6.��ѯ�����绰\t" << "Q: �˳�\n";
		cin >> choice;
		switch (choice) {
		case'0':Initial.Initial();break;//��ʼ��
		case'1':Add.Append();break;//�����Ϣ
		case'2':Modify.Modify();break;//�޸���Ϣ
		case'3':Inquire.Inquire();break;//��ѯ��Ϣ
		case'4':Delete.Delete();break;//ɾ����Ϣ
		case'5':Sort.Sort();break;//����
		case'6':Urgency.Urgency();break;//��ѯ�����绰
		case'q':
		case'Q':cout << "�˳�ϵͳ\n";
			return 0;
		default:cout << "��Ч���룬��������\n";
		}
	}
}