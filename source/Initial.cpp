#include"msg.h"
#include"InitialMsg.h"

//初始化信息函数
void InitialMsg::Initial() {
	ofstream outstuf;
	cout << "若文件存在，将删除原有数据，要进行所有文件初始化吗？（Y/N）\n";
	char answer;
	cin >> answer;
	if (answer == 'Y' || answer == 'y') {

		//初始化存储学生信息的文本文件
		outstuf.open(file1, ios::out);
		if (!outstuf) {
			cerr << "File could not be open." << endl;
			abort();
		}
		outstuf << "This is an addressbook of students\n";
		outstuf.close();

		//初始化存储同事信息的文本文件
		outstuf.open(file2, ios::out);
		if (!outstuf) {
			cerr << "File could not be open." << endl;
			abort();
		}
		outstuf << "This is an addressbook of colleagues\n";
		outstuf.close();

		//初始化存储朋友信息的文本文件
		outstuf.open(file3, ios::out);
		if (!outstuf) {
			cerr << "File could not be open." << endl;
			abort();
		}
		outstuf << "This is an addressbook of friends\n";
		outstuf.close();

		//初始化存储亲戚信息的文本文件
		outstuf.open(file4, ios::out);
		if (!outstuf) {
			cerr << "File could not be open." << endl;
			abort();
		}
		outstuf << "This is an addressbook of relatives\n";
		outstuf.close();

		//初始化存储同学信息的二进制文件
		fstream fdat1(fileDat1, ios::out | ios::binary);
		fdat1.seekp(0, ios::beg);
		fdat1.write((char*)&mark1, sizeof(student));//写入结束标志
		fdat1.close();
		//初始化存储同事信息的二进制文件
		fstream fdat2(fileDat2, ios::out | ios::binary);
		fdat2.seekp(0, ios::beg);
		fdat2.write((char*)&mark2, sizeof(colleague));//写入结束标志
		fdat2.close();
		//初始化存储朋友信息的二进制文件
		fstream fdat3(fileDat3, ios::out | ios::binary);
		fdat3.seekp(0, ios::beg);
		fdat3.write((char*)&mark3, sizeof(friends));//写入结束标志
		fdat3.close();
		//初始化存储亲戚信息的二进制文件
		fstream fdat4(fileDat4, ios::out | ios::binary);
		fdat4.seekp(0, ios::beg);
		fdat4.write((char*)&mark4, sizeof(relative));//写入结束标志
		fdat4.close();
		cout << "所有文件已经初始化。\n";
	}
	else cout << "取消操作\n";
}