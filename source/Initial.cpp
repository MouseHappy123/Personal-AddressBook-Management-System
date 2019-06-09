#include"msg.h"
#include"InitialMsg.h"

//��ʼ����Ϣ����
void InitialMsg::Initial() {
	ofstream outstuf;
	cout << "���ļ����ڣ���ɾ��ԭ�����ݣ�Ҫ���������ļ���ʼ���𣿣�Y/N��\n";
	char answer;
	cin >> answer;
	if (answer == 'Y' || answer == 'y') {

		//��ʼ���洢ѧ����Ϣ���ı��ļ�
		outstuf.open(file1, ios::out);
		if (!outstuf) {
			cerr << "File could not be open." << endl;
			abort();
		}
		outstuf << "This is an addressbook of students\n";
		outstuf.close();

		//��ʼ���洢ͬ����Ϣ���ı��ļ�
		outstuf.open(file2, ios::out);
		if (!outstuf) {
			cerr << "File could not be open." << endl;
			abort();
		}
		outstuf << "This is an addressbook of colleagues\n";
		outstuf.close();

		//��ʼ���洢������Ϣ���ı��ļ�
		outstuf.open(file3, ios::out);
		if (!outstuf) {
			cerr << "File could not be open." << endl;
			abort();
		}
		outstuf << "This is an addressbook of friends\n";
		outstuf.close();

		//��ʼ���洢������Ϣ���ı��ļ�
		outstuf.open(file4, ios::out);
		if (!outstuf) {
			cerr << "File could not be open." << endl;
			abort();
		}
		outstuf << "This is an addressbook of relatives\n";
		outstuf.close();

		//��ʼ���洢ͬѧ��Ϣ�Ķ������ļ�
		fstream fdat1(fileDat1, ios::out | ios::binary);
		fdat1.seekp(0, ios::beg);
		fdat1.write((char*)&mark1, sizeof(student));//д�������־
		fdat1.close();
		//��ʼ���洢ͬ����Ϣ�Ķ������ļ�
		fstream fdat2(fileDat2, ios::out | ios::binary);
		fdat2.seekp(0, ios::beg);
		fdat2.write((char*)&mark2, sizeof(colleague));//д�������־
		fdat2.close();
		//��ʼ���洢������Ϣ�Ķ������ļ�
		fstream fdat3(fileDat3, ios::out | ios::binary);
		fdat3.seekp(0, ios::beg);
		fdat3.write((char*)&mark3, sizeof(friends));//д�������־
		fdat3.close();
		//��ʼ���洢������Ϣ�Ķ������ļ�
		fstream fdat4(fileDat4, ios::out | ios::binary);
		fdat4.seekp(0, ios::beg);
		fdat4.write((char*)&mark4, sizeof(relative));//д�������־
		fdat4.close();
		cout << "�����ļ��Ѿ���ʼ����\n";
	}
	else cout << "ȡ������\n";
}