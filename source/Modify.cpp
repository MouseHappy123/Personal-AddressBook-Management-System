#include"msg.h"
#include"ModifyMsg.h"

//�޸���Ϣ����
void ModifyMsg::Modify() {
	File file;
	cout << "��ѡ������Ҫ�޸ĵ���Ϣ�ķ��ࣨ1.ͬѧ;2.ͬ��;3.����;4.����;��:\n";
	int part;
	cin >> part;
	char name[10];
	if (part == 1) {
		cout << "��������Ҫ�޸ĵ���Ա��������";
		cin >> name;
		fstream fdat(file.fileDat1, ios::in | ios::out | ios::binary);
		fdat.seekg(0, ios::beg);
		student stu;
		student stu1;
		//����ԭ��Ϣ
		cout << "ԭ��Ϣ����\n";
		cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "ѧУ" << endl;
		do {
			fdat.read((char*)&stu, sizeof(student));
		} while (strcmp(stu.name, name) != 0 && strcmp(stu.name, "no") != 0);
		if (strcmp(stu.name, name) == 0) {//�ҵ�ԭ��Ϣ
			cout << std::left << setw(18) << stu.name << std::left << setw(18) << stu.year << std::left << setw(18) << stu.month << std::left << setw(18) << stu.day << std::left << setw(18) << stu.telephone << std::left << setw(18) << stu.Email << std::left << setw(18) << stu.school << endl;
			cout << "�������޸ĺ����Ϣ���밴���� ��������(���� �� ������) �绰 Email ѧУ���Ƶ�˳�����룺\n";
			cin >> stu1.name >> stu1.year >> stu1.month >> stu1.day >> stu1.telephone >> stu1.Email >> stu1.school;
			fdat.seekp(-long(sizeof(student)), ios::cur);
			fdat.write((char*)&stu1, sizeof(student));//д��������ļ�
			cout << "�޸ĳɹ���\n";
			fdat.seekg(0, ios::beg);
			//��д�ı��ļ�
			ofstream outstuf;
			outstuf.open(file.file1, ios::out);
			if (!outstuf) {
				cerr << "txt file could not open!";
				abort();
			}
			outstuf << "This is an addressbook of students\n";
			do {
				fdat.read((char*)&stu, sizeof(student));
				outstuf << stu.name << " " << stu.year << " " << stu.month << " " << stu.day << " " << stu.telephone << " " << stu.Email << " " << stu.school << "\n";
			} while (strcmp(stu.name, "no") != 0);
			outstuf.close();
		}
		else cout << "������Ϣ�����ڣ�\n";
		fdat.close();
	}
	if (part == 2) {
		cout << "��������Ҫ�޸ĵ���Ա��������";
		cin >> name;
		fstream fdat(file.fileDat2, ios::in | ios::binary);
		fdat.seekg(0, ios::beg);
		colleague col;
		colleague col1;
		//����ԭ��Ϣ
		cout << "ԭ��Ϣ����\n";
		cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "��λ" << endl;
		do {
			fdat.read((char*)&col, sizeof(colleague));
		} while (strcmp(col.name, name) != 0 && strcmp(col.name, "no") != 0);
		if (strcmp(col.name, name) == 0) {//�ҵ�ԭ��Ϣ
			cout << std::left << setw(18) << col.name << std::left << setw(18) << col.year << std::left << setw(18) << col.month << std::left << setw(18) << col.day << std::left << setw(18) << col.telephone << std::left << setw(18) << col.Email << std::left << setw(18) << col.unit << endl;
			cout << "�������޸ĺ����Ϣ���밴���� ��������(���� �� ������) �绰 Email ��λ���Ƶ�˳�����룺\n";
			cin >> col1.name >> col1.year >> col1.month >> col1.day >> col1.telephone >> col1.Email >> col1.unit;
			fdat.seekp(-long(sizeof(colleague)), ios::cur);
			fdat.write((char*)&col1, sizeof(colleague));//д��������ļ�
			cout << "�޸ĳɹ���\n";
			fdat.seekg(0, ios::beg);
			//��д�ı��ļ�
			ofstream outstuf;
			outstuf.open(file.file2, ios::out);
			if (!outstuf) {
				cerr << "txt file could not open!";
				abort();
			}
			outstuf << "This is an addressbook of colleagues\n";
			do {
				fdat.read((char*)&col, sizeof(colleague));
				outstuf << col.name << " " << col.year << " " << col.month << " " << col.day << " " << col.telephone << " " << col.Email << " " << col.unit << "\n";
			} while (strcmp(col.name, "no") != 0);
			outstuf.close();
		}
		else cout << "������Ϣ�����ڣ�\n";
		fdat.close();
	}
	if (part == 3) {
		cout << "��������Ҫ�޸ĵ���Ա��������";
		cin >> name;
		fstream fdat(file.fileDat3, ios::in | ios::binary);
		fdat.seekg(0, ios::beg);
		friends fri;
		friends fri1;
		//����ԭ��Ϣ
		cout << "ԭ��Ϣ����\n";
		cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "��ʶ�ص�" << endl;
		do {
			fdat.read((char*)&fri, sizeof(friends));
		} while (strcmp(fri.name, name) != 0 && strcmp(fri.name, "no") != 0);
		if (strcmp(fri.name, name) == 0) {
			cout << std::left << setw(18) << fri.name << std::left << setw(18) << fri.year << std::left << setw(18) << fri.month << std::left << setw(18) << fri.day << std::left << setw(18) << fri.telephone << std::left << setw(18) << fri.Email << std::left << setw(18) << fri.site << endl;
			cout << "�������޸ĺ����Ϣ���밴���� ��������(���� �� ������) �绰 Email ��ʶ�ص��˳�����룺\n";
			cin >> fri1.name >> fri1.year >> fri1.month >> fri1.day >> fri1.telephone >> fri1.Email >> fri1.site;
			fdat.seekp(-long(sizeof(friends)), ios::cur);
			fdat.write((char*)&fri1, sizeof(friends));//д��������ļ�
			cout << "�޸ĳɹ���\n";
			fdat.seekg(0, ios::beg);
			//��д�ı��ļ�
			ofstream outstuf;
			outstuf.open(file.file3, ios::out);
			if (!outstuf) {
				cerr << "txt file could not open!";
				abort();
			}
			outstuf << "This is an addressbook of friends\n";
			do {
				fdat.read((char*)&fri, sizeof(friends));
				outstuf << fri.name << " " << fri.year << " " << fri.month << " " << fri.day << " " << fri.telephone << " " << fri.Email << " " << fri.site << "\n";
			} while (strcmp(fri.name, "no") != 0);
			outstuf.close();
		}
		else cout << "������Ϣ�����ڣ�\n";
		fdat.close();
	}
	if (part == 4) {
		cout << "��������Ҫ�޸ĵ���Ա��������";
		cin >> name;
		fstream fdat(file.fileDat4, ios::in | ios::binary);
		fdat.seekg(0, ios::beg);
		relative rel;
		relative rel1;
		//����ԭ��Ϣ
		cout << "ԭ��Ϣ����\n";
		cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "�ƺ�" << endl;
		do {
			fdat.read((char*)&rel, sizeof(relative));
		} while (strcmp(rel.name, name) != 0 && strcmp(rel.name, "no") != 0);
		if (strcmp(rel.name, name) == 0) {
			cout << std::left << setw(18) << rel.name << std::left << setw(18) << rel.year << std::left << setw(18) << rel.month << std::left << setw(18) << rel.day << std::left << setw(18) << rel.telephone << std::left << setw(18) << rel.Email << std::left << setw(18) << rel.call << endl;
			cout << "�������޸ĺ����Ϣ���밴���� ��������(���� �� ������) �绰 Email �ƺ���˳�����룺\n";
			cin >> rel1.name >> rel1.year >> rel1.month >> rel1.day >> rel1.telephone >> rel1.Email >> rel1.call;
			fdat.seekp(-long(sizeof(relative)), ios::cur);
			fdat.write((char*)&rel1, sizeof(relative));//д��������ļ�
			cout << "�޸ĳɹ���\n";
			fdat.seekg(0, ios::beg);
			//��д�ı��ļ�
			ofstream outstuf;
			outstuf.open(file.file4, ios::out);
			if (!outstuf) {
				cerr << "txt file could not open!";
				abort();
			}
			outstuf << "This is an addressbook of relatives\n";
			do {
				fdat.read((char*)&rel, sizeof(relative));
				outstuf << rel.name << " " << rel.year << " " << rel.month << " " << rel.day << " " << rel.telephone << " " << rel.Email << " " << rel.call << "\n";
			} while (strcmp(rel.name, "no") != 0);
			outstuf.close();
		}
		else cout << "������Ϣ�����ڣ�\n";
		fdat.close();
	}
}