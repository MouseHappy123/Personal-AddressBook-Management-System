#include"msg.h"
#include"AddMsg.h"

//�����Ϣ����
void AddMsg::Append() {
	File file;
	cout << "******��Ϣ�Ǽ�*****" << endl;
	char choice;
	while (1) {
		cout << "����������Ҫ¼�����Ա���ࣨ1.ͬѧ;2.ͬ��;3.����;4.����;Q:�˳�;����\n";
		cin >> choice;
		ofstream outstuf;
		switch (choice)
		{
		case '1': {
			student stu, stu1;
			int choice;
			fstream fdat(file.fileDat1, ios::in | ios::out | ios::binary);
			if (!fdat) {
				cout << "�ļ������ڣ�����г�ʼ��������\n";
				return;
			}
			cout << "*****ѧ����Ϣ¼��*****" << endl;
			cout << "�밴���� ��������(���� �� ������) �绰 Email ѧУ���Ƶ�˳�����룺\n";
			cin >> stu1.name >> stu1.year >> stu1.month >> stu1.day >> stu1.telephone >> stu1.Email >> stu1.school;
			fdat.seekg(0, ios::beg);
			do {
				fdat.read((char*)&stu, sizeof(student));
			} while (strcmp(stu.name, stu1.name) != 0 && strcmp(stu.name, "no") != 0);
			//���ӹ��ܣ������Ϣʱ�����û��Ƿ��Ѵ��ڸ���Ϣ����ʾ�޸�
			if (strcmp(stu.name, stu1.name) == 0) {
				cout << "����Ա��Ϣ�Ѵ��ڣ�ԭ��Ϣ����:\n";
				cout << "������" << stu.name << endl;
				cout << "�������ڣ�" << stu.year << " " << stu.month << " " << stu.day << endl;
				cout << "�绰��" << stu.telephone << endl;
				cout << "Email��" << stu.Email << endl;
				cout << "ѧУ��" << stu.school << endl;
				cout << "�Ƿ��޸ģ���1.��;2.��;��\n";
				cin >> choice;
				if (choice == 1) {
					cout << "�������޸ĺ����Ϣ���밴���� ��������(���� �� ������) �绰 Email ѧУ���Ƶ�˳�����룺\n";
					cin >> stu1.name >> stu1.year >> stu1.month >> stu1.day >> stu1.telephone >> stu1.Email >> stu1.school;
					fdat.seekp(-long(sizeof(student)), ios::cur);
					fdat.write((char*)&stu1, sizeof(student));//д��������ļ�
					cout << "�޸ĳɹ���\n";
					//д���ı��ļ�
					ofstream outstuf;
					outstuf.open(file.file1, ios::out);
					if (!outstuf) {
						cerr << "txt file could not open!";
						abort();
					}
					outstuf << "This is an addressbook of students\n";
					fdat.seekg(0, ios::beg);
					do {
						fdat.read((char*)&stu, sizeof(student));
						outstuf << stu.name << " " << stu.year << " " << stu.month << " " << stu.day << " " << stu.telephone << " " << stu.Email << " " << stu.school << "\n";
					} while (strcmp(stu.name, "no") != 0);
					outstuf.close();
					fdat.close();
					break;
				}
				if (choice == 2) {
					break;
				}
			}
			//δ�����д�����Ϣ������ֱ�д��������ļ����ı��ļ�
			fdat.seekp(-long(sizeof(student)), ios::cur);
			fdat.write((char*)&stu1, sizeof(student));
			fdat.write((char*)&mark1, sizeof(student));
			fdat.seekg(0, ios::beg);
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
			cout << "��ӳɹ���\n";
			outstuf.close();
			fdat.close();
			break;
		}
		case '2': {
			colleague col, col1;
			int choice;
			fstream fdat(file.fileDat2, ios::in | ios::out | ios::binary);
			if (!fdat) {
				cout << "�ļ������ڣ�����г�ʼ��������\n";
				return;
			}
			cout << "*****ͬ����Ϣ¼��*****" << endl;
			cout << "�밴���� ��������(���� �� ������) �绰 Email ��λ���Ƶ�˳�����룺\n";
			cin >> col1.name >> col1.year >> col1.month >> col1.day >> col1.telephone >> col1.Email >> col1.unit;
			fdat.seekg(0, ios::beg);
			do {
				fdat.read((char*)&col, sizeof(colleague));
			} while (strcmp(col.name, col1.name) != 0 && strcmp(col.name, "no") != 0);
			//���ӹ��ܣ������Ϣʱ�����û��Ƿ��Ѵ��ڸ���Ϣ����ʾ�޸�
			if (strcmp(col.name, col1.name) == 0) {
				cout << "����Ա��Ϣ�Ѵ��ڣ�ԭ��Ϣ����:\n";
				cout << "������" << col.name << endl;
				cout << "�������ڣ�" << col.year << " " << col.month << " " << col.day << endl;
				cout << "�绰��" << col.telephone << endl;
				cout << "Email��" << col.Email << endl;
				cout << "��λ��" << col.unit << endl;
				cout << "�Ƿ��޸ģ���1.��;2.��;��\n";
				cin >> choice;
				if (choice == 1) {
					cout << "�������޸ĺ����Ϣ���밴���� ��������(���� �� ������) �绰 Email ��λ���Ƶ�˳�����룺\n";
					cin >> col1.name >> col1.year >> col1.month >> col1.day >> col1.telephone >> col1.Email >> col1.unit;
					fdat.seekp(-long(sizeof(colleague)), ios::cur);
					fdat.write((char*)&col1, sizeof(colleague));//д��������ļ�
					cout << "�޸ĳɹ���\n";
					//д���ı��ļ�
					ofstream outstuf;
					outstuf.open(file.file2, ios::out);
					if (!outstuf) {
						cerr << "txt file could not open!";
						abort();
					}
					outstuf << "This is an addressbook of colleagues\n";
					fdat.seekg(0, ios::beg);
					do {
						fdat.read((char*)&col, sizeof(colleague));
						outstuf << col.name << " " << col.year << " " << col.month << " " << col.day << " " << col.telephone << " " << col.Email << " " << col.unit << "\n";
					} while (strcmp(col.name, "no") != 0);
					outstuf.close();
					fdat.close();
					break;
				}
				if (choice == 2) {
					break;
				}
			}
			//δ�����д�����Ϣ������ֱ�д��������ļ����ı��ļ�
			fdat.seekp(-long(sizeof(colleague)), ios::cur);
			fdat.write((char*)&col1, sizeof(colleague));
			fdat.write((char*)&mark2, sizeof(colleague));
			fdat.seekg(0, ios::beg);
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
			cout << "��ӳɹ���\n";
			outstuf.close();
			fdat.close();
			break;
		}
		case '3': {
			friends fri, fri1;
			int choice;
			fstream fdat(file.fileDat3, ios::in | ios::out | ios::binary);
			if (!fdat) {
				cout << "�ļ������ڣ�����г�ʼ��������\n";
				return;
			}
			cout << "*****������Ϣ¼��*****" << endl;
			cout << "�밴���� ��������(���� �� ������) �绰 Email ��ʶ�ص��˳�����룺\n";
			cin >> fri1.name >> fri1.year >> fri1.month >> fri1.day >> fri1.telephone >> fri1.Email >> fri1.site;
			fdat.seekg(0, ios::beg);
			do {
				fdat.read((char*)&fri, sizeof(friends));
			} while (strcmp(fri.name, fri1.name) != 0 && strcmp(fri.name, "no") != 0);
			//���ӹ��ܣ������Ϣʱ�����û��Ƿ��Ѵ��ڸ���Ϣ����ʾ�޸�
			if (strcmp(fri.name, fri1.name) == 0) {
				cout << "����Ա��Ϣ�Ѵ��ڣ�ԭ��Ϣ����:\n";
				cout << "������" << fri.name << endl;
				cout << "�������ڣ�" << fri.year << " " << fri.month << " " << fri.day << endl;
				cout << "�绰��" << fri.telephone << endl;
				cout << "Email��" << fri.Email << endl;
				cout << "��ʶ�ص㣺" << fri.site << endl;
				cout << "�Ƿ��޸ģ���1.��;2.��;��\n";
				cin >> choice;
				if (choice == 1) {
					cout << "�������޸ĺ����Ϣ���밴���� ��������(���� �� ������) �绰 Email ��ʶ�ص��˳�����룺\n";
					cin >> fri1.name >> fri1.year >> fri1.month >> fri1.day >> fri1.telephone >> fri1.Email >> fri1.site;
					fdat.seekp(-long(sizeof(friends)), ios::cur);
					fdat.write((char*)&fri1, sizeof(friends));//д��������ļ�
					cout << "�޸ĳɹ���\n";
					//д���ı��ļ�
					ofstream outstuf;
					outstuf.open(file.file3, ios::out);
					if (!outstuf) {
						cerr << "txt file could not open!";
						abort();
					}
					outstuf << "This is an addressbook of friends\n";
					fdat.seekg(0, ios::beg);
					do {
						fdat.read((char*)&fri, sizeof(friends));
						outstuf << fri.name << " " << fri.year << " " << fri.month << " " << fri.day << " " << fri.telephone << " " << fri.Email << " " << fri.site << "\n";
					} while (strcmp(fri.name, "no") != 0);
					outstuf.close();
					fdat.close();
					break;
				}
				if (choice == 2) {
					break;
				}
			}
			//δ�����д�����Ϣ������ֱ�д��������ļ����ı��ļ�
			fdat.seekp(-long(sizeof(friends)), ios::cur);
			fdat.write((char*)&fri1, sizeof(friends));
			fdat.write((char*)&mark3, sizeof(friends));
			fdat.seekg(0, ios::beg);
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
			cout << "��ӳɹ���\n";
			outstuf.close();
			fdat.close();
			break;
		}
		case '4': {
			relative rel, rel1;
			fstream fdat(file.fileDat4, ios::in | ios::out | ios::binary);
			if (!fdat) {
				cout << "�ļ������ڣ�����г�ʼ��������\n";
				return;
			}
			cout << "*****������Ϣ¼��*****" << endl;
			cout << "�밴���� ��������(���� �� ������) �绰 Email �ƺ���˳�����룺\n";
			cin >> rel1.name >> rel1.year >> rel1.month >> rel1.day >> rel1.telephone >> rel1.Email >> rel1.call;
			fdat.seekg(0, ios::beg);
			do {
				fdat.read((char*)&rel, sizeof(relative));
			} while (strcmp(rel.name, rel1.name) != 0 && strcmp(rel.name, "no") != 0);
			//���ӹ��ܣ������Ϣʱ�����û��Ƿ��Ѵ��ڸ���Ϣ����ʾ�޸�
			if (strcmp(rel.name, rel1.name) == 0) {
				cout << "����Ա��Ϣ�Ѵ��ڣ�ԭ��Ϣ����:\n";
				cout << "������" << rel.name << endl;
				cout << "�������ڣ�" << rel.year << " " << rel.month << " " << rel.day << endl;
				cout << "�绰��" << rel.telephone << endl;
				cout << "Email��" << rel.Email << endl;
				cout << "�ƺ���" << rel.call << endl;
				cout << "�Ƿ��޸ģ���1.��;2.��;��\n";
				cin >> choice;
				if (choice == 1) {
					cout << "�������޸ĺ����Ϣ���밴���� ��������(���� �� ������) �绰 Email �ƺ���˳�����룺\n";
					cin >> rel1.name >> rel1.year >> rel1.month >> rel1.day >> rel1.telephone >> rel1.Email >> rel1.call;
					fdat.seekp(-long(sizeof(relative)), ios::cur);
					fdat.write((char*)&rel1, sizeof(relative));//д��������ļ�
					cout << "�޸ĳɹ���\n";
					//д���ı��ļ�
					ofstream outstuf;
					outstuf.open(file.file4, ios::out);
					if (!outstuf) {
						cerr << "txt file could not open!";
						abort();
					}
					outstuf << "This is an addressbook of relatives\n";
					fdat.seekg(0, ios::beg);
					do {
						fdat.read((char*)&rel, sizeof(relative));
						outstuf << rel.name << " " << rel.year << " " << rel.month << " " << rel.day << " " << rel.telephone << " " << rel.Email << " " << rel.call << "\n";
					} while (strcmp(rel.name, "no") != 0);
					outstuf.close();
					break;
				}
				if (choice == 2) {
					break;
				}
			}
			//δ�����д�����Ϣ������ֱ�д��������ļ����ı��ļ�
			fdat.seekp(-long(sizeof(relative)), ios::cur);
			fdat.write((char*)&rel1, sizeof(relative));
			fdat.write((char*)&mark4, sizeof(relative));
			fdat.seekg(0, ios::beg);
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
			cout << "��ӳɹ���\n";
			outstuf.close();
			fdat.close();
			break;
		}
		case 'Q':
		case 'q': {
			return;
		}
		}
	}
}