#include"msg.h"
#include"SortMsg.h"

//������
void SortMsg::Sort() {
	cout << "*****����*****\n";
	char choice;
	int part;
	while (1) {
		File file;
		cout << "����������ʽ(1.����;2.��������;Q:�˳�;)";
		cin >> choice;
		switch (choice) {
		case '1': {
			cout << "��ѡ���������Ϣ���ࣨ1.ͬѧ;2.ͬ��;3.����;4.����;��:\n";
			cin >> part;
			int i = -1, j, k, temp;//i���ڼ�¼����
			if (part == 1) {
				fstream fdat(file.fileDat1, ios::in | ios::binary);
				fdat.seekg(0, ios::beg);
				student stu;
				do {
					fdat.read((char*)&stu, sizeof(student));
					i++;
				} while (strcmp(stu.name, "no") != 0);
				student *stu1 = new student[i];
				int *index = new int[i];//��̬������������
				for (j = 0;j < i;j++) {
					index[j] = j;
				}
				fdat.seekg(0, ios::beg);
				for (j = 0;j < i;j++) {
					fdat.read((char*)&stu1[j], sizeof(student));
				}
				//ð�����򣬲�����������
				for (j = 1;j < i;j++) {
					for (k = 0;k <= i - j - 1;k++) {
						if (strcmp(stu1[index[k]].name, stu1[index[k + 1]].name) < 0) {
							temp = index[k];
							index[k] = index[k + 1];
							index[k + 1] = temp;
						}
					}
				}
				cout << "***����������***\n";
				cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "ѧУ" << endl;
				for (j = 0;j < i;j++)
					cout << std::left << setw(18) << stu1[index[j]].name << std::left << setw(18) << stu1[index[j]].year << std::left << setw(18) << stu1[index[j]].month << std::left << setw(18) << stu1[index[j]].day << std::left << setw(18) << stu1[index[j]].telephone << std::left << setw(18) << stu1[index[j]].Email << std::left << setw(18) << stu1[index[j]].school << endl;
				fdat.close();
				i = -1;
			}
			if (part == 2) {
				fstream fdat(file.fileDat2, ios::in | ios::binary);
				fdat.seekg(0, ios::beg);
				colleague col;
				do {
					fdat.read((char*)&col, sizeof(colleague));
					i++;
				} while (strcmp(col.name, "no") != 0);
				colleague *col1 = new colleague[i];
				int *index = new int[i];//��̬������������
				for (j = 0;j < i;j++) {
					index[j] = j;
				}
				fdat.seekg(0, ios::beg);
				for (j = 0;j < i;j++) {
					fdat.read((char*)&col1[j], sizeof(colleague));
				}
				//ð�����򣬲�����������
				for (j = 1;j < i;j++) {
					for (k = 0;k <= i - j - 1;k++) {
						if (strcmp(col1[index[k]].name, col1[index[k + 1]].name) < 0) {
							temp = index[k];
							index[k] = index[k + 1];
							index[k + 1] = temp;
						}
					}
				}
				cout << "***����������***\n";
				cout << std::left << setw(18) << "����" << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "��λ" << endl;
				for (j = 0;j < i;j++)
					cout << std::left << setw(18) << col1[index[j]].name << std::left << setw(18) << col1[index[j]].year << std::left << setw(18) << col1[index[j]].month << std::left << setw(18) << col1[index[j]].day << std::left << setw(18) << col1[index[j]].telephone << std::left << setw(18) << col1[index[j]].Email << std::left << setw(18) << col1[index[j]].unit << endl;
				fdat.close();
				i = -1;
			}
			if (part == 3) {
				fstream fdat(file.fileDat3, ios::in | ios::binary);
				fdat.seekg(0, ios::beg);
				friends fri;
				do {
					fdat.read((char*)&fri, sizeof(friends));
					i++;
				} while (strcmp(fri.name, "no") != 0);
				friends *fri1 = new friends[i];
				int *index = new int[i];//��̬������������
				for (j = 0;j < i;j++) {
					index[j] = j;
				}
				fdat.seekg(0, ios::beg);
				for (j = 0;j < i;j++) {
					fdat.read((char*)&fri1[j], sizeof(friends));
				}
				//ð�����򣬲�����������
				for (j = 1;j < i;j++) {
					for (k = 0;k <= i - j - 1;k++) {
						if (strcmp(fri1[index[k]].name, fri1[index[k + 1]].name) < 0) {
							temp = index[k];
							index[k] = index[k + 1];
							index[k + 1] = temp;
						}
					}
				}
				cout << "***����������***\n";
				cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "��ʶ�ص�" << endl;
				for (j = 0;j < i;j++)
					cout << std::left << setw(18) << fri1[index[j]].name << std::left << setw(18) << fri1[index[j]].year << std::left << setw(18) << fri1[index[j]].month << std::left << setw(18) << fri1[index[j]].day << std::left << setw(18) << fri1[index[j]].telephone << std::left << setw(18) << fri1[index[j]].Email << std::left << setw(18) << fri1[index[j]].site << endl;
				fdat.close();
				i = -1;
			}
			if (part == 4) {
				fstream fdat(file.fileDat4, ios::in | ios::binary);
				fdat.seekg(0, ios::beg);
				relative rel;
				do {
					fdat.read((char*)&rel, sizeof(relative));
					i++;
				} while (strcmp(rel.name, "no") != 0);
				relative *rel1 = new relative[i];
				int *index = new int[i];//��̬������������
				for (j = 0;j < i;j++) {
					index[j] = j;
				}
				fdat.seekg(0, ios::beg);
				for (j = 0;j < i;j++) {
					fdat.read((char*)&rel1[j], sizeof(relative));
				}
				//ð�����򣬲�����������
				for (j = 1;j < i;j++) {
					for (k = 0;k <= i - j - 1;k++) {
						if (strcmp(rel1[index[k]].name, rel1[index[k + 1]].name) < 0) {
							temp = index[k];
							index[k] = index[k + 1];
							index[k + 1] = temp;
						}
					}
				}
				cout << "***����������***\n";
				cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "�ƺ�" << endl;
				for (j = 0;j < i;j++)
					cout << std::left << setw(18) << rel1[index[j]].name << std::left << setw(18) << rel1[index[j]].year << std::left << setw(18) << rel1[index[j]].month << std::left << setw(18) << rel1[index[j]].day << std::left << setw(18) << rel1[index[j]].telephone << std::left << setw(18) << rel1[index[j]].Email << std::left << setw(18) << rel1[index[j]].call << endl;
				fdat.close();
				i = -1;
			}
			break;
		}
		case '2': {
			cout << "��ѡ���������Ϣ���ࣨ1.ͬѧ;2.ͬ��;3.����;4.����;��:\n";
			cin >> part;
			int i = -1, j, k, temp;//i���ڼ�¼����
			if (part == 1) {
				fstream fdat(file.fileDat1, ios::in | ios::binary);
				fdat.seekg(0, ios::beg);
				student stu;
				do {
					fdat.read((char*)&stu, sizeof(student));
					i++;
				} while (strcmp(stu.name, "no") != 0);
				student *stu1 = new student[i];
				int *index = new int[i];//��̬������������
				for (j = 0;j < i;j++) {
					index[j] = j;
				}
				fdat.seekg(0, ios::beg);
				for (j = 0;j < i;j++) {
					fdat.read((char*)&stu1[j], sizeof(student));
				}
				//ð�����򣬲�����������
				for (j = 1;j < i;j++) {
					for (k = 0;k <= i - j - 1;k++) {
						if (stu1[index[k]].year < stu1[index[k + 1]].year || stu1[index[k]].year == stu1[index[k + 1]].year&&stu1[index[k]].month < stu1[index[k + 1]].month || stu1[index[k]].year == stu1[index[k + 1]].year&&stu1[index[k]].month == stu1[index[k + 1]].month&&stu1[index[k]].day < stu1[index[k + 1]].day) {
							temp = index[k];
							index[k] = index[k + 1];
							index[k + 1] = temp;
						}
					}
				}
				cout << "***��������������***\n";
				cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "ѧУ" << endl;
				for (j = 0;j < i;j++)
					cout << std::left << setw(18) << stu1[index[j]].name << std::left << setw(18) << stu1[index[j]].year << std::left << setw(18) << stu1[index[j]].month << std::left << setw(18) << stu1[index[j]].day << std::left << setw(18) << stu1[index[j]].telephone << std::left << setw(18) << stu1[index[j]].Email << std::left << setw(18) << stu1[index[j]].school << endl;
				fdat.close();
				i = -1;
			}
			if (part == 2) {
				fstream fdat(file.fileDat2, ios::in | ios::binary);
				fdat.seekg(0, ios::beg);
				colleague col;
				do {
					fdat.read((char*)&col, sizeof(colleague));
					i++;
				} while (strcmp(col.name, "no") != 0);
				colleague *col1 = new colleague[i];
				int *index = new int[i];//��̬������������
				for (j = 0;j < i;j++) {
					index[j] = j;
				}
				fdat.seekg(0, ios::beg);
				for (j = 0;j < i;j++) {
					fdat.read((char*)&col1[j], sizeof(colleague));
				}
				//ð�����򣬲�����������
				for (j = 1;j < i;j++) {
					for (k = 0;k <= i - j - 1;k++) {
						if (col1[index[k]].year < col1[index[k + 1]].year || col1[index[k]].year == col1[index[k + 1]].year&&col1[index[k]].month < col1[index[k + 1]].month || col1[index[k]].year == col1[index[k + 1]].year&&col1[index[k]].month == col1[index[k + 1]].month&&col1[index[k]].day < col1[index[k + 1]].day) {
							temp = index[k];
							index[k] = index[k + 1];
							index[k + 1] = temp;
						}
					}
				}
				cout << "***��������������***\n";
				cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "��λ" << endl;
				for (j = 0;j < i;j++)
					cout << std::left << setw(18) << col1[index[j]].name << std::left << setw(18) << col1[index[j]].year << std::left << setw(18) << col1[index[j]].month << std::left << setw(18) << col1[index[j]].day << std::left << setw(18) << col1[index[j]].telephone << std::left << setw(18) << col1[index[j]].Email << std::left << setw(18) << col1[index[j]].unit << endl;
				fdat.close();
				i = -1;
			}
			if (part == 3) {
				fstream fdat(file.fileDat3, ios::in | ios::binary);
				fdat.seekg(0, ios::beg);
				friends fri;
				do {
					fdat.read((char*)&fri, sizeof(friends));
					i++;
				} while (strcmp(fri.name, "no") != 0);
				friends *fri1 = new friends[i];
				int *index = new int[i];//��̬������������
				for (j = 0;j < i;j++) {
					index[j] = j;
				}
				fdat.seekg(0, ios::beg);
				for (j = 0;j < i;j++) {
					fdat.read((char*)&fri1[j], sizeof(friends));
				}
				//ð�����򣬲�����������
				for (j = 1;j < i;j++) {
					for (k = 0;k <= i - j - 1;k++) {
						if (fri1[index[k]].year < fri1[index[k + 1]].year || fri1[index[k]].year == fri1[index[k + 1]].year&&fri1[index[k]].month < fri1[index[k + 1]].month || fri1[index[k]].year == fri1[index[k + 1]].year&&fri1[index[k]].month == fri1[index[k + 1]].month&&fri1[index[k]].day < fri1[index[k + 1]].day) {
							temp = index[k];
							index[k] = index[k + 1];
							index[k + 1] = temp;
						}
					}
				}
				cout << "***��������������***\n";
				cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "��ʶ�ص�" << endl;
				for (j = 0;j < i;j++)
					cout << std::left << setw(18) << fri1[index[j]].name << std::left << setw(18) << fri1[index[j]].year << std::left << setw(18) << fri1[index[j]].month << std::left << setw(18) << fri1[index[j]].day << std::left << setw(18) << fri1[index[j]].telephone << std::left << setw(18) << fri1[index[j]].Email << std::left << setw(18) << fri1[index[j]].site << endl;
				fdat.close();
				i = -1;
			}
			if (part == 4) {
				fstream fdat(file.fileDat4, ios::in | ios::binary);
				fdat.seekg(0, ios::beg);
				relative rel;
				do {
					fdat.read((char*)&rel, sizeof(relative));
					i++;
				} while (strcmp(rel.name, "no") != 0);
				relative *rel1 = new relative[i];
				int *index = new int[i];//��̬������������
				for (j = 0;j < i;j++) {
					index[j] = j;
				}
				fdat.seekg(0, ios::beg);
				for (j = 0;j < i;j++) {
					fdat.read((char*)&rel1[j], sizeof(relative));
				}
				//ð�����򣬲�����������
				for (j = 1;j < i;j++) {
					for (k = 0;k <= i - j - 1;k++) {
						if (rel1[index[k]].year < rel1[index[k + 1]].year || rel1[index[k]].year == rel1[index[k + 1]].year&&rel1[index[k]].month < rel1[index[k + 1]].month || rel1[index[k]].year == rel1[index[k + 1]].year&&rel1[index[k]].month == rel1[index[k + 1]].month&&rel1[index[k]].day < rel1[index[k + 1]].day) {
							temp = index[k];
							index[k] = index[k + 1];
							index[k + 1] = temp;
						}
					}
				}
				cout << "***��������������***\n";
				cout << std::left << setw(18) << "����" << std::left << setw(18) << "(��������)��" << std::left << setw(18) << "��" << std::left << setw(18) << "��" << std::left << setw(18) << "�绰" << std::left << setw(18) << "Email" << std::left << setw(18) << "�ƺ�" << endl;
				for (j = 0;j < i;j++)
					cout << std::left << setw(18) << rel1[index[j]].name << std::left << setw(18) << rel1[index[j]].year << std::left << setw(18) << rel1[index[j]].month << std::left << setw(18) << rel1[index[j]].day << std::left << setw(18) << rel1[index[j]].telephone << std::left << setw(18) << rel1[index[j]].Email << std::left << setw(18) << rel1[index[j]].call << endl;
				fdat.close();
				i = -1;
			}
			break;
		}
		case 'Q':
		case 'q':return;
		}
	}
}