#include"msg.h"
#include"InquireMsg.h"

//�ж��Ƿ�Ϊ����
bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

// �Թ�Ԫ 1 �� 1 �� 1 ��Ϊ��׼�����㾭�������� 
int getDays(int year, int month, int day)
{
	int m[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//ÿ���·ݵ�����
	if (isLeapYear(year))
		m[2]++;
	int result = 0;
	for (int i = 1;i < year;i++)
	{
		result += 365;
		if (isLeapYear(i))
			result++;
	}
	for (int i = 1;i < month;i++)
	{
		result += m[i];
	}
	result += day;

	return result;
}

//�����������ڼ������
int dayDis(int year1, int month1, int day1,
	int year2, int month2, int day2)
{
	return abs(getDays(year2, month2, day2) - getDays(year1, month1, day1));
}

//��ѯ��Ϣ����
void InquireMsg::Inquire() {
	cout << "*****��ѯ*****\n";
	char choice;//ѡ�����
	char name[10];//����
	char tel[11];//�绰
	int key = 0;//�����ж��Ƿ��ѯ����Ϣ�ı���
	while (1) {
		File file;
		cout << "���������ѡ��\n" << "1:��������ѯ;2.���绰��ѯ;3.��ѯ�����·ݹ���������;4.�г�ȫ����Ա��Ϣ;\n"
			<< "5.�ֱ��г�ͬѧ��ͬ�¡����ѡ����ݵ���Ϣ;6.��ѯ5���ڹ�������Ա��Ϣ;Q:�˳�\n";
		cin >> choice;
		switch (choice) {
		case '1': {
			fstream fdat1(file.fileDat1, ios::in | ios::binary);
			fdat1.seekg(0, ios::beg);
			student stu;
			cout << "������";
			cin >> name;
			do {
				fdat1.read((char*)&stu, sizeof(student));
				if (strcmp(stu.name, name) == 0) {//�ҵ�������Ӧ����Ϣ
					cout << "���ҳɹ���������Ϊ���ͬѧ��\n";
					cout << "������" << stu.name << endl;
					cout << "�������ڣ�" << stu.year << " " << stu.month << " " << stu.day << endl;
					cout << "�绰��" << stu.telephone << endl;
					cout << "Email��" << stu.Email << endl;
					cout << "ѧУ��" << stu.school << endl;
					key++;
				}
			} while (strcmp(stu.name, "no") != 0);
			fdat1.close();
			fstream fdat2(file.fileDat2, ios::in | ios::binary);
			fdat2.seekg(0, ios::beg);
			colleague col;
			do {
				fdat2.read((char*)&col, sizeof(colleague));
				if (strcmp(col.name, name) == 0) {//�ҵ�������Ӧ����Ϣ
					cout << "���ҳɹ���������Ϊ���ͬ�£�\n";
					cout << "������" << col.name << endl;
					cout << "�������ڣ�" << col.year << " " << col.month << " " << col.day << endl;
					cout << "�绰��" << col.telephone << endl;
					cout << "Email��" << col.Email << endl;
					cout << "��λ��" << col.unit << endl;
					key++;
				}
			} while (strcmp(col.name, "no") != 0);
			fdat2.close();
			fstream fdat3(file.fileDat3, ios::in | ios::binary);
			fdat3.seekg(0, ios::beg);
			friends fri;
			do {
				fdat3.read((char*)&fri, sizeof(friends));
				if (strcmp(fri.name, name) == 0) {//�ҵ�������Ӧ����Ϣ
					cout << "���ҳɹ���������Ϊ������ѣ�\n";
					cout << "������" << fri.name << endl;
					cout << "�������ڣ�" << fri.year << " " << fri.month << " " << fri.day << endl;
					cout << "�绰��" << fri.telephone << endl;
					cout << "Email��" << fri.Email << endl;
					cout << "��ʶ�ص㣺" << fri.site << endl;
					key++;
				}
			} while (strcmp(fri.name, "no") != 0);
			fdat3.close();
			fstream fdat4(file.fileDat4, ios::in | ios::binary);
			fdat4.seekg(0, ios::beg);
			relative rel;
			do {
				fdat4.read((char*)&rel, sizeof(relative));
				if (strcmp(rel.name, name) == 0) {//�ҵ�������Ӧ����Ϣ
					cout << "���ҳɹ���������Ϊ������ݣ�\n";
					cout << "������" << rel.name << endl;
					cout << "�������ڣ�" << rel.year << " " << rel.month << " " << rel.day << endl;
					cout << "�绰��" << rel.telephone << endl;
					cout << "Email��" << rel.Email << endl;
					cout << "�ƺ���" << rel.call << endl;
					key++;
				}
			} while (strcmp(rel.name, "no") != 0);
			fdat4.close();
			if (key == 0) {
				cout << "�Ҳ�����¼��\n";
				continue;
			}
			key = 0;
			break;
		}
		case '2': {
			fstream fdat1(file.fileDat1, ios::in | ios::binary);
			fdat1.seekg(0, ios::beg);
			student stu;
			cout << "�绰��";
			cin >> tel;
			do {
				fdat1.read((char*)&stu, sizeof(student));
				if (strcmp(stu.telephone, tel) == 0) {//�ҵ��绰��Ӧ����Ϣ
					cout << "���ҳɹ���������Ϊ���ͬѧ��\n";
					cout << "������" << stu.name << endl;
					cout << "�������ڣ�" << stu.year << " " << stu.month << " " << stu.day << endl;
					cout << "�绰��" << stu.telephone << endl;
					cout << "Email��" << stu.Email << endl;
					cout << "ѧУ��" << stu.school << endl;
					key++;
				}
			} while (strcmp(stu.telephone, "no") != 0);
			fdat1.close();
			fstream fdat2(file.fileDat2, ios::in | ios::binary);
			fdat2.seekg(0, ios::beg);
			colleague col;
			do {
				fdat2.read((char*)&col, sizeof(colleague));
				if (strcmp(col.telephone, tel) == 0) {//�ҵ��绰��Ӧ����Ϣ
					cout << "���ҳɹ���������Ϊ���ͬ�£�\n";
					cout << "������" << col.name << endl;
					cout << "�������ڣ�" << col.year << " " << col.month << " " << col.day << endl;
					cout << "�绰��" << col.telephone << endl;
					cout << "Email��" << col.Email << endl;
					cout << "��λ��" << col.unit << endl;
					key++;
				}
			} while (strcmp(col.telephone, "no") != 0);
			fdat2.close();
			fstream fdat3(file.fileDat3, ios::in | ios::binary);
			fdat3.seekg(0, ios::beg);
			friends fri;
			do {
				fdat3.read((char*)&fri, sizeof(friends));
				if (strcmp(fri.telephone, tel) == 0) {//�ҵ��绰��Ӧ����Ϣ
					cout << "���ҳɹ���������Ϊ������ѣ�\n";
					cout << "������" << fri.name << endl;
					cout << "�������ڣ�" << fri.year << " " << fri.month << " " << fri.day << endl;
					cout << "�绰��" << fri.telephone << endl;
					cout << "Email��" << fri.Email << endl;
					cout << "��ʶ�ص㣺" << fri.site << endl;
					key++;
				}
			} while (strcmp(fri.telephone, "no") != 0);
			fdat3.close();
			fstream fdat4(file.fileDat4, ios::in | ios::binary);
			fdat4.seekg(0, ios::beg);
			relative rel;
			do {
				fdat4.read((char*)&rel, sizeof(relative));
				if (strcmp(rel.telephone, tel) == 0) {//�ҵ��绰��Ӧ����Ϣ
					cout << "���ҳɹ���������Ϊ������ݣ�\n";
					cout << "������" << rel.name << endl;
					cout << "�������ڣ�" << rel.year << " " << rel.month << " " << rel.day << endl;
					cout << "�绰��" << rel.telephone << endl;
					cout << "Email��" << rel.Email << endl;
					cout << "�ƺ���" << rel.call << endl;
					key++;
				}
			} while (strcmp(rel.telephone, "no") != 0);
			fdat4.close();
			if (key == 0) {
				cout << "�Ҳ�����¼��\n";
				continue;
			}
			key = 0;
			break;
		}
		case '3': {
			int num = 0;//���ڼ�¼�����ı���
			int month;//�·�
			cout << "�������·ݣ�";
			cin >> month;
			fstream fdat1(file.fileDat1, ios::in | ios::binary);
			fdat1.seekg(0, ios::beg);
			student stu;
			do {
				fdat1.read((char*)&stu, sizeof(student));
				if (stu.month == month)num++;//�ҵ������·ݵ���Ϣ��num+1
			} while (strcmp(stu.name, "no") != 0);
			fdat1.close();
			fstream fdat2(file.fileDat2, ios::in | ios::binary);
			fdat2.seekg(0, ios::beg);
			colleague col;
			do {
				fdat2.read((char*)&col, sizeof(colleague));
				if (col.month == month)num++;//�ҵ������·ݵ���Ϣ��num+1
			} while (strcmp(col.name, "no") != 0);
			fdat2.close();
			fstream fdat3(file.fileDat3, ios::in | ios::binary);
			fdat3.seekg(0, ios::beg);
			friends fri;
			do {
				fdat3.read((char*)&fri, sizeof(friends));
				if (fri.month == month)num++;//�ҵ������·ݵ���Ϣ��num+1
			} while (strcmp(fri.name, "no") != 0);
			fdat3.close();
			fstream fdat4(file.fileDat4, ios::in | ios::binary);
			fdat4.seekg(0, ios::beg);
			relative rel;
			do {
				fdat4.read((char*)&rel, sizeof(relative));
				if (rel.month == month)num++;//�ҵ������·ݵ���Ϣ��num+1
			} while (strcmp(rel.name, "no") != 0);
			fdat4.close();
			cout << "��" << month << "�������������Ϊ��" << num << endl;
			break;
		}
		case '4': {
			//����洢ѧ����Ϣ�Ķ������ļ�
			fstream fdat1(file.fileDat1, ios::in | ios::binary);
			fdat1.seekg(0, ios::beg);
			student stu;
			cout << "*****ѧ����Ϣ*****\n";
			cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "ѧУ" << endl;
			do {
				fdat1.read((char*)&stu, sizeof(student));
				cout << std::left << setw(18) << stu.name << std::left << setw(18) << stu.year << std::left << setw(18) << stu.month << std::left << setw(18) << stu.day << std::left << setw(18) << stu.telephone << std::left << setw(18) << stu.Email << std::left << setw(18) << stu.school << endl;
			} while (strcmp(stu.name, "no") != 0);
			fdat1.close();
			//����洢ͬ����Ϣ�Ķ������ļ�
			fstream fdat2(file.fileDat2, ios::in | ios::binary);
			fdat2.seekg(0, ios::beg);
			colleague col;
			cout << "*****ͬ����Ϣ*****\n";
			cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "��λ" << endl;
			do {
				fdat2.read((char*)&col, sizeof(colleague));
				cout << std::left << setw(18) << col.name << std::left << setw(18) << col.year << std::left << setw(18) << col.month << std::left << setw(18) << col.day << std::left << setw(18) << col.telephone << std::left << setw(18) << col.Email << std::left << setw(18) << col.unit << endl;

			} while (strcmp(col.name, "no") != 0);
			fdat2.close();
			//����洢������Ϣ�Ķ������ļ�
			fstream fdat3(file.fileDat3, ios::in | ios::binary);
			fdat3.seekg(0, ios::beg);
			friends fri;
			cout << "*****������Ϣ*****\n";
			cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "��ʶ�ص�" << endl;
			do {
				fdat3.read((char*)&fri, sizeof(friends));
				cout << std::left << setw(18) << fri.name << std::left << setw(18) << fri.year << std::left << setw(18) << fri.month << std::left << setw(18) << fri.day << std::left << setw(18) << fri.telephone << std::left << setw(18) << fri.Email << std::left << setw(18) << fri.site << endl;

			} while (strcmp(fri.name, "no") != 0);
			fdat3.close();
			//����洢������Ϣ�Ķ������ļ�
			fstream fdat4(file.fileDat4, ios::in | ios::binary);
			fdat4.seekg(0, ios::beg);
			relative rel;
			cout << "*****������Ϣ*****\n";
			cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "�ƺ�" << endl;
			do {
				fdat4.read((char*)&rel, sizeof(relative));
				cout << std::left << setw(18) << rel.name << std::left << setw(18) << rel.year << std::left << setw(18) << rel.month << std::left << setw(18) << rel.day << std::left << setw(18) << rel.telephone << std::left << setw(18) << rel.Email << std::left << setw(18) << rel.call << endl;
			} while (strcmp(rel.name, "no") != 0);
			fdat4.close();
			break;
		}
		case '5': {
			cout << "��ѡ������Ҫ�鿴����Ϣ�ķ��ࣨ1.ͬѧ;2.ͬ��;3.����;4.����;����\n";
			int part;
			cin >> part;
			if (part == 1) {
				//����洢ѧ����Ϣ�Ķ������ļ�
				fstream fdat(file.fileDat1, ios::in | ios::binary);
				fdat.seekg(0, ios::beg);
				student stu;
				cout << "*****ѧ����Ϣ*****\n";
				cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "ѧУ" << endl;
				do {
					fdat.read((char*)&stu, sizeof(student));
					cout << std::left << setw(18) << stu.name << std::left << setw(18) << stu.year << std::left << setw(18) << stu.month << std::left << setw(18) << stu.day << std::left << setw(18) << stu.telephone << std::left << setw(18) << stu.Email << std::left << setw(18) << stu.school << endl;
				} while (strcmp(stu.name, "no") != 0);
				fdat.close();
			}
			if (part == 2) {
				//����洢ͬ����Ϣ�Ķ������ļ�
				fstream fdat(file.fileDat2, ios::in | ios::binary);
				fdat.seekg(0, ios::beg);
				colleague col;
				cout << "*****ͬ����Ϣ*****\n";
				cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "��λ" << endl;
				do {
					fdat.read((char*)&col, sizeof(colleague));
					cout << std::left << setw(18) << col.name << std::left << setw(18) << col.year << std::left << setw(18) << col.month << std::left << setw(18) << col.day << std::left << setw(18) << col.telephone << std::left << setw(18) << col.Email << std::left << setw(18) << col.unit << endl;

				} while (strcmp(col.name, "no") != 0);
				fdat.close();
			}
			if (part == 3) {
				//����洢������Ϣ�Ķ������ļ�
				fstream fdat(file.fileDat3, ios::in | ios::binary);
				fdat.seekg(0, ios::beg);
				friends fri;
				cout << "*****������Ϣ*****\n";
				cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "��ʶ�ص�" << endl;
				do {
					fdat.read((char*)&fri, sizeof(friends));
					cout << std::left << setw(18) << fri.name << std::left << setw(18) << fri.year << std::left << setw(18) << fri.month << std::left << setw(18) << fri.day << std::left << setw(18) << fri.telephone << std::left << setw(18) << fri.Email << std::left << setw(18) << fri.site << endl;

				} while (strcmp(fri.name, "no") != 0);
				fdat.close();
			}
			if (part == 4) {
				//����洢������Ϣ�Ķ������ļ�
				fstream fdat(file.fileDat4, ios::in | ios::binary);
				fdat.seekg(0, ios::beg);
				relative rel;
				cout << "*****������Ϣ*****\n";
				cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "�ƺ�" << endl;
				do {
					fdat.read((char*)&rel, sizeof(relative));
					cout << std::left << setw(18) << rel.name << std::left << setw(18) << rel.year << std::left << setw(18) << rel.month << std::left << setw(18) << rel.day << std::left << setw(18) << rel.telephone << std::left << setw(18) << rel.Email << std::left << setw(18) << rel.call << endl;
				} while (strcmp(rel.name, "no") != 0);
				fdat.close();
			}
			break;
		}
		case '6': {
			cout << "�������������ڣ������� �� �յĸ�ʽ���룩:\n";
			int y, m, d;
			cin >> y >> m >> d;
			char weekday[][10] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };//�������飬�洢�������ڵ�Ӣ�ı�ʾ
			//����洢ѧ����Ϣ�Ķ������ļ�
			fstream fdat1(file.fileDat1, ios::in | ios::binary);
			fdat1.seekg(0, ios::beg);
			student stu;
			cout << "*****ͬѧ��Ϣ*****\n";
			cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "���ڼ�" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "ѧУ" << endl;
			int i[4] = { 0 };//���ڼ�¼���������Ĳ�ͬ�������Ա������
			char name[100][10];//���ڴ洢����������ѧ������
			do {
				fdat1.read((char*)&stu, sizeof(student));
				if (dayDis(y, m, d, stu.year, stu.month, stu.day) <= 5 && strcmp(stu.name, "no") != 0) {//���ҵ�5�������յ�ѧ����Ϣ
					cout << std::left << setw(18) << stu.name << std::left << setw(18) << stu.year << std::left << setw(18) << stu.month << std::left << setw(18) << stu.day << std::left << setw(18) << weekday[(stu.year + 2 * stu.month + 3 * (stu.month + 1) / 5 + stu.day + stu.day / 4 - stu.day / 100 + stu.day / 400 + 1) % 7] << std::left << setw(18) << stu.telephone << std::left << setw(18) << stu.Email << std::left << setw(18) << stu.school << endl;
					strcpy(name[i[0]], stu.name);//�洢ѧ������
					i[0]++;
				}
			} while (strcmp(stu.name, "no") != 0);
			if (!i[0])cout << "δ�ҵ����ϵ�ѧ����Ϣ\n";
			fdat1.close();
			//����洢ͬ����Ϣ�Ķ������ļ�
			fstream fdat2(file.fileDat2, ios::in | ios::binary);
			fdat2.seekg(0, ios::beg);
			colleague col;
			cout << "*****ͬ����Ϣ*****\n";
			cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "���ڼ�" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "��λ" << endl;
			do {
				fdat2.read((char*)&col, sizeof(colleague));
				if (dayDis(y, m, d, col.year, col.month, col.day) <= 5 && strcmp(col.name, "no") != 0) {//���ҵ�5�������յ�ͬ����Ϣ
					cout << std::left << setw(18) << col.name << std::left << setw(18) << col.year << std::left << setw(18) << col.month << std::left << setw(18) << col.day << std::left << setw(18) << weekday[(col.year + 2 * col.month + 3 * (col.month + 1) / 5 + col.day + col.day / 4 - col.day / 100 + col.day / 400 + 1) % 7] << std::left << setw(18) << col.telephone << std::left << setw(18) << col.Email << std::left << setw(18) << col.unit << endl;
					strcpy(name[i[0] + i[1]], col.name);//�洢ͬ������
					i[1]++;
				}
			} while (strcmp(col.name, "no") != 0);
			if (!i[1])cout << "δ�ҵ����ϵ�ͬ����Ϣ\n";
			fdat2.close();
			//����洢������Ϣ�Ķ������ļ�
			fstream fdat3(file.fileDat3, ios::in | ios::binary);
			fdat3.seekg(0, ios::beg);
			friends fri;
			cout << "*****������Ϣ*****\n";
			cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "���ڼ�" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "��ʶ�ص�" << endl;
			do {
				fdat3.read((char*)&fri, sizeof(friends));
				if (dayDis(y, m, d, fri.year, fri.month, fri.day) <= 5 && strcmp(fri.name, "no") != 0) {//���ҵ�5�������յ�������Ϣ
					cout << std::left << setw(18) << fri.name << std::left << setw(18) << fri.year << std::left << setw(18) << fri.month << std::left << setw(18) << fri.day << std::left << setw(18) << weekday[(fri.year + 2 * fri.month + 3 * (fri.month + 1) / 5 + fri.day + fri.day / 4 - fri.day / 100 + fri.day / 400 + 1) % 7] << std::left << setw(18) << fri.telephone << std::left << setw(18) << fri.Email << std::left << setw(18) << fri.site << endl;
					strcpy(name[i[0] + i[1] + i[2]], fri.name);//�洢��������
					i[2]++;
				}
			} while (strcmp(fri.name, "no") != 0);
			if (!i[2])cout << "δ�ҵ����ϵ�������Ϣ\n";
			fdat3.close();
			//����洢������Ϣ�Ķ������ļ�
			fstream fdat4(file.fileDat4, ios::in | ios::binary);
			fdat4.seekg(0, ios::beg);
			relative rel;
			cout << "*****������Ϣ*****\n";
			cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "���ڼ�" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "�ƺ�" << endl;
			do {
				fdat4.read((char*)&rel, sizeof(relative));
				if (dayDis(y, m, d, rel.year, rel.month, rel.day) <= 5 && strcmp(rel.name, "no") != 0) {//���ҵ�5�������յ�������Ϣ
					cout << std::left << setw(18) << rel.name << std::left << setw(18) << rel.year << std::left << setw(18) << rel.month << std::left << setw(18) << rel.day << std::left << setw(18) << weekday[(rel.year + 2 * rel.month + 3 * (rel.month + 1) / 5 + rel.day + rel.day / 4 - rel.day / 100 + rel.day / 400 + 1) % 7] << std::left << setw(18) << rel.telephone << std::left << setw(18) << rel.Email << std::left << setw(18) << rel.call << endl;
					strcpy(name[i[0] + i[1] + i[2] + i[3]], rel.name);//�洢��������
					i[3]++;
				}
			} while (strcmp(rel.name, "no") != 0);
			if (!i[3])cout << "δ�ҵ����ϵ�������Ϣ\n";
			fdat4.close();
			//�������պؿ�
			if (i[0] + i[1] + i[2] + i[3] > 0) {
				cout << "�Ƿ�����ף�����յĵ����ʼ�(1.��;2.��;)\n";
				int choice;
				cin >> choice;
				if (choice == 1) {
					cout << "���պؿ������ɣ�\n";
					ofstream outstuf;
					//����������պؿ�
					for (int j = 0;j < i[0] + i[1] + i[2] + i[3]; j++) {
						string filename = "d:\\";
						filename = filename + name[j] + "'s birthday card.txt";
						outstuf.open(filename, ios::out);
						outstuf << "�װ���" << name[j] << ":" << endl;
						outstuf << "     ף���տ��֣������Ҹ���" << endl;
						outstuf << "                                                                     ������" << endl;
						outstuf.close();
					}
				}
				if (choice == 2) {
					return;
				}
			}
			break;
		}
		case 'Q':
		case 'q':return;
		}
	}
}