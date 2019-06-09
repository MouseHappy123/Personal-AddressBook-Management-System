#include"msg.h"
#include"AddMsg.h"

//添加信息函数
void AddMsg::Append() {
	File file;
	cout << "******信息登记*****" << endl;
	char choice;
	while (1) {
		cout << "请输入你想要录入的人员分类（1.同学;2.同事;3.朋友;4.亲戚;Q:退出;）：\n";
		cin >> choice;
		ofstream outstuf;
		switch (choice)
		{
		case '1': {
			student stu, stu1;
			int choice;
			fstream fdat(file.fileDat1, ios::in | ios::out | ios::binary);
			if (!fdat) {
				cout << "文件不存在，请进行初始化操作。\n";
				return;
			}
			cout << "*****学生信息录入*****" << endl;
			cout << "请按姓名 出生日期(按年 月 日输入) 电话 Email 学校名称的顺序输入：\n";
			cin >> stu1.name >> stu1.year >> stu1.month >> stu1.day >> stu1.telephone >> stu1.Email >> stu1.school;
			fdat.seekg(0, ios::beg);
			do {
				fdat.read((char*)&stu, sizeof(student));
			} while (strcmp(stu.name, stu1.name) != 0 && strcmp(stu.name, "no") != 0);
			//附加功能：添加信息时反馈用户是否已存在该消息，提示修改
			if (strcmp(stu.name, stu1.name) == 0) {
				cout << "该人员信息已存在，原信息如下:\n";
				cout << "姓名：" << stu.name << endl;
				cout << "出生日期：" << stu.year << " " << stu.month << " " << stu.day << endl;
				cout << "电话：" << stu.telephone << endl;
				cout << "Email：" << stu.Email << endl;
				cout << "学校：" << stu.school << endl;
				cout << "是否修改？（1.是;2.否;）\n";
				cin >> choice;
				if (choice == 1) {
					cout << "请输入修改后的信息，请按姓名 出生日期(按年 月 日输入) 电话 Email 学校名称的顺序输入：\n";
					cin >> stu1.name >> stu1.year >> stu1.month >> stu1.day >> stu1.telephone >> stu1.Email >> stu1.school;
					fdat.seekp(-long(sizeof(student)), ios::cur);
					fdat.write((char*)&stu1, sizeof(student));//写入二进制文件
					cout << "修改成功！\n";
					//写入文本文件
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
			//未发现有存在信息情况，分别写入二进制文件和文本文件
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
			cout << "添加成功！\n";
			outstuf.close();
			fdat.close();
			break;
		}
		case '2': {
			colleague col, col1;
			int choice;
			fstream fdat(file.fileDat2, ios::in | ios::out | ios::binary);
			if (!fdat) {
				cout << "文件不存在，请进行初始化操作。\n";
				return;
			}
			cout << "*****同事信息录入*****" << endl;
			cout << "请按姓名 出生日期(按年 月 日输入) 电话 Email 单位名称的顺序输入：\n";
			cin >> col1.name >> col1.year >> col1.month >> col1.day >> col1.telephone >> col1.Email >> col1.unit;
			fdat.seekg(0, ios::beg);
			do {
				fdat.read((char*)&col, sizeof(colleague));
			} while (strcmp(col.name, col1.name) != 0 && strcmp(col.name, "no") != 0);
			//附加功能：添加信息时反馈用户是否已存在该消息，提示修改
			if (strcmp(col.name, col1.name) == 0) {
				cout << "该人员信息已存在，原信息如下:\n";
				cout << "姓名：" << col.name << endl;
				cout << "出生日期：" << col.year << " " << col.month << " " << col.day << endl;
				cout << "电话：" << col.telephone << endl;
				cout << "Email：" << col.Email << endl;
				cout << "单位：" << col.unit << endl;
				cout << "是否修改？（1.是;2.否;）\n";
				cin >> choice;
				if (choice == 1) {
					cout << "请输入修改后的信息，请按姓名 出生日期(按年 月 日输入) 电话 Email 单位名称的顺序输入：\n";
					cin >> col1.name >> col1.year >> col1.month >> col1.day >> col1.telephone >> col1.Email >> col1.unit;
					fdat.seekp(-long(sizeof(colleague)), ios::cur);
					fdat.write((char*)&col1, sizeof(colleague));//写入二进制文件
					cout << "修改成功！\n";
					//写入文本文件
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
			//未发现有存在信息情况，分别写入二进制文件和文本文件
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
			cout << "添加成功！\n";
			outstuf.close();
			fdat.close();
			break;
		}
		case '3': {
			friends fri, fri1;
			int choice;
			fstream fdat(file.fileDat3, ios::in | ios::out | ios::binary);
			if (!fdat) {
				cout << "文件不存在，请进行初始化操作。\n";
				return;
			}
			cout << "*****朋友信息录入*****" << endl;
			cout << "请按姓名 出生日期(按年 月 日输入) 电话 Email 认识地点的顺序输入：\n";
			cin >> fri1.name >> fri1.year >> fri1.month >> fri1.day >> fri1.telephone >> fri1.Email >> fri1.site;
			fdat.seekg(0, ios::beg);
			do {
				fdat.read((char*)&fri, sizeof(friends));
			} while (strcmp(fri.name, fri1.name) != 0 && strcmp(fri.name, "no") != 0);
			//附加功能：添加信息时反馈用户是否已存在该消息，提示修改
			if (strcmp(fri.name, fri1.name) == 0) {
				cout << "该人员信息已存在，原信息如下:\n";
				cout << "姓名：" << fri.name << endl;
				cout << "出生日期：" << fri.year << " " << fri.month << " " << fri.day << endl;
				cout << "电话：" << fri.telephone << endl;
				cout << "Email：" << fri.Email << endl;
				cout << "认识地点：" << fri.site << endl;
				cout << "是否修改？（1.是;2.否;）\n";
				cin >> choice;
				if (choice == 1) {
					cout << "请输入修改后的信息，请按姓名 出生日期(按年 月 日输入) 电话 Email 认识地点的顺序输入：\n";
					cin >> fri1.name >> fri1.year >> fri1.month >> fri1.day >> fri1.telephone >> fri1.Email >> fri1.site;
					fdat.seekp(-long(sizeof(friends)), ios::cur);
					fdat.write((char*)&fri1, sizeof(friends));//写入二进制文件
					cout << "修改成功！\n";
					//写入文本文件
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
			//未发现有存在信息情况，分别写入二进制文件和文本文件
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
			cout << "添加成功！\n";
			outstuf.close();
			fdat.close();
			break;
		}
		case '4': {
			relative rel, rel1;
			fstream fdat(file.fileDat4, ios::in | ios::out | ios::binary);
			if (!fdat) {
				cout << "文件不存在，请进行初始化操作。\n";
				return;
			}
			cout << "*****亲戚信息录入*****" << endl;
			cout << "请按姓名 出生日期(按年 月 日输入) 电话 Email 称呼的顺序输入：\n";
			cin >> rel1.name >> rel1.year >> rel1.month >> rel1.day >> rel1.telephone >> rel1.Email >> rel1.call;
			fdat.seekg(0, ios::beg);
			do {
				fdat.read((char*)&rel, sizeof(relative));
			} while (strcmp(rel.name, rel1.name) != 0 && strcmp(rel.name, "no") != 0);
			//附加功能：添加信息时反馈用户是否已存在该消息，提示修改
			if (strcmp(rel.name, rel1.name) == 0) {
				cout << "该人员信息已存在，原信息如下:\n";
				cout << "姓名：" << rel.name << endl;
				cout << "出生日期：" << rel.year << " " << rel.month << " " << rel.day << endl;
				cout << "电话：" << rel.telephone << endl;
				cout << "Email：" << rel.Email << endl;
				cout << "称呼：" << rel.call << endl;
				cout << "是否修改？（1.是;2.否;）\n";
				cin >> choice;
				if (choice == 1) {
					cout << "请输入修改后的信息，请按姓名 出生日期(按年 月 日输入) 电话 Email 称呼的顺序输入：\n";
					cin >> rel1.name >> rel1.year >> rel1.month >> rel1.day >> rel1.telephone >> rel1.Email >> rel1.call;
					fdat.seekp(-long(sizeof(relative)), ios::cur);
					fdat.write((char*)&rel1, sizeof(relative));//写入二进制文件
					cout << "修改成功！\n";
					//写入文本文件
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
			//未发现有存在信息情况，分别写入二进制文件和文本文件
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
			cout << "添加成功！\n";
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