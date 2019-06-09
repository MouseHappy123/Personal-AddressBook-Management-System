#include"msg.h"
#include"SortMsg.h"

//排序函数
void SortMsg::Sort() {
	cout << "*****排序*****\n";
	char choice;
	int part;
	while (1) {
		File file;
		cout << "请输入排序方式(1.姓名;2.出生日期;Q:退出;)";
		cin >> choice;
		switch (choice) {
		case '1': {
			cout << "请选择排序的信息分类（1.同学;2.同事;3.朋友;4.亲戚;）:\n";
			cin >> part;
			int i = -1, j, k, temp;//i用于记录人数
			if (part == 1) {
				fstream fdat(file.fileDat1, ios::in | ios::binary);
				fdat.seekg(0, ios::beg);
				student stu;
				do {
					fdat.read((char*)&stu, sizeof(student));
					i++;
				} while (strcmp(stu.name, "no") != 0);
				student *stu1 = new student[i];
				int *index = new int[i];//动态建立索引数组
				for (j = 0;j < i;j++) {
					index[j] = j;
				}
				fdat.seekg(0, ios::beg);
				for (j = 0;j < i;j++) {
					fdat.read((char*)&stu1[j], sizeof(student));
				}
				//冒泡排序，采用索引数组
				for (j = 1;j < i;j++) {
					for (k = 0;k <= i - j - 1;k++) {
						if (strcmp(stu1[index[k]].name, stu1[index[k + 1]].name) < 0) {
							temp = index[k];
							index[k] = index[k + 1];
							index[k + 1] = temp;
						}
					}
				}
				cout << "***按姓名排序***\n";
				cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "学校" << endl;
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
				int *index = new int[i];//动态建立索引数组
				for (j = 0;j < i;j++) {
					index[j] = j;
				}
				fdat.seekg(0, ios::beg);
				for (j = 0;j < i;j++) {
					fdat.read((char*)&col1[j], sizeof(colleague));
				}
				//冒泡排序，采用索引数组
				for (j = 1;j < i;j++) {
					for (k = 0;k <= i - j - 1;k++) {
						if (strcmp(col1[index[k]].name, col1[index[k + 1]].name) < 0) {
							temp = index[k];
							index[k] = index[k + 1];
							index[k + 1] = temp;
						}
					}
				}
				cout << "***按姓名排序***\n";
				cout << std::left << setw(18) << "姓名" << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "单位" << endl;
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
				int *index = new int[i];//动态建立索引数组
				for (j = 0;j < i;j++) {
					index[j] = j;
				}
				fdat.seekg(0, ios::beg);
				for (j = 0;j < i;j++) {
					fdat.read((char*)&fri1[j], sizeof(friends));
				}
				//冒泡排序，采用索引数组
				for (j = 1;j < i;j++) {
					for (k = 0;k <= i - j - 1;k++) {
						if (strcmp(fri1[index[k]].name, fri1[index[k + 1]].name) < 0) {
							temp = index[k];
							index[k] = index[k + 1];
							index[k + 1] = temp;
						}
					}
				}
				cout << "***按姓名排序***\n";
				cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "认识地点" << endl;
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
				int *index = new int[i];//动态建立索引数组
				for (j = 0;j < i;j++) {
					index[j] = j;
				}
				fdat.seekg(0, ios::beg);
				for (j = 0;j < i;j++) {
					fdat.read((char*)&rel1[j], sizeof(relative));
				}
				//冒泡排序，采用索引数组
				for (j = 1;j < i;j++) {
					for (k = 0;k <= i - j - 1;k++) {
						if (strcmp(rel1[index[k]].name, rel1[index[k + 1]].name) < 0) {
							temp = index[k];
							index[k] = index[k + 1];
							index[k + 1] = temp;
						}
					}
				}
				cout << "***按姓名排序***\n";
				cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "称呼" << endl;
				for (j = 0;j < i;j++)
					cout << std::left << setw(18) << rel1[index[j]].name << std::left << setw(18) << rel1[index[j]].year << std::left << setw(18) << rel1[index[j]].month << std::left << setw(18) << rel1[index[j]].day << std::left << setw(18) << rel1[index[j]].telephone << std::left << setw(18) << rel1[index[j]].Email << std::left << setw(18) << rel1[index[j]].call << endl;
				fdat.close();
				i = -1;
			}
			break;
		}
		case '2': {
			cout << "请选择排序的信息分类（1.同学;2.同事;3.朋友;4.亲戚;）:\n";
			cin >> part;
			int i = -1, j, k, temp;//i用于记录人数
			if (part == 1) {
				fstream fdat(file.fileDat1, ios::in | ios::binary);
				fdat.seekg(0, ios::beg);
				student stu;
				do {
					fdat.read((char*)&stu, sizeof(student));
					i++;
				} while (strcmp(stu.name, "no") != 0);
				student *stu1 = new student[i];
				int *index = new int[i];//动态建立索引数组
				for (j = 0;j < i;j++) {
					index[j] = j;
				}
				fdat.seekg(0, ios::beg);
				for (j = 0;j < i;j++) {
					fdat.read((char*)&stu1[j], sizeof(student));
				}
				//冒泡排序，采用索引数组
				for (j = 1;j < i;j++) {
					for (k = 0;k <= i - j - 1;k++) {
						if (stu1[index[k]].year < stu1[index[k + 1]].year || stu1[index[k]].year == stu1[index[k + 1]].year&&stu1[index[k]].month < stu1[index[k + 1]].month || stu1[index[k]].year == stu1[index[k + 1]].year&&stu1[index[k]].month == stu1[index[k + 1]].month&&stu1[index[k]].day < stu1[index[k + 1]].day) {
							temp = index[k];
							index[k] = index[k + 1];
							index[k + 1] = temp;
						}
					}
				}
				cout << "***按出生日期排序***\n";
				cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "学校" << endl;
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
				int *index = new int[i];//动态建立索引数组
				for (j = 0;j < i;j++) {
					index[j] = j;
				}
				fdat.seekg(0, ios::beg);
				for (j = 0;j < i;j++) {
					fdat.read((char*)&col1[j], sizeof(colleague));
				}
				//冒泡排序，采用索引数组
				for (j = 1;j < i;j++) {
					for (k = 0;k <= i - j - 1;k++) {
						if (col1[index[k]].year < col1[index[k + 1]].year || col1[index[k]].year == col1[index[k + 1]].year&&col1[index[k]].month < col1[index[k + 1]].month || col1[index[k]].year == col1[index[k + 1]].year&&col1[index[k]].month == col1[index[k + 1]].month&&col1[index[k]].day < col1[index[k + 1]].day) {
							temp = index[k];
							index[k] = index[k + 1];
							index[k + 1] = temp;
						}
					}
				}
				cout << "***按出生日期排序***\n";
				cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "单位" << endl;
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
				int *index = new int[i];//动态建立索引数组
				for (j = 0;j < i;j++) {
					index[j] = j;
				}
				fdat.seekg(0, ios::beg);
				for (j = 0;j < i;j++) {
					fdat.read((char*)&fri1[j], sizeof(friends));
				}
				//冒泡排序，采用索引数组
				for (j = 1;j < i;j++) {
					for (k = 0;k <= i - j - 1;k++) {
						if (fri1[index[k]].year < fri1[index[k + 1]].year || fri1[index[k]].year == fri1[index[k + 1]].year&&fri1[index[k]].month < fri1[index[k + 1]].month || fri1[index[k]].year == fri1[index[k + 1]].year&&fri1[index[k]].month == fri1[index[k + 1]].month&&fri1[index[k]].day < fri1[index[k + 1]].day) {
							temp = index[k];
							index[k] = index[k + 1];
							index[k + 1] = temp;
						}
					}
				}
				cout << "***按出生日期排序***\n";
				cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "认识地点" << endl;
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
				int *index = new int[i];//动态建立索引数组
				for (j = 0;j < i;j++) {
					index[j] = j;
				}
				fdat.seekg(0, ios::beg);
				for (j = 0;j < i;j++) {
					fdat.read((char*)&rel1[j], sizeof(relative));
				}
				//冒泡排序，采用索引数组
				for (j = 1;j < i;j++) {
					for (k = 0;k <= i - j - 1;k++) {
						if (rel1[index[k]].year < rel1[index[k + 1]].year || rel1[index[k]].year == rel1[index[k + 1]].year&&rel1[index[k]].month < rel1[index[k + 1]].month || rel1[index[k]].year == rel1[index[k + 1]].year&&rel1[index[k]].month == rel1[index[k + 1]].month&&rel1[index[k]].day < rel1[index[k + 1]].day) {
							temp = index[k];
							index[k] = index[k + 1];
							index[k + 1] = temp;
						}
					}
				}
				cout << "***按出生日期排序***\n";
				cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "称呼" << endl;
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