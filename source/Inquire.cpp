#include"msg.h"
#include"InquireMsg.h"

//判断是否为闰年
bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

// 以公元 1 年 1 月 1 日为基准，计算经过的日期 
int getDays(int year, int month, int day)
{
	int m[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//每个月份的天数
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

//计算两个日期间的天数
int dayDis(int year1, int month1, int day1,
	int year2, int month2, int day2)
{
	return abs(getDays(year2, month2, day2) - getDays(year1, month1, day1));
}

//查询信息函数
void InquireMsg::Inquire() {
	cout << "*****查询*****\n";
	char choice;//选择变量
	char name[10];//姓名
	char tel[11];//电话
	int key = 0;//用于判断是否查询到信息的变量
	while (1) {
		File file;
		cout << "请输入操作选择\n" << "1:按姓名查询;2.按电话查询;3.查询给定月份过生日人数;4.列出全体人员信息;\n"
			<< "5.分别列出同学、同事、朋友、亲戚的信息;6.查询5天内过生日人员信息;Q:退出\n";
		cin >> choice;
		switch (choice) {
		case '1': {
			fstream fdat1(file.fileDat1, ios::in | ios::binary);
			fdat1.seekg(0, ios::beg);
			student stu;
			cout << "姓名：";
			cin >> name;
			do {
				fdat1.read((char*)&stu, sizeof(student));
				if (strcmp(stu.name, name) == 0) {//找到姓名对应的信息
					cout << "查找成功，查找人为你的同学！\n";
					cout << "姓名：" << stu.name << endl;
					cout << "出生日期：" << stu.year << " " << stu.month << " " << stu.day << endl;
					cout << "电话：" << stu.telephone << endl;
					cout << "Email：" << stu.Email << endl;
					cout << "学校：" << stu.school << endl;
					key++;
				}
			} while (strcmp(stu.name, "no") != 0);
			fdat1.close();
			fstream fdat2(file.fileDat2, ios::in | ios::binary);
			fdat2.seekg(0, ios::beg);
			colleague col;
			do {
				fdat2.read((char*)&col, sizeof(colleague));
				if (strcmp(col.name, name) == 0) {//找到姓名对应的信息
					cout << "查找成功，查找人为你的同事！\n";
					cout << "姓名：" << col.name << endl;
					cout << "出生日期：" << col.year << " " << col.month << " " << col.day << endl;
					cout << "电话：" << col.telephone << endl;
					cout << "Email：" << col.Email << endl;
					cout << "单位：" << col.unit << endl;
					key++;
				}
			} while (strcmp(col.name, "no") != 0);
			fdat2.close();
			fstream fdat3(file.fileDat3, ios::in | ios::binary);
			fdat3.seekg(0, ios::beg);
			friends fri;
			do {
				fdat3.read((char*)&fri, sizeof(friends));
				if (strcmp(fri.name, name) == 0) {//找到姓名对应的信息
					cout << "查找成功，查找人为你的朋友！\n";
					cout << "姓名：" << fri.name << endl;
					cout << "出生日期：" << fri.year << " " << fri.month << " " << fri.day << endl;
					cout << "电话：" << fri.telephone << endl;
					cout << "Email：" << fri.Email << endl;
					cout << "认识地点：" << fri.site << endl;
					key++;
				}
			} while (strcmp(fri.name, "no") != 0);
			fdat3.close();
			fstream fdat4(file.fileDat4, ios::in | ios::binary);
			fdat4.seekg(0, ios::beg);
			relative rel;
			do {
				fdat4.read((char*)&rel, sizeof(relative));
				if (strcmp(rel.name, name) == 0) {//找到姓名对应的信息
					cout << "查找成功，查找人为你的亲戚！\n";
					cout << "姓名：" << rel.name << endl;
					cout << "出生日期：" << rel.year << " " << rel.month << " " << rel.day << endl;
					cout << "电话：" << rel.telephone << endl;
					cout << "Email：" << rel.Email << endl;
					cout << "称呼：" << rel.call << endl;
					key++;
				}
			} while (strcmp(rel.name, "no") != 0);
			fdat4.close();
			if (key == 0) {
				cout << "找不到记录！\n";
				continue;
			}
			key = 0;
			break;
		}
		case '2': {
			fstream fdat1(file.fileDat1, ios::in | ios::binary);
			fdat1.seekg(0, ios::beg);
			student stu;
			cout << "电话：";
			cin >> tel;
			do {
				fdat1.read((char*)&stu, sizeof(student));
				if (strcmp(stu.telephone, tel) == 0) {//找到电话对应的信息
					cout << "查找成功，查找人为你的同学！\n";
					cout << "姓名：" << stu.name << endl;
					cout << "出生日期：" << stu.year << " " << stu.month << " " << stu.day << endl;
					cout << "电话：" << stu.telephone << endl;
					cout << "Email：" << stu.Email << endl;
					cout << "学校：" << stu.school << endl;
					key++;
				}
			} while (strcmp(stu.telephone, "no") != 0);
			fdat1.close();
			fstream fdat2(file.fileDat2, ios::in | ios::binary);
			fdat2.seekg(0, ios::beg);
			colleague col;
			do {
				fdat2.read((char*)&col, sizeof(colleague));
				if (strcmp(col.telephone, tel) == 0) {//找到电话对应的信息
					cout << "查找成功，查找人为你的同事！\n";
					cout << "姓名：" << col.name << endl;
					cout << "出生日期：" << col.year << " " << col.month << " " << col.day << endl;
					cout << "电话：" << col.telephone << endl;
					cout << "Email：" << col.Email << endl;
					cout << "单位：" << col.unit << endl;
					key++;
				}
			} while (strcmp(col.telephone, "no") != 0);
			fdat2.close();
			fstream fdat3(file.fileDat3, ios::in | ios::binary);
			fdat3.seekg(0, ios::beg);
			friends fri;
			do {
				fdat3.read((char*)&fri, sizeof(friends));
				if (strcmp(fri.telephone, tel) == 0) {//找到电话对应的信息
					cout << "查找成功，查找人为你的朋友！\n";
					cout << "姓名：" << fri.name << endl;
					cout << "出生日期：" << fri.year << " " << fri.month << " " << fri.day << endl;
					cout << "电话：" << fri.telephone << endl;
					cout << "Email：" << fri.Email << endl;
					cout << "认识地点：" << fri.site << endl;
					key++;
				}
			} while (strcmp(fri.telephone, "no") != 0);
			fdat3.close();
			fstream fdat4(file.fileDat4, ios::in | ios::binary);
			fdat4.seekg(0, ios::beg);
			relative rel;
			do {
				fdat4.read((char*)&rel, sizeof(relative));
				if (strcmp(rel.telephone, tel) == 0) {//找到电话对应的信息
					cout << "查找成功，查找人为你的亲戚！\n";
					cout << "姓名：" << rel.name << endl;
					cout << "出生日期：" << rel.year << " " << rel.month << " " << rel.day << endl;
					cout << "电话：" << rel.telephone << endl;
					cout << "Email：" << rel.Email << endl;
					cout << "称呼：" << rel.call << endl;
					key++;
				}
			} while (strcmp(rel.telephone, "no") != 0);
			fdat4.close();
			if (key == 0) {
				cout << "找不到记录！\n";
				continue;
			}
			key = 0;
			break;
		}
		case '3': {
			int num = 0;//用于记录人数的变量
			int month;//月份
			cout << "请输入月份：";
			cin >> month;
			fstream fdat1(file.fileDat1, ios::in | ios::binary);
			fdat1.seekg(0, ios::beg);
			student stu;
			do {
				fdat1.read((char*)&stu, sizeof(student));
				if (stu.month == month)num++;//找到对于月份的信息，num+1
			} while (strcmp(stu.name, "no") != 0);
			fdat1.close();
			fstream fdat2(file.fileDat2, ios::in | ios::binary);
			fdat2.seekg(0, ios::beg);
			colleague col;
			do {
				fdat2.read((char*)&col, sizeof(colleague));
				if (col.month == month)num++;//找到对于月份的信息，num+1
			} while (strcmp(col.name, "no") != 0);
			fdat2.close();
			fstream fdat3(file.fileDat3, ios::in | ios::binary);
			fdat3.seekg(0, ios::beg);
			friends fri;
			do {
				fdat3.read((char*)&fri, sizeof(friends));
				if (fri.month == month)num++;//找到对于月份的信息，num+1
			} while (strcmp(fri.name, "no") != 0);
			fdat3.close();
			fstream fdat4(file.fileDat4, ios::in | ios::binary);
			fdat4.seekg(0, ios::beg);
			relative rel;
			do {
				fdat4.read((char*)&rel, sizeof(relative));
				if (rel.month == month)num++;//找到对于月份的信息，num+1
			} while (strcmp(rel.name, "no") != 0);
			fdat4.close();
			cout << "在" << month << "月里出生的人数为：" << num << endl;
			break;
		}
		case '4': {
			//读入存储学生信息的二进制文件
			fstream fdat1(file.fileDat1, ios::in | ios::binary);
			fdat1.seekg(0, ios::beg);
			student stu;
			cout << "*****学生信息*****\n";
			cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "学校" << endl;
			do {
				fdat1.read((char*)&stu, sizeof(student));
				cout << std::left << setw(18) << stu.name << std::left << setw(18) << stu.year << std::left << setw(18) << stu.month << std::left << setw(18) << stu.day << std::left << setw(18) << stu.telephone << std::left << setw(18) << stu.Email << std::left << setw(18) << stu.school << endl;
			} while (strcmp(stu.name, "no") != 0);
			fdat1.close();
			//读入存储同事信息的二进制文件
			fstream fdat2(file.fileDat2, ios::in | ios::binary);
			fdat2.seekg(0, ios::beg);
			colleague col;
			cout << "*****同事信息*****\n";
			cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "单位" << endl;
			do {
				fdat2.read((char*)&col, sizeof(colleague));
				cout << std::left << setw(18) << col.name << std::left << setw(18) << col.year << std::left << setw(18) << col.month << std::left << setw(18) << col.day << std::left << setw(18) << col.telephone << std::left << setw(18) << col.Email << std::left << setw(18) << col.unit << endl;

			} while (strcmp(col.name, "no") != 0);
			fdat2.close();
			//读入存储朋友信息的二进制文件
			fstream fdat3(file.fileDat3, ios::in | ios::binary);
			fdat3.seekg(0, ios::beg);
			friends fri;
			cout << "*****朋友信息*****\n";
			cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "认识地点" << endl;
			do {
				fdat3.read((char*)&fri, sizeof(friends));
				cout << std::left << setw(18) << fri.name << std::left << setw(18) << fri.year << std::left << setw(18) << fri.month << std::left << setw(18) << fri.day << std::left << setw(18) << fri.telephone << std::left << setw(18) << fri.Email << std::left << setw(18) << fri.site << endl;

			} while (strcmp(fri.name, "no") != 0);
			fdat3.close();
			//读入存储亲戚信息的二进制文件
			fstream fdat4(file.fileDat4, ios::in | ios::binary);
			fdat4.seekg(0, ios::beg);
			relative rel;
			cout << "*****亲戚信息*****\n";
			cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "称呼" << endl;
			do {
				fdat4.read((char*)&rel, sizeof(relative));
				cout << std::left << setw(18) << rel.name << std::left << setw(18) << rel.year << std::left << setw(18) << rel.month << std::left << setw(18) << rel.day << std::left << setw(18) << rel.telephone << std::left << setw(18) << rel.Email << std::left << setw(18) << rel.call << endl;
			} while (strcmp(rel.name, "no") != 0);
			fdat4.close();
			break;
		}
		case '5': {
			cout << "请选择你想要查看的信息的分类（1.同学;2.同事;3.朋友;4.亲戚;）：\n";
			int part;
			cin >> part;
			if (part == 1) {
				//读入存储学生信息的二进制文件
				fstream fdat(file.fileDat1, ios::in | ios::binary);
				fdat.seekg(0, ios::beg);
				student stu;
				cout << "*****学生信息*****\n";
				cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "学校" << endl;
				do {
					fdat.read((char*)&stu, sizeof(student));
					cout << std::left << setw(18) << stu.name << std::left << setw(18) << stu.year << std::left << setw(18) << stu.month << std::left << setw(18) << stu.day << std::left << setw(18) << stu.telephone << std::left << setw(18) << stu.Email << std::left << setw(18) << stu.school << endl;
				} while (strcmp(stu.name, "no") != 0);
				fdat.close();
			}
			if (part == 2) {
				//读入存储同事信息的二进制文件
				fstream fdat(file.fileDat2, ios::in | ios::binary);
				fdat.seekg(0, ios::beg);
				colleague col;
				cout << "*****同事信息*****\n";
				cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "单位" << endl;
				do {
					fdat.read((char*)&col, sizeof(colleague));
					cout << std::left << setw(18) << col.name << std::left << setw(18) << col.year << std::left << setw(18) << col.month << std::left << setw(18) << col.day << std::left << setw(18) << col.telephone << std::left << setw(18) << col.Email << std::left << setw(18) << col.unit << endl;

				} while (strcmp(col.name, "no") != 0);
				fdat.close();
			}
			if (part == 3) {
				//读入存储朋友信息的二进制文件
				fstream fdat(file.fileDat3, ios::in | ios::binary);
				fdat.seekg(0, ios::beg);
				friends fri;
				cout << "*****朋友信息*****\n";
				cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "认识地点" << endl;
				do {
					fdat.read((char*)&fri, sizeof(friends));
					cout << std::left << setw(18) << fri.name << std::left << setw(18) << fri.year << std::left << setw(18) << fri.month << std::left << setw(18) << fri.day << std::left << setw(18) << fri.telephone << std::left << setw(18) << fri.Email << std::left << setw(18) << fri.site << endl;

				} while (strcmp(fri.name, "no") != 0);
				fdat.close();
			}
			if (part == 4) {
				//读入存储亲戚信息的二进制文件
				fstream fdat(file.fileDat4, ios::in | ios::binary);
				fdat.seekg(0, ios::beg);
				relative rel;
				cout << "*****亲戚信息*****\n";
				cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "称呼" << endl;
				do {
					fdat.read((char*)&rel, sizeof(relative));
					cout << std::left << setw(18) << rel.name << std::left << setw(18) << rel.year << std::left << setw(18) << rel.month << std::left << setw(18) << rel.day << std::left << setw(18) << rel.telephone << std::left << setw(18) << rel.Email << std::left << setw(18) << rel.call << endl;
				} while (strcmp(rel.name, "no") != 0);
				fdat.close();
			}
			break;
		}
		case '6': {
			cout << "请输入今天的日期（按照年 月 日的格式输入）:\n";
			int y, m, d;
			cin >> y >> m >> d;
			char weekday[][10] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };//星期数组，存储所有星期的英文表示
			//读入存储学生信息的二进制文件
			fstream fdat1(file.fileDat1, ios::in | ios::binary);
			fdat1.seekg(0, ios::beg);
			student stu;
			cout << "*****同学信息*****\n";
			cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "星期几" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "学校" << endl;
			int i[4] = { 0 };//用于记录符合条件的不同种类的人员的人数
			char name[100][10];//用于存储符合条件的学生姓名
			do {
				fdat1.read((char*)&stu, sizeof(student));
				if (dayDis(y, m, d, stu.year, stu.month, stu.day) <= 5 && strcmp(stu.name, "no") != 0) {//查找到5天内生日的学生信息
					cout << std::left << setw(18) << stu.name << std::left << setw(18) << stu.year << std::left << setw(18) << stu.month << std::left << setw(18) << stu.day << std::left << setw(18) << weekday[(stu.year + 2 * stu.month + 3 * (stu.month + 1) / 5 + stu.day + stu.day / 4 - stu.day / 100 + stu.day / 400 + 1) % 7] << std::left << setw(18) << stu.telephone << std::left << setw(18) << stu.Email << std::left << setw(18) << stu.school << endl;
					strcpy(name[i[0]], stu.name);//存储学生姓名
					i[0]++;
				}
			} while (strcmp(stu.name, "no") != 0);
			if (!i[0])cout << "未找到符合的学生信息\n";
			fdat1.close();
			//读入存储同事信息的二进制文件
			fstream fdat2(file.fileDat2, ios::in | ios::binary);
			fdat2.seekg(0, ios::beg);
			colleague col;
			cout << "*****同事信息*****\n";
			cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "星期几" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "单位" << endl;
			do {
				fdat2.read((char*)&col, sizeof(colleague));
				if (dayDis(y, m, d, col.year, col.month, col.day) <= 5 && strcmp(col.name, "no") != 0) {//查找到5天内生日的同事信息
					cout << std::left << setw(18) << col.name << std::left << setw(18) << col.year << std::left << setw(18) << col.month << std::left << setw(18) << col.day << std::left << setw(18) << weekday[(col.year + 2 * col.month + 3 * (col.month + 1) / 5 + col.day + col.day / 4 - col.day / 100 + col.day / 400 + 1) % 7] << std::left << setw(18) << col.telephone << std::left << setw(18) << col.Email << std::left << setw(18) << col.unit << endl;
					strcpy(name[i[0] + i[1]], col.name);//存储同事姓名
					i[1]++;
				}
			} while (strcmp(col.name, "no") != 0);
			if (!i[1])cout << "未找到符合的同事信息\n";
			fdat2.close();
			//读入存储朋友信息的二进制文件
			fstream fdat3(file.fileDat3, ios::in | ios::binary);
			fdat3.seekg(0, ios::beg);
			friends fri;
			cout << "*****朋友信息*****\n";
			cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "星期几" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "认识地点" << endl;
			do {
				fdat3.read((char*)&fri, sizeof(friends));
				if (dayDis(y, m, d, fri.year, fri.month, fri.day) <= 5 && strcmp(fri.name, "no") != 0) {//查找到5天内生日的朋友信息
					cout << std::left << setw(18) << fri.name << std::left << setw(18) << fri.year << std::left << setw(18) << fri.month << std::left << setw(18) << fri.day << std::left << setw(18) << weekday[(fri.year + 2 * fri.month + 3 * (fri.month + 1) / 5 + fri.day + fri.day / 4 - fri.day / 100 + fri.day / 400 + 1) % 7] << std::left << setw(18) << fri.telephone << std::left << setw(18) << fri.Email << std::left << setw(18) << fri.site << endl;
					strcpy(name[i[0] + i[1] + i[2]], fri.name);//存储朋友姓名
					i[2]++;
				}
			} while (strcmp(fri.name, "no") != 0);
			if (!i[2])cout << "未找到符合的朋友信息\n";
			fdat3.close();
			//读入存储亲戚信息的二进制文件
			fstream fdat4(file.fileDat4, ios::in | ios::binary);
			fdat4.seekg(0, ios::beg);
			relative rel;
			cout << "*****亲戚信息*****\n";
			cout << std::left << setw(18) << "姓名" << std::left << setw(18) << "(出生日期)年" << std::left << setw(18) << "月" << std::left << setw(18) << "日" << std::left << setw(18) << "星期几" << std::left << setw(18) << "电话" << std::left << setw(18) << "Email" << std::left << setw(18) << "称呼" << endl;
			do {
				fdat4.read((char*)&rel, sizeof(relative));
				if (dayDis(y, m, d, rel.year, rel.month, rel.day) <= 5 && strcmp(rel.name, "no") != 0) {//查找到5天内生日的亲戚信息
					cout << std::left << setw(18) << rel.name << std::left << setw(18) << rel.year << std::left << setw(18) << rel.month << std::left << setw(18) << rel.day << std::left << setw(18) << weekday[(rel.year + 2 * rel.month + 3 * (rel.month + 1) / 5 + rel.day + rel.day / 4 - rel.day / 100 + rel.day / 400 + 1) % 7] << std::left << setw(18) << rel.telephone << std::left << setw(18) << rel.Email << std::left << setw(18) << rel.call << endl;
					strcpy(name[i[0] + i[1] + i[2] + i[3]], rel.name);//存储亲戚姓名
					i[3]++;
				}
			} while (strcmp(rel.name, "no") != 0);
			if (!i[3])cout << "未找到符合的亲戚信息\n";
			fdat4.close();
			//生成生日贺卡
			if (i[0] + i[1] + i[2] + i[3] > 0) {
				cout << "是否生成祝贺生日的电子邮件(1.是;2.否;)\n";
				int choice;
				cin >> choice;
				if (choice == 1) {
					cout << "生日贺卡已生成！\n";
					ofstream outstuf;
					//逐个生成生日贺卡
					for (int j = 0;j < i[0] + i[1] + i[2] + i[3]; j++) {
						string filename = "d:\\";
						filename = filename + name[j] + "'s birthday card.txt";
						outstuf.open(filename, ios::out);
						outstuf << "亲爱的" << name[j] << ":" << endl;
						outstuf << "     祝生日快乐，健康幸福。" << endl;
						outstuf << "                                                                     开发者" << endl;
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