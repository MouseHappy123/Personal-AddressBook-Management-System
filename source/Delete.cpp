#include"msg.h"
#include"DeleteMsg.h"

//删除信息函数
void DeleteMsg::Delete() {
	File file;
	cout << "请选择你想要删除的信息的分类（1.同学;2.同事;3.朋友;4.亲戚;）:\n";
	int part;
	cin >> part;
	char name[10];
	if (part == 1) {
		cout << "请输入想要删除的人员的姓名：";
		cin >> name;
		fstream fdat(file.fileDat1, ios::in | ios::out | ios::binary);
		fdat.seekg(0, ios::beg);
		student stu;
		int choose, i = -1, j, mark = -2;
		//查找原信息
		student stu1[100+5];
		cout << "原信息如下\n";
		cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "学校" << endl;
		do {
			i++;
			fdat.read((char*)&stu1[i], sizeof(student));
			if (strcmp(stu1[i].name, name) == 0) {
				cout << std::left << setw(18) << stu1[i].name << std::left << setw(18) << stu1[i].year << std::left << setw(18) << stu1[i].month << std::left << setw(18) << stu1[i].day << std::left << setw(18) << stu1[i].telephone << std::left << setw(18) << stu1[i].Email << std::left << setw(18) << stu1[i].school << endl;
				mark = i;
			}
		} while (strcmp(stu1[i].name, "no") != 0);
		if (mark == -2)cout << "此人信息不存在！";
		else {
			cout << "是否删除？（1.;是2.否;）";
			cin >> choose;
			if (choose == 1) {
				fdat.close();
				fdat.open(file.fileDat1, ios::trunc | ios::out | ios::binary);
				fdat.seekg(0, ios::beg);
				//重写二进制文件，跳过删除信息
				for (j = 0;j <= i;j++) {
					if (j == mark)continue;
					fdat.write((char*)&stu1[j], sizeof(student));
				}
				fdat.seekg(0, ios::beg);
				cout << "删除成功！\n";
				//重写文本文件
				ofstream outstuf;
				outstuf.open(file.file1, ios::out | ios::trunc);
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
				fdat.close();
			}
			if (choose == 2) {
				cout << "取消操作！\n";
			}
		}
	}
	if (part == 2) {
		cout << "请输入想要删除的人员的姓名：";
		cin >> name;
		fstream fdat(file.fileDat2, ios::in | ios::binary);
		fdat.seekg(0, ios::beg);
		colleague col;
		int choose, i = -1, j, mark = -2;
		//查找原信息
		colleague col1[100+5];
		cout << "原信息如下\n";
		cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "单位" << endl;
		do {
			i++;
			fdat.read((char*)&col1[i], sizeof(colleague));
			if (strcmp(col1[i].name, name) == 0) {
				cout << std::left << setw(18) << col1[i].name << std::left << setw(18) << col1[i].year << std::left << setw(18) << col1[i].month << std::left << setw(18) << col1[i].day << std::left << setw(18) << col1[i].telephone << std::left << setw(18) << col1[i].Email << std::left << setw(18) << col1[i].unit << endl;
				mark = i;
			}
		} while (strcmp(col1[i].name, "no") != 0);
		if (mark == -2)cout << "此人信息不存在！";
		else {
			cout << "是否删除？（1.;是2.否;）";
			cin >> choose;
			if (choose == 1) {
				fdat.close();
				fdat.open(file.fileDat2, ios::out | ios::trunc | ios::binary);//清空二进制文件
				fdat.seekg(0, ios::beg);
				//重写二进制文件
				for (j = 0;j <= i;j++) {
					if (j == mark)continue;
					fdat.write((char*)&col1[j], sizeof(colleague));
				}
				fdat.seekg(0, ios::beg);
				cout << "删除成功！\n";
				//重写文本文件
				ofstream outstuf;
				outstuf.open(file.file2, ios::out | ios::trunc);
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
				fdat.close();
			}
			if (choose == 2) {
				cout << "取消操作！\n";
			}
		}
	}
	if (part == 3) {
		cout << "请输入想要删除的人员的姓名：";
		cin >> name;
		fstream fdat(file.fileDat3, ios::in | ios::binary);
		fdat.seekg(0, ios::beg);
		friends fri;
		int choose, i = -1, j, mark = -2;
		//查找原信息
		friends fri1[100+5];
		cout << "原信息如下\n";
		cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "认识地点" << endl;
		do {
			i++;
			fdat.read((char*)&fri1[i], sizeof(friends));
			if (strcmp(fri1[i].name, name) == 0) {
				cout << std::left << setw(18) << fri1[i].name << std::left << setw(18) << fri1[i].year << std::left << setw(18) << fri1[i].month << std::left << setw(18) << fri1[i].day << std::left << setw(18) << fri1[i].telephone << std::left << setw(18) << fri1[i].Email << std::left << setw(18) << fri1[i].site << endl;
				mark = i;
			}
		} while (strcmp(fri1[i].name, "no") != 0);
		if (mark == -2)cout << "此人信息不存在！";
		else {
			cout << "是否删除？（1.;是2.否;）";
			cin >> choose;
			if (choose == 1) {
				fdat.close();
				fdat.open(file.fileDat3, ios::out | ios::trunc | ios::binary);//清空二进制文件
				fdat.seekg(0, ios::beg);
				//重写二进制文件
				for (j = 0;j <= i;j++) {
					if (j == mark)continue;
					fdat.write((char*)&fri1[j], sizeof(friends));
				}
				fdat.seekg(0, ios::beg);
				cout << "删除成功！\n";
				//重写文本文件
				ofstream outstuf;
				outstuf.open(file.file3, ios::out | ios::trunc);
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
				fdat.close();
			}
			if (choose == 2) {
				cout << "取消操作！\n";
			}
		}
	}
	if (part == 4) {
		cout << "请输入想要删除的人员的姓名：";
		cin >> name;
		fstream fdat(file.fileDat4, ios::in | ios::binary);
		fdat.seekg(0, ios::beg);
		relative rel;
		int choose, i = -1, j, mark = -2;
		//查找原信息
		relative rel1[100+5];
		cout << "原信息如下\n";
		cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "称呼" << endl;
		do {
			i++;
			fdat.read((char*)&rel1[i], sizeof(relative));
			if (strcmp(rel1[i].name, name) == 0) {
				cout << std::left << setw(18) << rel1[i].name << std::left << setw(18) << rel1[i].year << std::left << setw(18) << rel1[i].month << std::left << setw(18) << rel1[i].day << std::left << setw(18) << rel1[i].telephone << std::left << setw(18) << rel1[i].Email << std::left << setw(18) << rel1[i].call << endl;
				mark = i;
			}
		} while (strcmp(rel1[i].name, "no") != 0);
		if (mark == -2)cout << "此人信息不存在！";
		else {
			cout << "是否删除？（1.;是2.否;）";
			cin >> choose;
			if (choose == 1) {
				fdat.close();
				fdat.open(file.fileDat4, ios::out | ios::trunc | ios::binary);//清空二进制文件
				fdat.seekg(0, ios::beg);
				//重写二进制文件
				for (j = 0;j <= i;j++) {
					if (j == mark)continue;
					fdat.write((char*)&rel1[j], sizeof(relative));
				}
				fdat.seekg(0, ios::beg);
				cout << "删除成功！\n";
				//重写文本文件
				ofstream outstuf;
				outstuf.open(file.file4, ios::out | ios::trunc);
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
				fdat.close();
			}
			if (choose == 2) {
				cout << "取消操作！\n";
			}
		}
	}
}