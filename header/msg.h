#pragma once
#include<iostream>
#include<fstream>
#include<istream>
#include<iomanip>
#include<cstdio>
#include<cstring>
using namespace std;


//文件类
class File {
public:
	const char *file1 = "d:\\AddressBook1.txt";//存储学生信息的文本文件地址
	const char *file2 = "d:\\AddressBook2.txt";//存储同事信息的文本文件地址
	const char *file3 = "d:\\AddressBook3.txt";//存储朋友信息的文本文件地址
	const char *file4 = "d:\\AddressBook4.txt";//存储亲戚信息的文本文件地址
	const char *fileDat1 = "d:\\AddressBook1.dat";//存储学生信息的二进制文件地址
	const char *fileDat2 = "d:\\AddressBook2.dat";//存储同事信息的二进制文件地址
	const char *fileDat3 = "d:\\AddressBook3.dat";//存储朋友信息的二进制文件地址
	const char *fileDat4 = "d:\\AddressBook4.dat";//存储亲戚信息的二进制文件地址
};

//人员信息类
class msg {
public:
	char name[10]="no";//姓名 初值为no
	int year=0;//出生日期的年 初值为0
	int month=0;//出生日期的月 初值为0
	int day=0;//出生日期的日 初值为0
	char telephone[12]="no";//电话 初值为no
	char Email[20]="no";//邮箱 初值为no
};

//学生类，继承信息基类
class student :public msg {
public:
	char school[20]="no";//学生独有变量：学校 初值为no
};

const student mark1;//存储学生信息的二进制文件结束标志

//同事类，继承信息基类
class colleague : public msg{
public:
	char unit[20]="no";//同事独有变量：单位 初值为no
};

const colleague mark2;//存储同事信息的二进制文件结束标志

//朋友类，继承信息基类
class friends : public msg{
public:
	char site[20]="no";//朋友独有变量：认识地点 初值为no
};

const friends mark3;//存储朋友信息的二进制文件结束标志

//亲戚类，继承信息基类
class relative : public msg{
public:
	char call[20]="no";//亲戚独有变量：称呼 初值为no
};

const relative mark4;//存储亲戚信息的二进制文件结束标志



