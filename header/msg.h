#pragma once
#include<iostream>
#include<fstream>
#include<istream>
#include<iomanip>
#include<cstdio>
#include<cstring>
using namespace std;


//�ļ���
class File {
public:
	const char *file1 = "d:\\AddressBook1.txt";//�洢ѧ����Ϣ���ı��ļ���ַ
	const char *file2 = "d:\\AddressBook2.txt";//�洢ͬ����Ϣ���ı��ļ���ַ
	const char *file3 = "d:\\AddressBook3.txt";//�洢������Ϣ���ı��ļ���ַ
	const char *file4 = "d:\\AddressBook4.txt";//�洢������Ϣ���ı��ļ���ַ
	const char *fileDat1 = "d:\\AddressBook1.dat";//�洢ѧ����Ϣ�Ķ������ļ���ַ
	const char *fileDat2 = "d:\\AddressBook2.dat";//�洢ͬ����Ϣ�Ķ������ļ���ַ
	const char *fileDat3 = "d:\\AddressBook3.dat";//�洢������Ϣ�Ķ������ļ���ַ
	const char *fileDat4 = "d:\\AddressBook4.dat";//�洢������Ϣ�Ķ������ļ���ַ
};

//��Ա��Ϣ��
class msg {
public:
	char name[10]="no";//���� ��ֵΪno
	int year=0;//�������ڵ��� ��ֵΪ0
	int month=0;//�������ڵ��� ��ֵΪ0
	int day=0;//�������ڵ��� ��ֵΪ0
	char telephone[12]="no";//�绰 ��ֵΪno
	char Email[20]="no";//���� ��ֵΪno
};

//ѧ���࣬�̳���Ϣ����
class student :public msg {
public:
	char school[20]="no";//ѧ�����б�����ѧУ ��ֵΪno
};

const student mark1;//�洢ѧ����Ϣ�Ķ������ļ�������־

//ͬ���࣬�̳���Ϣ����
class colleague : public msg{
public:
	char unit[20]="no";//ͬ�¶��б�������λ ��ֵΪno
};

const colleague mark2;//�洢ͬ����Ϣ�Ķ������ļ�������־

//�����࣬�̳���Ϣ����
class friends : public msg{
public:
	char site[20]="no";//���Ѷ��б�������ʶ�ص� ��ֵΪno
};

const friends mark3;//�洢������Ϣ�Ķ������ļ�������־

//�����࣬�̳���Ϣ����
class relative : public msg{
public:
	char call[20]="no";//���ݶ��б������ƺ� ��ֵΪno
};

const relative mark4;//�洢������Ϣ�Ķ������ļ�������־



